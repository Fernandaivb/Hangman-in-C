/****************************************************************************************************************************
*File: bigProject.c
*Names: Kearsten Crocker, Blake Webber, Fernanda Villafana Benitez
****************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void hangState();
char randomWord();
int playGame();
char enterLetter();
int gameOver();

int main(){
    system("clear");
    FILE *fp;
    char str[500];
    char* filename = "title.txt";       //Make sure you have title.txt in same file location
    fp = fopen(filename, "r");
    if (fp == NULL)
        printf("Could not open file %s",filename);
    while (fgets(str, 500, fp) != NULL)
        printf("%s", str);
    fclose(fp);

    printf("These are movies from 2019\n");                                 
    hangState(0);
    randomWord();
return 0;
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
    if(6-incor == 0){
        printf("You have used up all of your guesses. Game over!\n");
        exit(0);
    }
}


int playGame(char show[]){
    
    int showLength,x,y,solve=0,guessLength,count=0,wrong=0,letterLength=0;
    char guesses[26]={""};
    //printf("%s\n",show);
    showLength=strlen(show)-1;
    for(y=0;y<showLength;y++){
        if(show[y]==32)
            printf("%c ",show[y]);
        else
        printf("_ ");
    }
    printf("\n");
    while(solve!=1){
        letterLength=0;
        wrong=0;
        guesses[count]=enterLetter(guesses,guessLength);
        guessLength=strlen(guesses);
        for(y=0;y<showLength;y++){
            for(x=0;x<guessLength;x++){          //for loops for each character in the answer
            
                if(show[y]==32){
                    printf("%c ",show[y]);
                    break;
                }
                else if(show[y]==guesses[x]){
                    printf("%c ",show[y]);
                    break;
                }
                else if(x<guessLength-1)
                    continue;
                else{
                    printf("_ ");
                    letterLength++;
                }
            }
        } 

        for(x=0;x<guessLength;x++){
            for(y=0;y<showLength;y++){ 
                //printf("guessletter %c, show letter %c\n",guesses[x],show[y]);
                if(guesses[x]==show[y])
                    break; 
                else if(y<showLength-1)
                    continue;
                else{
                    //printf("wrong guess %c\n",guesses[x]);
                    wrong=wrong+1;
                }
            }
        }


       // printf("wrong guesses %d\n",wrong);
        printf("\n");
        hangState(wrong);
        count=count+1;
        if (letterLength == 0){
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
    scanf("%c%*c",&input);              //reading in the new line character

    for(x=0;x<guessLength;x++){
        if(input==guess[x]){
            reuse=1;
            break;
        }
        else if(x<guessLength-1)
            continue;
        else
            reuse=0;
    }

    while((input<97 || input>122) || reuse==1){
        printf("Invalid Input. Try again.\n");
        printf("Enter a lower case letter: ");
        scanf("%c%*c",&input);
        for(x=0;x<guessLength;x++){
            if(input==guess[x]){
                reuse=1;
                break;
            }
            else if(x<guessLength-1)
                continue;
            else
                reuse=0;
        }

    }
    system("clear");
return input;

}


int gameOver(char guesses[], char show[]){
    printf("Secret movie title: %s", show);
    printf("These were all of your guesses: %s\n", guesses);
    //printf("Here is what your man looks like\n %s",state[incor][y]);
    exit(0);
}



