//
//  Table.cpp
//  PokerSimulator
//
//  Created by Ryan Carney on 10/7/23.
//

#include <stdio.h>
#include "Table.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

Table::Table() {
    
    // IMPLEMENT LATER WHEN YOU FIGURE OUT CRASHING BUG
}

Table::Table( vector<Player> players, int chips ) {
    mPlayers = players;
    if(players.size() > 8 ) {
        cerr << "Maximum of 8 Players." << endl;
        mPlayers.resize( 8 );
        mNumPlayers = 8;
    }
    else {
        // sets num of players and resizes vector
        mNumPlayers = static_cast<int>(players.size());
        mPlayers.resize( mNumPlayers );
    }
    
    // makes sure flop has 3 cards
    mFlop.resize( 3 );
    // temporarily holds amount of chips for each player and adds them to player
    mTotalChips = chips;
    for( int i = 0; i < mNumPlayers; ++i ) {
        mPlayers[i].addChips(chips);
    }
    // sets total chips to true value
    mTotalChips *= mNumPlayers;
    // sets starting values for pots and bets
    mMiniPot = 0;
    mPot = 0;
    mCurrentBet = 0;
    // makes sure table starts with 52 cards
    resetDeck();
    
    //    Implement buy back feature later
    //
    //    cout << "\nHow many rebuys will each player have?: ";
    //    cin >> mNumRebuysSetting;
    //
    //
    
}

Table::Table( int players, int chips ) {
    
    if( players > 8 ) {
        cerr << "Maximum of 8 Players." << endl;
        mPlayers.resize( 8 );
        mNumPlayers = 8;
    }
    else {
        // sets num of players and resizes vector
        mNumPlayers = players;
        mPlayers.resize( players );
    }
    
    string playerName;
    for( int i = 0; i < players; ++i ) {
        cout << "Player " << (i+1) << "'s name: ";
        cin >> playerName;
        mPlayers[i].setName( playerName );
        cout << endl;
    }
    
    // makes sure flop has 3 cards
    mFlop.resize( 3 );
    // temporarily holds amount of chips for each player and adds them to player
    mTotalChips = chips;
    for( int i = 0; i < mNumPlayers; ++i ) {
        mPlayers[i].addChips(chips);
    }
    // sets total chips to true value
    mTotalChips *= mNumPlayers;
    // sets starting values for pots and bets
    mMiniPot = 0;
    mPot = 0;
    mCurrentBet = 0;
    // makes sure table starts with 52 cards
    resetDeck();
    
    //    Implement buy back feature later
    //
    //    cout << "\nHow many rebuys will each player have?: ";
    //    cin >> mNumRebuysSetting;
    //
    //
    
}

void Table::start() {
    
}

//                                      *****CARD ACTIONS*****

// returns an index for a card from the remaining deck
 size_t Table::assignCard() {
     return ( rand() % mRemainingDeck.size() );
}

// to be called after every hand in order to put all cards back in the deck
void Table::resetDeck() {
    mRemainingDeck = {Card(Suit::CLUBS, Face::ACE), Card(Suit::CLUBS, Face::DEUCE), Card(Suit::CLUBS, Face::THREE), Card(Suit::CLUBS, Face::FOUR), Card(Suit::CLUBS, Face::FIVE), Card(Suit::CLUBS, Face::SIX), Card(Suit::CLUBS, Face::SEVEN), Card(Suit::CLUBS, Face::EIGHT), Card(Suit::CLUBS, Face::NINE), Card(Suit::CLUBS, Face::TEN), Card(Suit::CLUBS, Face::JACK), Card(Suit::CLUBS, Face::QUEEN), Card(Suit::CLUBS, Face::KING),                                             Card(Suit::SPADES, Face::ACE), Card(Suit::SPADES, Face::DEUCE), Card(Suit::SPADES, Face::THREE), Card(Suit::SPADES, Face::FOUR), Card(Suit::SPADES, Face::FIVE), Card(Suit::SPADES, Face::SIX), Card(Suit::SPADES, Face::SEVEN), Card(Suit::SPADES, Face::EIGHT), Card(Suit::SPADES, Face::NINE), Card(Suit::SPADES, Face::TEN), Card(Suit::SPADES, Face::JACK), Card(Suit::SPADES, Face::QUEEN), Card(Suit::SPADES, Face::KING),                                                             Card(Suit::HEARTS, Face::ACE), Card(Suit::HEARTS, Face::DEUCE), Card(Suit::HEARTS, Face::THREE), Card(Suit::HEARTS, Face::FOUR), Card(Suit::HEARTS, Face::FIVE), Card(Suit::HEARTS, Face::SIX), Card(Suit::HEARTS, Face::SEVEN), Card(Suit::HEARTS, Face::EIGHT), Card(Suit::HEARTS, Face::NINE), Card(Suit::HEARTS, Face::TEN), Card(Suit::HEARTS, Face::JACK), Card(Suit::HEARTS, Face::QUEEN), Card(Suit::HEARTS, Face::KING),                                                                            Card(Suit::DIAMONDS, Face::ACE), Card(Suit::DIAMONDS, Face::DEUCE), Card(Suit::DIAMONDS, Face::THREE), Card(Suit::DIAMONDS, Face::FOUR), Card(Suit::DIAMONDS, Face::FIVE), Card(Suit::DIAMONDS, Face::SIX), Card(Suit::DIAMONDS, Face::SEVEN), Card(Suit::DIAMONDS, Face::EIGHT), Card(Suit::DIAMONDS, Face::NINE), Card(Suit::DIAMONDS, Face::TEN), Card(Suit::DIAMONDS, Face::JACK), Card(Suit::DIAMONDS, Face::QUEEN), Card(Suit::DIAMONDS, Face::KING)};
}

//                                          *****GAME ACTIONS*****

// resets the table to be able to run the next hand
void Table::nextHand() {
    // purely for testing, will need to implement algorithm to find winner
    mHandWinner = &mPlayers[0];
    //
    
    mHandWinner->addChips(mPot);
    mPot = 0;
    mMiniPot = 0;
    mCurrentBet = 0;
    for(int i = 0; i < mNumPlayers; ++i) {
        mPlayers[ i ].setCurrentBet( 0 );
    }
    resetDeck();
}


void Table::deal() {
    
    size_t index;
    for( int i = 0; i < mNumPlayers; ++i ) {
        // chooses card and assigns it to player's first card
        index = assignCard();
        mPlayers[i].setCard1( mRemainingDeck[index] );
        // removes card from deck
        mRemainingDeck.erase( mRemainingDeck.begin() + index );
    }
    
    for( int i = 0; i < mNumPlayers; ++i ) {
        // chooses card and assigns it to player's second card
        index = assignCard();
        mPlayers[i].setCard2( mRemainingDeck[index] );
        // removes card from deck
        mRemainingDeck.erase( mRemainingDeck.begin() + index );
    }
    
    for( int i = 0; i < mNumPlayers; ++i ) {
        mPlayers[i].sortHand();
    }
}

//
void Table::burn() {
    size_t index = assignCard();
    mRemainingDeck.erase( mRemainingDeck.begin() + index );
}

// prints out three community cards (the mFlop)
void Table::runFlop() {
    // burn one and then print three
    burn();
    size_t index;
    for(int i = 0; i < 3; ++i) {
        index = assignCard();
        mFlop[ i ] = mRemainingDeck[ index ];
        mRemainingDeck.erase( mRemainingDeck.begin() + index );
    }
    std::cout << "Flop: " << mFlop[ 0 ].to_string() << ", " << mFlop[ 1 ].to_string() << ", " << mFlop[ 2 ].to_string() << std::endl;
}
// prints out one community card (the turn)
void Table::runTurn() {
    // resets members from previous street
    
    // adds chips from previous street
    mPot+= mMiniPot;
    // sets the pot back to 0
    mMiniPot = 0;
    mCurrentBet = 0;
    for(int i = 0; i < mNumPlayers; ++i) {
        // resets each player's current bet for the street
        mPlayers[i].setCurrentBet( 0 );
    }
    
    // printing out new card
    
    // burn one print one
    burn();
    size_t index = assignCard();
    mTurn = mRemainingDeck[ index ];
    mRemainingDeck.erase( mRemainingDeck.begin() + index );
    std::cout << "Turn: " << mTurn.to_string() << std::endl;
}
// prints out one commmunity card
void Table::runRiver() {
    // resets members from previous street
    
    // adds chips from previous street
    mTotalChips += mPot;
    // resets members from previous street
    mMiniPot = 0;
    mCurrentBet = 0;
    for( int i = 0; i < mNumPlayers; ++i ) {
        // resets each player's current bet for the street
        mPlayers[i].setCurrentBet( 0 );
    }
    
    //printing out new card
    
    // burn one print one
    burn();
    size_t index = assignCard();
    mRiver = mRemainingDeck[ index ];
    mRemainingDeck.erase( mRemainingDeck.begin() + index );
    std::cout << "River: " << mRiver.to_string() << std::endl;
}

void Table::evaluateHands() {
    FiveCardHand highestRankingHand;
    HandRanking highestRank;
    for( int i = 0; i < mNumPlayers; ++i ) {
        if( !mPlayers[i].hasFolded() ) {
            
            //  1  PlayerHand, flop0, flop1, flop2
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mPlayers[i].getCard2(), mFlop[0], mFlop[1], mFlop[2] );
            highestRank = mPlayers[i].evaluateHand();
            highestRankingHand = mPlayers[i].getFiveCardHand();
            
            //  2  PlayerHand, flop0, flop1, turn
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mPlayers[i].getCard2(), mFlop[0], mFlop[1], mTurn );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            } // goes with hand combo 2
            
            //  3  PlayerHand, flop0, flop1, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mPlayers[i].getCard2(), mFlop[0], mFlop[1], mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  4  PlayerHand, flop0, flop2, turn
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mPlayers[i].getCard2(), mFlop[0], mFlop[2], mTurn );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  5  PlayerHand, flop0, flop2, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mPlayers[i].getCard2(), mFlop[0], mFlop[2], mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  6  PlayerHand, flop1, flop2, turn
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mPlayers[i].getCard2(), mFlop[1], mFlop[2], mTurn );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            //  7  PlayerHand, flop1, flop2, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mPlayers[i].getCard2(), mFlop[1], mFlop[2], mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  8  PlayerHand, flop0, turn, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mPlayers[i].getCard2(), mFlop[0], mTurn, mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  9  PlayerHand, flop1, turn, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mPlayers[i].getCard2(), mFlop[1], mTurn, mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  10  PlayerHand, flop2, turn, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mPlayers[i].getCard2(), mFlop[2], mTurn, mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if ( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  11  PlayerCard1, flop0, flop1, flop2, turn
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mFlop[0], mFlop[1], mFlop[2], mTurn );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  12  PlayerCard1, flop0, flop1, flop2, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mFlop[0], mFlop[1], mFlop[2], mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  13  PlayerCard1, flop0, flop1, turn, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mFlop[0], mFlop[1], mTurn, mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  14  PlayerCard1, flop0, flop2, turn, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mFlop[0], mFlop[2], mTurn, mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  15 PlayerCard1, flop1, flop2, turn, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard1(), mFlop[1], mFlop[2], mTurn, mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  16  PlayerCard2, flop0, flop1, flop2, turn
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard2(), mFlop[0], mFlop[1], mFlop[2], mTurn );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            //  17  PlayerCard2, flop0, flop1, flop2, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard2(), mFlop[0], mFlop[1], mFlop[2], mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            //  18  PlayerCard2, flop0, flop1, turn, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard2(), mFlop[0], mFlop[1], mTurn, mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  19  PlayerCard2, flop0, flop2, turn, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard2(), mFlop[0], mFlop[2], mTurn, mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  20  PlayerCard2, flop1, flop2, turn, river
            mPlayers[i].setFiveCardHand( mPlayers[i].getCard2(), mFlop[1], mFlop[2], mTurn, mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            else if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            
            //  21  flop0, flop1, flop2, turn, river
            mPlayers[i].setFiveCardHand( mFlop[0], mFlop[1], mFlop[2], mTurn, mRiver );
            if( mPlayers[i].evaluateHand() > highestRank ) {
                highestRank = mPlayers[i].evaluateHand();
                highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            if( mPlayers[i].evaluateHand() == highestRank ) {
                if ( !highestRankingHand.checkHandAgainst( mPlayers[i].getFiveCardHand() ) )
                    highestRankingHand = mPlayers[i].getFiveCardHand();
            }
            mPlayers[i].setFiveCardHand( highestRankingHand );
        }
    }
}


vector<Player*> Table::calculateWinner() {
    
    
    
    int counter = 0;
    vector<Player*> winner;
    while( mPlayers[counter].hasFolded() ) {
        ++counter;
    }
    winner.push_back(&mPlayers[counter]);
    
    // iterates through remaining players
    for( int j = 0; j < mNumPlayers; ++j ) {
        
        // checking if the player hasnt folded
        if( !mPlayers[j].hasFolded() && ( find( winner.begin(), winner.end(), &mPlayers[j] ) == winner.end() ) ) {
            
            // checks if the player is already in the winner vector
            mPlayers[j].sortHand();
            
            // if the player's hand is better than the winner's
            if( mPlayers[j].evaluateHand() > winner.at(0)->evaluateHand() ) {
                winner.resize(0); 
                winner.push_back( &mPlayers[j] );
            }
            // For if the hand is the same HandRanking
            else if( mPlayers[j].evaluateHand() == winner.at(0)->evaluateHand() ) {
                
                // if the HandRanking is HIGHCARD
                if( winner.at(0)->evaluateHand() == HandRanking::HIGHCARD ) {
                    // if the player's high card is higher than the winner's
                    if( mPlayers[j].getFiveCardHand().getHighCard() > winner.at(0)->getFiveCardHand().getHighCard() ) {
                        winner.resize(0);
                        winner.push_back( &mPlayers[j] );
                    }// matches with if( getHighCard() > )
                    // if the player's high card is the same as the winner's
                    else if( mPlayers[j].getFiveCardHand().getHighCard() == winner.at(0)->getFiveCardHand().getHighCard() ) {
                        // if the player's hand contains card 2
                        if( mPlayers[j].getFiveCardHand().contains( mPlayers[j].getHand().getCard2() ) ) {
                            // if the winners hand contains card 2
                            if( winner.at(0)->getFiveCardHand().contains( winner.at(0)->getHand().getCard2() ) ) {
                                if( mPlayers[j].getHand().getCard2().getValue() > winner.at(0)->getHand().getCard2().getValue() ) {
                                    winner.resize(0);
                                    winner.push_back( &mPlayers[j] );
                                }
                                else if( mPlayers[j].getHand().getCard2().getValue() == winner.at(0)->getHand().getCard2().getValue() ) {
                                    if( mPlayers[j].getFiveCardHand().contains( mPlayers[j].getHand().getCard1() ) ) {
                                        if( winner.at(0)->getFiveCardHand().contains( winner.at(0)->getHand().getCard1() ) ) {
                                            if( mPlayers[j].getHand().getCard1().getValue() > winner.at(0)->getHand().getCard1().getValue() ) {
                                                winner.resize(0);
                                                winner.push_back( &mPlayers[j] );
                                            }
                                            // if the card 1 values are the same
                                            else if( mPlayers[j].getHand().getCard1().getValue() == winner.at(0)->getHand().getCard1().getValue() ) {
                                                winner.push_back( &mPlayers[j] );
                                            } // goes with if the card 1 values are the same
                                        }
                                        // if winners hand doesn't have card 1
                                        else {
                                            winner.resize(0);
                                            winner.push_back( &mPlayers[j] );
                                        } // goes with if winner's hand doesn't have card 1
                                    } // goes with if the player's hand contains card 1
                                } // goes with if the players card 2 == winner's card 2
                            } // goes with if the winners hand contains card 2
                            // if the winner's hand doesn't contain card 2
                            else {
                                winner.resize(0);
                                winner.push_back( &mPlayers[j] );
                            } // goes with if the winner's hand doesn't contain card 2
                        } // goes with if the player's hand contains card 2
                    } // goes with if the high cards are the same
                } // goes with HIGHCARD
                
                // if the HandRanking is a PAIRs
                else if( winner.at(0)->evaluateHand() == HandRanking::PAIR ) {
                    // player pair beats winner's pair
                    if( mPlayers[j].getFiveCardHand().whatPair() > winner.at(0)->getFiveCardHand().whatPair() ) {
                        winner.resize(0);
                        winner.push_back(&mPlayers[j]);
                    }
                    // if the pair is the same
                    else if( mPlayers[j].getFiveCardHand().whatPair() == winner.at(0)->getFiveCardHand().whatPair() ) {
                        // if the player's high card beats winner's
                        if( mPlayers[j].getFiveCardHand().whatKicker() > winner.at(0)->getFiveCardHand().whatKicker() ) {
                            winner.resize(0);
                            winner.push_back( &mPlayers[j] );
                        }
                        else if( mPlayers[j].getFiveCardHand().whatKicker() == winner.at(0)->getFiveCardHand().whatKicker() ) {
                            for( int k = 4; k >= 0; --k ) {
                                if( ( mPlayers[j].getFiveCardHand().getCard(k).getFace() != mPlayers[j].getFiveCardHand().whatPair() ) && ( mPlayers[j].getFiveCardHand().getCard(k).getFace() != mPlayers[j].getFiveCardHand().whatKicker() ) ){
                                    if( mPlayers[j].getFiveCardHand().getCard(k).getValue() > winner.at(0)->getFiveCardHand().getCard(k).getValue() ) {
                                        winner.resize(0);
                                        winner.push_back( &mPlayers[j] );
                                    }
                                    else if( mPlayers[j].getFiveCardHand().getCard(k).getValue() == winner.at(0)->getFiveCardHand().getCard(k).getValue() ) {
                                        winner.push_back( &mPlayers[j] );
                                    }
                                    k = -1;
                                }
                            }
                        }
                    } // matches with if pair is the same
                } // matches with PAIR
                
                // if their hand is a TWOPAIR
                else if( winner.at(0)->evaluateHand() == HandRanking::TWOPAIR ) {
                    // if player's top player is better than winners
                    if( mPlayers[j].getFiveCardHand().whatPair() > winner.at(0)->getFiveCardHand().whatPair() ) {
                        winner.resize(0);
                        winner.push_back( &mPlayers[j] );
                    }
                    // if player's top pair is same as winners
                    else if( mPlayers[j].getFiveCardHand().whatPair() == winner.at(0)->getFiveCardHand().whatPair() ) {
                        // if the player's second pair is better than winner's
                        if( mPlayers[j].getFiveCardHand().whatSecondPair() > winner.at(0)->getFiveCardHand().whatSecondPair() ) {
                            winner.resize(0);
                            winner.push_back( &mPlayers[j] );
                        } // goes with if( whatSecondPair > )
                        // if the player's second pair is the same as the winner's
                        else if( mPlayers[j].getFiveCardHand().whatSecondPair() == winner.at(0)->getFiveCardHand().whatSecondPair() ) {
                            // if the player's kicker is better than the winner's
                            if( mPlayers[j].getFiveCardHand().whatKicker() > winner.at(0)->getFiveCardHand().whatKicker() ) {
                                winner.resize(0);
                                winner.push_back( &mPlayers[j] );
                            } // goes with if( whatKicker > )
                            // if the player's kicker is the same as the winner's
                            else if( mPlayers[j].getFiveCardHand().whatKicker() == winner.at(0)->getFiveCardHand().whatKicker() ) {
                                winner.push_back(&mPlayers[j]);
                            } // goes with if( whatKicker == )
                        } // goes with if( whatSecondPair == )
                    } // goes with if( whatPair == )
                } // goes with if handRanking is TWOPAIR
                
                // if the handRanking is THREEOFAKIND
                else if( winner.at(0)->evaluateHand() == HandRanking::THREEOFAKIND ) {
                    // if the player's THREEOFAKIND is better than the winner's
                    if( mPlayers[j].getFiveCardHand().whatThreeOfAKind() > winner.at(0)->getFiveCardHand().whatThreeOfAKind() ) {
                        winner.resize(0);
                        winner.at(0) = &mPlayers[j];
                    }// matches with if THREEOFAKIND is better
                    // if the THREEOFAKINDs are the same
                    else if( mPlayers[j].getFiveCardHand().whatThreeOfAKind() == winner.at(0)->getFiveCardHand().whatThreeOfAKind() ) {
                        // if the player's kicker beats the winner's
                        if( mPlayers[j].getFiveCardHand().whatKicker() > winner.at(0)->getFiveCardHand().whatKicker() ) {
                            winner.resize(0);
                            winner.at(0) = &mPlayers[j];
                        }
                        // if the kickers are the same
                        else if( mPlayers[j].getFiveCardHand().whatKicker() == winner.at(0)->getFiveCardHand().whatKicker() ) {
                            for( int k = 4; k >= 0; --k ) {
                                if( ( mPlayers[j].getFiveCardHand().getCard(k).getFace() != mPlayers[j].getFiveCardHand().whatThreeOfAKind() ) && ( mPlayers[j].getFiveCardHand().getCard(k).getFace() != mPlayers[j].getFiveCardHand().whatKicker() ) ){
                                    if( mPlayers[j].getFiveCardHand().getCard(k).getValue() > winner.at(0)->getFiveCardHand().getCard(k).getValue() ) {
                                        winner.resize(0);
                                        winner.push_back( &mPlayers[j] );
                                    }
                                    else if( mPlayers[j].getFiveCardHand().getCard(k).getValue() == winner.at(0)->getFiveCardHand().getCard(k).getValue() ) {
                                        winner.push_back( &mPlayers[j] );
                                    }
                                    k = -1;
                                }
                            }
                            winner.push_back( &mPlayers[j] );
                        } // matches with if the kickers are the same
                    } // matches with if the three of a kinds are the same
                } // matches with THREEOFAKIND
                
                // if the hand is a STRAIGHT
                else if( winner.at(0)->evaluateHand() == HandRanking::STRAIGHT ) {
                    // if the player's STRAIGHT is better than the winner's
                    if( mPlayers[j].getFiveCardHand().getHighCard() > winner.at(0)->getFiveCardHand().getHighCard() ) {
                        winner.resize(0);
                        winner.push_back( &mPlayers[j] );
                    }// matches with if STRAIGHT is better than winner's
                    // if the player's STRAIGHT is the same as the winner's
                    else if( mPlayers[j].getFiveCardHand().getHighCard() == winner.at(0)->getFiveCardHand().getHighCard() ) {
                        winner.push_back( &mPlayers[j] );
                    }
                }// matches with STRAIGHT
                
                
                // if the hand is a FLUSH
                else if( winner.at(0)->evaluateHand() == HandRanking::FLUSH ) {
                    // if the player's hand contains card 2
                    if( mPlayers[j].getFiveCardHand().contains( mPlayers[j].getHand().getCard2() ) ) {
                        // if the winners hand contains card 2
                        if( winner.at(0)->getFiveCardHand().contains( winner.at(0)->getHand().getCard2() ) ) {
                            if( mPlayers[j].getHand().getCard2().getValue() > winner.at(0)->getHand().getCard2().getValue() ) {
                                winner.resize(0);
                                winner.push_back( &mPlayers[j] );
                            }
                        } // matches with if winner's hand contains card 2
                        else if( winner.at(0)->getFiveCardHand().contains( winner.at(0)->getHand().getCard1() ) ){
                            // if the players card 2 is better than winners card 1
                            if( mPlayers[j].getHand().getCard2().getValue() > winner.at(0)->getHand().getCard1().getValue() ) {
                                winner.resize(0);
                                winner.push_back( &mPlayers[j] );
                            } // matches with if player's card 2 is better than winners card 1
                        } // matches with if winner's hand contains card 1
                    } // matches with if player's hand contains card 2
                    
                    // if the player's hand contains card 1
                    else if( mPlayers[j].getFiveCardHand().contains( mPlayers[j].getHand().getCard1() ) ) {
                        // if the winners hand contains card 2
                        if( winner.at(0)->getFiveCardHand().contains( winner.at(0)->getHand().getCard2() ) ) {
                            if( mPlayers[j].getHand().getCard1().getValue() > winner.at(0)->getHand().getCard2().getValue() ) {
                                winner.resize(0);
                                winner.push_back( &mPlayers[j] );
                            } // matcehs with if the player's card 1 is better than winners card 2
                        } // matches with if winner's hand contains card 2
                        else if( winner.at(0)->getFiveCardHand().contains( winner.at(0)->getHand().getCard1() ) ){
                            // if the players card 2 is better than winners card 1
                            if( mPlayers[j].getHand().getCard2().getValue() > winner.at(0)->getHand().getCard1().getValue() ) {
                                winner.resize(0);
                                winner.push_back( &mPlayers[j] );
                            } // matches with if player's card 1 is better than winners card 1
                        } // matches with if winner's hand contains card 1
                    } // matches with if player's hand contains card 1
                    
                    else if( !(winner.at(0)->getFiveCardHand().contains( winner.at(0)->getHand().getCard2() ) || winner.at(0)->getFiveCardHand().contains( winner.at(0)->getHand().getCard1 () ) ) ) {
                        winner.push_back( &mPlayers[j] );
                    }
                    
                } // matches with FLUSH
                
                
                
                // if the hand is a FULLHOUSE
                else if( winner.at(0)->evaluateHand() == HandRanking::FULLHOUSE ) {
                    // if the player's flush is better than the winner's
                    if( mPlayers[j].getFiveCardHand().whatThreeOfAKind() > winner.at(0)->getFiveCardHand().whatThreeOfAKind() ) {
                        winner.resize(0);
                        winner.at(0) = &mPlayers[j];
                    }// matches with if flush is better than winner's
                    //if the player's flush is the same as the winner's
                    if( mPlayers[j].getFiveCardHand().whatThreeOfAKind() == winner.at(0)->getFiveCardHand().whatThreeOfAKind() ) {
                        // if the player's whatFullOf() is better than winner's
                        if( mPlayers[j].getFiveCardHand().whatFullOf() > winner.at(0)->getFiveCardHand().whatFullOf() ) {
                            winner.resize(0);
                            winner.push_back( &mPlayers[j] );
                        } // matches with if ( fullof() > )
                        else if( mPlayers[j].getFiveCardHand().whatFullOf() == winner.at(0)->getFiveCardHand().whatFullOf() ) {
                            winner.push_back( &mPlayers[j] );
                        } // matches with if ( fullOf() == )
                    }// matches with if ( whatThreeOfAKind() == );
                }// matches with FULLHOUSE
                
                // if hand is FOUROFAKIND
                else if( winner.at(0)->evaluateHand() == HandRanking::FOUROFAKIND ) {
                    // if the player's FOUROFAKIND is better than the winner's
                    if( mPlayers[j].getFiveCardHand().whatFourOfAKind() > winner.at(0)->getFiveCardHand().whatFourOfAKind() ) {
                        winner.resize(0);
                        winner.at(0) = &mPlayers[j];
                    }// matches with if FOUROFAKIND is better
                    // if the FOUROFAKIND are the same
                    if( mPlayers[j].getFiveCardHand().whatFourOfAKind() == winner.at(0)->getFiveCardHand().whatFourOfAKind() ) {
                        // if the player's kicker beats the winner's
                        if( mPlayers[j].getFiveCardHand().whatKicker() > winner.at(0)->getFiveCardHand().whatKicker() ) {
                            winner.resize(0);
                            winner.at(0) = &mPlayers[j];
                        }
                        // if the kickers are the same
                        else if( mPlayers[j].getFiveCardHand().whatKicker() == winner.at(0)->getFiveCardHand().whatKicker() ) {
                            winner.push_back( &mPlayers[j] );
                        } // matches with if the kickers are the same
                    } // matches with if the FOUROFAKIND are the same
                } // matches with FOUROFAKIND
                
                //if hand is STRAIGHTFLUSH
                else if( winner.at(0)->evaluateHand() == HandRanking::STRAIGHTFLUSH ) {
                    // if the player's STRAIGHTFLUSH is better than the winner's
                    if( mPlayers[j].getFiveCardHand().getHighCard() > winner.at(0)->getFiveCardHand().getHighCard() ) {
                        winner.resize(0);
                        winner.push_back( &mPlayers[j] );
                    }// matches with if STRAIGHTFLUSH is better than winner's
                    // if the player's STRAIGHTFLUSH is the same as the winner's
                    else if( mPlayers[j].getFiveCardHand().getHighCard() == winner.at(0)->getFiveCardHand().getHighCard() ) {
                        winner.push_back(&mPlayers[j]);
                    } // matches with if ( highCard() == )
                }// matches with STRAIGHTFLUSH
                
                
                
            } // matches with if ( HandRankings are equal )
        } // matches with if( Player hasFolded )
    } // matches with for loop
    
    return winner; // returns vector with player(s) that won the hand
}
                                  //       *****PLAYER ACTIONS*****

void Table::bet( Player * plyr, int amount ) {
    // adds to pot for the current street
    mMiniPot += amount;
    // takes away chips from the current player
    plyr->loseChips( amount );
    // sets the player's current bet at the amount that they bet
    plyr->setCurrentBet( amount );
    // sets amount to the current bet for the street
    mCurrentBet = amount;

}
// matches the currentBet for the street
//void Table::call( Player plyr ) {
//    mMiniPot += mCurrentBet - plyr.getCurrentBet();
//    plyr.loseChips( mCurrentBet - plyr.getCurrentBet() );
//}
void Table::call( Player* plyr ) {
    mMiniPot += mCurrentBet - plyr->getCurrentBet();
    plyr->loseChips( mCurrentBet - plyr->getCurrentBet() );
}
// raises the currentBet for the street
void Table::raiseTo( Player* plyr, int amount ) {
    if( amount <= ( 2 * mCurrentBet ) ) {
        cout << "Amount must be double the current bet. Please enter higher value: ";
        cin >> amount;
        raiseTo( plyr, amount );
    }
    else {
        mMiniPot += amount;
        plyr->loseChips( amount - plyr->getCurrentBet() );
        mCurrentBet = amount;
    }
}


//                                      ***** TESTING METHODS *****
size_t Table::getDeckSize() {
    return mRemainingDeck.size();
}
int Table::getMiniPot() {
    return mMiniPot;
}

vector<Player> Table::getPlayers() {
    return mPlayers;
}

void Table::printDeck() {
    for(int i = 0; i < mRemainingDeck.size(); ++i) {
        cout <<  to_string( i + 1 ) + " " + mRemainingDeck.at(i).to_string() << endl;
    }
}

void Table::printHands() {
    for( int i = 0; i < mNumPlayers; ++i ) {
        if( !mPlayers.at(i).hasFolded() ) {
            cout << "Player " << to_string(i+1) << ": " << mPlayers.at(i).getCard1().to_string() << ", " << mPlayers.at(i).getCard2().to_string() << endl;
        }
    }
}

void Table::printFiveCardHands() {
    for( int i = 0; i < mNumPlayers; ++i ) {
        if( !mPlayers.at(i).hasFolded() ) {
            cout << "Player " << to_string(i+1) << ": " << mPlayers[i].getFiveCardHand().to_string() << endl;
        }
    }
}

void Table::printWinner() {
    vector<Player*> winner = calculateWinner();
    if( winner.size() == 1 ) {
        cout << "Winner: " << winner.at(0)->getName() << endl;
    }
    else if( winner.size() > 1 ) {
        cout << "Chop Pot, Winners: ";
        for(int i = 0; i < winner.size() - 1; ++i ) {
            cout << winner.at(i)->getName() << ", ";
        }
        cout << winner.at( winner.size() - 1 )->getName() << endl;
    }
    else
        cerr << "Error: no winners detected." << endl;
}

