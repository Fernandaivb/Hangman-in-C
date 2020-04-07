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
char randomWord();
int playGame();
char enterLetter();
int gameOver();

int main(){
    system("clear");
    FILE *welcome;                      //This file contains the word art that welcomes the user
    char str[500];
    char* filename = "title.txt";       //Make sure you have title.txt in same file location
    welcome = fopen(filename, "r");
    if (welcome == NULL)
        printf("Could not open file %s",filename);
    while (fgets(str, 500, welcome) != NULL)
        printf("%s", str);
    fclose(welcome);

    printf("These are movies from 2019\n");                                 
    hangState(0);
    randomWord();
return 0;
}


char randomWord(){                      //This function reads in a word list from a file and randomly chooses a word
    char wordList[10][200];
    int randomPosition, counter=0;
    FILE * movies;
    movies = fopen( "words.txt" , "r" );    //Make sure you have words.txt in same file location
    
    while (fgets(wordList[counter],200, movies )){
            ++counter;
    }
    
    srand(time(NULL));
    randomPosition=rand()%10;
    playGame(wordList[randomPosition]);
    return 0;
}


void hangState(int incor){              //This function uses a three dimentional array to hold and call all the different hang states that could happen through out the game
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
    if(6-incor == 0){                                                       //If the user has too many incorrect guesses this if statement runs telling them they lost the game
        printf("You have used up all of your guesses. Game over!\n");
        exit(0);
    }
}


int playGame(char show[]){
    
    int showLength,x,y,solve=0,guessLength,count=0,wrong=0,unguessedLetters=0;
    char guesses[26]={""};
    showLength=strlen(show)-1;
    for(y=0;y<showLength;y++){      //This for loop prints all the blank spaces where each letter goes
        if(show[y]==32)
            printf("%c ",show[y]);
        else
        printf("_ ");
    }
    printf("\n");
    while(solve!=1){
        unguessedLetters=0;
        wrong=0;
        guesses[count]=enterLetter(guesses,guessLength);    //calls the enterLetter function and assigns what is returned to an array
        guessLength=strlen(guesses);
        for(y=0;y<showLength;y++){                      //This set of for loops looks at each letter in the show vs each guess and either prints the letter if they match or prints an _
            for(x=0;x<guessLength;x++){          
            
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
                    unguessedLetters++;                 //adds 1 to ungeussedLetters which is used to see if they have guessed every letter                
                }
            }
        } 

        for(x=0;x<guessLength;x++){                     //This set of for loops works opposite of the prior ones by comparing the guess with a show letter and if it doesn't match any show letters it adds 1 in the wrong
            for(y=0;y<showLength;y++){ 
                if(guesses[x]==show[y])
                    break; 
                else if(y<showLength-1)
                    continue;
                else{
                    wrong=wrong+1;
                }
            }
        }


        printf("\n");
        hangState(wrong);                                   //calls hangstate with the amount of incorrect guesses
        count=count+1;
        if (unguessedLetters == 0){                         //checks to see if there are any unguessed letters and if not calls the gameOver function
            printf("\n\nWinner!\n");
            gameOver(guesses,show);
        }
      
    }
return 0;
}


char enterLetter(char *guess,int len){          //Points at the array of guessed letters of the playGame function and reads in the length of the array
    int x,reuse=0,guessLength;
    char input;
    guessLength=strlen(guess);
    printf("Guessed Letters: ");
    for(x=0;x<guessLength;x++)          //prints the already guessed letters
        printf("%c ",guess[x]);
    printf("\n");
    printf("Enter a lower case letter: ");
    scanf("%c%*c",&input);              //%*c reads in the new line character

    for(x=0;x<guessLength;x++){         //Checks if the letter inputed by the user has already been enterd
        if(input==guess[x]){
            reuse=1;
            break;
        }
        else if(x<guessLength-1)
            continue;
        else
            reuse=0;
    }

    while((input<97 || input>122) || reuse==1){     //this while loop runs while the character entered isn't a lower case letter and while the character has already been taken
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
return input;                               //returns the character entered by the user

}


int gameOver(char guesses[], char show[]){          //this function runs if the user guesses all the letters to the function
    printf("Secret movie title: %s", show);
    printf("These were all of your guesses: %s\n", guesses);
    exit(0);
}



