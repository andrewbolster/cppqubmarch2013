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
void demoStrchr(const char * p1, char p2) {
    char * first_pos = strchr(p1,p2);
    char * last_pos = strrchr(p1,p2);

    printf("First instance of %c at %d\n", p2, distance(p1,first_pos));
    printf("Last instance of %c at %d\n", p2, distance(p1,last_pos));
    printf("\n-------------------------\n");
}
int main() {
    const char * str = "abcdeffedcba";
    demoStrchr(str,'a');
    demoStrchr(str,'b');
    demoStrchr(str,'c');
    demoStrchr(str,'d');
    demoStrchr(str,'e');
    demoStrchr(str,'f');
}
