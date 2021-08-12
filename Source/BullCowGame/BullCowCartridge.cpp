// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() {
    // When the game starts
    Super::BeginPlay();
    //print welcome
    PrintLine(TEXT("Hello! Welcome to Cows and Bulls. You need to guess the word before running out of lives."));
    PrintLine(TEXT("Guess the 4 letter word."));
    PrintLine(TEXT("Press enter to continue..."));

    SetupGame();

}

// When the player hits enter
void UBullCowCartridge::OnInput(const FString& Input) {
    ClearScreen();
    //check input
    if (Input == HiddenWord) {
        PrintLine(TEXT("You Guessed correct!"));
    } else {
        PrintLine(TEXT("You guessed wrong! Loser!"));
    }
    
}

void UBullCowCartridge::SetupGame() {
    HiddenWord = TEXT("Cake");
    Lives = 4;
    
}