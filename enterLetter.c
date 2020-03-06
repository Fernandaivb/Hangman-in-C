#include <stdio.h>
#include <ctype.h>
#include <strings.h>

#define ATTEMPT 3

int main(){
    char str[ATTEMPT + 1]; // +1 is for the NULL character
    char max[100];
    int x;
    char userInput;

    for (x=0; x<ATTEMPT; x++){
        printf(" Enter character: ");
        int rc = scanf("%s", max);
        userInput= tolower(max[0]);
        str[x] = userInput;
    }    
    //str[ATTEMPT] = 0;
    printf(" %s", str);
}
