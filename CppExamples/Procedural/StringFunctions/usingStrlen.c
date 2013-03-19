#include <stdio.h>
#include <string.h>

void demoStrlen(const char * p1) {
    int length  = strlen(p1);
    printf("String length is: %d\n", length);
}
int main() {
    const char * str1 = "ab";
    const char * str2 = "abcd";
    const char * str3 = "abcdef";
    const char * str4 = "abcdefgh";
    const char * str5 = "abcdefghij";
    const char * str6 = "abcdefghijkl";
    const char * str7 = "abcdefghijklmn";
    const char * str8 = "abcdefghijklmnop";
    const char * str9 = "abcdefghijklmnopqr";
    const char * str10 = "abcdefghijklmnopqrst";
    const char * str11 = "abcdefghijklmnopqrstuv";
    const char * str12 = "abcdefghijklmnopqrstuvwx";
    const char * str13 = "abcdefghijklmnopqrstuvwxyz";

    demoStrlen(str1);
    demoStrlen(str2);
    demoStrlen(str3);
    demoStrlen(str4);
    demoStrlen(str5);
    demoStrlen(str6);
    demoStrlen(str7);
    demoStrlen(str8);
    demoStrlen(str9);
    demoStrlen(str10);
    demoStrlen(str11);
    demoStrlen(str12);
    demoStrlen(str13);
}