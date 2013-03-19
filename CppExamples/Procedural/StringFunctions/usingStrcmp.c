#include <stdio.h>
#include <string.h>

void demoStrcmp(const char * p1, const char * p2) {
    int retval = strcmp(p1,p2);
    if(retval > 0) {
        printf("First string is greater\n");
    } else if(retval < 0) {
        printf("Second string is greater\n");
    } else {
        printf("Strings are equal\n");
    }
}
int main() {
    const char * str1 = "abcdef";
    const char * str2 = "abcdef";
    const char * str3 = "abcefg";

    demoStrcmp(str1,str2);
    demoStrcmp(str2,str3);
    demoStrcmp(str3,str2);
}