#include <stdio.h>
#include <string.h>

void demoStrcat(char * p1, const char * p2) {
    strcat(p1,p2);
    printf("%s\n", p1);
}
int main() {
    const char * str1 = "cdef";
    const char * str2 = "ghij";
    const char * str3 = "klmn";
    const char * str4 = "opqr";
    const char * str5 = "stuv";
    const char * str6 = "wxyz";

    char buffer[27];
    buffer[0] = 'a';
    buffer[1] = 'b';
    buffer[2] = '\0';

    printf("%s\n", buffer);

    demoStrcat(buffer,str1);
    demoStrcat(buffer,str2);
    demoStrcat(buffer,str3);
    demoStrcat(buffer,str4);
    demoStrcat(buffer,str5);
    demoStrcat(buffer,str6);
}
