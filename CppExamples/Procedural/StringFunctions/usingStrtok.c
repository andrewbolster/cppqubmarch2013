#include <stdio.h>
#include <string.h>

int main() {
    char buffer[36];
    strcpy(buffer,"abc#def!ghi~jkl!mno#pqr!stu~vwz!yza");

    printf("Tokens are:\n");
    char * str = strtok(buffer,"#!~");
    while(str != 0) {
        printf("\t%s\n", str);
        str = strtok(0,"#!~");
    }
}