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
//int enterLetter();
//int gameOver();

int userIn;
int main(){
    startGame();
    if(userIn==1){                                                                      //this is lets the user choose the phrase to guess
        char custom[100];
        printf("What would you like the phrase to be:");    
        scanf("%s",custom);
        hangState();
        //playgame(custom)
    }
    else if(userIn==2){   
        printf("These are movies from 2019\n");                                 
        //hangState();
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
    char movie[]="";
    char wordList[10][200];
    int randomPosition, counter=0;
    FILE * movies;
    movies = fopen( "words.txt" , "r" );
    
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


int playGame(char show[]){
    
    int length,x,y,solve=0,newlength,compare;
    char guessLength[6]={"abcde"};
    length=strlen(show)-1;
    newlength=strlen(guessLength)-1;
    printf("new len %d\n",newlength);
    while(solve!=1){
        for(y=0;y<length;y++){
            for(x=0;x<newlength;x++){          //for loops for each character in the answer
                compare=strcmp(show[y],guessLength[x]);
                if(compare==0)
                    printf("%c",show[x]);   
                
                
    
            }
        }
    }
}
/*
int enterLetter(){


}

int gameOver(){

}
*/


