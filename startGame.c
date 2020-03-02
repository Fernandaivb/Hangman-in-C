/****************************************************************************************************************************
*File: bigProject.c
*Names: Kearsten Crocker, Blake Webber, Fernanda Villafana Benitez
*Resources: 
****************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char custom[100];
char* customWord(){                                                                                                                                           // This function is called when the there is two players. It allows player one to enter a word that player two will will guess
    printf("Player 1 enter a word: ");
    scanf("%s", custom);
    return custom;                                                                                                                                              //This returns the string custom 
}
char randomWord(){                                                                                                                                          //This function is used when there is one player. It randomly generators a word called in from a text file containing movie tiles from 2019
    char wordList[10][200];                                                                                                                                         
    int randomPosition, counter=0;
    FILE * movies;
    movies = fopen( "bigproject.txt" , "r" );
    while (fgets(wordList[counter],200, movies )){
            //printf(" This is a test to print the file... %s\n", wordList[counter]); This shows that the file is read into the array wordList
            ++counter;
    }
    srand(time(NULL));    
    randomPosition=rand()%10;
    printf("%s\n", wordList[randomPosition]);                            
    return 0;
}

int startGame(){                                                                                                                                               // This function asks the user if they want to play hangman
    char userIn[5];                                                                                                                                             // This variable will be user input to wihether or not they want to play 
    int playerCount=0, check;
    printf("Welcome to Hangman! Would you like to play? (Yes=y and No=n)");
    scanf("%s", userIn);
    if (strcmp (userIn,"y")==0){
        printf("Would you like to play with 1 player or 2 players?");
        scanf("%d", &playerCount);      
        if (playerCount==1){
            printf("You are now playing with 1 player!\n");
            randomWord();                                                                                                                                   // If they are playing only, the randomWord function will randomly select a word from the movie list
        }
        else if (playerCount==2){
            printf("You are now playing with 2 players!\n");
            customWord();                                                                                                                                   // If there are two players, the customWord function will allow player one to enter a word for player two to guess
        }
        while ((playerCount!=1) && (playerCount!=2)){                                                                                       // Error checking making sure the user enters only 1 or 2 players
            printf("Invalid answer. Would you like to play 1 player or 2 players?");
            scanf("%d", &playerCount);
        }
    }
    else if (strcmp(userIn, "n")==0){
        printf("You are not playing.");
    }
    while ((strcmp (userIn, "y")!= 0) && (strcmp(userIn, "n")!=0)){                                                                      // Error checking making sure the user answers yes or no to playing
        printf("That is an invalid answer. Would you like to play hangman? (Yes=y and No=n)");
        scanf("%s", userIn);
    }
    return 0;
} 
int main (){
    int x;
    x= startGame();
    printf("%s", custom); 

    //fclose();
    return 0;
}