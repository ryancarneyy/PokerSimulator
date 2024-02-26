//
//  Player.hpp
//  PokerSimulator
//
//  Created by Ryan Carney on 10/7/23.
//
#include "FiveCardHand.h"
#include "PlayerHand.h"
#include <stdio.h>


#ifndef PLAYER_H
#define PLAYER_H


class Player {
public:
    // constructors
    Player(); // no-arg
    Player( std::string name );
    Player( int startChips ); // constructor for when player joins table
    Player( std::string name, int startChips ); 
    
    // setter method for Player obj
    void setName( std::string name );
    void setHand( PlayerHand h );
    void setFiveCardHand( Card c1, Card c2, Card c3, Card c4, Card c5 );
    void setFiveCardHand( FiveCardHand fch );
    void setCard1( Card c1 );
    void setCard2( Card c2 );
    void sortHand();
    void setCurrentBet( int amount);
//    void setNumRebuys( int num );                     //Implement this later
    
    // methods for using at poker table
    void addChips( int amount );
    void loseChips( int amount );
    
//    void buyBackIn( int amount );                   // Implement this later
    
    // getter method for Player obj
    std::string getName();
    PlayerHand getHand();
    FiveCardHand getFiveCardHand();
    HandRanking getHandRank();
    Card getCard1();
    Card getCard2();
    int getChips();
    int getCurrentBet();
//    int getNumRebuys();                            // Implement this later
    // returns whether a player has folded or not
    bool hasFolded();
    
    HandRanking evaluateHand();
    
 
    
    

private:
    
    // fields for Player obj
    std::string mName;
    PlayerHand mHand;
    FiveCardHand mFiveCardHand;
    // the amt a Player has bet for that street
    int mCurrentBet;
    int mChips;
//    int mNumRebuys;                               // Implement this later
    bool mHasFolded;
    
    
};
#endif /* Player_h */
