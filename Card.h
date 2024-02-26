//
//  Card.h
//  PokerSimulator
//
//  Created by Ryan Carney on 10/6/23.
//
#include "CardEnums.h"
#include <string>

#ifndef CARD_H
#define CARD_H

class Card {
    
public:
    Card();
    // contructor to set Suit and Face of Card
    Card( Suit s, Face f );
    
    // setter for Suit field of Card
    void setSuit( Suit s );
    // setter for Face field of Card
    void setFace( Face f );
    
    // getter for Suit field of Card
    Suit getSuit();
    // getter for Face field of Card
    Face getFace();
    // getter for value of Card
    int getValue();
    
    bool equals( Card c );
    
    //to_string method for the card
    std::string to_string();
     
private:
    // fields for Card class
    Suit mSuit;
    Face mFace;
};

#endif /* Card_h */
