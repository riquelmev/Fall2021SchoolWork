#include "csapp.h"

/* suggested entry and cache structs for Part II */
typedef struct cache_entry {
    char *uri;
    char *item;
    struct cache_entry *next;
    size_t size;
} cache_entry_t;

typedef struct {
    cache_entry_t *head;
    size_t total_size;
} cache_t;

// For Part II: a global variable to point to the in-memory cache
cache_t *cache;

/* print out the contents of the cache */
void cache_print() {
    cache_entry_t *cur = cache->head;
    printf("current cache: (%zd)\n", cache->total_size);
    while(cur) {
        printf("%s (%zd)\n", cur->uri, cur->size);
        cur = cur->next;
    }
}

/* initialize the global cache variable (allocate memory and initialize fields) */
void cache_init() {
    cache = malloc(sizeof(cache_t));
    cache->head = NULL;
    cache->total_size = 0;
}

/* debugging function for printing the uris stored in the cache */
void cache_output(char *output) {
    cache_entry_t *current =  cache->head;
    while (current!=NULL){ /* iterate through the end of the linked cache */
        strncat(output, current->uri, 100);
        strncat(output, " , ", 100);
        current = current -> next;
    }
}
/* deallocate the entire cache (all the entries and the cache global variable) */
void cache_free() {
    cache_entry_t *next;
    cache_entry_t *current =  cache->head;
    while (current!=NULL){ /* iterate through the end of the linked cache */
        next = current->next;
        free(current->item);
        free(current->uri);
        free(current);
        current = next;
    }
    free(cache);
}

/* search cache for an entry with a matching uri 
 * return a pointer to the matching entry or NULL if no matching entry is found
*/
cache_entry_t* cache_lookup(char *uri) {
    cache_entry_t *current =  cache->head;
    while (current!=NULL){ /* iterate through the end of the linked cache */
        if(strcmp(current->uri, uri) == 0){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* insert a new entry at the head of the cache */
void cache_insert(char *uri, char *item, size_t size) {
    cache_entry_t *new_entry = malloc(sizeof(cache_entry_t));
    new_entry ->uri = malloc(MAXLINE);
    new_entry ->item = malloc(MAXLINE);
    strcpy(new_entry->uri, uri);
    strcpy(new_entry->item, item);
    new_entry ->size = size;
    new_entry ->next = cache->head;
    cache->head = new_entry;
    cache->total_size += 1;
}

/* Implement this function for Part I
 * For Part III, you may need to change the parameter and return type of handle_request
 */
void* handle_request(void *argvp) {
    //FILE * fp = fopen("output.txt", "a"); //debugging
    //char output[800] = "cake: ";
    //cache_output(output); 
    long connfd = (long) argvp;
    pthread_detach(pthread_self());
    
    //initialise strings to store data from request
    char buf[MAXLINE], method[MAXLINE], uri[MAXLINE], version[MAXLINE];

    //initialize rio objects
    rio_t rio_client;
    rio_t rio_server;
    
    /* Read request line*/
    Rio_readinitb(&rio_client, connfd);
    if (!Rio_readlineb(&rio_client, buf, MAXLINE))  //line:netp:doit:readrequest
        return NULL;
    //printf("%s", buf);
    sscanf(buf, "%s %s %s", method, uri, version); 
    //fprintf(fp, "blah %s %s %s %s\n", method, uri, version, output);

    /* attempts cache lookup, NULL if not found */
    cache_entry_t *cached_item = cache_lookup(uri);
    char *cache_response = "HTTP/1.0 200 OK\r\n\r\n";

    //if uri is in cache, write request line and content to client
    if (cached_item != NULL){
        //fprintf(fp, "reached cache lookup");
        Rio_writen(connfd, cache_response, strlen(cache_response));
        Rio_writen(connfd, cached_item->item , cached_item->size);
        //fclose(fp);

        //return so that we don't do the rest of the handle request, 
        //since it is unecessary and we don't want duplicate caches
        return NULL;
    }

    
    /* parses uri and formulates request */
    char *token;
    char *all_tokens[100][200];

    /* since we will parse uri with strtok, which has side effects on the original string,
    we must save an original version to use in our cache */
    char uri_saved[MAXLINE] = "";
    strcat(uri_saved, uri);
    token = strtok(uri, " :/");

    /* tokenize uri using the appropriate delimiters */
    int i = 0;
    while(token != NULL){
        token = strtok(NULL, " :/");
        *all_tokens[i] = token;
        i++;
    }

    /* very simple parser, assumes consistent structure */
    char *host = *all_tokens[0];
    char *port  = *all_tokens[1];
    char *page_parsed = *all_tokens[2];

    /* create the new request line to send to the server, with HTTP/1.0 and the relevant page */
    char request[100] = "GET /";
    strcat(request, page_parsed);
    strcat(request, " HTTP/1.0\r\n");

    /* connect to server */
    int destfd = Open_clientfd(host, port);

    Rio_readinitb(&rio_server, destfd); // initialize rio struct to be ready for buffered reading from server

    /* write request line to the sever */
    size_t n = strlen(request);
    Rio_writen(destfd, request, n); // write the request to the server

    /* begin buffered reading from the client and writing to the server until a blank line is reached */
    n = Rio_readlineb(&rio_client, buf, MAXLINE);
    while (strcmp(buf, "\r\n")) { // read one line of up to MAXLINE characters from server
        //printf("client sent %d bytes\n", (int)n);
        //printf("%s", buf);
        Rio_writen(destfd, buf, n); // write the input read from server back to the client
        n = Rio_readlineb(&rio_client, buf, MAXLINE);
    }

    /* write blank line to server to indicate end of request headers */
    Rio_writen(destfd, "\r\n", 3);


    


    /* initialize values for reading the headers and saving content length */
    char header[30];
    int value;
    int content_len = 0;

    /* begin buffered reading from the server and writing to the client until a blank line is reached,
    indicating the end of the response headers */
    n = Rio_readlineb(&rio_server, buf, MAXLINE);
    while (strcmp(buf, "\r\n")) { // read one line of up to MAXLINE characters from server
        //printf("server received %d bytes\n", (int)n);
        //printf("%s", buf);
        Rio_writen(connfd, buf, n); // write the input read from server back to the client
        sscanf(buf, "%s %d", header, &value); 
        if (strcmp(header, "Content-length:") == 0 ){ //if header is content length, save value so we know how much to read/write
            content_len = value;
        }
        n = Rio_readlineb(&rio_server, buf, MAXLINE);
    }
    Rio_writen(connfd, buf, n); // write the blank line from server back to the client
    
    /* create buffer for reading content from server */
    char newbuf[content_len];
    
    /* Read content from server, write to client */
    Rio_readn(destfd, newbuf, content_len);
    Rio_writen(connfd, newbuf, content_len);

    /* insert content into the cache */
    cache_insert(uri_saved, newbuf, content_len);
    //fclose(fp);
    return NULL;
}

int main(int argc, char **argv) {
    long listenfd, connfd;
    char hostname[MAXLINE], port[MAXLINE];
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;
    cache_init();

    /* Check command line args */
    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = Open_listenfd(argv[1]);
    while (1) {
        clientlen = sizeof(clientaddr);
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
        Getnameinfo((SA *)&clientaddr, clientlen, hostname, MAXLINE,
                    port, MAXLINE, 0);
        printf("Accepted connection from (%s, %s)\n", hostname, port);

        
        /* Threading allows concurrent requests */
        pthread_t tid;
        Pthread_create(&tid, NULL, handle_request, (void *)connfd);
        
    }
    cache_free();
}

