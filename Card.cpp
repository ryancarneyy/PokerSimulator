//
//  Card.cpp
//  PokerSimulator
//
//  Created by Ryan Carney on 10/6/23.
//

#include <stdio.h>
#include "Card.h"

// no-arg constructor
Card::Card() {
    mSuit = Suit::SPADES;
    mFace = Face::DEUCE;
}
// constructor
Card::Card( Suit s, Face f ) {
    mSuit = s;
    mFace = f;
}

// setter methods
void Card::setSuit( Suit s ) {
    mSuit = s;
}
void Card::setFace ( Face f ) {
    mFace = f;
}

// getter methods
Suit Card::getSuit() {
    return mSuit;
}
Face Card::getFace() {
    return mFace;
}
int Card::getValue() {
    switch ( mFace ) {
        case Face::DEUCE:
            return 2;
            break;
        case Face::THREE:
            return 3;
            break;
        case Face::FOUR:
            return 4;
            break;
        case Face::FIVE:
            return 5;
            break;
        case Face::SIX:
            return 6;
            break;
        case Face::SEVEN:
            return 7;
            break;
        case Face::EIGHT:
            return 8;
            break;
        case Face::NINE:
            return 9;
            break;
        case Face::TEN:
            return 10;
            break;
        case Face::JACK:
            return 11;
            break;
        case Face::QUEEN:
            return 12;
            break;
        case Face::KING:
            return 13;
            break;
        case Face::ACE:
            return 14;
            break;
        default:
            return 1;
            break;
    }
}

bool Card::equals( Card c ) {
    if( mFace == c.getFace() && mSuit == c.getSuit() ) 
        return true;
    else
        return false;
}
std::string Card::to_string() {
    std::string result = "";
    // switch to determine face
    switch( mFace ) {
        case Face::ACE:
            result = "Ace of ";
            break;
        case Face::DEUCE:
            result = "Deuce of ";
            break;
        case Face::THREE:
            result = "Three of ";
            break;
        case Face::FOUR:
            result = "Four of ";
            break;
        case Face::FIVE:
            result = "Five of ";
            break;
        case Face::SIX:
            result = "Six of ";
            break;
        case Face::SEVEN:
            result = "Seven of ";
            break;
        case Face::EIGHT:
            result = "Eight of ";
            break;
        case Face::NINE:
            result = "Nine of ";
            break;
        case Face::TEN:
            result = "Ten of ";
            break;
        case Face::JACK:
            result = "Jack of ";
            break;
        case Face::QUEEN:
            result = "Queen of ";
            break;
        case Face::KING:
            result = "King of ";
            break;
        }
    // switch to determine suit
    switch( mSuit )
    {
        case Suit::HEARTS:
            result += "Hearts";
            break;
        case Suit::CLUBS:
            result += "Clubs";
            break;
        case Suit::DIAMONDS:
            result += "Diamonds";
            break;
        case Suit::SPADES:
            result += "Spades";
            break;
    }
    return ( result );
}

