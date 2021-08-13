// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() {
    // When the game starts
    Super::BeginPlay();
    //print welcome
    PrintLine(TEXT("Hello! Welcome to Cows and Bulls. You need to guess the word before running out of lives."));
    SetupGame();

}

// When the player hits enter
void UBullCowCartridge::OnInput(const FString& Input) {
    /* 
        if game is over or lives gone, clear screen and setup game again
        else, we check the PlayerGuess
    */
    if (bGameOver || Lives <= 0) {
        ClearScreen();
        SetupGame();
    } else {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame() {
    HiddenWord = TEXT("CakeE");
    Lives = HiddenWord.Len();
    bGameOver = false;
    //bGameOver = false;
    PrintLine(FString::Printf(TEXT("Guess the %i letter word."), Lives));
    PrintLine(FString::Printf(TEXT("You have %i lives."), Lives));
    PrintLine(TEXT("Press enter to continue..."));

     //for debugging
    PrintLine(FString::Printf(TEXT("Hidden Word: %s."), *HiddenWord)); 
}

void UBullCowCartridge::EndGame() {
    bGameOver = true;
    PrintLine(TEXT("Please press enter to continue..."));
}

void UBullCowCartridge::ProcessGuess(FString Guess) {
        //check input
        if (Guess.Len() != HiddenWord.Len()) {
            PrintLine(TEXT("Please input a word of proper length."));
            return;
        }
        if (Guess == HiddenWord) {
            PrintLine(TEXT("You Guessed correct!"));
            EndGame();
            return;
        } 

        //incorrect guess. Decrement a life and let them know.
        PrintLine(TEXT("You guessed wrong! This cost you one life."));
        --Lives;
        if (Lives == 0) {
            bGameOver = true;
            EndGame();
            return;
        }
        PrintLine(FString::Printf(TEXT("You have %i lives remaining."), Lives));
    
}

bool UBullCowCartridge::IsIsogram(FString Word) const {
    
    return true;
}