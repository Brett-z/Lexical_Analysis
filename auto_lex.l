%{
#include <stdio.h>
#include <stdlib.h>

int constant = 0;
int operator = 0;
int border = 0;
int identifier = 0;
int keyWord = 0;

%}

INTERGER    [0-9]
OCTALCONS   0[0-7]+
HEXCONS     0[xX][0-9a-fA-F]+
OPERATOR    [\+\-\*\/\%\<\>\!\=\&\|]
BORDER      [\(\)\{\}\"\'\[\]\;\,]
BOOLEAN     (true)|(false)
NOTE_S      \/\/(.)*\n
NOTE_M      \/\*(.|\n)*?\*\/
IDENTIFIER [_a-zA-Z][_a-zA-Z0-9]*


%%

"int"                       {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"main"                      {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"continue"                  {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"const"                     {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"else"                      {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"if"                        {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"double"                    {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"float"                     {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"return"                    {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"void"                      {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"while"                     {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"enum"                      {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"switch"                    {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"case"                      {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"for"                       {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"sizeof"                    {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"static"                    {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"typedef"                   {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"short"                     {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"break"                     {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"do"                        {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"struct"                    {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"signed"                    {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"unsigned"                  {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"default"                   {keyWord ++; printf("<%s   keyWord>\n",yytext);}
"char"                      {keyWord ++; printf("<%s   keyWord>\n",yytext);}
{NOTE_S}*                   {printf("@@@_note distinguished :%s\n",yytext);}
{NOTE_M}*                   {printf("@@@_note distinguished :%s\n",yytext);}
{INTERGER}+"."*{INTERGER}* 	{constant ++; printf("<%s   constant>\n",yytext);}
{OCTALCONS}                 {constant ++; printf("<%s   constant>\n",yytext);}
{HEXCONS}                   {constant ++; printf("<%s   constant>\n",yytext);}
{BOOLEAN}                   {constant ++; printf("<%s   constant>\n",yytext);}
{OPERATOR}+               	{operator ++; printf("<%s   operator>\n",yytext);}
{BORDER}                    {border ++; printf("<%s   border>\n",yytext);}
{IDENTIFIER}                {identifier++; printf("<%s   identifier>\n",yytext);}


%%

int yywrap(){
    return 1;
}

void main(int argc, char **argv){
    yylex();

    printf("constant: %8d\n", constant);
    printf("operator: %8d\n", operator);
    printf("border: %8d\n", border);
    printf("identifier: %8d\n", identifier);
    printf("keyWord: %8d\n", keyWord);
    
}
