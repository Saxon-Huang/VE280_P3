//
// Created by 28995 on 2020/6/28.
//
#include <iostream>
using namespace std;
#include "deck.h"
Deck::Deck() {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 13; j++){
            deck[i*13 + j].suit = Suit(i);
            deck[i*13 + j].spot = Spot(j);
        }
    next = 0;
}
void Deck::reset() {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 13; j++){
            deck[i*13 + j].suit = Suit(i);
            deck[i*13 + j].spot = Spot(j);
        }
    next = 0;
}
void Deck::shuffle(int n) {
    Card temp[52];
    for(int i = 0; i < 52; i++) temp[i] = deck[i];
    for(int i = 0; i < n && i < 52 - n; i++){
        deck[2*i] = temp[n + i];
        deck[2*i + 1] = temp[i];
    }
    if(n > 26){
        for(int i = 52 - n; i < n; i++){
            deck[52 - n + i] = temp[i];
        }
    }
    next = 0; // not correct
}
Card Deck::deal() {
    if(cardsLeft() > 0){
        next ++;
        return deck[next - 1];
    }
    else{
        DeckEmpty exception;
        throw exception;
    }
}
int Deck::cardsLeft() {
    return 52 - next;
}


// helper function
void Deck::deck_print()
{
    for(int i = 0; i < 52; i++)
        cout << i << ":  " << deck[i].suit*13 + deck[i].spot << endl;
}
