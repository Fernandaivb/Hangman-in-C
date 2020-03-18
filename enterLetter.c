#include <stdio.h>
#include <ctype.h>
#include <strings.h>

#define ATTEMPT 3

int main(){
    char str[ATTEMPT];
    char max[100];
    int x;
    char userInput;

    char c='*';
    int d; //d = duplicate;
    int r; // r = remove;


    for (x=0; x<ATTEMPT; x++){      //scans and conversts upper case characters to lower
        printf(" Enter character: ");
        int rc = scanf("%s", max);
        userInput= tolower(max[0]);
        str[x] = userInput;
    }
    
    for (x=0; x<ATTEMPT; x++){  //detects repeated characters
        if(!(str[x]==c)){
            for(d=x+1; str[d];d++){
                if(str[x] == str[d])
                    str[d]=c;
            }
	    }
    }
    
    /*for (x=0; x<ATTEMPT; x++){
        str[x]=str[x+r];
        if (str[x] == c){
            r++;
            x--;
        }
    }*/
    //str[ATTEMPT] = 0;

    printf(" %s", str);
}
