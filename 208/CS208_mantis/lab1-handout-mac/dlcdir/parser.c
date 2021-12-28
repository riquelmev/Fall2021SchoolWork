/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ANSI-C.y" /* yacc.c:339  */


    /* Copyright (C) 1989,1990 James A. Roskind, All rights reserved.
    This grammar was developed  and  written  by  James  A.  Roskind. 
    Copying  of  this  grammar  description, as a whole, is permitted 
    providing this notice is intact and applicable  in  all  complete 
    copies.   Translations as a whole to other parser generator input 
    languages  (or  grammar  description  languages)   is   permitted 
    provided  that  this  notice is intact and applicable in all such 
    copies,  along  with  a  disclaimer  that  the  contents  are   a 
    translation.   The reproduction of derived text, such as modified 
    versions of this grammar, or the output of parser generators,  is 
    permitted,  provided  the  resulting  work includes the copyright 
    notice "Portions Copyright (c)  1989,  1990  James  A.  Roskind". 
    Derived products, such as compilers, translators, browsers, etc., 
    that  use  this  grammar,  must also provide the notice "Portions 
    Copyright  (c)  1989,  1990  James  A.  Roskind"  in   a   manner 
    appropriate  to  the  utility,  and in keeping with copyright law 
    (e.g.: EITHER displayed when first invoked/executed; OR displayed 
    continuously on display terminal; OR via placement in the  object 
    code  in  form  readable in a printout, with or near the title of 
    the work, or at the end of the file).  No royalties, licenses  or 
    commissions  of  any  kind are required to copy this grammar, its 
    translations, or derivative products, when the copies are made in 
    compliance with this notice. Persons or corporations that do make 
    copies in compliance with this notice may charge  whatever  price 
    is  agreeable  to  a  buyer, for such copies or derivative works. 
    THIS GRAMMAR IS PROVIDED ``AS IS'' AND  WITHOUT  ANY  EXPRESS  OR 
    IMPLIED  WARRANTIES,  INCLUDING,  WITHOUT LIMITATION, THE IMPLIED 
    WARRANTIES  OF  MERCHANTABILITY  AND  FITNESS  FOR  A  PARTICULAR 
    PURPOSE.

    James A. Roskind
    Independent Consultant
    516 Latania Palm Drive
    Indialantic FL, 32903
    (407)729-4348
    jar@ileaf.com
    or ...!uunet!leafusa!jar


    ---end of copyright notice---


This file is a companion file to a C++ grammar description file.

*/

/*************************************************************************
 *
 *  C-to-C Translator
 *
 *  Adapted from Clean ANSI C Parser
 *  Eric A. Brewer, Michael D. Noakes
 *  
 *  File: ANSI-C.y
 *  ANSI-C.y,v
 * Revision 1.18  1995/05/11  18:53:51  rcm
 * Added gcc extension __attribute__.
 *
 * Revision 1.17  1995/04/21  05:43:54  rcm
 * Cleaned up data-flow analysis, and separated into two files, dataflow.c
 * and analyze.c.  Fixed void pointer arithmetic bug (void *p; p+=5).
 * Moved CVS Id after comment header of each file.
 *
 * Revision 1.16  1995/04/09  21:30:36  rcm
 * Added Analysis phase to perform all analysis at one place in pipeline.
 * Also added checking for functions without return values and unreachable
 * code.  Added tests of live-variable analysis.
 *
 * Revision 1.15  1995/02/13  01:59:53  rcm
 * Added ASTWALK macro; fixed some small bugs.
 *
 * Revision 1.14  1995/02/10  22:09:37  rcm
 * Allow comma at end of enum
 *
 * Revision 1.13  1995/02/01  23:01:20  rcm
 * Added Text node and #pragma collection
 *
 * Revision 1.12  1995/02/01  21:07:01  rcm
 * New AST constructors convention: MakeFoo makes a foo with unknown coordinates,
 * whereas MakeFooCoord takes an explicit Coord argument.
 *
 * Revision 1.11  1995/02/01  07:36:18  rcm
 * Renamed list primitives consistently from '...Element' to '...Item'
 *
 * Revision 1.10  1995/01/27  01:38:45  rcm
 * Redesigned type qualifiers and storage classes;  introduced "declaration
 * qualifier."
 *
 * Revision 1.9  1995/01/25  21:38:10  rcm
 * Added TypeModifiers to make type modifiers extensible
 *
 * Revision 1.8  1995/01/25  02:16:10  rcm
 * Changed how Prim types are created and merged.
 *
 * Revision 1.7  1995/01/20  03:37:53  rcm
 * Added some GNU extensions (long long, zero-length arrays, cast to union).
 * Moved all scope manipulation out of lexer.
 *
 * Revision 1.6  1994/12/23  09:16:00  rcm
 * Marks global declarations
 *
 * Revision 1.5  1994/12/20  09:23:44  rcm
 * Added ASTSWITCH, made other changes to simplify extensions
 *
 * Revision 1.4  1994/11/22  01:54:20  rcm
 * No longer folds constant expressions.
 *
 * Revision 1.3  1994/11/10  03:07:26  rcm
 * Line-number behavior changed.  Now keeps coordinates of first terminal
 * in production, rather than end of production.
 *
 * Revision 1.2  1994/10/28  18:51:53  rcm
 * Removed ALEWIFE-isms.
 *
 *
 *************************************************************************/
#pragma ident "ANSI-C.y,v 1.18 1995/05/11 18:53:51 rcm Exp"

/* FILENAME: C.Y */

/*  This  is a grammar file for the dpANSI C language.  This file was 
last modified by J. Roskind on 3/7/90. Version 1.00 */




/* ACKNOWLEDGMENT:

Without the effort expended by the ANSI C standardizing committee,  I 
would  have been lost.  Although the ANSI C standard does not include 
a fully disambiguated syntax description, the committee has at  least 
provided most of the disambiguating rules in narratives.

Several  reviewers  have also recently critiqued this grammar, and/or 
assisted in discussions during it's preparation.  These reviewers are 
certainly not responsible for the errors I have committed  here,  but 
they  are responsible for allowing me to provide fewer errors.  These 
colleagues include: Bruce Blodgett, and Mark Langley. */

/* Added by Eric A. Brewer */

#define _Y_TAB_H_  /* prevents redundant inclusion of y.tab.h */
#include "ast.h"

#ifndef YYDEBUG
int yydebug=0;
#endif

extern int yylex(void);

GLOBAL List *GrabPragmas(List *stmts_or_decls);  /* from c4.l */
PRIVATE void WarnAboutPrecedence(OpType op, Node *node);

PRIVATE void yyerror(const char *msg)
{
    SyntaxError(msg);
}

/* End of create code (EAB) */





#line 233 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AUTO = 258,
    DOUBLE = 259,
    INT = 260,
    STRUCT = 261,
    BREAK = 262,
    ELSE = 263,
    LONG = 264,
    SWITCH = 265,
    CASE = 266,
    ENUM = 267,
    REGISTER = 268,
    TYPEDEF = 269,
    CHAR = 270,
    EXTERN = 271,
    RETURN = 272,
    UNION = 273,
    CONST = 274,
    FLOAT = 275,
    SHORT = 276,
    UNSIGNED = 277,
    CONTINUE = 278,
    FOR = 279,
    SIGNED = 280,
    VOID = 281,
    DEFAULT = 282,
    GOTO = 283,
    SIZEOF = 284,
    VOLATILE = 285,
    DO = 286,
    IF = 287,
    STATIC = 288,
    WHILE = 289,
    UPLUS = 290,
    UMINUS = 291,
    INDIR = 292,
    ADDRESS = 293,
    POSTINC = 294,
    POSTDEC = 295,
    PREINC = 296,
    PREDEC = 297,
    BOGUS = 298,
    IDENTIFIER = 299,
    STRINGliteral = 300,
    FLOATINGconstant = 301,
    INTEGERconstant = 302,
    OCTALconstant = 303,
    HEXconstant = 304,
    WIDECHARconstant = 305,
    CHARACTERconstant = 306,
    TYPEDEFname = 307,
    ARROW = 308,
    ICR = 309,
    DECR = 310,
    LS = 311,
    RS = 312,
    LE = 313,
    GE = 314,
    EQ = 315,
    NE = 316,
    ANDAND = 317,
    OROR = 318,
    ELLIPSIS = 319,
    MULTassign = 320,
    DIVassign = 321,
    MODassign = 322,
    PLUSassign = 323,
    MINUSassign = 324,
    LSassign = 325,
    RSassign = 326,
    ANDassign = 327,
    ERassign = 328,
    ORassign = 329,
    INLINE = 330,
    ATTRIBUTE = 331
  };
#endif
/* Tokens.  */
#define AUTO 258
#define DOUBLE 259
#define INT 260
#define STRUCT 261
#define BREAK 262
#define ELSE 263
#define LONG 264
#define SWITCH 265
#define CASE 266
#define ENUM 267
#define REGISTER 268
#define TYPEDEF 269
#define CHAR 270
#define EXTERN 271
#define RETURN 272
#define UNION 273
#define CONST 274
#define FLOAT 275
#define SHORT 276
#define UNSIGNED 277
#define CONTINUE 278
#define FOR 279
#define SIGNED 280
#define VOID 281
#define DEFAULT 282
#define GOTO 283
#define SIZEOF 284
#define VOLATILE 285
#define DO 286
#define IF 287
#define STATIC 288
#define WHILE 289
#define UPLUS 290
#define UMINUS 291
#define INDIR 292
#define ADDRESS 293
#define POSTINC 294
#define POSTDEC 295
#define PREINC 296
#define PREDEC 297
#define BOGUS 298
#define IDENTIFIER 299
#define STRINGliteral 300
#define FLOATINGconstant 301
#define INTEGERconstant 302
#define OCTALconstant 303
#define HEXconstant 304
#define WIDECHARconstant 305
#define CHARACTERconstant 306
#define TYPEDEFname 307
#define ARROW 308
#define ICR 309
#define DECR 310
#define LS 311
#define RS 312
#define LE 313
#define GE 314
#define EQ 315
#define NE 316
#define ANDAND 317
#define OROR 318
#define ELLIPSIS 319
#define MULTassign 320
#define DIVassign 321
#define MODassign 322
#define PLUSassign 323
#define MINUSassign 324
#define LSassign 325
#define RSassign 326
#define ANDassign 327
#define ERassign 328
#define ORassign 329
#define INLINE 330
#define ATTRIBUTE 331

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 211 "ANSI-C.y" /* yacc.c:355  */

    Node      *n;
    List      *L;

  /* tq: type qualifiers */
    struct {
        TypeQual   tq;
	Coord      coord;   /* coordinates where type quals began */ 
    } tq;

  /* tok: token coordinates */
    Coord tok;

#line 439 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 456 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2874

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  150
/* YYNRULES -- Number of rules.  */
#define YYNRULES  400
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  647

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     8,     2,     2,     2,    13,     3,     2,
      15,    16,     4,     5,    22,     6,    17,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,    19,
       9,    88,    10,    18,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,    24,    12,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    20,    11,    21,     7,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   343,   343,   354,   355,   356,   357,   362,   366,   373,
     374,   376,   378,   380,   382,   384,   386,   390,   392,   397,
     399,   404,   406,   408,   410,   413,   415,   420,   421,   422,
     423,   424,   425,   429,   430,   435,   436,   438,   440,   445,
     446,   448,   453,   454,   456,   461,   462,   464,   466,   468,
     473,   474,   476,   481,   482,   487,   488,   497,   498,   507,
     508,   513,   514,   523,   524,   532,   533,   540,   541,   543,
     545,   547,   549,   551,   553,   555,   557,   559,   564,   565,
     580,   584,   585,   621,   623,   625,   627,   634,   637,   633,
     643,   646,   642,   652,   655,   651,   665,   664,   675,   674,
     683,   690,   693,   689,   699,   702,   698,   708,   709,   707,
     716,   715,   726,   725,   734,   739,   741,   742,   748,   750,
     752,   754,   761,   763,   765,   772,   774,   776,   783,   784,
     787,   794,   795,   800,   802,   803,   808,   809,   811,   813,
     819,   820,   822,   829,   831,   833,   839,   840,   846,   847,
     854,   855,   860,   861,   862,   863,   873,   874,   877,   880,
     883,   891,   894,   897,   904,   906,   913,   915,   917,   926,
     927,   930,   937,   940,   947,   948,   949,   954,   956,   958,
     961,   968,   971,   974,   977,   984,   985,   986,   991,   992,
     997,   998,  1001,  1008,  1010,  1013,  1020,  1022,  1029,  1034,
    1037,  1044,  1049,  1053,  1069,  1071,  1077,  1078,  1083,  1085,
    1087,  1089,  1098,  1099,  1104,  1106,  1111,  1118,  1120,  1126,
    1127,  1129,  1135,  1136,  1137,  1142,  1143,  1148,  1149,  1150,
    1155,  1157,  1167,  1168,  1171,  1180,  1182,  1186,  1191,  1197,
    1199,  1202,  1205,  1208,  1210,  1212,  1214,  1216,  1219,  1222,
    1225,  1227,  1229,  1235,  1237,  1239,  1244,  1259,  1263,  1268,
    1273,  1279,  1289,  1290,  1295,  1296,  1302,  1303,  1309,  1315,
    1321,  1323,  1330,  1333,  1340,  1343,  1350,  1351,  1356,  1361,
    1363,  1365,  1371,  1373,  1379,  1380,  1384,  1385,  1395,  1396,
    1397,  1398,  1399,  1400,  1402,  1408,  1407,  1412,  1414,  1418,
    1423,  1425,  1427,  1429,  1433,  1435,  1442,  1444,  1446,  1448,
    1455,  1456,  1461,  1462,  1467,  1471,  1473,  1475,  1475,  1482,
    1481,  1486,  1485,  1490,  1489,  1496,  1495,  1500,  1499,  1504,
    1503,  1507,  1507,  1512,  1514,  1516,  1518,  1522,  1533,  1534,
    1540,  1550,  1564,  1563,  1575,  1580,  1579,  1589,  1588,  1601,
    1600,  1612,  1611,  1623,  1622,  1635,  1634,  1646,  1645,  1657,
    1656,  1669,  1668,  1681,  1680,  1693,  1692,  1704,  1703,  1715,
    1714,  1727,  1726,  1743,  1743,  1760,  1761,  1762,  1763,  1764,
    1769,  1770,  1792,  1793,  1794,  1798,  1799,  1803,  1804,  1805,
    1806,  1807,  1811,  1812,  1813,  1814,  1815,  1817,  1818,  1820,
    1821
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'<'", "'>'", "'|'", "'^'", "'%'", "'/'", "'('", "')'", "'.'", "'?'",
  "';'", "'{'", "'}'", "','", "'['", "']'", "':'", "AUTO", "DOUBLE", "INT",
  "STRUCT", "BREAK", "ELSE", "LONG", "SWITCH", "CASE", "ENUM", "REGISTER",
  "TYPEDEF", "CHAR", "EXTERN", "RETURN", "UNION", "CONST", "FLOAT",
  "SHORT", "UNSIGNED", "CONTINUE", "FOR", "SIGNED", "VOID", "DEFAULT",
  "GOTO", "SIZEOF", "VOLATILE", "DO", "IF", "STATIC", "WHILE", "UPLUS",
  "UMINUS", "INDIR", "ADDRESS", "POSTINC", "POSTDEC", "PREINC", "PREDEC",
  "BOGUS", "IDENTIFIER", "STRINGliteral", "FLOATINGconstant",
  "INTEGERconstant", "OCTALconstant", "HEXconstant", "WIDECHARconstant",
  "CHARACTERconstant", "TYPEDEFname", "ARROW", "ICR", "DECR", "LS", "RS",
  "LE", "GE", "EQ", "NE", "ANDAND", "OROR", "ELLIPSIS", "'='",
  "MULTassign", "DIVassign", "MODassign", "PLUSassign", "MINUSassign",
  "LSassign", "RSassign", "ANDassign", "ERassign", "ORassign", "INLINE",
  "ATTRIBUTE", "$accept", "prog.start", "primary.expression",
  "postfix.expression", "argument.expression.list", "unary.expression",
  "unary.operator", "cast.expression", "multiplicative.expression",
  "additive.expression", "shift.expression", "relational.expression",
  "equality.expression", "AND.expression", "exclusive.OR.expression",
  "inclusive.OR.expression", "logical.AND.expression",
  "logical.OR.expression", "conditional.expression",
  "assignment.expression", "assignment.operator", "expression",
  "constant.expression", "expression.opt", "declaration", "declaring.list",
  "$@1", "$@2", "$@3", "$@4", "@5", "$@6", "$@7", "$@8",
  "default.declaring.list", "$@9", "$@10", "$@11", "$@12", "@13", "$@14",
  "$@15", "$@16", "declaration.specifier", "basic.declaration.specifier",
  "sue.declaration.specifier", "typedef.declaration.specifier",
  "declaration.qualifier.list", "declaration.qualifier", "type.specifier",
  "basic.type.specifier", "sue.type.specifier", "typedef.type.specifier",
  "type.qualifier.list", "pointer.type.qualifier.list",
  "elaborated.type.name", "declarator", "paren.typedef.declarator",
  "paren.postfix.typedef.declarator", "simple.paren.typedef.declarator",
  "parameter.typedef.declarator", "clean.typedef.declarator",
  "clean.postfix.typedef.declarator", "abstract.declarator",
  "unary.abstract.declarator", "postfix.abstract.declarator",
  "postfixing.abstract.declarator", "identifier.declarator",
  "unary.identifier.declarator", "postfix.identifier.declarator",
  "paren.identifier.declarator", "old.function.declarator",
  "postfix.old.function.declarator", "identifier.list",
  "identifier.or.typedef.name", "type.name", "attributes.opt",
  "attributes", "attribute", "attribute.list", "attrib", "any.word",
  "initializer.opt", "initializer", "initializer.list",
  "parameter.type.list", "parameter.list", "parameter.declaration",
  "array.abstract.declarator", "struct.or.union.specifier",
  "struct.or.union", "struct.declaration.list", "struct.declaration",
  "struct.default.declaring.list", "struct.declaring.list",
  "struct.declarator", "struct.identifier.declarator",
  "bit.field.size.opt", "bit.field.size", "enum.specifier",
  "enumerator.list", "enumerator.value.opt", "comma.opt", "statement",
  "labeled.statement", "@17", "compound.statement", "lblock", "rblock",
  "compound.statement.no.new.scope", "declaration.list", "statement.list",
  "expression.statement", "selection.statement", "$@18",
  "iteration.statement", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24",
  "$@25", "jump.statement", "translation.unit", "external.definition",
  "function.definition", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31",
  "$@32", "$@33", "$@34", "$@35", "$@36", "$@37", "$@38", "$@39", "$@40",
  "old.function.declaration.list", "$@41", "constant",
  "string.literal.list", "type.qualifier", "pointer.type.qualifier",
  "storage.class", "basic.type.name", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    38,    42,    43,    45,   126,    33,    60,
      62,   124,    94,    37,    47,    40,    41,    46,    63,    59,
     123,   125,    44,    91,    93,    58,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,    61,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331
};
# endif

#define YYPACT_NINF -396

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-396)))

#define YYTABLE_NINF -362

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1721,   661,   336,  -396,  -396,  -396,  -396,  -396,    42,  -396,
    -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,  -396,     9,  -396,    48,    84,   382,
    2775,   400,   551,  1113,   429,  2775,   601,   551,  1166,  -396,
     -26,  -396,  -396,    74,    37,  -396,  -396,    62,  -396,  1721,
    -396,  -396,  -396,  -396,  -396,  -396,  -396,   661,  -396,  -396,
    -396,    71,   128,   134,   113,  -396,  -396,   140,  -396,  -396,
     580,  -396,   505,  -396,  1164,   301,   138,  -396,  -396,  -396,
    -396,  -396,  -396,   151,    58,  -396,  -396,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,  -396,  -396,   153,   181,  -396,  -396,
    -396,   188,   190,  -396,  -396,  -396,  -396,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,   229,   260,  -396,  -396,  -396,  -396,
     267,  1834,  2486,  -396,     0,   267,  -396,  2707,  1923,   290,
    -396,  -396,  -396,  -396,   138,  -396,   138,   115,   302,   113,
    -396,  -396,  -396,  -396,  -396,  1118,   420,  -396,   138,   232,
     301,  1217,  -396,  -396,   301,  -396,   326,   138,   331,  1887,
    -396,   232,   267,   267,  -396,   232,   232,   267,   267,  -396,
     232,   232,   267,   267,  -396,   232,   232,   267,   267,  -396,
     798,  -396,  -396,  -396,  -396,   107,   551,  1615,   107,   551,
    1668,    28,   349,   347,   291,  -396,  -396,  -396,  -396,  -396,
    -396,  1387,  -396,  2633,  -396,  -396,  -396,  -396,  -396,  -396,
    -396,  2709,  2709,  -396,   568,  -396,  2722,  -396,    86,   435,
     405,    39,   378,   381,   376,   393,   315,    24,  -396,   392,
    -396,   360,  2509,  -396,   267,  -396,   382,  1219,   429,  1272,
    2707,  -396,   228,   717,   262,   262,  1757,  1952,  -396,   165,
     300,  1988,  -396,  -396,  2722,  -396,   113,   424,   302,   232,
    1118,   383,   232,   437,   362,   232,  -396,   456,   301,  -396,
    -396,   496,   138,   449,   138,  -396,  -396,  -396,   267,   362,
    -396,  -396,  -396,   267,   362,  -396,  -396,  -396,   267,   362,
    -396,  -396,  -396,   267,   448,  -396,  -396,   451,  -396,  2722,
    2722,   467,   486,   478,   170,  -396,   490,  -396,   483,   492,
    1353,  -396,  -396,   521,   530,  -396,  -396,  -396,   879,   960,
    2074,  -396,  -396,  -396,  -396,   618,  1456,  -396,  -396,  -396,
    -396,  -396,  -396,   231,  1509,  -396,  -396,  -396,  -396,  -396,
    -396,  -396,  -396,   499,  -396,  1325,  2522,   218,   174,  1799,
     529,  1038,  1387,  -396,  2598,  -396,  -396,  2619,   183,  2722,
     245,  -396,  -396,  -396,  2722,  2722,  2722,  2722,  2722,  2722,
    2722,  2722,  2722,  2722,  2722,  2722,  2722,  2722,  2722,  2722,
    2722,  2722,  2722,  -396,  -396,  -396,   535,  -396,  -396,  -396,
    -396,  2722,   536,  -396,   232,   536,  -396,   232,  -396,  -396,
    -396,   292,  -396,   228,  -396,  2017,  -396,   115,  -396,   554,
    -396,  -396,   564,  2522,  -396,  -396,  -396,   498,  -396,  -396,
    -396,  -396,   362,  -396,  -396,   362,  -396,  -396,   362,  -396,
    -396,   362,  -396,  -396,  -396,   574,   573,   582,  -396,  2386,
    2308,   586,   587,  2308,  2722,   584,  -396,  2308,  -396,  -396,
    -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,  2722,
    2722,  -396,  -396,  -396,   879,  2152,  -396,  2230,  -396,   492,
    -396,   618,  -396,   595,   596,   599,   231,  -396,  -396,  -396,
    -396,  2522,  -396,  -396,  -396,   652,  1562,  -396,  -396,  2722,
    1038,  2152,   600,  -396,   350,  -396,  -396,  -396,    91,  -396,
    -396,  -396,  -396,  -396,    86,    86,   435,   435,   405,   405,
     405,   405,    39,    39,   378,   381,   376,   393,   321,   315,
    -396,  -396,   232,  -396,  -396,   232,  -396,  -396,  -396,  -396,
    -396,  -396,   362,   362,    52,  -396,  -396,  -396,  -396,  -396,
    -396,  2722,  2308,  -396,   307,   598,  -396,  -396,  -396,   569,
     380,  2722,  2308,  -396,  -396,  -396,  -396,  2152,  -396,  -396,
    -396,   138,  -396,  -396,  -396,   494,   652,  -396,  2152,   605,
    -396,  -396,  2722,  -396,  2722,  -396,  -396,  -396,  -396,  -396,
    -396,  -396,   389,  -396,   610,   416,  -396,  -396,  2722,  2407,
     613,  2308,   472,  -396,  -396,  -396,  -396,   705,   614,  -396,
    -396,  -396,   620,    52,  2722,  2308,  2308,   623,   630,   632,
    2722,   608,  2308,  -396,  -396,  -396,  -396,  -396,   524,  -396,
    -396,  2722,  2722,  2428,   526,  2308,  -396,  -396,   636,   642,
     643,   645,   647,  -396,  -396,  -396,  -396,  -396,  -396,  2308,
    2308,  2308,  2308,  -396,  -396,  -396,  -396
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,   390,   396,   394,   262,   400,     0,   391,
     387,   393,   388,   263,   382,   395,   399,   398,   397,   392,
     383,   389,   196,   143,   384,     0,   340,     0,     0,     0,
     115,   116,   117,     0,     0,   133,   134,   135,     0,   140,
     342,   188,   190,   189,   373,   198,   150,     0,   151,     2,
     338,   341,   146,   128,   136,   385,   386,     0,   191,   199,
     148,     0,     0,     0,     0,   206,   207,   281,     1,    83,
       0,    84,     0,    96,     0,     0,   166,    87,   152,   156,
     153,   168,   169,   154,   373,   120,   131,   132,   121,    85,
     124,   127,   110,   126,   130,   123,   101,   373,   119,    98,
      90,   154,   373,   138,   118,   139,    86,   142,   122,   145,
     125,   112,   144,   141,   104,   373,   147,   129,   137,   344,
       0,     0,     0,   193,   185,     0,   363,     0,     0,   259,
     339,   192,   200,   149,   194,   197,   202,   284,   286,     0,
     100,    93,   154,   155,   114,     0,     0,   107,   189,   212,
       0,     0,   157,   170,     0,   164,     0,     0,     0,     0,
     167,   212,     0,     0,   365,   212,   212,     0,     0,   369,
     212,   212,     0,     0,   367,   212,   212,     0,     0,   371,
       0,   343,   186,   204,   234,   239,   116,   243,   246,   134,
     250,     0,     0,   232,   235,    27,    28,    29,    30,    31,
      32,     0,   253,     0,     3,   380,   375,   376,   377,   378,
     379,     0,     0,     9,    21,    33,     0,    35,    39,    42,
      45,    50,    53,    55,    57,    59,    61,    63,    80,     0,
       4,     5,     0,   354,     0,   310,     0,     0,     0,     0,
     374,   260,     0,   133,   134,   135,     0,     0,   264,     0,
       0,     0,   195,   203,     0,   282,   287,     0,   286,   212,
       0,     0,   212,     0,   225,   213,   214,     0,     0,   160,
     171,     0,   161,     0,   172,    88,   346,   356,     0,   225,
     102,   350,   360,     0,   225,    91,   348,   358,     0,   225,
     105,   352,   362,     0,     0,   304,   306,     0,   317,     0,
      81,     0,     0,     0,     0,   321,     0,   319,     3,   143,
      33,    65,    78,    82,     0,   312,   288,   289,     0,     0,
       0,   290,   291,   292,   293,   177,     0,   242,   240,   174,
     175,   176,   241,   177,     0,   244,   245,   249,   247,   248,
     251,   252,   201,     0,   187,     0,     0,     0,   208,   210,
       0,     0,     0,    25,     0,    22,    23,     0,     0,     0,
       0,    15,    16,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   381,   256,     0,   364,   101,   104,
     311,     0,   276,   270,   212,   276,   268,   212,   257,   265,
     267,     0,   266,     0,   261,     0,   285,   284,   279,     0,
      94,   108,     0,     0,    97,   215,   158,     0,   165,   163,
     162,   173,   225,   366,   111,   225,   370,    99,   225,   368,
     113,   225,   372,   294,   335,     0,     0,     0,   334,     0,
       0,     0,     0,     0,     0,     0,   295,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,   314,   305,   300,     0,     0,   307,     0,   308,     0,
     313,   178,   179,     0,     0,     0,   178,   205,   238,   233,
     236,     0,   229,   237,     6,   177,     0,   209,   211,     0,
       0,     0,     0,    11,     0,    19,    13,    17,     0,    14,
      18,    36,    38,    37,    40,    41,    43,    44,    46,    47,
      48,    49,    51,    52,    54,    56,    58,    60,     0,    62,
     255,   278,   212,   277,   273,   212,   275,   269,   271,   258,
     283,   280,   225,   225,   219,   226,   159,    89,   103,    92,
     106,     0,     0,   336,     0,     0,   298,   333,   337,     0,
       0,     0,     0,   299,    66,    79,   301,     0,   302,   309,
     180,   181,   182,   183,   230,     0,   178,    34,     0,     0,
      26,    12,     0,    10,     0,   272,   274,    95,   109,   224,
     222,   223,     0,   217,   220,     0,   297,   331,    81,     0,
       0,     0,     0,   296,   303,   184,   227,     0,     0,     7,
      20,    64,     0,   219,     0,     0,     0,     0,     0,     0,
       0,   315,     0,   228,   231,     8,   216,   218,     0,   318,
     332,    81,    81,     0,     0,     0,   320,   221,     0,     0,
       0,     0,     0,   316,   325,   329,   327,   323,   322,     0,
       0,     0,     0,   326,   330,   328,   324
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -396,  -396,  -396,  -396,  -396,   159,  -396,  -210,   185,   186,
     325,   198,   252,   284,   285,   289,   288,  -396,  -114,  -312,
    -396,  -187,  -191,  -287,     2,  -396,  -396,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,
    -396,  -396,  -396,     3,  -396,  -101,  -396,     7,    41,     4,
    -116,   -52,  -113,     5,   -64,   261,   -23,    -9,  -396,  -111,
     -49,   -38,  -396,  -158,  -310,  -288,   -43,    26,    29,  -396,
     121,   344,  -396,  -396,    14,   320,   298,  -396,   408,  -396,
      75,  -396,  -205,  -395,  -396,  -396,  -396,   329,  -396,  -396,
    -396,   426,  -219,  -396,  -396,   278,   282,   306,  -154,  -396,
     547,   280,   457,   111,  -396,  -396,  -396,  -184,  -243,   446,
    -159,  -283,  -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,  -396,   655,  -396,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,
    -396,  -396,   310,  -396,  -396,  -396,   445,   -56,   532,   357
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,   213,   214,   494,   310,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   311,   312,
     459,   313,   229,   314,   235,    27,   161,   422,   171,   428,
     259,   532,   149,   170,    28,   166,   425,   176,   431,   262,
     533,   165,   175,   236,    30,    31,    32,   237,    94,   238,
      35,    36,    37,   239,    57,    39,    77,    78,    79,   157,
      80,    81,    82,   472,   329,   330,   331,    58,    41,    42,
      43,    63,    45,   191,   137,   350,   264,   265,   266,   582,
     583,   584,   414,   483,   565,   192,   193,   194,   124,    46,
      47,   247,   248,   249,   250,   393,   396,   522,   394,    48,
     138,   255,   257,   315,   316,   552,   317,   318,   463,   181,
     240,   320,   321,   322,   435,   323,   445,   443,   642,   639,
     641,   640,   606,   324,    49,    50,    51,   120,   162,   172,
     167,   177,   125,   163,   173,   168,   178,   234,   278,   288,
     283,   293,   126,   127,   230,   231,    52,    60,    53,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     123,   133,    26,    29,    34,    38,   363,    33,   228,    68,
     151,   100,   243,   437,   347,   245,   473,   351,   535,   123,
     186,   319,    67,   232,   473,   153,    40,   328,   399,   335,
     338,    61,   340,   160,   482,   465,   467,   158,   474,   267,
     119,   386,   381,   271,   342,   495,   474,   141,   371,   372,
     343,    26,    29,    34,    38,    83,    33,  -353,   186,    96,
     101,   129,    64,   406,   114,   152,   156,    69,   491,   189,
      70,    85,    90,    91,   424,    40,   244,  -155,  -355,   427,
    -155,   260,   128,   131,   430,   243,   564,   134,   245,   121,
     364,   252,   397,   253,   579,   133,   142,   122,   147,   365,
     366,   482,   270,    71,    61,   123,    72,   189,   436,    65,
     382,   325,   158,   460,   273,   573,   158,    66,   228,   580,
     373,   374,   326,    62,   185,   188,   190,   581,   187,    65,
     122,   243,   242,   246,   245,   243,   327,    66,   245,   337,
     228,   156,   269,   121,   135,   156,  -155,   554,   555,   244,
     136,   122,   545,   159,   501,   502,   503,   417,  -155,   464,
     139,   122,   185,   188,   190,   347,   187,   347,   351,   482,
     351,  -345,   498,  -349,    22,    61,   473,   131,   485,    61,
      65,   557,    76,    61,   400,   228,   399,   401,    66,   486,
     487,   488,   490,   148,   518,   244,    62,   122,   474,   244,
     521,  -359,   614,   254,   133,   348,   349,   568,  -347,  -155,
    -357,   332,  -155,   336,   339,   100,   341,   537,   123,   392,
     538,   556,   558,   539,   273,   186,   540,    90,   273,   419,
     158,   421,    74,   186,   484,   333,   243,   441,   523,   245,
     460,   523,   390,    75,   186,   442,   334,   397,   569,  -351,
     496,   242,   246,   391,   122,   242,   246,   550,   497,   156,
     600,   471,   142,   388,   142,   389,   148,   261,   142,   476,
     407,    62,   395,    55,   189,    62,   153,   228,  -155,   567,
    -361,   215,   189,   475,    56,   482,   131,   180,   158,   243,
    -155,   475,   245,   189,    95,    22,   145,    61,    22,   113,
     244,   607,   609,    76,    14,    74,   148,   146,   148,   148,
     251,   148,   499,   560,   594,    20,   154,   391,   560,   402,
     500,   390,   403,   587,   256,   598,   588,   577,   578,   185,
     188,   190,   263,   187,   628,   629,   631,   185,   188,   190,
       1,   187,   272,   460,    44,    59,   574,   274,   185,   188,
     190,     2,   187,   244,   585,    61,   348,   349,   148,    22,
     148,    24,   353,    61,   592,   344,   571,   148,    22,   345,
     355,   356,   572,    84,   273,   215,   155,    97,   102,   346,
     392,   148,   115,    73,   377,   186,    74,    88,   378,    62,
      98,   215,   105,    44,   164,   118,   591,    75,   159,   135,
     380,   132,   460,    22,   379,   602,   122,   169,   560,   242,
     246,   603,   174,   215,   143,   133,   383,   618,    59,    89,
     133,   566,   270,   624,   145,   179,     3,   395,   384,   142,
      99,   470,   605,    74,   189,   146,     9,    10,   460,    12,
     367,   368,    14,   475,    75,   408,   148,   261,    95,    22,
     413,   113,   412,    20,   148,   261,    21,    76,   215,   275,
     601,   375,   376,   279,   280,   420,   390,   433,   284,   285,
     434,   159,   416,   289,   290,    86,    86,    86,    86,   122,
     103,   107,   109,   116,   369,   370,   438,    22,   612,   185,
     188,   190,   390,   187,   460,   132,    22,   131,    95,    24,
     113,   439,   131,   440,    76,   444,   144,   113,   446,   145,
     133,   159,   418,   159,   536,   596,   597,   447,   595,   122,
     146,   122,   148,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     627,   215,   632,   460,    98,   489,   460,   118,   460,   461,
     215,   546,   504,   505,   549,   506,   507,   410,   553,   520,
     411,   391,    87,    87,    87,    87,   477,   104,   108,   110,
     117,   233,    22,   512,   513,   531,   470,     3,   470,   534,
     143,   140,   143,   357,    74,   358,   143,     9,    10,   541,
      12,   359,   148,    14,    98,    75,   118,   148,   542,   551,
     105,   543,   470,   118,    20,   547,   548,    21,   276,   277,
     113,   561,   562,   281,   282,   563,   570,   589,   286,   287,
     106,   599,   325,   291,   292,   604,   590,     3,   610,   514,
     615,    86,    86,   326,   107,   116,   616,     9,    10,   625,
      12,   122,   621,    14,   360,   361,   362,    22,   215,   622,
      24,   623,   634,   586,    20,    76,   485,    21,   635,   636,
      55,   637,   515,   593,   516,     1,   638,   486,   470,   517,
     519,    56,   492,   415,   480,   122,     2,   405,   617,   470,
     387,   528,    86,   527,   116,    22,   258,   530,   103,   107,
     109,   116,   524,    76,    55,   526,   508,   509,   510,   511,
      24,   525,   611,    55,   130,    56,   118,     0,   195,   196,
     197,   198,   199,   200,    56,   409,   619,   620,    87,    87,
     201,   108,   117,   626,   423,   481,   613,     0,    22,   426,
       0,     0,     0,   215,   429,     0,   633,     0,     0,   432,
       0,     0,     0,     0,     4,     5,     0,   143,     0,     7,
     643,   644,   645,   646,     0,    11,     0,   203,     0,    14,
      15,    16,    17,     0,     0,    18,    19,     0,     0,    87,
      20,   117,   204,   205,   206,   207,   208,   209,     0,   210,
       0,     0,   211,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,     0,   294,
       0,   195,   196,   197,   198,   199,   200,     0,     0,     0,
       0,     0,     0,   201,     0,     0,    24,   -81,   295,   296,
     575,     0,     0,   576,     3,     4,     5,     6,   297,     0,
       7,   298,   299,     8,     9,    10,    11,    12,   300,    13,
      14,    15,    16,    17,   301,   302,    18,    19,   303,   304,
     203,    20,   305,   306,    21,   307,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   308,   205,   206,   207,   208,
     209,     0,   210,   309,     0,   211,   212,     0,     0,     0,
     294,     0,   195,   196,   197,   198,   199,   200,     0,     0,
       0,     0,     0,     0,   201,     0,     0,    24,   -81,   295,
     462,     0,     0,     0,     0,     3,     4,     5,     6,   297,
       0,     7,   298,   299,     8,     9,    10,    11,    12,   300,
      13,    14,    15,    16,    17,   301,   302,    18,    19,   303,
     304,   203,    20,   305,   306,    21,   307,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   308,   205,   206,   207,
     208,   209,     0,   210,   309,     0,   211,   212,     0,     0,
       0,   294,     0,   195,   196,   197,   198,   199,   200,     0,
       0,     0,     0,     0,     0,   201,     0,     0,    24,   -81,
     295,   466,     0,     0,     0,     0,     3,     4,     5,     6,
     297,     0,     7,   298,   299,     8,     9,    10,    11,    12,
     300,    13,    14,    15,    16,    17,   301,   302,    18,    19,
     303,   304,   203,    20,   305,   306,    21,   307,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   308,   205,   206,
     207,   208,   209,     0,   210,   309,     0,   211,   212,   294,
       0,   195,   196,   197,   198,   199,   200,     0,     0,     0,
       0,     0,     0,   201,     0,     0,     0,   -81,   295,    24,
       0,     0,     0,     0,     3,     4,     5,     6,   297,     0,
       7,   298,   299,     8,     9,    10,    11,    12,   300,    13,
      14,    15,    16,    17,   301,   302,    18,    19,   303,   304,
     203,    20,   305,   306,    21,   307,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   308,   205,   206,   207,   208,
     209,     0,   210,   309,    92,   211,   212,     1,     0,     0,
       0,     0,   145,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,   146,     0,     0,     0,    24,     0,     3,
       4,     5,     6,     0,     0,     7,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,    15,    16,    17,     0,
      55,    18,    19,     0,     0,     0,    20,   111,    74,    21,
       1,    56,     0,     0,     0,     0,     0,     0,     0,   150,
      22,     2,     0,     0,     0,    22,     0,     0,    93,     0,
       0,     0,     3,     4,     5,     6,     0,     0,     7,     0,
       0,     8,     9,    10,    11,    12,    55,    13,    14,    15,
      16,    17,    24,     0,    18,    19,     0,    56,     0,    20,
      92,    74,    21,   145,     0,     0,     0,     0,     0,     0,
       0,    22,   268,    22,   146,     0,     0,     0,     0,    76,
       0,   112,     0,     0,     0,     3,     4,     5,     6,     0,
       0,     7,     0,     0,     8,     9,    10,    11,    12,    55,
      13,    14,    15,    16,    17,    24,     0,    18,    19,     0,
      56,     0,    20,   111,     0,    21,   145,     0,     0,     0,
       0,     0,     0,     0,    22,     0,    22,   146,     0,     0,
       0,     0,    76,     0,    93,     0,     0,     0,     3,     4,
       5,     6,     0,     0,     7,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,    15,    16,    17,    24,     0,
      18,    19,     0,     0,     0,    20,   478,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,     0,   112,     0,     0,
       0,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       8,     9,    10,    11,    12,     0,    13,    14,    15,    16,
      17,    24,     0,    18,    19,     0,     0,     0,    20,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
     195,   196,   197,   198,   199,   200,     0,     0,     0,     0,
      23,     0,   201,     0,     0,     0,     0,   295,     0,     0,
       0,     0,   479,     0,     4,     5,     6,     0,     0,     7,
       0,     0,     8,     0,    24,    11,     0,     0,    13,    14,
      15,    16,    17,     0,     0,    18,    19,     0,     0,   203,
      20,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,     0,     0,   204,   205,   206,   207,   208,   209,
     325,   210,    23,     0,   211,   212,     0,     0,     0,     0,
       0,   326,   182,     0,     0,     0,     0,     0,     0,   122,
       0,     0,     3,     4,     5,     6,    24,     0,     7,     0,
       0,     8,     9,    10,    11,    12,     0,    13,    14,    15,
      16,    17,     0,     0,    18,    19,     0,     0,     0,    20,
       0,     0,    21,   333,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,   334,   182,     0,     0,     0,     0,
       0,    23,   122,     0,     0,     3,     4,     5,     6,     0,
       0,     7,     0,   184,     8,     9,    10,    11,    12,     0,
      13,    14,    15,    16,    17,    24,     0,    18,    19,     0,
       0,     0,    20,     0,     0,    21,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,   486,   182,     0,
       0,     0,     0,     0,    23,   122,     0,     0,     3,     4,
       5,     6,     0,     0,     7,     0,   184,     8,     9,    10,
      11,    12,     0,    13,    14,    15,    16,    17,    24,     0,
      18,    19,     0,     0,     0,    20,     0,     0,    21,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     334,     0,     0,     0,     0,     0,     0,    23,   122,     0,
       0,     3,     4,     5,     6,     0,     0,     7,     0,   184,
       8,     9,    10,    11,    12,     0,    13,    14,    15,    16,
      17,    24,     0,    18,    19,     0,     0,     0,    20,     0,
       0,    21,   333,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,   334,     0,     0,     0,     0,     0,     0,
      93,   122,     0,     0,     3,     4,     5,     6,     0,     0,
       7,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,    15,    16,    17,    24,     0,    18,    19,     0,     0,
       0,    20,     0,     0,    21,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     2,     0,     0,     0,
       0,     0,     0,   112,     0,     0,     0,     3,     4,     5,
       6,     0,     0,     7,     0,     0,     8,     9,    10,    11,
      12,   145,    13,    14,    15,    16,    17,    24,     0,    18,
      19,     0,   146,     0,    20,     0,     0,    21,     0,     0,
       0,     0,   391,     0,     4,     5,     6,     0,    22,     7,
       0,     0,     8,     0,     0,    11,    23,     0,    13,    14,
      15,    16,    17,   485,     0,    18,    19,     0,     0,     0,
      20,     0,     0,     0,   486,     0,     0,     0,     0,     0,
      24,     0,   122,     0,    22,     0,     4,     5,     6,     0,
       0,     7,   112,     0,     8,     0,     0,    11,     0,     0,
      13,    14,    15,    16,    17,     0,     0,    18,    19,     0,
     182,     0,    20,     0,     0,     0,    24,     0,     0,     0,
       3,     4,     5,     6,     0,     0,     7,     0,     0,     8,
       9,    10,    11,    12,   112,    13,    14,    15,    16,    17,
       0,     0,    18,    19,     0,     0,     0,    20,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,   183,     0,   182,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     3,     4,     5,     6,     0,     0,     7,
       0,   184,     8,     9,    10,    11,    12,     0,    13,    14,
      15,    16,    17,    24,     0,    18,    19,     0,     0,     0,
      20,     0,     0,    21,   241,     0,     0,     0,     0,     0,
       4,     5,     6,     0,     0,     7,     0,     0,     8,     0,
       0,    11,    23,     0,    13,    14,    15,    16,    17,     0,
       0,    18,    19,   398,   184,     0,    20,     0,     0,     4,
       5,     6,     0,     0,     7,     0,    24,     8,     0,     0,
      11,     0,     0,    13,    14,    15,    16,    17,    23,     0,
      18,    19,     0,     0,     0,    20,     0,     0,     0,   404,
       0,     0,     0,     0,     0,     4,     5,     6,     0,     0,
       7,     0,    24,     8,     0,     0,    11,    23,     0,    13,
      14,    15,    16,    17,     0,     0,    18,    19,   529,     0,
       0,    20,     0,     0,     4,     5,     6,     0,     0,     7,
       0,    24,     8,     0,     0,    11,     0,     0,    13,    14,
      15,    16,    17,    23,     0,    18,    19,     0,     0,     0,
      20,     0,     0,     0,     0,   294,     0,   195,   196,   197,
     198,   199,   200,     0,     0,     0,     0,    24,     0,   201,
       0,     0,    23,   -81,   295,   468,     0,     0,     0,     0,
       0,     0,     0,     0,   297,     0,     0,   298,   299,     0,
       0,     0,     0,     0,   300,     0,    24,     0,     0,     0,
     301,   302,     0,     0,   303,   304,   203,     0,   305,   306,
       0,   307,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   308,   205,   206,   207,   208,   209,     0,   210,   469,
       0,   211,   212,   294,     0,   195,   196,   197,   198,   199,
     200,     0,     0,     0,     0,     0,     0,   201,     0,     0,
       0,   -81,   295,   462,     0,     0,     0,     0,     0,     0,
       0,     0,   297,     0,     0,   298,   299,     0,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,   301,   302,
       0,     0,   303,   304,   203,     0,   305,   306,     0,   307,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   308,
     205,   206,   207,   208,   209,     0,   210,   469,     0,   211,
     212,   294,     0,   195,   196,   197,   198,   199,   200,     0,
       0,     0,     0,     0,     0,   201,     0,     0,     0,   -81,
     295,   559,     0,     0,     0,     0,     0,     0,     0,     0,
     297,     0,     0,   298,   299,     0,     0,     0,     0,     0,
     300,     0,     0,     0,     0,     0,   301,   302,     0,     0,
     303,   304,   203,     0,   305,   306,     0,   307,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   308,   205,   206,
     207,   208,   209,     0,   210,   469,     0,   211,   212,   294,
       0,   195,   196,   197,   198,   199,   200,     0,     0,     0,
       0,     0,     0,   201,     0,     0,     0,   -81,   295,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   297,     0,
       0,   298,   299,     0,     0,     0,     0,     0,   300,     0,
       0,     0,     0,     0,   301,   302,     0,     0,   303,   304,
     203,     0,   305,   306,     0,   307,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   308,   205,   206,   207,   208,
     209,     0,   210,   469,     0,   211,   212,   544,     0,   195,
     196,   197,   198,   199,   200,     0,     0,     0,     0,     0,
       0,   201,     0,     0,     0,   -81,     0,     0,   608,     0,
     195,   196,   197,   198,   199,   200,     0,     0,     0,     0,
       0,     0,   201,     0,     0,     0,   -81,     0,     0,   630,
       0,   195,   196,   197,   198,   199,   200,     0,   203,     0,
       0,     0,     0,   201,   -81,     0,     0,     0,     0,     0,
       0,     0,     0,   204,   205,   206,   207,   208,   209,   203,
     210,     0,     0,   211,   212,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   204,   205,   206,   207,   208,   209,
     203,   210,     0,     0,   211,   212,     0,     0,     0,   195,
     196,   197,   198,   199,   200,   204,   205,   206,   207,   208,
     209,   201,   210,     0,     0,   211,   212,     0,     0,     0,
     202,     0,   195,   196,   197,   198,   199,   200,     0,     0,
       0,     0,     0,     0,   201,   195,   196,   197,   198,   199,
     200,     0,     0,   385,     0,     0,     0,   201,   203,     0,
       0,     0,   481,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   204,   205,   206,   207,   208,   209,     0,
     210,   203,     0,   211,   212,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,     0,   204,   205,   206,   207,
     208,   209,     0,   210,     0,     0,   211,   212,     0,   204,
     205,   206,   207,   208,   209,     0,   210,     0,     0,   211,
     212,   195,   196,   197,   198,   199,   200,     0,     0,     0,
       0,     0,     0,   201,     0,     0,     0,     0,   295,     0,
       0,     0,   195,   196,   197,   198,   199,   200,     0,     0,
       0,     0,     0,     0,   201,   493,   195,   196,   197,   198,
     199,   200,     0,     0,     0,     0,     0,     0,   352,     0,
     203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   204,   205,   206,   207,   208,
     209,   203,   210,     0,     0,   211,   212,     0,     0,     0,
       0,     0,     0,     0,     0,   203,   204,   205,   206,   207,
     208,   209,     0,   210,     0,     0,   211,   212,     0,     0,
     204,   205,   206,   207,   208,   209,     0,   210,     0,     0,
     211,   212,   195,   196,   197,   198,   199,   200,     0,     0,
       0,     0,     0,     0,   354,   195,   196,   197,   198,   199,
     200,     0,     0,     3,     4,     5,     6,   201,     0,     7,
       0,     0,     8,     9,    10,    11,    12,     0,    13,    14,
      15,    16,    17,     0,     0,    18,    19,     0,     0,     0,
      20,   203,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,     0,   204,   205,   206,   207,
     208,   209,    23,   210,     0,     0,   211,   212,     0,   204,
     205,   206,   207,   208,   209,     0,   210,     0,     0,   211,
     212,     3,     4,     5,     0,     0,    24,     7,     0,     0,
       0,     9,    10,    11,    12,     0,     0,    14,    15,    16,
      17,     0,     0,    18,    19,     0,     0,     0,    20,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24
};

static const yytype_int16 yycheck[] =
{
      43,    57,     0,     0,     0,     0,   216,     0,   122,     0,
      74,    34,   128,   300,   201,   128,   326,   201,   413,    62,
     121,   180,     8,    23,   334,    74,     0,   185,   247,   187,
     188,     2,   190,    76,   346,   318,   319,    75,   326,   150,
      66,   232,    18,   154,    16,   357,   334,    70,     9,    10,
      22,    49,    49,    49,    49,    29,    49,    20,   159,    33,
      34,    47,    20,   254,    38,    74,    75,    19,   351,   121,
      22,    30,    31,    32,   279,    49,   128,    19,    20,   284,
      22,   145,    20,    57,   289,   201,   481,    16,   201,    15,
       4,   134,   246,   136,    42,   151,    70,    23,    72,    13,
      14,   413,   151,    19,    75,   148,    22,   159,   299,    67,
      86,     4,   150,    22,   157,    24,   154,    75,   232,    67,
      81,    82,    15,     2,   121,   121,   121,    75,   121,    67,
      23,   247,   128,   128,   247,   251,   185,    75,   251,   188,
     254,   150,   151,    15,    16,   154,    88,   459,   460,   201,
      16,    23,   439,    15,   364,   365,   366,   268,   100,   318,
      20,    23,   159,   159,   159,   352,   159,   354,   352,   481,
     354,    20,   359,    20,    67,   146,   486,   151,     4,   150,
      67,   464,    75,   154,    19,   299,   405,    22,    75,    15,
     348,   349,   351,    72,   381,   247,    75,    23,   486,   251,
     391,    20,   597,    88,   260,   201,   201,   490,    20,    19,
      20,   185,    22,   187,   188,   238,   190,   422,   261,   242,
     425,   464,   465,   428,   267,   326,   431,   186,   271,   272,
     268,   274,     4,   334,    16,     4,   352,    67,   392,   352,
      22,   395,   240,    15,   345,    75,    15,   401,   491,    20,
      67,   247,   247,    25,    23,   251,   251,   444,    75,   268,
     572,   325,   236,   237,   238,   239,   145,   146,   242,   333,
     256,   150,   246,    42,   326,   154,   325,   391,    88,   489,
      20,   122,   334,   326,    53,   597,   260,    20,   326,   405,
     100,   334,   405,   345,    33,    67,     4,   268,    67,    38,
     352,   588,   589,    75,    42,     4,   185,    15,   187,   188,
      20,   190,    67,   471,   557,    53,    15,    25,   476,    19,
      75,   319,    22,    16,    22,   568,    19,   532,   533,   326,
     326,   326,   100,   326,   621,   622,   623,   334,   334,   334,
       4,   334,    16,    22,     0,     1,    25,    16,   345,   345,
     345,    15,   345,   405,   541,   326,   352,   352,   237,    67,
     239,    99,   203,   334,   551,    16,    16,   246,    67,    22,
     211,   212,    22,    29,   417,   216,    75,    33,    34,    88,
     403,   260,    38,     1,     3,   486,     4,    30,    12,   268,
      33,   232,    35,    49,    84,    38,    16,    15,    15,    16,
      85,    57,    22,    67,    11,    16,    23,    97,   566,   405,
     405,    22,   102,   254,    70,   471,    24,   604,    74,    19,
     476,   485,   471,   610,     4,   115,    26,   401,    68,   403,
       1,   320,    16,     4,   486,    15,    36,    37,    22,    39,
       5,     6,    42,   486,    15,    21,   325,   326,   187,    67,
      88,   190,    15,    53,   333,   334,    56,    75,   299,   161,
     574,    83,    84,   165,   166,    16,   464,    19,   170,   171,
      19,    15,    16,   175,   176,    30,    31,    32,    33,    23,
      35,    36,    37,    38,    79,    80,    19,    67,    16,   486,
     486,   486,   490,   486,    22,   151,    67,   471,   237,    99,
     239,    15,   476,    25,    75,    15,     1,   246,    25,     4,
     566,    15,    16,    15,    16,    21,    22,    25,   561,    23,
      15,    23,   401,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
      16,   382,    16,    22,   187,    16,    22,   190,    22,    19,
     391,   440,   367,   368,   443,   369,   370,   259,   447,    24,
     262,    25,    30,    31,    32,    33,    67,    35,    36,    37,
      38,   125,    67,   375,   376,    21,   465,    26,   467,    15,
     236,     1,   238,    15,     4,    17,   242,    36,    37,    15,
      39,    23,   471,    42,   237,    15,   239,   476,    25,    15,
     243,    19,   491,   246,    53,    19,    19,    56,   162,   163,
     349,    16,    16,   167,   168,    16,    16,    19,   172,   173,
      19,    16,     4,   177,   178,    15,    57,    26,    15,   377,
      16,   186,   187,    15,   189,   190,    16,    36,    37,    31,
      39,    23,    19,    42,    76,    77,    78,    67,   489,    19,
      99,    19,    16,   542,    53,    75,     4,    56,    16,    16,
      42,    16,   378,   552,   379,     4,    19,    15,   557,   380,
     382,    53,   352,   265,   345,    23,    15,   251,   603,   568,
     234,   403,   237,   401,   239,    67,   139,   407,   243,   244,
     245,   246,   394,    75,    42,   397,   371,   372,   373,   374,
      99,   395,   591,    42,    49,    53,   349,    -1,     3,     4,
       5,     6,     7,     8,    53,   258,   605,   606,   186,   187,
      15,   189,   190,   612,   278,    20,    21,    -1,    67,   283,
      -1,    -1,    -1,   574,   288,    -1,   625,    -1,    -1,   293,
      -1,    -1,    -1,    -1,    27,    28,    -1,   403,    -1,    32,
     639,   640,   641,   642,    -1,    38,    -1,    52,    -1,    42,
      43,    44,    45,    -1,    -1,    48,    49,    -1,    -1,   237,
      53,   239,    67,    68,    69,    70,    71,    72,    -1,    74,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    99,    19,    20,    21,
     522,    -1,    -1,   525,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    -1,    74,    75,    -1,    77,    78,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    99,    19,    20,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    -1,    74,    75,    -1,    77,    78,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    99,    19,
      20,    21,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    -1,    74,    75,    -1,    77,    78,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    20,    99,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    -1,    74,    75,     1,    77,    78,     4,    -1,    -1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    99,    -1,    26,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,    35,    36,
      37,    38,    39,    -1,    41,    42,    43,    44,    45,    -1,
      42,    48,    49,    -1,    -1,    -1,    53,     1,     4,    56,
       4,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      67,    15,    -1,    -1,    -1,    67,    -1,    -1,    75,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,    -1,
      -1,    35,    36,    37,    38,    39,    42,    41,    42,    43,
      44,    45,    99,    -1,    48,    49,    -1,    53,    -1,    53,
       1,     4,    56,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    15,    67,    15,    -1,    -1,    -1,    -1,    75,
      -1,    75,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,    37,    38,    39,    42,
      41,    42,    43,    44,    45,    99,    -1,    48,    49,    -1,
      53,    -1,    53,     1,    -1,    56,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    67,    15,    -1,    -1,
      -1,    -1,    75,    -1,    75,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    45,    99,    -1,
      48,    49,    -1,    -1,    -1,    53,     1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      45,    99,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      75,    -1,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    87,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    35,    -1,    99,    38,    -1,    -1,    41,    42,
      43,    44,    45,    -1,    -1,    48,    49,    -1,    -1,    52,
      53,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    67,    68,    69,    70,    71,    72,
       4,    74,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    26,    27,    28,    29,    99,    -1,    32,    -1,
      -1,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    45,    -1,    -1,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    56,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    15,    16,    -1,    -1,    -1,    -1,
      -1,    75,    23,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    32,    -1,    87,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    44,    45,    99,    -1,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    56,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    15,    16,    -1,
      -1,    -1,    -1,    -1,    75,    23,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    -1,    87,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    45,    99,    -1,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    75,    23,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    32,    -1,    87,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      45,    99,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    56,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    23,    -1,    -1,    26,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    45,    99,    -1,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    56,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    26,    27,    28,
      29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,
      39,     4,    41,    42,    43,    44,    45,    99,    -1,    48,
      49,    -1,    15,    -1,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    -1,    67,    32,
      -1,    -1,    35,    -1,    -1,    38,    75,    -1,    41,    42,
      43,    44,    45,     4,    -1,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    23,    -1,    67,    -1,    27,    28,    29,    -1,
      -1,    32,    75,    -1,    35,    -1,    -1,    38,    -1,    -1,
      41,    42,    43,    44,    45,    -1,    -1,    48,    49,    -1,
      16,    -1,    53,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      26,    27,    28,    29,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    38,    39,    75,    41,    42,    43,    44,    45,
      -1,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    67,    -1,    16,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,
      -1,    87,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,    44,    45,    99,    -1,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    56,    21,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,    35,    -1,
      -1,    38,    75,    -1,    41,    42,    43,    44,    45,    -1,
      -1,    48,    49,    21,    87,    -1,    53,    -1,    -1,    27,
      28,    29,    -1,    -1,    32,    -1,    99,    35,    -1,    -1,
      38,    -1,    -1,    41,    42,    43,    44,    45,    75,    -1,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    99,    35,    -1,    -1,    38,    75,    -1,    41,
      42,    43,    44,    45,    -1,    -1,    48,    49,    21,    -1,
      -1,    53,    -1,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    99,    35,    -1,    -1,    38,    -1,    -1,    41,    42,
      43,    44,    45,    75,    -1,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    99,    -1,    15,
      -1,    -1,    75,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    99,    -1,    -1,    -1,
      46,    47,    -1,    -1,    50,    51,    52,    -1,    54,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    -1,    74,    75,
      -1,    77,    78,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    -1,    50,    51,    52,    -1,    54,    55,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    -1,    74,    75,    -1,    77,
      78,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,
      50,    51,    52,    -1,    54,    55,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    -1,    74,    75,    -1,    77,    78,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    50,    51,
      52,    -1,    54,    55,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    -1,    74,    75,    -1,    77,    78,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    19,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    19,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    52,    -1,
      -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    52,
      74,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      52,    74,    -1,    -1,    77,    78,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    67,    68,    69,    70,    71,
      72,    15,    74,    -1,    -1,    77,    78,    -1,    -1,    -1,
      24,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,     3,     4,     5,     6,     7,
       8,    -1,    -1,    24,    -1,    -1,    -1,    15,    52,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    -1,
      74,    52,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    67,    68,    69,    70,
      71,    72,    -1,    74,    -1,    -1,    77,    78,    -1,    67,
      68,    69,    70,    71,    72,    -1,    74,    -1,    -1,    77,
      78,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    52,    74,    -1,    -1,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    67,    68,    69,    70,
      71,    72,    -1,    74,    -1,    -1,    77,    78,    -1,    -1,
      67,    68,    69,    70,    71,    72,    -1,    74,    -1,    -1,
      77,    78,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,     3,     4,     5,     6,     7,
       8,    -1,    -1,    26,    27,    28,    29,    15,    -1,    32,
      -1,    -1,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,    44,    45,    -1,    -1,    48,    49,    -1,    -1,    -1,
      53,    52,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    67,    68,    69,    70,
      71,    72,    75,    74,    -1,    -1,    77,    78,    -1,    67,
      68,    69,    70,    71,    72,    -1,    74,    -1,    -1,    77,
      78,    26,    27,    28,    -1,    -1,    99,    32,    -1,    -1,
      -1,    36,    37,    38,    39,    -1,    -1,    42,    43,    44,
      45,    -1,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    15,    26,    27,    28,    29,    32,    35,    36,
      37,    38,    39,    41,    42,    43,    44,    45,    48,    49,
      53,    56,    67,    75,    99,   102,   125,   126,   135,   144,
     145,   146,   147,   148,   150,   151,   152,   153,   154,   156,
     168,   169,   170,   171,   172,   173,   190,   191,   200,   225,
     226,   227,   247,   249,   250,    42,    53,   155,   168,   172,
     248,   169,   171,   172,    20,    67,    75,   175,     0,    19,
      22,    19,    22,     1,     4,    15,    75,   157,   158,   159,
     161,   162,   163,   168,   172,   149,   247,   249,   250,    19,
     149,   149,     1,    75,   149,   156,   168,   172,   250,     1,
     157,   168,   172,   247,   249,   250,    19,   247,   249,   247,
     249,     1,    75,   156,   168,   172,   247,   249,   250,    66,
     228,    15,    23,   167,   189,   233,   243,   244,    20,   175,
     226,   168,   172,   248,    16,    16,    16,   175,   201,    20,
       1,   157,   168,   172,     1,     4,    15,   168,   171,   133,
      15,   155,   158,   161,    15,    75,   158,   160,   162,    15,
     167,   127,   229,   234,   243,   142,   136,   231,   236,   243,
     134,   129,   230,   235,   243,   143,   138,   232,   237,   243,
      20,   210,    16,    67,    87,   144,   146,   148,   150,   152,
     154,   174,   186,   187,   188,     3,     4,     5,     6,     7,
       8,    15,    24,    52,    67,    68,    69,    70,    71,    72,
      74,    77,    78,   103,   104,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   123,
     245,   246,    23,   210,   238,   125,   144,   148,   150,   154,
     211,    21,   150,   151,   152,   153,   154,   192,   193,   194,
     195,    20,   167,   167,    88,   202,    22,   203,   201,   131,
     155,   171,   140,   100,   177,   178,   179,   160,    15,   158,
     161,   160,    16,   167,    16,   177,   210,   210,   239,   177,
     177,   210,   210,   241,   177,   177,   210,   210,   240,   177,
     177,   210,   210,   242,     1,    20,    21,    30,    33,    34,
      40,    46,    47,    50,    51,    54,    55,    57,    67,    75,
     106,   119,   120,   122,   124,   204,   205,   207,   208,   211,
     212,   213,   214,   216,   224,     4,    15,   161,   164,   165,
     166,   167,   168,     4,    15,   164,   168,   161,   164,   168,
     164,   168,    16,    22,    16,    22,    88,   122,   150,   154,
     176,   208,    15,   106,    15,   106,   106,    15,    17,    23,
      76,    77,    78,   108,     4,    13,    14,     5,     6,    79,
      80,     9,    10,    81,    82,    83,    84,     3,    12,    11,
      85,    18,    86,    24,    68,    24,   123,   210,   168,   168,
     125,    25,   157,   196,   199,   168,   197,   199,    21,   193,
      19,    22,    19,    22,    21,   192,   123,   175,    21,   203,
     177,   177,    15,    88,   183,   179,    16,   160,    16,   167,
      16,   167,   128,   210,   183,   137,   210,   183,   130,   210,
     183,   139,   210,    19,    19,   215,   123,   124,    19,    15,
      25,    67,    75,   218,    15,   217,    25,    25,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,   121,
      22,    19,    21,   209,   211,   212,    21,   212,    21,    75,
     204,   155,   164,   165,   166,   167,   155,    67,     1,    87,
     188,    20,   120,   184,    16,     4,    15,   164,   164,    16,
     211,   212,   176,    16,   105,   120,    67,    75,   122,    67,
      75,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     111,   111,   112,   112,   113,   114,   115,   116,   122,   117,
      24,   123,   198,   199,   177,   198,   177,   197,   196,    21,
     202,    21,   132,   141,    15,   184,    16,   183,   183,   183,
     183,    15,    25,    19,     1,   124,   204,    19,    19,   204,
     122,    15,   206,   204,   120,   120,   209,   212,   209,    21,
     164,    16,    16,    16,   184,   185,   155,   108,   212,   209,
      16,    16,    22,    24,    25,   177,   177,   183,   183,    42,
      67,    75,   180,   181,   182,   122,   204,    16,    19,    19,
      57,    16,   122,   204,   209,   167,    21,    22,   209,    16,
     120,   119,    16,    22,    15,    16,   223,   124,     1,   124,
      15,   204,    16,    21,   184,    16,    16,   181,   122,   204,
     204,    19,    19,    19,   122,    31,   204,    16,   124,   124,
       1,   124,    16,   204,    16,    16,    16,    16,    19,   220,
     222,   221,   219,   204,   204,   204,   204
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   103,   103,   103,   103,   103,   103,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   105,
     105,   106,   106,   106,   106,   106,   106,   107,   107,   107,
     107,   107,   107,   108,   108,   109,   109,   109,   109,   110,
     110,   110,   111,   111,   111,   112,   112,   112,   112,   112,
     113,   113,   113,   114,   114,   115,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   120,   120,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   122,   122,
     123,   124,   124,   125,   125,   125,   125,   127,   128,   126,
     129,   130,   126,   131,   132,   126,   133,   126,   134,   126,
     126,   136,   137,   135,   138,   139,   135,   140,   141,   135,
     142,   135,   143,   135,   135,   144,   144,   144,   145,   145,
     145,   145,   146,   146,   146,   147,   147,   147,   148,   148,
     148,   149,   149,   150,   150,   150,   151,   151,   151,   151,
     152,   152,   152,   153,   153,   153,   154,   154,   155,   155,
     156,   156,   157,   157,   157,   157,   158,   158,   158,   158,
     158,   159,   159,   159,   160,   160,   161,   161,   161,   162,
     162,   162,   163,   163,   164,   164,   164,   165,   165,   165,
     165,   166,   166,   166,   166,   167,   167,   167,   168,   168,
     169,   169,   169,   170,   170,   170,   171,   171,   172,   172,
     172,   173,   173,   173,   174,   174,   175,   175,   176,   176,
     176,   176,   177,   177,   178,   178,   179,   180,   180,   181,
     181,   181,   182,   182,   182,   183,   183,   184,   184,   184,
     185,   185,   186,   186,   186,   187,   187,   187,   187,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   189,   189,   189,   189,   190,   190,   190,
     190,   190,   191,   191,   192,   192,   193,   193,   194,   194,
     195,   195,   196,   196,   197,   197,   198,   198,   199,   200,
     200,   200,   201,   201,   202,   202,   203,   203,   204,   204,
     204,   204,   204,   204,   204,   206,   205,   205,   205,   205,
     207,   207,   207,   207,   208,   209,   210,   210,   210,   210,
     211,   211,   212,   212,   213,   214,   214,   215,   214,   217,
     216,   218,   216,   219,   216,   220,   216,   221,   216,   222,
     216,   223,   216,   224,   224,   224,   224,   224,   225,   225,
     226,   226,   228,   227,   227,   229,   227,   230,   227,   231,
     227,   232,   227,   233,   227,   234,   227,   235,   227,   236,
     227,   237,   227,   238,   227,   239,   227,   240,   227,   241,
     227,   242,   227,   244,   243,   245,   245,   245,   245,   245,
     246,   246,   247,   247,   247,   248,   248,   249,   249,   249,
     249,   249,   250,   250,   250,   250,   250,   250,   250,   250,
     250
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     5,     6,     1,
       4,     3,     4,     3,     3,     2,     2,     3,     3,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     0,     1,     2,     2,     2,     2,     0,     0,     6,
       0,     0,     6,     0,     0,     7,     0,     5,     0,     5,
       3,     0,     0,     6,     0,     0,     6,     0,     0,     7,
       0,     5,     0,     5,     3,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     2,     2,     1,     2,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     5,
       3,     3,     4,     4,     1,     3,     1,     2,     1,     1,
       2,     3,     3,     4,     1,     1,     1,     1,     2,     2,
       3,     3,     3,     3,     4,     1,     2,     3,     1,     1,
       1,     2,     3,     2,     3,     4,     1,     3,     1,     2,
       3,     4,     3,     4,     1,     3,     1,     1,     1,     2,
       1,     2,     0,     1,     1,     2,     6,     1,     3,     0,
       1,     4,     1,     1,     1,     0,     2,     3,     4,     1,
       1,     3,     1,     3,     1,     1,     3,     3,     3,     1,
       2,     2,     2,     1,     2,     2,     1,     2,     2,     2,
       1,     2,     2,     2,     3,     4,     3,     4,     5,     2,
       3,     4,     1,     1,     1,     2,     2,     2,     2,     3,
       2,     3,     3,     2,     3,     2,     0,     1,     2,     5,
       6,     2,     2,     4,     0,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     4,     4,     3,     3,
       2,     3,     3,     4,     1,     1,     2,     3,     3,     4,
       1,     2,     1,     2,     2,     5,     7,     0,     6,     0,
       6,     0,     8,     0,    10,     0,    10,     0,    10,     0,
      10,     0,     6,     3,     2,     2,     3,     3,     1,     2,
       1,     1,     0,     3,     2,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     3,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     5,     0,     5,     0,
       5,     0,     5,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 343 "ANSI-C.y" /* yacc.c:1646  */
    { Program = GrabPragmas((yyvsp[0].L)); }
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 354 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 357 "ANSI-C.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].n)->typ == Comma) (yyvsp[-1].n)->coord = (yyvsp[-2].tok);
                                  (yyvsp[-1].n)->parenthesized = TRUE;
                                  (yyval.n) = (yyvsp[-1].n); }
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 363 "ANSI-C.y" /* yacc.c:1646  */
    { if (ANSIOnly)
	         SyntaxError("statement expressions not allowed with -ansi switch");
               (yyval.n) = MakeBlockCoord(NULL, NULL, GrabPragmas((yyvsp[-2].L)), (yyvsp[-4].tok), (yyvsp[-1].tok)); }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 367 "ANSI-C.y" /* yacc.c:1646  */
    { if (ANSIOnly)
	         SyntaxError("statement expressions not allowed with -ansi switch");
              (yyval.n) = MakeBlockCoord(NULL, (yyvsp[-3].L), GrabPragmas((yyvsp[-2].L)), (yyvsp[-5].tok), (yyvsp[-1].tok)); }
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 375 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ExtendArray((yyvsp[-3].n), (yyvsp[-1].n), (yyvsp[-2].tok)); arrayop();}
#line 2546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 377 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeCallCoord((yyvsp[-2].n), NULL, (yyvsp[-1].tok)); funccall((yyvsp[-2].n));}
#line 2552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 379 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeCallCoord((yyvsp[-3].n), (yyvsp[-1].L), (yyvsp[-2].tok)); funccall((yyvsp[-3].n));}
#line 2558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 381 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord('.', (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop('.');}
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 383 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(ARROW, (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop(ARROW);}
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 385 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUnaryCoord(POSTINC, (yyvsp[-1].n), (yyvsp[0].tok)); checkop(POSTINC);}
#line 2576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 387 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUnaryCoord(POSTDEC, (yyvsp[-1].n), (yyvsp[0].tok)); checkop(POSTDEC);}
#line 2582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 391 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord('.', (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop('.');}
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 393 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(ARROW, (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop(ARROW);}
#line 2594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 398 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = MakeNewList((yyvsp[0].n)); }
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 400 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = AppendItem((yyvsp[-2].L), (yyvsp[0].n)); }
#line 2606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 405 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = LookupPostfixExpression((yyvsp[0].n)); }
#line 2612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 407 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUnaryCoord(PREINC, (yyvsp[0].n), (yyvsp[-1].tok)); }
#line 2618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 409 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUnaryCoord(PREDEC, (yyvsp[0].n), (yyvsp[-1].tok)); }
#line 2624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 411 "ANSI-C.y" /* yacc.c:1646  */
    { (yyvsp[-1].n)->u.unary.expr = (yyvsp[0].n);
              (yyval.n) = (yyvsp[-1].n); }
#line 2631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 414 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUnaryCoord(SIZEOF, (yyvsp[0].n), (yyvsp[-1].tok)); checkstmt("sizeof");}
#line 2637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 416 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUnaryCoord(SIZEOF, (yyvsp[-1].n), (yyvsp[-3].tok)); checkstmt("sizeof");}
#line 2643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 420 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUnaryCoord('&', NULL, (yyvsp[0].tok)); checkop('&');}
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 421 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUnaryCoord('*', NULL, (yyvsp[0].tok)); checkop('*');}
#line 2655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 422 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUnaryCoord('+', NULL, (yyvsp[0].tok)); checkop('+');}
#line 2661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 423 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUnaryCoord('-', NULL, (yyvsp[0].tok)); checkop('-');}
#line 2667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 424 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUnaryCoord('~', NULL, (yyvsp[0].tok)); checkop('~');}
#line 2673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 425 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUnaryCoord('!', NULL, (yyvsp[0].tok)); checkop('!');}
#line 2679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 430 "ANSI-C.y" /* yacc.c:1646  */
    { 
	  (yyval.n) = MakeCastCoord((yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-3].tok)); castwarning(); }
#line 2686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 437 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord('*', (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop('*');}
#line 2692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 439 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord('/', (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop('/');}
#line 2698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 441 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord('%', (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop('%');}
#line 2704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 447 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord('+', (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop('+');}
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 449 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord('-', (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop('-');}
#line 2716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 455 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(LS, (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop(LS);}
#line 2722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 457 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(RS, (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop(RS);}
#line 2728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 463 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord('<', (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop('<');}
#line 2734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 465 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord('>', (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop('>');}
#line 2740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 467 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(LE, (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop(LE);}
#line 2746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 469 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(GE, (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop(GE);}
#line 2752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 475 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(EQ, (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop(EQ);}
#line 2758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 477 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(NE, (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop(NE);}
#line 2764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 483 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord('&', (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop('&');}
#line 2770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 489 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      checkop('^');
              WarnAboutPrecedence('^', (yyvsp[-2].n));
              WarnAboutPrecedence('^', (yyvsp[0].n));
	      (yyval.n) = MakeBinopCoord('^', (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); }
#line 2780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 499 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      checkop('|');
	      WarnAboutPrecedence('|', (yyvsp[-2].n));
              WarnAboutPrecedence('|', (yyvsp[0].n));
              (yyval.n) = MakeBinopCoord('|', (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); }
#line 2790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 509 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(ANDAND, (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); checkop(ANDAND);}
#line 2796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 515 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      checkop(OROR);
	      WarnAboutPrecedence(OROR, (yyvsp[-2].n));
              WarnAboutPrecedence(OROR, (yyvsp[0].n));
              (yyval.n) = MakeBinopCoord(OROR, (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-1].tok)); }
#line 2806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 525 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      (yyval.n) = MakeTernaryCoord((yyvsp[-4].n), (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-3].tok), (yyvsp[-1].tok)); 
	      checkstmt("ternary if");
	    }
#line 2815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 534 "ANSI-C.y" /* yacc.c:1646  */
    { (yyvsp[-1].n)->u.binop.left = (yyvsp[-2].n);
              (yyvsp[-1].n)->u.binop.right = (yyvsp[0].n);
              (yyval.n) = (yyvsp[-1].n); }
#line 2823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 540 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord('=', NULL, NULL, (yyvsp[0].tok)); }
#line 2829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 541 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(MULTassign, NULL, NULL, (yyvsp[0].tok)); 
	checkop('*');}
#line 2836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 543 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(DIVassign, NULL, NULL, (yyvsp[0].tok)); 
	checkop('/');}
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 545 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(MODassign, NULL, NULL, (yyvsp[0].tok)); 
	checkop('%');}
#line 2850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 547 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(PLUSassign, NULL, NULL, (yyvsp[0].tok)); 
	checkop('+');}
#line 2857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 549 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(MINUSassign, NULL, NULL, (yyvsp[0].tok)); 
	checkop('-');}
#line 2864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 551 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(LSassign, NULL, NULL, (yyvsp[0].tok));    
	checkop(LS);}
#line 2871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 553 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(RSassign, NULL, NULL, (yyvsp[0].tok));    
	checkop(RS);}
#line 2878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 555 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(ANDassign, NULL, NULL, (yyvsp[0].tok));   
	checkop('&');}
#line 2885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 557 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(ERassign, NULL, NULL, (yyvsp[0].tok));    
	checkop('^');}
#line 2892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 559 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBinopCoord(ORassign, NULL, NULL, (yyvsp[0].tok));    
	checkop('|');}
#line 2899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 566 "ANSI-C.y" /* yacc.c:1646  */
    {  
              if ((yyvsp[-2].n)->typ == Comma) 
                {
		  AppendItem((yyvsp[-2].n)->u.comma.exprs, (yyvsp[0].n));
		  (yyval.n) = (yyvsp[-2].n);
		}
              else
                {
		  (yyval.n) = MakeCommaCoord(AppendItem(MakeNewList((yyvsp[-2].n)), (yyvsp[0].n)), (yyvsp[-2].n)->coord);
		}
	    }
#line 2915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 580 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 584 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (Node *) NULL; }
#line 2927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 585 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 622 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = (yyvsp[-1].L); }
#line 2939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 624 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = (yyvsp[-1].L); }
#line 2945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 626 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = MakeNewList(ForceNewSU((yyvsp[-1].n), (yyvsp[0].tok))); }
#line 2951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 628 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = MakeNewList(ForceNewSU((yyvsp[-1].n), (yyvsp[0].tok))); }
#line 2957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 634 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      SetDeclType((yyvsp[0].n), (yyvsp[-1].n), Redecl);
	    }
#line 2965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 637 "ANSI-C.y" /* yacc.c:1646  */
    { SetDeclAttribs((yyvsp[-2].n), (yyvsp[0].L)); }
#line 2971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 639 "ANSI-C.y" /* yacc.c:1646  */
    { 
              (yyval.L) = MakeNewList(SetDeclInit((yyvsp[-4].n), (yyvsp[0].n))); 
            }
#line 2979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 643 "ANSI-C.y" /* yacc.c:1646  */
    { 
              SetDeclType((yyvsp[0].n), (yyvsp[-1].n), Redecl);
            }
#line 2987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 646 "ANSI-C.y" /* yacc.c:1646  */
    { SetDeclAttribs((yyvsp[-2].n), (yyvsp[0].L)); }
#line 2993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 648 "ANSI-C.y" /* yacc.c:1646  */
    { 
              (yyval.L) = MakeNewList(SetDeclInit((yyvsp[-4].n), (yyvsp[0].n))); 
	    }
#line 3001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 652 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      (yyval.L) = AppendDecl((yyvsp[-2].L), (yyvsp[0].n), Redecl);
	    }
#line 3009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 655 "ANSI-C.y" /* yacc.c:1646  */
    { SetDeclAttribs((yyvsp[-2].n), (yyvsp[0].L)); }
#line 3015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 657 "ANSI-C.y" /* yacc.c:1646  */
    { 
              SetDeclInit((yyvsp[-4].n), (yyvsp[0].n)); 
            }
#line 3023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 665 "ANSI-C.y" /* yacc.c:1646  */
    { 
              SyntaxError("declaration without a variable"); 
            }
#line 3031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 670 "ANSI-C.y" /* yacc.c:1646  */
    { 
              (yyval.L) = NULL; /* empty list */ 
            }
#line 3039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 675 "ANSI-C.y" /* yacc.c:1646  */
    { 
              SyntaxError("declaration without a variable"); 
            }
#line 3047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 680 "ANSI-C.y" /* yacc.c:1646  */
    { 
              (yyval.L) = NULL; /* empty list */ 
            }
#line 3055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 690 "ANSI-C.y" /* yacc.c:1646  */
    { 
              SetDeclType((yyvsp[0].n), MakeDefaultPrimType((yyvsp[-1].tq).tq, (yyvsp[-1].tq).coord), NoRedecl);
            }
#line 3063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 693 "ANSI-C.y" /* yacc.c:1646  */
    { SetDeclAttribs((yyvsp[-2].n), (yyvsp[0].L)); }
#line 3069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 695 "ANSI-C.y" /* yacc.c:1646  */
    { 
              (yyval.L) = MakeNewList(SetDeclInit((yyvsp[-4].n), (yyvsp[0].n))); 
            }
#line 3077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 699 "ANSI-C.y" /* yacc.c:1646  */
    { 
              SetDeclType((yyvsp[0].n), MakeDefaultPrimType((yyvsp[-1].tq).tq, (yyvsp[-1].tq).coord), NoRedecl);
            }
#line 3085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 702 "ANSI-C.y" /* yacc.c:1646  */
    { SetDeclAttribs((yyvsp[-2].n), (yyvsp[0].L)); }
#line 3091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 704 "ANSI-C.y" /* yacc.c:1646  */
    { 
              (yyval.L) = MakeNewList(SetDeclInit((yyvsp[-4].n), (yyvsp[0].n))); 
	    }
#line 3099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 708 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = AppendDecl((yyvsp[-2].L), (yyvsp[0].n), NoRedecl); }
#line 3105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 709 "ANSI-C.y" /* yacc.c:1646  */
    { SetDeclAttribs((yyvsp[-2].n), (yyvsp[0].L)); }
#line 3111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 711 "ANSI-C.y" /* yacc.c:1646  */
    { SetDeclInit((yyvsp[-4].n), (yyvsp[0].n)); }
#line 3117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 716 "ANSI-C.y" /* yacc.c:1646  */
    { 
              SyntaxError("declaration without a variable"); 
	    }
#line 3125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 721 "ANSI-C.y" /* yacc.c:1646  */
    { 
              (yyval.L) = NULL; /* empty list */ 
	    }
#line 3133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 726 "ANSI-C.y" /* yacc.c:1646  */
    { 
              SyntaxError("declaration without a variable"); 
	    }
#line 3141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 731 "ANSI-C.y" /* yacc.c:1646  */
    { 
              (yyval.L) = NULL; /* empty list */ 
            }
#line 3149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 740 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = FinishPrimType((yyvsp[0].n)); }
#line 3155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 749 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[-1].n), (yyvsp[0].tq).tq); }
#line 3161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 751 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[0].n), (yyvsp[-1].tq).tq); (yyval.n)->coord = (yyvsp[-1].tq).coord; }
#line 3167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 753 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[-1].n), (yyvsp[0].tq).tq); }
#line 3173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 755 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MergePrimTypes((yyvsp[-1].n), (yyvsp[0].n)); }
#line 3179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 762 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[-1].n), (yyvsp[0].tq).tq); }
#line 3185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 764 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[0].n), (yyvsp[-1].tq).tq); (yyval.n)->coord = (yyvsp[-1].tq).coord; }
#line 3191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 766 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[-1].n), (yyvsp[0].tq).tq); }
#line 3197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 773 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[-1].n), (yyvsp[0].tq).tq); }
#line 3203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 775 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ConvertIdToTdef((yyvsp[0].n), (yyvsp[-1].tq).tq, GetTypedefType((yyvsp[0].n))); (yyval.n)->coord = (yyvsp[-1].tq).coord; }
#line 3209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 777 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[-1].n), (yyvsp[0].tq).tq); }
#line 3215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 785 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = MergeTypeQuals((yyvsp[-1].tq).tq, (yyvsp[0].tq).tq, (yyvsp[0].tq).coord);
              (yyval.tq).coord = (yyvsp[-1].tq).coord; }
#line 3222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 788 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = MergeTypeQuals((yyvsp[-1].tq).tq, (yyvsp[0].tq).tq, (yyvsp[0].tq).coord);
              (yyval.tq).coord = (yyvsp[-1].tq).coord; }
#line 3229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 801 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = FinishPrimType((yyvsp[0].n)); }
#line 3235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 810 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[0].n), (yyvsp[-1].tq).tq); (yyval.n)->coord = (yyvsp[-1].tq).coord; }
#line 3241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 812 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[-1].n), (yyvsp[0].tq).tq); }
#line 3247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 814 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MergePrimTypes((yyvsp[-1].n), (yyvsp[0].n)); }
#line 3253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 821 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[0].n), (yyvsp[-1].tq).tq); (yyval.n)->coord = (yyvsp[-1].tq).coord; }
#line 3259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 823 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[-1].n), (yyvsp[0].tq).tq); }
#line 3265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 830 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ConvertIdToTdef((yyvsp[0].n), EMPTY_TQ, GetTypedefType((yyvsp[0].n))); }
#line 3271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 832 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ConvertIdToTdef((yyvsp[0].n), (yyvsp[-1].tq).tq, GetTypedefType((yyvsp[0].n))); (yyval.n)->coord = (yyvsp[-1].tq).coord; }
#line 3277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 834 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = TypeQualifyNode((yyvsp[-1].n), (yyvsp[0].tq).tq); }
#line 3283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 841 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = MergeTypeQuals((yyvsp[-1].tq).tq, (yyvsp[0].tq).tq, (yyvsp[0].tq).coord);
              (yyval.tq).coord = (yyvsp[-1].tq).coord; }
#line 3290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 848 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = MergeTypeQuals((yyvsp[-1].tq).tq, (yyvsp[0].tq).tq, (yyvsp[0].tq).coord);
              (yyval.tq).coord = (yyvsp[-1].tq).coord; }
#line 3297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 864 "ANSI-C.y" /* yacc.c:1646  */
    {
	      Warning(2, "function prototype parameters must have types");
              (yyval.n) = AddDefaultParameterTypes((yyvsp[0].n));
            }
#line 3306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 875 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[0].n), MakePtrCoord(EMPTY_TQ, NULL, (yyvsp[-1].tok)), Redecl);
               }
#line 3313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 878 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[-1].n), MakePtrCoord(EMPTY_TQ, NULL, (yyvsp[-3].tok)), Redecl); 
               }
#line 3320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 881 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[-1].n), MakePtrCoord(   (yyvsp[-3].tq).tq,    NULL, (yyvsp[-4].tok)), Redecl);
               }
#line 3327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 884 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[0].n), MakePtrCoord(   (yyvsp[-1].tq).tq,    NULL, (yyvsp[-2].tok)), Redecl); 
               }
#line 3334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 892 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n);  
              }
#line 3341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 895 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ModifyDeclType((yyvsp[-2].n), (yyvsp[-1].n)); 
               }
#line 3348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 898 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ModifyDeclType((yyvsp[-2].n), (yyvsp[0].n)); 
               }
#line 3355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 905 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ConvertIdToDecl((yyvsp[0].n), EMPTY_TQ, NULL, NULL, NULL); }
#line 3361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 907 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n);  
               }
#line 3368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 914 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ConvertIdToDecl((yyvsp[0].n), EMPTY_TQ, NULL, NULL, NULL); }
#line 3374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 916 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ConvertIdToDecl((yyvsp[-1].n), EMPTY_TQ, (yyvsp[0].n), NULL, NULL);   }
#line 3380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 928 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[0].n), MakePtrCoord(EMPTY_TQ, NULL, (yyvsp[-1].tok)), Redecl); 
               }
#line 3387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 931 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[0].n), MakePtrCoord((yyvsp[-1].tq).tq, NULL, (yyvsp[-2].tok)), Redecl); 
               }
#line 3394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 938 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); 
               }
#line 3401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 941 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ModifyDeclType((yyvsp[-2].n), (yyvsp[0].n)); 
               }
#line 3408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 955 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakePtrCoord(EMPTY_TQ, NULL, (yyvsp[0].tok)); }
#line 3414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 957 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakePtrCoord((yyvsp[0].tq).tq, NULL, (yyvsp[-1].tok)); }
#line 3420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 959 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetBaseType((yyvsp[0].n), MakePtrCoord(EMPTY_TQ, NULL, (yyvsp[-1].tok))); 
               }
#line 3427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 962 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetBaseType((yyvsp[0].n), MakePtrCoord((yyvsp[-1].tq).tq, NULL, (yyvsp[-2].tok))); 
               }
#line 3434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 969 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); 
               }
#line 3441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 972 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); 
               }
#line 3448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 975 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); 
               }
#line 3455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 978 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetBaseType((yyvsp[-2].n), (yyvsp[0].n)); 
               }
#line 3462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 984 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n);                   }
#line 3468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 985 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeFdclCoord(EMPTY_TQ, NULL, NULL, (yyvsp[-1].tok)); }
#line 3474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 986 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeFdclCoord(EMPTY_TQ, (yyvsp[-1].L), NULL, (yyvsp[-2].tok)); }
#line 3480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 999 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ModifyDeclType((yyvsp[0].n), MakePtrCoord(EMPTY_TQ, NULL, (yyvsp[-1].tok))); 
               }
#line 3487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1002 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ModifyDeclType((yyvsp[0].n), MakePtrCoord(   (yyvsp[-1].tq).tq,    NULL, (yyvsp[-2].tok))); 
               }
#line 3494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1009 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ModifyDeclType((yyvsp[-1].n), (yyvsp[0].n)); }
#line 3500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1011 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); 
               }
#line 3507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1014 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ModifyDeclType((yyvsp[-2].n), (yyvsp[0].n)); 
               }
#line 3514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1021 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ConvertIdToDecl((yyvsp[0].n), EMPTY_TQ, NULL, NULL, NULL); }
#line 3520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1023 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); 
               }
#line 3527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1030 "ANSI-C.y" /* yacc.c:1646  */
    { 
/*              OldStyleFunctionDefinition = TRUE; */
              (yyval.n) = (yyvsp[0].n); 
            }
#line 3536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1035 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[0].n), MakePtrCoord(EMPTY_TQ, NULL, (yyvsp[-1].tok)), SU); 
               }
#line 3543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1038 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[0].n), MakePtrCoord((yyvsp[-1].tq).tq, NULL, (yyvsp[-2].tok)), SU); 
               }
#line 3550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1045 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      (yyval.n) = ModifyDeclType((yyvsp[-3].n), MakeFdclCoord(EMPTY_TQ, (yyvsp[-1].L), NULL, (yyvsp[-2].tok))); 
	    }
#line 3558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1050 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      (yyval.n) = (yyvsp[-1].n); 
	    }
#line 3566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1054 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      (yyval.n) = ModifyDeclType((yyvsp[-2].n), (yyvsp[0].n)); 
	    }
#line 3574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1070 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = MakeNewList((yyvsp[0].n)); }
#line 3580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1072 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = AppendItem((yyvsp[-2].L), (yyvsp[0].n)); }
#line 3586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1084 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = FinishType((yyvsp[0].n)); }
#line 3592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1086 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = FinishType(SetBaseType((yyvsp[0].n), (yyvsp[-1].n))); }
#line 3598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1088 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeDefaultPrimType((yyvsp[0].tq).tq, (yyvsp[0].tq).coord); }
#line 3604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1090 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetBaseType((yyvsp[0].n), MakeDefaultPrimType((yyvsp[-1].tq).tq, (yyvsp[-1].tq).coord)); }
#line 3610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1098 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = NULL; }
#line 3616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1100 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = (yyvsp[0].L); }
#line 3622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1105 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = (yyvsp[0].L); }
#line 3628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1107 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = JoinLists ((yyvsp[-1].L), (yyvsp[0].L)); }
#line 3634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1112 "ANSI-C.y" /* yacc.c:1646  */
    { if (ANSIOnly)
	            SyntaxError("__attribute__ not allowed with -ansi switch");
                  (yyval.L) = (yyvsp[-2].L); }
#line 3642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1119 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = MakeNewList((yyvsp[0].n)); }
#line 3648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1121 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = AppendItem((yyvsp[-2].L), (yyvsp[0].n)); }
#line 3654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1126 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = NULL; }
#line 3660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1128 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ConvertIdToAttrib((yyvsp[0].n), NULL); }
#line 3666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1130 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ConvertIdToAttrib((yyvsp[-3].n), (yyvsp[-1].n)); }
#line 3672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1137 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeIdCoord(UniqueString("const"), (yyvsp[0].tok)); }
#line 3678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1142 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = NULL; }
#line 3684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1143 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 3690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1148 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); (yyval.n)->coord = (yyvsp[-2].tok); }
#line 3696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1149 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-2].n); (yyval.n)->coord = (yyvsp[-3].tok); }
#line 3702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1150 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 3708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1156 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeInitializerCoord(MakeNewList((yyvsp[0].n)), (yyvsp[0].n)->coord); }
#line 3714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1158 "ANSI-C.y" /* yacc.c:1646  */
    { 
              assert((yyvsp[-2].n)->typ == Initializer);
              AppendItem((yyvsp[-2].n)->u.initializer.exprs, (yyvsp[0].n));
              (yyval.n) = (yyvsp[-2].n); 
            }
#line 3724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1168 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = AppendItem((yyvsp[-2].L), EllipsisNode); }
#line 3730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1172 "ANSI-C.y" /* yacc.c:1646  */
    { Node *n = MakePrimCoord(EMPTY_TQ, Void, (yyvsp[0].tok));
	      SyntaxErrorCoord(n->coord, "First argument cannot be `...'");
              (yyval.L) = MakeNewList(n);
            }
#line 3739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1181 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = MakeNewList((yyvsp[0].n)); }
#line 3745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1183 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = AppendItem((yyvsp[-2].L), (yyvsp[0].n)); }
#line 3751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1187 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      SyntaxErrorCoord((yyvsp[-2].n)->coord, "formals cannot have initializers");
              (yyval.L) = MakeNewList((yyvsp[-2].n)); 
            }
#line 3760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1192 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = (yyvsp[-2].L); }
#line 3766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1198 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 3772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1200 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetBaseType((yyvsp[0].n), (yyvsp[-1].n)); 
            }
#line 3779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1203 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[0].n), (yyvsp[-1].n), Formal); 
            }
#line 3786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1206 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[0].n), (yyvsp[-1].n), Formal); 
            }
#line 3793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1209 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeDefaultPrimType((yyvsp[0].tq).tq, (yyvsp[0].tq).coord); }
#line 3799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1211 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetBaseType((yyvsp[0].n), MakeDefaultPrimType((yyvsp[-1].tq).tq, (yyvsp[-1].tq).coord)); }
#line 3805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1213 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[0].n), MakeDefaultPrimType((yyvsp[-1].tq).tq, (yyvsp[-1].tq).coord), Formal); }
#line 3811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1215 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 3817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1217 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetBaseType((yyvsp[0].n), (yyvsp[-1].n)); 
            }
#line 3824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1220 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[0].n), (yyvsp[-1].n), Formal); 
            }
#line 3831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1223 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[0].n), (yyvsp[-1].n), Formal); 
            }
#line 3838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1226 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeDefaultPrimType((yyvsp[0].tq).tq, (yyvsp[0].tq).coord); }
#line 3844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1228 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetBaseType((yyvsp[0].n), MakeDefaultPrimType((yyvsp[-1].tq).tq, (yyvsp[-1].tq).coord)); }
#line 3850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1230 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclType((yyvsp[0].n), MakeDefaultPrimType((yyvsp[-1].tq).tq, (yyvsp[-1].tq).coord), Formal); }
#line 3856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1236 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeAdclCoord(EMPTY_TQ, NULL, NULL, (yyvsp[-1].tok)); arrayop();}
#line 3862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1238 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeAdclCoord(EMPTY_TQ, NULL, (yyvsp[-1].n), (yyvsp[-2].tok)); arrayop();}
#line 3868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1240 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetBaseType((yyvsp[-3].n), MakeAdclCoord(EMPTY_TQ, NULL, (yyvsp[-1].n), (yyvsp[-2].tok))); arrayop();}
#line 3874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1245 "ANSI-C.y" /* yacc.c:1646  */
    { 
              SyntaxError("array declaration with illegal empty dimension");
              (yyval.n) = SetBaseType((yyvsp[-2].n), MakeAdclCoord(EMPTY_TQ, NULL, SintOne, (yyvsp[-1].tok))); 
            }
#line 3883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1260 "ANSI-C.y" /* yacc.c:1646  */
    { 
              (yyval.n) = SetSUdclNameFields((yyvsp[-3].n), NULL, (yyvsp[-1].L), (yyvsp[-2].tok), (yyvsp[0].tok));
            }
#line 3891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1265 "ANSI-C.y" /* yacc.c:1646  */
    { 
              (yyval.n) = SetSUdclNameFields((yyvsp[-4].n), (yyvsp[-3].n), (yyvsp[-1].L), (yyvsp[-2].tok), (yyvsp[0].tok));
	    }
#line 3899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1269 "ANSI-C.y" /* yacc.c:1646  */
    { 
              (yyval.n) = SetSUdclName((yyvsp[-1].n), (yyvsp[0].n), (yyvsp[-1].n)->coord);
	    }
#line 3907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1274 "ANSI-C.y" /* yacc.c:1646  */
    { 
              if (ANSIOnly)
                 Warning(1, "empty structure declaration");
              (yyval.n) = SetSUdclNameFields((yyvsp[-2].n), NULL, NULL, (yyvsp[-1].tok), (yyvsp[0].tok)); 
	    }
#line 3917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1280 "ANSI-C.y" /* yacc.c:1646  */
    { 
              if (ANSIOnly)
                 Warning(1, "empty structure declaration");
              (yyval.n) = SetSUdclNameFields((yyvsp[-3].n), (yyvsp[-2].n), NULL, (yyvsp[-1].tok), (yyvsp[0].tok)); 
	    }
#line 3927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1289 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeSdclCoord(EMPTY_TQ, NULL, (yyvsp[0].tok)); }
#line 3933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1290 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeUdclCoord(EMPTY_TQ, NULL, (yyvsp[0].tok)); }
#line 3939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1297 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = JoinLists((yyvsp[-1].L), (yyvsp[0].L)); }
#line 3945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1310 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      (yyval.L) = MakeNewList(SetDeclType((yyvsp[0].n),
					    MakeDefaultPrimType((yyvsp[-1].tq).tq, (yyvsp[-1].tq).coord),
					    SU)); 
	    }
#line 3955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1316 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = AppendDecl((yyvsp[-2].L), (yyvsp[0].n), SU); }
#line 3961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1322 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = MakeNewList(SetDeclType((yyvsp[0].n), (yyvsp[-1].n), SU)); }
#line 3967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1324 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = AppendDecl((yyvsp[-2].L), (yyvsp[0].n), SU); }
#line 3973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1331 "ANSI-C.y" /* yacc.c:1646  */
    { SetDeclAttribs((yyvsp[-2].n), (yyvsp[0].L));
              (yyval.n) = SetDeclBitSize((yyvsp[-2].n), (yyvsp[-1].n)); }
#line 3980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1334 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeDeclCoord(NULL, EMPTY_TQ, NULL, NULL, (yyvsp[-1].n), (yyvsp[-1].n)->coord);
              SetDeclAttribs((yyval.n), (yyvsp[0].L)); }
#line 3987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1341 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetDeclBitSize((yyvsp[-2].n), (yyvsp[-1].n));
              SetDeclAttribs((yyvsp[-2].n), (yyvsp[0].L)); }
#line 3994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1344 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeDeclCoord(NULL, EMPTY_TQ, NULL, NULL, (yyvsp[-1].n), (yyvsp[-1].n)->coord);
              SetDeclAttribs((yyval.n), (yyvsp[0].L)); }
#line 4001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1350 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = NULL; }
#line 4007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1356 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 4013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1362 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = BuildEnum(NULL, (yyvsp[-2].L), (yyvsp[-4].tok), (yyvsp[-3].tok), (yyvsp[0].tok)); }
#line 4019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1364 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = BuildEnum((yyvsp[-4].n), (yyvsp[-2].L), (yyvsp[-5].tok), (yyvsp[-3].tok), (yyvsp[0].tok));   }
#line 4025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1366 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = BuildEnum((yyvsp[0].n), NULL, (yyvsp[-1].tok), (yyvsp[0].n)->coord, (yyvsp[0].n)->coord); }
#line 4031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1372 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = MakeNewList(BuildEnumConst((yyvsp[-1].n), (yyvsp[0].n))); }
#line 4037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1374 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = AppendItem((yyvsp[-3].L), BuildEnumConst((yyvsp[-1].n), (yyvsp[0].n))); }
#line 4043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1379 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = NULL; }
#line 4049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1380 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n);   }
#line 4055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1384 "ANSI-C.y" /* yacc.c:1646  */
    { }
#line 4061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1385 "ANSI-C.y" /* yacc.c:1646  */
    { }
#line 4067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1403 "ANSI-C.y" /* yacc.c:1646  */
    {  (yyval.n) = NULL; }
#line 4073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1408 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = BuildLabel((yyvsp[-1].n), NULL); }
#line 4079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1410 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n)->u.label.stmt = (yyvsp[0].n); }
#line 4085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1413 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = AddContainee(MakeCaseCoord((yyvsp[-2].n), (yyvsp[0].n), NULL, (yyvsp[-3].tok))); }
#line 4091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1415 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = AddContainee(MakeDefaultCoord((yyvsp[0].n), NULL, (yyvsp[-2].tok))); }
#line 4097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1419 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = BuildLabel((yyvsp[-2].n), (yyvsp[0].n)); }
#line 4103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1424 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBlockCoord(PrimVoid, NULL, NULL, (yyvsp[-1].tok), (yyvsp[0].tok)); }
#line 4109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1426 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBlockCoord(PrimVoid, GrabPragmas((yyvsp[-1].L)), NULL, (yyvsp[-2].tok), (yyvsp[0].tok)); }
#line 4115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1428 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBlockCoord(PrimVoid, NULL, GrabPragmas((yyvsp[-1].L)), (yyvsp[-2].tok), (yyvsp[0].tok)); }
#line 4121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1430 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBlockCoord(PrimVoid, (yyvsp[-2].L), GrabPragmas((yyvsp[-1].L)), (yyvsp[-3].tok), (yyvsp[0].tok)); }
#line 4127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1433 "ANSI-C.y" /* yacc.c:1646  */
    { EnterScope(); }
#line 4133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1435 "ANSI-C.y" /* yacc.c:1646  */
    { ExitScope(); }
#line 4139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1443 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBlockCoord(PrimVoid, NULL, NULL, (yyvsp[-1].tok), (yyvsp[0].tok));disable_check();}
#line 4145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1445 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBlockCoord(PrimVoid, GrabPragmas((yyvsp[-1].L)), NULL, (yyvsp[-2].tok), (yyvsp[0].tok)); disable_check();}
#line 4151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1447 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBlockCoord(PrimVoid, NULL, GrabPragmas((yyvsp[-1].L)), (yyvsp[-2].tok), (yyvsp[0].tok)); disable_check();}
#line 4157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1449 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeBlockCoord(PrimVoid, (yyvsp[-2].L), GrabPragmas((yyvsp[-1].L)), (yyvsp[-3].tok), (yyvsp[0].tok)); disable_check();}
#line 4163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1455 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = GrabPragmas((yyvsp[0].L)); }
#line 4169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1456 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = JoinLists(GrabPragmas((yyvsp[-1].L)),
                                                         (yyvsp[0].L)); }
#line 4176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1461 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = GrabPragmas(MakeNewList((yyvsp[0].n))); }
#line 4182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1462 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = AppendItem(GrabPragmas((yyvsp[-1].L)), 
                                                        (yyvsp[0].n)); }
#line 4189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1472 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeIfCoord((yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-4].tok)); checkstmt("if");}
#line 4195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1474 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = MakeIfElseCoord((yyvsp[-4].n), (yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-6].tok), (yyvsp[-1].tok)); checkstmt("if");}
#line 4201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1475 "ANSI-C.y" /* yacc.c:1646  */
    { PushContainer(Switch); }
#line 4207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1476 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = PopContainer(MakeSwitchCoord((yyvsp[-2].n), (yyvsp[0].n), NULL, (yyvsp[-5].tok))); 
	    checkstmt("switch");}
#line 4214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1482 "ANSI-C.y" /* yacc.c:1646  */
    { PushContainer(While);}
#line 4220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1484 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = PopContainer(MakeWhileCoord((yyvsp[-2].n), (yyvsp[0].n), (yyvsp[-5].tok))); checkstmt("while");}
#line 4226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1486 "ANSI-C.y" /* yacc.c:1646  */
    { PushContainer(Do);}
#line 4232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1488 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = PopContainer(MakeDoCoord((yyvsp[-5].n), (yyvsp[-2].n), (yyvsp[-7].tok), (yyvsp[-4].tok))); checkstmt("do");}
#line 4238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1490 "ANSI-C.y" /* yacc.c:1646  */
    { PushContainer(For);}
#line 4244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1492 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = PopContainer(MakeForCoord((yyvsp[-7].n), (yyvsp[-5].n), (yyvsp[-3].n), (yyvsp[0].n), (yyvsp[-9].tok))); checkstmt("for");}
#line 4250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1496 "ANSI-C.y" /* yacc.c:1646  */
    { PushContainer(For);}
#line 4256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1498 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = PopContainer(MakeForCoord(NULL, (yyvsp[-5].n), (yyvsp[-3].n), (yyvsp[0].n), (yyvsp[-9].tok))); }
#line 4262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1500 "ANSI-C.y" /* yacc.c:1646  */
    { PushContainer(For);}
#line 4268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1502 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = PopContainer(MakeForCoord((yyvsp[-7].n), (yyvsp[-5].n), NULL, (yyvsp[0].n), (yyvsp[-9].tok))); }
#line 4274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1504 "ANSI-C.y" /* yacc.c:1646  */
    { PushContainer(For);}
#line 4280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1506 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = PopContainer(MakeForCoord((yyvsp[-7].n), NULL, (yyvsp[-3].n), (yyvsp[0].n), (yyvsp[-9].tok))); }
#line 4286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1507 "ANSI-C.y" /* yacc.c:1646  */
    { PushContainer(For);}
#line 4292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1508 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = PopContainer(MakeForCoord(NULL, SintZero, NULL, (yyvsp[0].n), (yyvsp[-5].tok))); }
#line 4298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1513 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ResolveGoto((yyvsp[-1].n), (yyvsp[-2].tok)); checkstmt("goto");}
#line 4304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1515 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = AddContainee(MakeContinueCoord(NULL, (yyvsp[-1].tok))); checkstmt("continue");}
#line 4310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1517 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = AddContainee(MakeBreakCoord(NULL, (yyvsp[-1].tok))); checkstmt("break");}
#line 4316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1519 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = AddReturn(MakeReturnCoord((yyvsp[-1].n), (yyvsp[-2].tok))); }
#line 4322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1523 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = ResolveGoto((yyvsp[-1].n), (yyvsp[-2].tok)); }
#line 4328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1535 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.L) = JoinLists(GrabPragmas((yyvsp[-1].L)), (yyvsp[0].L)); }
#line 4334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1541 "ANSI-C.y" /* yacc.c:1646  */
    {
              if (yydebug)
                {
                  printf("external.definition # declaration\n");
                  PrintNode(stdout, FirstItem((yyvsp[0].L)), 0); 
                  printf("\n\n\n");
		}
              (yyval.L) = (yyvsp[0].L);
            }
#line 4348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1551 "ANSI-C.y" /* yacc.c:1646  */
    { 
              if (yydebug)
                {
                  printf("external.definition # function.definition\n");
                  PrintNode(stdout, (yyvsp[0].n), 0); 
                  printf("\n\n\n");
                }
              (yyval.L) = MakeNewList((yyvsp[0].n)); 
            }
#line 4362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1564 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      Node *decl;
	      decl = SetDeclType((yyvsp[0].n),
				       MakeDefaultPrimType(EMPTY_TQ, 
							   (yyvsp[0].n)->coord),
				       Redecl);
	      newfunc(decl);
              (yyvsp[0].n) = DefineProc(FALSE, decl);
            }
#line 4376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1574 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-2].n), (yyvsp[0].n)); }
#line 4382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1580 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      Node *decl;
	      decl = SetDeclType((yyvsp[0].n), (yyvsp[-1].n), Redecl);
	      newfunc(decl);
	      (yyvsp[0].n) = DefineProc(FALSE, decl); 
	    }
#line 4393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1587 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-2].n), (yyvsp[0].n)); }
#line 4399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1589 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      Node *decl;
	      decl = SetDeclType((yyvsp[0].n), (yyvsp[-1].n), Redecl);
	      newfunc(decl);
	      (yyvsp[0].n) = DefineProc(FALSE, decl); 
	    }
#line 4410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1596 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      endfunc((yyvsp[0].n));
	      (yyval.n) = SetProcBody((yyvsp[-2].n), (yyvsp[0].n)); 
	    }
#line 4419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1601 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      Node *decl;
	      decl = SetDeclType((yyvsp[0].n),
				       MakeDefaultPrimType((yyvsp[-1].tq).tq, (yyvsp[-1].tq).coord),
				       Redecl);
	      newfunc(decl);
              (yyvsp[0].n) = DefineProc(FALSE, decl);
            }
#line 4432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1610 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-2].n), (yyvsp[0].n)); }
#line 4438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1612 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      Node *decl;
	      decl = SetDeclType((yyvsp[0].n),
				       MakeDefaultPrimType((yyvsp[-1].tq).tq, (yyvsp[-1].tq).coord),
				       Redecl);
	      newfunc(decl);
              (yyvsp[0].n) = DefineProc(FALSE, decl);
            }
#line 4451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1621 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-2].n), (yyvsp[0].n)); }
#line 4457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1623 "ANSI-C.y" /* yacc.c:1646  */
    { 
	      Node *decl;
	      decl = SetDeclType((yyvsp[0].n),
				       MakeDefaultPrimType(EMPTY_TQ, 
							   (yyvsp[0].n)->coord),
				       Redecl);
	      newfunc(decl);
              (yyvsp[0].n) = DefineProc(TRUE, decl);
            }
#line 4471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1633 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-2].n), (yyvsp[0].n)); }
#line 4477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1635 "ANSI-C.y" /* yacc.c:1646  */
    {
	       Node *decl;
	       decl = SetDeclType((yyvsp[0].n), (yyvsp[-1].n), Redecl);  
	       newfunc(decl);

               AddParameterTypes(decl, NULL);
               (yyvsp[0].n) = DefineProc(TRUE, decl);
            }
#line 4490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1644 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-2].n), (yyvsp[0].n)); }
#line 4496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1646 "ANSI-C.y" /* yacc.c:1646  */
    {
	      Node *decl;
	      decl = SetDeclType((yyvsp[0].n), (yyvsp[-1].n), Redecl);
	      newfunc(decl);

              AddParameterTypes(decl, NULL);
              (yyvsp[0].n) = DefineProc(TRUE, decl);
            }
#line 4509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1655 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-2].n), (yyvsp[0].n)); }
#line 4515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1657 "ANSI-C.y" /* yacc.c:1646  */
    {
	      Node *type, *decl;
	      type == MakeDefaultPrimType((yyvsp[-1].tq).tq, (yyvsp[-1].tq).coord);
              decl = SetDeclType((yyvsp[0].n), type, Redecl);
	      newfunc(decl);

              AddParameterTypes(decl, NULL);
              (yyvsp[0].n) = DefineProc(TRUE, decl);
            }
#line 4529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1667 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-2].n), (yyvsp[0].n)); }
#line 4535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1669 "ANSI-C.y" /* yacc.c:1646  */
    {
	      Node *type, *decl;
	      type = MakeDefaultPrimType((yyvsp[-1].tq).tq, (yyvsp[-1].tq).coord);
	      decl = SetDeclType((yyvsp[0].n), type, Redecl);
	      newfunc(decl);

              AddParameterTypes(decl, NULL);
              (yyvsp[0].n) = DefineProc(TRUE, decl);
            }
#line 4549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1679 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-2].n), (yyvsp[0].n)); }
#line 4555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1681 "ANSI-C.y" /* yacc.c:1646  */
    {
	      Node *type, *decl;
	      type = MakeDefaultPrimType(EMPTY_TQ, (yyvsp[-1].n)->coord);
	      decl = SetDeclType((yyvsp[-1].n), type, Redecl);
	      newfunc(decl);

              AddParameterTypes(decl, (yyvsp[0].L));
              (yyvsp[-1].n) = DefineProc(TRUE, decl);
            }
#line 4569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1691 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-3].n), (yyvsp[0].n)); }
#line 4575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1693 "ANSI-C.y" /* yacc.c:1646  */
    {
	      Node *decl;
	      decl = SetDeclType((yyvsp[-1].n), (yyvsp[-2].n), Redecl);
	      newfunc(decl);

              AddParameterTypes(decl, (yyvsp[0].L));
              (yyvsp[-1].n) = DefineProc(TRUE, decl);
            }
#line 4588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1702 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-3].n), (yyvsp[0].n)); }
#line 4594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1704 "ANSI-C.y" /* yacc.c:1646  */
    {
	      Node *decl;
	      decl = SetDeclType((yyvsp[-1].n), (yyvsp[-2].n), Redecl);
	      newfunc(decl);

              AddParameterTypes(decl, (yyvsp[0].L));
              (yyvsp[-1].n) = DefineProc(TRUE, decl);
            }
#line 4607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1713 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-3].n), (yyvsp[0].n)); }
#line 4613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1715 "ANSI-C.y" /* yacc.c:1646  */
    {
	      Node *type, *decl;
	      type = MakeDefaultPrimType((yyvsp[-2].tq).tq, (yyvsp[-2].tq).coord);
	      decl = SetDeclType((yyvsp[-1].n), type, Redecl);
	      newfunc(decl);

              AddParameterTypes(decl, (yyvsp[0].L));
              (yyvsp[-1].n) = DefineProc(TRUE, decl);
            }
#line 4627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1725 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-3].n), (yyvsp[0].n)); }
#line 4633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1727 "ANSI-C.y" /* yacc.c:1646  */
    {
	      Node *type, *decl;
	      type = MakeDefaultPrimType((yyvsp[-2].tq).tq, (yyvsp[-2].tq).coord);
	      decl = SetDeclType((yyvsp[-1].n), type, Redecl);
	      newfunc(decl);
   

              AddParameterTypes(decl, (yyvsp[0].L));
              (yyvsp[-1].n) = DefineProc(TRUE, decl);
            }
#line 4648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1738 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = SetProcBody((yyvsp[-3].n), (yyvsp[0].n)); }
#line 4654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1743 "ANSI-C.y" /* yacc.c:1646  */
    { OldStyleFunctionDefinition = TRUE; }
#line 4660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1745 "ANSI-C.y" /* yacc.c:1646  */
    { OldStyleFunctionDefinition = FALSE; 
               (yyval.L) = (yyvsp[0].L); }
#line 4667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1760 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); checkconst((yyvsp[0].n));}
#line 4673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1761 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); checkconst((yyvsp[0].n));}
#line 4679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1762 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); checkconst((yyvsp[0].n));}
#line 4685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1763 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); checkconst((yyvsp[0].n));}
#line 4691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1764 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); checkconst((yyvsp[0].n));}
#line 4697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1769 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 4703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1771 "ANSI-C.y" /* yacc.c:1646  */
    { const char *first_text  = (yyvsp[-1].n)->u.Const.text;
              const char *second_text = (yyvsp[0].n)->u.Const.text;
              int   length = strlen(first_text) + strlen(second_text) + 1;
              char *buffer = HeapNewArray(char, length);
              char *new_text, *new_val;
	
              /* since text (which includes quotes and escape codes)
		 is always longer than value, it's safe to use buffer
		 to concat both */
              strcpy(buffer, NodeConstantStringValue((yyvsp[-1].n)));
	      strcat(buffer, NodeConstantStringValue((yyvsp[0].n)));
              new_val = UniqueString(buffer);

              strcpy(buffer, first_text);
	      strcat(buffer, second_text);
              new_text = buffer;
              (yyval.n) = MakeStringTextCoord(new_text, new_val, (yyvsp[-1].n)->coord);
	     }
#line 4726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1792 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = T_CONST;    (yyval.tq).coord = (yyvsp[0].tok); }
#line 4732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1793 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = T_VOLATILE; (yyval.tq).coord = (yyvsp[0].tok); }
#line 4738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1794 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = T_INLINE;   (yyval.tq).coord = (yyvsp[0].tok); }
#line 4744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1798 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = T_CONST;    (yyval.tq).coord = (yyvsp[0].tok); }
#line 4750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1799 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = T_VOLATILE; (yyval.tq).coord = (yyvsp[0].tok); }
#line 4756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1803 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = T_TYPEDEF;  (yyval.tq).coord = (yyvsp[0].tok); }
#line 4762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1804 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = T_EXTERN;   (yyval.tq).coord = (yyvsp[0].tok); }
#line 4768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1805 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = T_STATIC;   (yyval.tq).coord = (yyvsp[0].tok); }
#line 4774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1806 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = T_AUTO;     (yyval.tq).coord = (yyvsp[0].tok); }
#line 4780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1807 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.tq).tq = T_REGISTER; (yyval.tq).coord = (yyvsp[0].tok); }
#line 4786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1811 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = StartPrimType(Void, (yyvsp[0].tok));    }
#line 4792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1812 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = StartPrimType(Char, (yyvsp[0].tok));  checktype(Char, "char");   }
#line 4798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1813 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = StartPrimType(Int_ParseOnly, (yyvsp[0].tok));     }
#line 4804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1814 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = StartPrimType(Float, (yyvsp[0].tok)); checktype(Float, "float");  }
#line 4810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 396:
#line 1815 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = StartPrimType(Double, (yyvsp[0].tok));  checktype(Double, "double"); }
#line 4816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 1817 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = StartPrimType(Signed, (yyvsp[0].tok));   }
#line 4822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 398:
#line 1818 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = StartPrimType(Unsigned, (yyvsp[0].tok)); checktype(Unsigned, "unsigned"); }
#line 4828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 399:
#line 1820 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = StartPrimType(Short, (yyvsp[0].tok));  checktype(Short, "short"); }
#line 4834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 400:
#line 1821 "ANSI-C.y" /* yacc.c:1646  */
    { (yyval.n) = StartPrimType(Long, (yyvsp[0].tok)); }
#line 4840 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4844 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1824 "ANSI-C.y" /* yacc.c:1906  */

/* ----end of grammar----*/


PRIVATE void WarnAboutPrecedence(OpType op, Node *node)
{
  if (node->typ == Binop && !node->parenthesized) {
    OpType subop = node->u.binop.op;

    if (op == OROR && subop == ANDAND)
      WarningCoord(4, node->coord, "suggest parentheses around && in operand of ||");
    else if ((op == '|' || op == '^') && 
	     (subop == '+' || subop == '-' || subop == '&' || subop == '^') &&
	     op != subop)
      WarningCoord(4, node->coord, "suggest parentheses around arithmetic in operand of %c", op);
  }
}


