#include <stdio.h>
#include <string.h>

int main() {
    const char * dataOne = "abcdefabcdefabcdefZ";
    const char * dataTwo = "bcdfghjklmnapqrstevwxyiz";
    const char * vowels = "aeiou";
	
    for(int i=0;i<18;i++) {
        printf("Span length to Z is: %i\n", strspn(dataOne + i, "abcdef"));
    }
    printf("------------------------\n");
    printf("Span length to first vowel is: %i\n", strcspn(dataTwo,vowels));
    printf("The first vowel is: %i\n", strpbrk(dataTwo,vowels)[0]);
}