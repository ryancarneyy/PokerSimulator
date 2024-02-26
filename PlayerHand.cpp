//
//  PlayerHand.cpp
//  PokerSimulator
//
//  Created by Ryan Carney on 10/7/23.
//

#include <stdio.h>
#include "PlayerHand.h"


PlayerHand::PlayerHand(){}
// constructor for PlayerHand
PlayerHand::PlayerHand( Card c1, Card c2 ) {
    mCard1 = c1;
    mCard2 = c2;
}

// setter methods for Hand
void PlayerHand::setCard1( Card c1 ) {
    mCard1 = c1;
}
void PlayerHand::setCard2( Card c2 ) {
    mCard2 = c2;
}

void PlayerHand::sortLtoH() {
    Card temp;
    if( mCard1.getValue() > mCard2.getValue() ) {
        temp = mCard1;
        mCard1 = mCard2;
        mCard2 = temp;
    }
}

// getter methods
Card PlayerHand::getCard1() {
    return mCard1;
}
Card PlayerHand::getCard2() {
    return mCard2;
}
Card PlayerHand::getHighCard() {
    if( mCard1.getValue() > mCard2.getValue())
        return mCard1;
    else
        return mCard2;
}




