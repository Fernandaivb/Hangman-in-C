/****************************************************************************************************************************
*File: bigProject.c
*Names: Kearsten Crocker, Blake Webber, Fernanda Villafana Benitez
*Resources: 
****************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define ATTEMPT 3

void hangState();
int startGame();                                                                        
//char randomWord();
//int playGame();
int enterLetter();
//int gameOver();

int userIn;
int main(){
    startGame();
    if(userIn==1){                                                                      //this is lets the user choose the phrase to guess
        char custom[100];
        printf("What would you like the phrase to be:");    
        scanf("%s",&custom);
        enterLetter();
        hangState();
        //playgame(custom)
    }
    else if(userIn==2){   
        printf("These are movies from 2019\n");                                 
        // randomWord();
        hangState();
    }

return 0;
}

int startGame(){
    char check[100];                                                                    //variable used to check that the input isn't a character
    printf("Welcome to hangman!\n");
    printf("Would you like to choose the phrase(1) or use a premade(2):");
    int rc=scanf("%d",&userIn);                                                         //rc checks to see if the input is a integer or character
    while((userIn!=1 &&  userIn!=2) || rc!=1){                                          //keeps the user in the while statement until they enter 1 or 2
        if(rc==0){
            scanf("%s",&check);                                                         //checks for int/char in the while loop
            printf("Invalid input\n");
            printf("Would you like to choose the phrase(1) or use a premade(2):");
            rc=scanf("%d", &userIn);
        }
        else{
            printf("Invalid input\n");
            printf("Would you like to choose the phrase(1) or use a premade(2):");
            rc=scanf("%d", &userIn);
        }
    }    
return userIn;
}
/*
char randomWord(){
}
*/
void hangState(){

    char state[8][8][20]=
{{  "  +---+ \n",
    "  |   | \n",   
    "      | \n",
    "      | \n",
    "      | \n",
    "      | \n",
    " ============ \n"},
{   "  +---+ \n",
    "  |   | \n",
    "  o   | \n",
    "      | \n",
    "      | \n",
    "      | \n",
    " ============ \n"},
{   "  +---+\n",
    "  |   | \n",
    "  o   | \n",
    "  |   | \n",
    "      | \n",
    "      | \n",
    " ============ \n"},
{   "  +---+\n",
    "  |   | \n",
    "  o   | \n",
    " /|   | \n",
    "      | \n",
    "      | \n",
    " ============ \n"},
{   "  +---+\n",
    "  |   | \n",
    "  o   | \n",
    " /|\\  | \n",
    "      | \n",
    "      | \n",
    " ============ \n"},
{   "  +---+\n",
    "  |   | \n",
    "  o   | \n",
    " /|\\  | \n",
    " /    | \n",
    "      | \n",
    " ============ \n"},
{   "  +---+\n",
    "  |   | \n",
    "  o   | \n",
    " /|\\  | \n",
    " / \\  | \n",
    "      | \n",
    " ============ \n"}};

    int y,z;
    for(y=0;y<7;y++){
        for(z=0;z<7;z++)
            printf("%s",state[y][z]);
    
        printf("You have %d incorrect guesses left.\n",6-y);
    }
   // playGame();
}

int enterLetter(){
    char str[ATTEMPT];
    char max[100];
    int x;
    char userInput;

    char c='*';
    int d; //d = duplicate;
    int r=0; // r = remove;


    for (x=0; x<ATTEMPT; x++){      //scans and conversts upper case characters to lower
        printf(" Guess a character: ");
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
    
    for (x=0; x<ATTEMPT; x++){	//Ensures repeated letters are not stored in the array
        str[x]=str[x+r];
        if (str[x] == c){
            printf("Don't guess the same letter more than once.\n");
            r++;
            x--;
        }
    }
    printf(" %s\n", str); //array of characters
}
/*
int playGame(){
}
int gameOver(){
}
*/
