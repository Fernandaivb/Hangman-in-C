/****************************************************************************************************************************
*File: bigProject.c
*Names: Kearsten Crocker, Blake Webber, Fernanda Villafana Benitez
*Resources: 
****************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void hangState();
int startGame();                                                                        
char randomWord();
int playGame();
char* enterLetter();
//int gameOver();

int userIn;
int main(){
    startGame();
    if(userIn==1){                                                                      //this is lets the user choose the phrase to guess
        char custom[100];
        printf("What would you like the phrase to be:");    
        scanf("%s",custom);
        //hangState();
        playGame(custom);
    }
    else if(userIn==2){   
        printf("These are movies from 2019\n");                                 
        hangState();
        randomWord();
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
            scanf("%s",check);                                                         //checks for int/char in the while loop
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

char randomWord(){                      //This function is used when there is one player.
    char wordList[10][200];
    int randomPosition, counter=0;
    FILE * movies;
    movies = fopen( "words.txt" , "r" );    //Make sure you have words.txt in same file location
    
    while (fgets(wordList[counter],200, movies )){
           // printf(" This is a test to print the file... %s\n", wordList[counter]);// This shows that the file is read into the array wordList
            ++counter;
    }
    
    srand(time(NULL));
    randomPosition=rand()%10;
    //printf("from word list %s", wordList[randomPosition]);
    playGame(wordList[randomPosition]);
    return 0;
}


void hangState(int incor){

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

    int y;
    for(y=0;y<8;y++)
        printf("%s",state[incor][y]);        
    printf("You have %d incorrect guesses left.\n",6-incor);
    
}


int playGame(char show[]){
    
    int length,x,y,solve=0,newlength,compare;
    char guesses[]={"abcd"};
    length=strlen(show)-1;
    newlength=strlen(guesses);
    //printf("len %d\n",length);
    //printf("new len %d\n",newlength);
    printf("%s\n",show);
    //enterLetter(guesses,newlength);
    while(solve!=1){
        for(y=0;y<length;y++){
            for(x=0;x<newlength;x++){          //for loops for each character in the answer

                if(show[y]==32){
                    printf("%c ",show[y]);
                    break;
                }
                else if(show[y]==guesses[x]){
                    printf("%c ",show[y]);
                    break;
                }
                else if(x<newlength-1)
                    continue;
                else
                    printf("_ ");
                  
            }
        }
    //enterLetter(guesses);
    printf("\n");
    break;      //Remove this when testing is done
    }
return 0;
}

/*
char* enterLetter(char *guess,int len){
    int x,reuse,guessLength;
    char input;
    printf("hi");
    guessLength=strlen(guess);
    printf("hi");
    printf("Guessed Letters: ");
    for(x=0;x<guessLength;x++)
        printf("%c ",guess[x]);
    printf("Enter a lower case letter: ");
    scanf("%c",input);

    for(x=0;x<guessLength;x++){
        if(input==guess[x])
            reuse=1;
        else if(x<guessLength)
            continue;
        else
            reuse=0;
    }

    while((input<97 && input>122) || reuse==1){
        printf("Invalid Input. Try again.Enter a lower case letter: ");
        scanf("%c",input);

        for(x=0;x<guessLength;x++){
            if(input==guess[x])
                reuse=1;
            else if(x<guessLength)
                continue;
            else
                reuse=0;
        }
    
    }

char* ret = input;
return ret;

}

*/
/*
int gameOver(){

}
*/


