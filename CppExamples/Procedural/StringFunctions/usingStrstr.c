#include <stdio.h>
#include <string.h>

int distance(const char * p1, const char * p2) {
    int count = 0;
    while(p1 != p2) {
        count++;
        p1++;
    }
    return count;
}
int main() {
    const char * data = "abcdefxyzghijklxyzmnopqrxyzuvwxyz";

    char * str = strstr(data,"xyz");
    printf("Distance to first substring is: %i\n", distance(data,str));
}