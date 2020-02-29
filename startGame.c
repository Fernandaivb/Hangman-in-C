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
char customWord(){
    char custom[100];
    printf("Player 1 enter a word: ");
    scanf("%s", custom);
    return custom;
}
//int randomWord(){
    //movies= fopen(bigproject.txt, "r"); 
    //random word generator
    //srand(time(NULL)); seed generator
//}
int startGame(){
    char userIn[5]; 
    int playerCount=0;
    printf("Welcome to Hangman! Would you like to play? (Yes=y and No=n)");
    scanf("%s", userIn);
    if (strcmp (userIn,"y")==0){
        printf("Would you like to play with 1 player or 2 players?");
        scanf("%d", &playerCount);
        if (playerCount==1){
            printf("You are now playing with 1 player!\n ");
            //randomWord();
        }
        else if (playerCount==2){
            printf("You are now playing with 2 players!\n");
            customWord();
        }
        while ((playerCount!=1) && (playerCount!=2)){
            printf("Invalid answer. Would you like to play 1 player or 2 players?");
            scanf("%d", &playerCount);
        }
    }
    else if (strcmp(userIn, "n")==0){
        printf("You are not playing.");
    }
    while ((strcmp (userIn, "y")!= 0) && (strcmp(userIn, "n")!=0)){
        printf("That is an invalid answer. Would you like to play hangman? (Yes=1 and No=2)");
        scanf("%s", userIn);
    }
} 
int main (){
    startGame();
    printf("%c", custom); 

    //fclose();
    return 0;
}