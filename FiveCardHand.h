//
//  5CardHand.hpp
//  PokerSimulator
//
//  Created by Ryan Carney on 11/6/23.
//

#include "Card.h"

#ifndef FIVECARDHAND_H
#define FIVECARDHAND_H

#include <iostream>
#include "HandEnums.h"

class FiveCardHand {
    
public:
    FiveCardHand();
    FiveCardHand( Card c1, Card c2, Card c3, Card c4, Card c5 );
    
    //sort method for checking for straight
    void sortLtoH();
    
    void setHandRank( HandRanking h );
    
    
    // used to see if the hands are exactly the same
    bool equals( FiveCardHand h );
    // checking methods for hand ranking
    
    bool isPair();
    bool isTwoPair();
    bool isThreeOfAKind();
    bool isStraight();
    bool isFlush();
    bool isFullHouse();
    bool isFourOfAKind();
    bool isStraightFlush();
    bool isRoyalFlush();
    
    bool contains( Card c );
    // helps for if 2 people have same hand rank
    bool checkHandAgainst( FiveCardHand h);

    Card getCard( int i ) {
        return mCards[i];
    }
    Face whatPair();
    // for lower pair in 2Pair
    Face whatSecondPair();
    Face whatThreeOfAKind();
    // to determine what boat is full of
    Face whatFullOf();
    Face whatFourOfAKind();
    // used in HIGHCARD, PAIR, TWOPAIR, THREEOFAKIND, FOUROFAKIND
    Face whatKicker();

    
    
    // returns the evaluated hand rank
    HandRanking evaluateHand();
    HandRanking getHandRank();
    Face getHighCard();
    
    // prints the 5 cards used in the hand
    void printCards();
    std::string to_string();
    
private:
  
   
    HandRanking mHandRank;
    Card mCards[5];
    
};

#endif /* FIVECARDHAND_h */

