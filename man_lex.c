/**
	************************************************************
	************************************************************
	*	作者： 		曾彬芮
	* 
	*	日期： 		2021-10-22
	*
	*	版本： 		V1.0
	*
	*	说明： 		词法分析器
	************************************************************
	************************************************************
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 能识别的最长标识符
#define MAX_LEN_STRING  50

// 全局变量
int constant = 0;
int operator = 0;
int border = 0;
int identifier = 0;
int keyWord = 0;

int constantAnalyze(char file[], int size);
int operatorAnalyze(char file[], int size);
int borderAnalyze(char file[], int size);
// stringAnalyze 包含对标识符和关键字的分析
void stringAnalyze(char file[], int size);

// int constantAnalyze(char file[], int size){
//     int num = 0;

//     return num;
// }

int operatorAnalyze(char file[], int size){
    int num = 0, count = 0;
    while(count<size){
        switch (file[count])
        {
        // [\+\-\*\/\%\==\!=\<\>\<=\>=\+=\-=\*=\/=\!\&&\||\=\>>\<<]
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
        case '!':
        case '>':
        case '<':
        case '&':
        case '|':
        num++; count++;
        if(file[count]=='='||file[count]=='&'||file[count]=='|'||file[count]=='>'||file[count]=='<'){
            count ++;
            printf("<%c%c  operator>\n", file[count-2], file[count-1]);
        }else{
            printf("<%c  operator>\n", file[count-1]);
        }break;
        default:count++;break;
        }
    }
    return num;
}

int borderAnalyze(char file[], int size){
    int num = 0, count = 0;
    while(count<size){
        switch (file[count])
        {
        // [\(\)\{\}\"\'\[\]\;\,]
        case '\\':
        case '(':
        case ')':
        case '{':
        case '}':
        case '\"':
        case '\'':
        case '[':
        case ']':
        case ';':
        case ',':
        num++; count++;
        printf("<%c  border>\n", file[count-1]);
        break;
        default:count++;break;
        }
    }
    return num;
}

void stringAnalyze(char file[], int size){
    // identifier用于存放标识符数量； keyWord用于存放关键字数量 -- 全局变量
    char string[MAX_LEN_STRING];
    int count = 0, store = 0, c_past, c_now=0, ifJudge = 0;
    int hasNum;
    while(count<size)
    {
        while(((file[count]>='a'&& file[count]<='z') || (file[count]>='A'&& file[count]<='Z') || file[count]=='_'))
        {
            string[store] = file[count];
            store++; count++;
            // 标识符除第一位以外，其他位可以为数字
            while(file[count]>='0' && file[count]<='9'){
                string[store] = file[count];
                store++; count++;
            }
            ifJudge = 1;
        }
        hasNum = 0;
        if(ifJudge==1)
        {
            // 判断是否为关键字
            c_past = c_now;
            if(strcmp(string, "int")==0) c_now ++;
            if(strcmp(string, "main")==0) c_now ++;
            if(strcmp(string, "continue")==0) c_now ++;
            if(strcmp(string, "const")==0) c_now ++;
            if(strcmp(string, "else")==0) c_now ++;
            if(strcmp(string, "if")==0) c_now ++;
            if(strcmp(string, "double")==0) c_now ++;
            if(strcmp(string, "float")==0) c_now ++;
            if(strcmp(string, "return")==0) c_now ++;
            if(strcmp(string, "void")==0) c_now ++;
            if(strcmp(string, "while")==0) c_now ++;
            if(strcmp(string, "enum")==0) c_now ++;
            if(strcmp(string, "switch")==0) c_now ++;
            if(strcmp(string, "case")==0) c_now ++;
            if(strcmp(string, "for")==0) c_now ++;
            if(strcmp(string, "sizeof")==0) c_now ++;
            if(strcmp(string, "static")==0) c_now ++;
            if(strcmp(string, "typeof")==0) c_now ++;
            if(strcmp(string, "short")==0) c_now ++;
            if(strcmp(string, "break")==0) c_now ++;
            if(strcmp(string, "do")==0) c_now ++;
            if(strcmp(string, "struct")==0) c_now ++;
            if(strcmp(string, "signed")==0) c_now ++;
            if(strcmp(string, "unsigned")==0) c_now ++;
            if(strcmp(string, "default")==0) c_now ++;
            if(strcmp(string, "char")==0) c_now ++;
            // 测试用
            // printf("@@past %d now %d\n", c_past, c_now);
            if(c_now!=c_past){
                keyWord ++;
                printf("<%s  KeyWord>\n", string);
            }else{
                identifier++;
                printf("<%s identifier>\n", string);
            }
            memset(string, 0, sizeof(string));
            store = 0;
        }
        ifJudge = 0; c_now = c_past = 0;
        count++;
    }
}

int main(int argc, char ** argv)
{

    int cur;
    FILE *fp = fopen(argv[1],"r");

    // 获得文件的大小
    fseek(fp,0L,SEEK_END);
    int filesize = ftell(fp);
    char fileString[filesize];

    // 重定向，使指针重新指向文件头
    rewind(fp);
    printf("File size is: %d\n",filesize);
    
    // 将文件中的字符串复制给fileString
    for(cur=0; cur < filesize; cur++){
        fscanf(fp,"%c",&fileString[cur]);
    }

    // 测试--是否能正确读取文件的内容
    // for(cur=0; cur < filesize; cur++){
    //     printf("%c", fileString[cur]);
    // }

    fclose(fp);

    // 调用函数计算每个量的值
    // constant = constantAnalyze(fileString, filesize);
    operator = operatorAnalyze(fileString, filesize);
    border = borderAnalyze(fileString, filesize);
    stringAnalyze(fileString, filesize);

    // printf("constant_num is : %d\n", constant);
    printf("operator_num is : %d\n", operator);
    printf("border_num is : %d\n", border);
    printf("identifier_num is : %d\n", identifier);
    printf("keyWord_num is : %d\n", keyWord);
    
    return 0;
}
