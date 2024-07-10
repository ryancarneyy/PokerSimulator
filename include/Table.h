//
//  Table.h
//  PokerSimulator
//
//  Created by Ryan Carney on 10/7/23.
//
#include <vector>
#include "Player.h"
#include <iostream>
#include <random>


#ifndef TABLE_h
#define TABLE_h
class Table {
    
public:
    //                                        *****TABLE ACTIONS****
    // no arg constructor
    Table();
    // vector with already made players and starting chips
    Table( std::vector<Player> players, int chips );
    // constructor with # of players and # of starting chips
    Table( int players, int chips );
    // adds a player to the table with a certain amount of chips
    void addPlayer( Player plyr, int chips );
    
    //                                        *****GAME ACTIONS****
    
    // starts the game, only method that should have to be called
    void start();
    // burns and then chooses three random cards for the mFlop
    void runFlop();
    // burns and then chooses a random card for the turn
    void runTurn();
    // burns and then chooses a random card for the mRiver
    void runRiver();
    // puts all cards back into the remaning deck
    void resetDeck();
    
    // deals cards to all mPlayers still remaining
    void deal();

    
    // overall game actions
    // resests the deck and mPot to be able to run the next hand
    void nextHand();
    
    // evaluates each player's hand to set their hand ranking
    void evaluateHands();
    std::vector<Player*> calculateWinner();
    
    //                                        *****CARD ACTIONS****
    

    // gets rid of a card from the deck
    void burn();
    // chooses random card in the remaining deck
    size_t assignCard();

    
    
   //                                         *****PLAYER ACTIONS*****
    
    // folds the mCurrentPlayer's hand
    void fold();
//    void bet( Player plyr, int amount );
    void bet( Player* plyr, int amount );
//    void call( Player plyr );
    void call( Player* plyr );
//    void raiseTo( Player plyr, int amount );
    void raiseTo( Player* plyr, int amount );
    
    
    //                                        *****TESTING METHODS*****
    size_t getDeckSize();
    std::vector<Player> getPlayers();
    int getMiniPot();
    void printDeck();
    void printHands();
    void printFiveCardHands();
    void printWinner();
    
    //                                   *****FIELD MADE PUBLIC FOR TESTING******

private:


    
    // player that the action is on
    Player * mCurrentPlayer;
    // holds mPlayers in Table
    std::vector<Player> mPlayers;
  
  
    int mNumPlayers;
//    int mNumRebuysSetting;  // Implement this later
    
    //                                              *****CARD FIELDS*****
    
    // cards remaining in the deck, will reset every hand
    std::vector<Card> mRemainingDeck;
    // current mFlop
    std::vector<Card> mFlop;
    // card for the turn
    Card mTurn;
    // card for the river
    Card mRiver;
    
    
    //                                              ******BETTING FIELDS*****
    
    // total chips on the Table
    int mTotalChips;
    // pot for the current street
    int mMiniPot;
    // mPot for the currentHand, contains cumulative bets for each hand
    int mPot;
    // the current bet for the hand
    int mCurrentBet;
    // Player that the action is on for each hand
  
    
    Player * mHandWinner;
    
    
    
};

#endif /* Table_h */
