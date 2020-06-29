//
// Created by 28995 on 2020/6/28.
//

#include "player.h"

class SimplePlayer : public Player {
// TODO: use protected:
public:
    int count = 0;
    //Hand hand;

public:
    //SimplePlayer();
    int bet(unsigned int bankroll,unsigned int minimum);
    bool draw(Card dealer, const Hand &player);
    void expose(Card c);
    void shuffled();
};
//SimplePlayer::SimplePlayer(){}
int SimplePlayer::bet(unsigned int bankroll, unsigned int minimum) {
    if(bankroll >= minimum)
        return minimum;
    else return 0;
    // TODO: What else?
}
bool SimplePlayer::draw(Card dealer, const Hand &player) {
    if(!player.handValue().soft){
        if(player.handValue().count <= 11) return true;
        else if(player.handValue().count == 12)
            return !(dealer.spot >= 4 && dealer.spot <= 6);
        else if(player.handValue().count <= 16)
            return !(dealer.spot >= 2 && dealer.spot <= 6);
        else return false;
    }
    else{
        if(player.handValue().count <= 17) return true;
        else if(player.handValue().count == 18)
            return !(dealer.spot == 2 || dealer.spot == 7 || dealer.spot == 8);
        else return false;
    }
}

class CountingPlayer : public SimplePlayer {

public:
    int bet(unsigned int bankroll,unsigned int minimum);
};

int CountingPlayer::bet(unsigned int bankroll, unsigned int minimum) {
if(count >= 2 && bankroll >= 2*minimum) return minimum + minimum;
else return minimum;
// TODO: What else?
}

void SimplePlayer::shuffled() {
    count = 0;
}

void SimplePlayer::expose(Card c){
    if(c.spot >= 9 || c.spot == 0) count--;
    else if(c.spot <= 6) count ++;
}

// Instance of the two classes
static SimplePlayer player1;
static CountingPlayer player2;

Player* get_Simple(){
    return &player1;
}

Player* get_Counting(){
    return &player2;
}