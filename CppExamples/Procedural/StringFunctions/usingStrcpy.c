#include <stdio.h>
#include <string.h>

void demoStrcpy(char * p1, const char * p2) {
    strcpy(p1,p2);
    printf("%s\n", p1);
}
int main() {
    const char * str1 = "cdef";
    const char * str2 = "ghij";
    const char * str3 = "klmn";
    const char * str4 = "opqr";
    const char * str5 = "stuv";
    const char * str6 = "wxyz";

    char buffer[] = {'a','b','a','b','\0'};

    printf("%s\n",buffer);

    demoStrcpy(buffer,str1);
    demoStrcpy(buffer,str2);
    demoStrcpy(buffer,str3);
    demoStrcpy(buffer,str4);
    demoStrcpy(buffer,str5);
    demoStrcpy(buffer,str6);
}