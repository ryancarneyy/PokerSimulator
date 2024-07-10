//
//  PlayerHand.h
//  PokerSimulator
//
//  Created by Ryan Carney on 10/6/23.
//

#ifndef PlayerHand_H
#define PlayerHand_H

#include "HandEnums.h"
#include "Card.h"

class PlayerHand {
    
public:
    // no-arg for when Player obj is created
    PlayerHand();
    // constructor to take two card
    PlayerHand( Card c1, Card c2 );
    // setter methods for PlayerHand
    void setCard1( Card c1 );
    void setCard2( Card c2 );
    // getter methods for Hand
    Card getCard1();
    Card getCard2();
    Card getHighCard();

    void sortLtoH();
    
    // will be called at every street, evaluates what the hand's ranking is
    void evaluateHand();
    
private:
    // fields of Hand
    Card mCard1;
    Card mCard2;

};
#endif /* PlayerHand_h */
