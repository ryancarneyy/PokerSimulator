//
//  Player.cpp
//  PokerSimulator
//
//  Created by Ryan Carney on 10/7/23.
//

#include "Player.h"

Player::Player() {
    mFiveCardHand.setHandRank( HandRanking::HIGHCARD );
}
Player::Player( std::string name ) {
    mName = name;
}
Player::Player( int startChips ) { // constructor for when player joins table
    mChips = startChips;
}

Player::Player( std::string name, int startChips ) {
    mName = name;
    mChips = startChips;
}


// setter method for Player obj
void Player::setName( std::string name ) {
    mName = name;
}
void Player::setHand( PlayerHand h ) {
    mHand = h;
}
// setter method for 5-card hand that will determine hand ranking
void Player::setFiveCardHand( Card c1, Card c2, Card c3, Card c4, Card c5 ) {
    mFiveCardHand = FiveCardHand( c1, c2, c3, c4, c5 );
}
void Player::setFiveCardHand( FiveCardHand fch ) {
    mFiveCardHand = fch;
}
void Player::setCard1( Card c1 ) {
    mHand.setCard1( c1 );
}
void Player::setCard2( Card c2 ) {
    mHand.setCard2( c2 );
}
void Player::setCurrentBet( int amount ) {
    mCurrentBet = amount;
}
// methods for using at poker table
void Player::addChips( int amount ) {
    mChips += amount;
}
void Player::loseChips( int amount ) {
    mChips -= amount;
}


//void Player::buyBackIn( int amount ) {    // Implement this later 
//    if(mNumRebuys != 0) {
//        mChips += amount;
//        mNumRebuys -= 1;
//    }
//}
// getter method for Player obj
std::string Player::getName() {
    return mName;
}
PlayerHand Player::getHand() {
    return mHand;
}
FiveCardHand Player::getFiveCardHand() {
    return mFiveCardHand;
}
HandRanking Player::getHandRank() {
    return mFiveCardHand.getHandRank();
}
Card Player::getCard1() {
    return mHand.getCard1();
}
Card Player::getCard2() {
    return mHand.getCard2();
}
int Player::getChips() {
    return mChips;
}
int Player::getCurrentBet() {
    return mCurrentBet;
}
// returns whether a player has folded or not
bool Player::hasFolded() {
    return mHasFolded;
}

void Player::sortHand() {
    mHand.sortLtoH();
}
HandRanking Player::evaluateHand() {
   return mFiveCardHand.evaluateHand();
}


