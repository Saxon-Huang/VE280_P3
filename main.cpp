#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "rand.h"
using namespace std;

int main(int argc, char* argv[]) {
    // ==========       Read the arguments.       ===========

    int bankroll = atoi(argv[1]);
    int thishand = atoi(argv[2]);
    char type = argv[3][0];

    // ==========          initialization         ===========

    // Initialize "deck".
    Deck deck;
    // Initialize "player".
    Player* player;
    if(type == 's') player = get_Simple();
    else player = get_Counting();
    // Initialize "hand".
    Hand hand_plr;
    Hand hand_dlr;

    // ==========          playing game           ===========

    // Shuffle() 7 times at the beginning.
    for(int i = 0; i < 7; i++) {
        cout << "Shuffling the deck" << endl;
        int cut = get_cut();
        cout <<  "cut at " << cut << endl;
        deck.shuffle(cut);
        player->shuffled();
    }

    // Start a hand.
    // TODO: 5 is not the minimum
    while(bankroll >= 5) {
        // Anounce hand.
        cout << "Hand " << thishand << " bankroll " << bankroll << endl;
        // Whether shuffle()?
        if(deck.cardsLeft() < 20)
            for(int i = 0; i < 7; i++) {
                cout << "Shuffling the deck" << endl;
                int cut = get_cut();
                cout <<  "cut at " << cut << endl;
                deck.shuffle(cut);
                player->shuffled();
            }
        // Ask player for "wager".
        // TODO: 5 is not the minimum
        int wager = player->bet(bankroll, 5);
        cout << "Player bets " << wager << endl;

        // Dealt 4 cards.
        Card c = deck.deal(); // card 1
        cout << "Player dealt " << SpotNames[c.spot] << "of " << SuitNames[c.suit] << endl;
        player->expose(c);
        hand_plr.addCard(c);
        c = deck.deal(); // card 2
        cout << "Dealer dealt " << SpotNames[c.spot] << "of " << SuitNames[c.suit] << endl;
        player->expose(c);
        hand_dlr.addCard(c);
        c = deck.deal(); // card 3
        cout << "Player dealt " << SpotNames[c.spot] << "of " << SuitNames[c.suit] << endl;
        player->expose(c);
        hand_plr.addCard(c);
        c = deck.deal();
        hand_dlr.addCard(c);

        // Whether natural 21?
        if(hand_plr.handValue().count == 21) {
            bankroll += wager*3/2;
            cout << "Player dealt natural 21" << endl;
            continue;
        }



    }
    // =========                    Test              ============
    /*
    Deck d;
    d.shuffle(52);
    d.deck_print();
    */
    //Player* p1 = get_Simple();
    //Player* p2 = get_Counting();

    return 0;
}
