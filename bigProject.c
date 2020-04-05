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
char enterLetter();
int gameOver();

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
        hangState(0);
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
    int solved;

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

    if(6-incor == 0){
        printf("You have used up all of your guesses. Game over!");
        exit(0);
        //solved = 1;
        //printf("This is the assigned integer %d",solved);
        //gameOver(state[incor][y]);
    }
}


int playGame(char show[]){
    
    int length,x,y,solve=0,newlength,count=0,wrong=0,letterlength=0;
    char guesses[26]={""};
    length=strlen(show)-1;
    printf("%s\n",show);
    while(solve!=1){
        letterlength=0;
        wrong=0;
        guesses[count]=enterLetter(guesses,newlength);    
        newlength=strlen(guesses);
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
                    letterlength++;
            }
        } 

        for(x=0;x<newlength;x++){
            for(y=0;y<length;y++){ 
                //printf("guessletter %c, show letter %c\n",guesses[x],show[y]);
                if(guesses[x]==show[y])
                    break; 
                else if(y<length-1)
                    continue;
                else{
                    //printf("wrong guess %c\n",guesses[x]);
                    wrong=wrong+1;
                }
            }
        }


        printf("wrong guesses %d\n",wrong);
        hangState(wrong);
        count=count+1;

        if (letterlength == 0){
            printf("\n\nWinner!\n");
            gameOver(guesses,show);
        }
        
    }
return 0;
}


char enterLetter(char *guess,int len){
    int x,reuse=0,guessLength;
    char input;
    guessLength=strlen(guess);
    printf("Guessed Letters: ");
    for(x=0;x<guessLength;x++)
        printf("%c ",guess[x]);
    printf("\n");
    printf("Enter a lower case letter: ");
    scanf("%*c%c",&input);              //reading in the new line character

    for(x=0;x<guessLength;x++){
        if(input==guess[x])
            reuse=1;
        else if(x<guessLength)
            continue;
        else
            reuse=0;
    }

    while((input<97 || input>122) || reuse==1){
        printf("Invalid Input. Try again.Enter a lower case letter: ");
        scanf("%c",&input);
        for(x=0;x<guessLength;x++){
            if(input==guess[x])
                reuse=1;
            else if(x<guessLength-1)
                continue;
            else
                reuse=0;
        }
    
    }

return input;

}


int gameOver(char guesses[], char show[]){
    printf("Secret movie title: %s", show);
    printf("These were all of your guesses: %s\n", guesses);
    //printf("Here is what your man looks like\n %s",state[incor][y]);
    exit(0);
}

