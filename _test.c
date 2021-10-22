#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s1[3];
    char s2[5];
    s1[0] = 'a';
    s1[1] = 'b';
    s2[0] = 'a';
    s2[1] = 'b';
    printf("%d", strcmp(s1,"abc"));
    memset(s1, 0, sizeof(s1));
    printf("%s", s1);
    return 0; 
}

