/*
description: lab test 2, this program uses multiple functions to create a number guessing game, the user enters their guess into the getPlayerGuess function, a random number is genorated whithn generateSecretNumber
                and feedback on the guess is given in provideFeedback. The aim of the game is for the user to guess the number within 10 trys.

author: Jake Lynam C24363376
date: 10/04/2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int generateSecretNumber(); //calls for functions
int getPlayerGuess();
void provideFeedback(int, int, int);
void playGame();


void main(){
    printf("Welcome to the Number Guessing Game!\n");
    playGame();

}

int generateSecretNumber(){ //random number genorator
    srand(time(NULL));

    return rand() %100 + 1; // creates random number

}

int getPlayerGuess(){   //function for player guess
    bool opr = true;    //boolean for guess check, if user doesnt enter valid number
    int guess = 0;
    while(opr == true){
        printf("\nEnter guess for secret number (1-100): \n");
        scanf("%d", &guess);
        printf("\nguess accepted\n");
        if(guess >= 1 && guess <= 100){
            opr = false;
        }
    }

    return guess;
}

void provideFeedback(int playerGuess, int randomNumber, int attempts){  // function for checking if user input  matches the random number
    if(playerGuess == randomNumber){
        printf("well done, you guessed right, number of guesses: %d\n", attempts);
        
    }

    if(playerGuess < randomNumber){
        printf("Incorrect, too low , try again\n");
        
    }

    if(playerGuess > randomNumber){
        printf("Incorrect, too high, try again\n");
    }

            
}

void playGame(){    //function to hold game logic, away from main
    int attempts = 1;   //how many attempts the user has had, starts at one as user will always have one attempt
    int secret_number =  generateSecretNumber(); 
    int guess = getPlayerGuess();
    provideFeedback(guess, secret_number, attempts);

    while(guess != secret_number){
        if(attempts > 10){
            printf("\nGAME OVER, the correct number was %d\n", secret_number);
            break;
        }
        attempts = attempts + 1;
        guess = getPlayerGuess();
        provideFeedback(guess, secret_number, attempts);
    }
}