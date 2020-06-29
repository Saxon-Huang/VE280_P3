//
// Created by 28995 on 2020/6/28.
//

#include "hand.h"
Hand::Hand() {
    curValue.count = 0;
    curValue.soft = false;
}
void Hand::discardAll() {
    curValue.count = 0;
    curValue.soft = false;
}
void Hand::addCard(Card c) {
    // First, add the card.
    if(c.spot == ACE){
        if(curValue.count <= 10){
            curValue.count += 11;
            curValue.soft = true;
        }
        else{
            curValue.count++;
        }
    }
    else{
        if(c.spot >= 10) curValue.count += 10;
        else curValue.count += c.spot;
    }
    // Next, change "soft" to "hard" if necessary.
    if(curValue.soft && curValue.count > 21){
        curValue.count -= 10;
        curValue.soft = false;
    }
}
HandValue Hand::handValue() const {
    return HandValue {curValue.count, curValue.soft};
}


