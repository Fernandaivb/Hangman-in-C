/****************************************************************************************************************************
*File: bigProject.c
*Names: Kearsten Crocker, Blake Webber, Fernanda Villafana Benitez
*Resources: 
****************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int startGame(){
    int yes=1, no=2, userIn=0, playerCount=0;
    char custom[100];
    printf("Welcome to Hangman! Would you like to play? (Yes=1 and No=2)");
    scanf("%d", &userIn);
    if (userIn==1){
        printf("Would you like to play with 1 player or 2 players?");
        scanf("%d", &playerCount);
        if (playerCount==1){
            printf("You are now playing with 1 player!");
        }
        else if (playerCount==2){
            printf("You are now playing with 2 players!");
        }
        while ((playerCount!=1) || (playerCount!=2)){
            printf("Invalid answer. Would you like to play 1 player or 2 players?");
            scanf("%d", &playerCount);
    }
    else if (userIn==2){
        printf("You are not playing.");
    }
    while ((userIn != 1) || (userIn !=2)){
        printf("That is an invalid answer. Would you like to play hangman? (Yes=1 and No=2)");
        scanf("%d", &userIn);
    }
}
  
int main (){
    startGame();
    
    return 0;
}