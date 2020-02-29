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
//char randomWord();
int playGame();
int enterLetter();

int userIn;
int main(){
    startGame();
    if(userIn==1){                                                                      //this is lets the user choose the phrase to guess
        char custom[100];
        printf("What would you like the phrase to be:");    
        scanf("%s",&custom);
        hangState(0);
        game(custom)
    }
    else if(userIn==2){                                                                  //calls the randomWord function 
       // randomWord();
        hangState();
        printf("These are movies from 2019\n");
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

//char randomWord(){

   // FILE *in_file = fopen("words","r");

void hangState(int=x){

    char state[]={"  +---+\n  |   | \n      | \n      | \n      | \n      | \n============ \n",""};
    printf("%s",state);
}

int playGame(){


}

int enterLetter(){


}





