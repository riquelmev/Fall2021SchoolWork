/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 211 "ANSI-C.y" /* yacc.c:1909  */

    Node      *n;
    List      *L;

  /* tq: type qualifiers */
    struct {
        TypeQual   tq;
	Coord      coord;   /* coordinates where type quals began */ 
    } tq;

  /* tok: token coordinates */
    Coord tok;

#line 220 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
