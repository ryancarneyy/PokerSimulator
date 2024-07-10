//
//  main.cpp
//  PokerSimulator
//
//  Created by Ryan Carney on 10/6/23.
//
#include "./../include/Table.h"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
using namespace std;



int main() {
    srand( ( unsigned ) time(0) );
//
//    Table table(2, 1000);
//    
//    table.runFlop();
//    table.mCurrentPlayer = &table.mPlayers[0];
//    cout << table.mCurrentPlayer->getChips() << endl;
//    table.bet(table.mCurrentPlayer, 1000);
//    cout << table.mCurrentPlayer->getChips() << endl;
//    cout << table.mCurrentPlayer->getCurrentBet() << endl;
//    table.mCurrentPlayer = &table.mPlayers[1];
//    table.call(table.mCurrentPlayer);
//    cout << "Pot size: " << table.getMiniPot() << endl;
//    table.runTurn();
//    table.runRiver();
//    table.nextHand();
//    table.mCurrentPlayer = &table.mPlayers[0];
//    cout << table.mCurrentPlayer->getChips() << endl;
    
    Card aceH( Suit::HEARTS, Face::ACE );
    Card kingH( Suit::HEARTS, Face::KING );
    Card queenH( Suit::HEARTS, Face::QUEEN );
    Card jackH( Suit::HEARTS, Face::JACK );
    Card tenH( Suit::HEARTS, Face::TEN );
    Card nineH( Suit::HEARTS, Face::NINE );
    Card eightH( Suit::HEARTS, Face::EIGHT );
    Card sevenH( Suit::HEARTS, Face::SEVEN );
    Card sixH( Suit::HEARTS, Face::SIX );
    Card fiveH( Suit::HEARTS, Face::FIVE );
    Card fourH( Suit::HEARTS, Face::FOUR );
    Card threeH( Suit::HEARTS, Face::THREE );
    Card deuceH( Suit::HEARTS, Face::DEUCE );
    
    Card aceD( Suit::DIAMONDS, Face::ACE );
    Card kingD( Suit::DIAMONDS, Face::KING );
    Card queenD( Suit::DIAMONDS, Face::QUEEN );
    Card jackD( Suit::DIAMONDS, Face::JACK );
    Card tenD( Suit::DIAMONDS, Face::TEN );
    Card nineD( Suit::DIAMONDS, Face::NINE );
    Card eightD( Suit::DIAMONDS, Face::EIGHT );
    Card sevenD( Suit::DIAMONDS, Face::SEVEN );
    Card sixD( Suit::DIAMONDS, Face::SIX );
    Card fiveD( Suit::DIAMONDS, Face::FIVE );
    Card fourD( Suit::DIAMONDS, Face::FOUR );
    Card threeD( Suit::DIAMONDS, Face::THREE );
    Card deuceD( Suit::DIAMONDS, Face::DEUCE );
    
    Card aceC( Suit::CLUBS, Face::ACE );
    Card kingC( Suit::CLUBS, Face::KING );
    Card queenC( Suit::CLUBS, Face::QUEEN );
    Card jackC( Suit::CLUBS, Face::JACK );
    Card tenC( Suit::CLUBS, Face::TEN );
    Card nineC( Suit::CLUBS, Face::NINE );
    Card eightC( Suit::CLUBS, Face::EIGHT );
    Card sevenC( Suit::CLUBS, Face::SEVEN );
    Card sixC( Suit::CLUBS, Face::SIX );
    Card fiveC( Suit::CLUBS, Face::FIVE );
    Card fourC( Suit::CLUBS, Face::FOUR );
    Card threeC( Suit::CLUBS, Face::THREE );
    Card deuceC( Suit::CLUBS, Face::DEUCE );
    
    Card aceS( Suit::SPADES, Face::ACE );
    Card kingS( Suit::SPADES, Face::KING );
    Card queenS( Suit::SPADES, Face::QUEEN );
    Card jackS( Suit::SPADES, Face::JACK );
    Card tenS( Suit::SPADES, Face::TEN );
    Card nineS( Suit::SPADES, Face::NINE );
    Card eightS( Suit::SPADES, Face::EIGHT );
    Card sevenS( Suit::SPADES, Face::SEVEN );
    Card sixS( Suit::SPADES, Face::SIX );
    Card fiveS( Suit::SPADES, Face::FIVE );
    Card fourS( Suit::SPADES, Face::FOUR );
    Card threeS( Suit::SPADES, Face::THREE );
    Card deuceS( Suit::SPADES, Face::DEUCE );

  
//    FiveCardHand pair = FiveCardHand( deuceD, deuceS, threeH, fourH, tenH );
//    FiveCardHand twoPair = FiveCardHand( kingS, kingH, threeS, threeC, tenS );
//    FiveCardHand trips = FiveCardHand( sevenD, sevenH, sevenC, fourC, jackC );
//    FiveCardHand straight = FiveCardHand( aceC, queenH, jackD, kingS, tenH );
//    FiveCardHand wheel = FiveCardHand( aceC, deuceC, threeD, fourH, fiveS );
//    FiveCardHand flush = FiveCardHand( aceC, deuceC, sevenC, eightC, tenC );
//    FiveCardHand boat = FiveCardHand( aceC, aceD, aceH, eightC, eightH );
//    FiveCardHand quads = FiveCardHand( aceC, aceD, aceH, aceS, kingC );
//    FiveCardHand sf = FiveCardHand( deuceC, sixC, fourC, fiveC, threeC);
//    FiveCardHand royal = FiveCardHand( aceC, jackC, kingC, queenC, tenC );
    
//    assert( pair.isPair() );
//    assert( !straight.isPair() );
//    
//    assert( twoPair.isTwoPair() );
//    assert( !pair.isTwoPair() );
//    
//    assert( !twoPair.isThreeOfAKind() );
//    assert( trips.isThreeOfAKind() );
//    
//    assert( straight.isStraight() );
//    assert( !trips.isStraight() );
//    assert( wheel.isStraight() );
//     
//    assert( !straight.isFlush() );
//    assert( flush.isFlush() );
//    
//    assert( boat.isFullHouse() );
//    assert( !twoPair.isFullHouse() );
//    assert( !trips.isFullHouse() );
//    
//    assert( quads.isFourOfAKind() );
//    assert( !trips.isFourOfAKind() );
//    
//    assert( sf.isStraightFlush() );
//    assert( royal.isStraightFlush() );
//    
//    assert( !sf.isRoyalFlush() );
//    assert( royal.isRoyalFlush() );
//    
//    
//    Player plyr1;
//    plyr1.setHand(PlayerHand(aceC, aceD));
//    plyr1.setFiveCardHand( plyr1.getCard1(), plyr1.getCard2(), aceH, kingC, kingD );
//    
//    Player plyr2;
//    plyr2.setHand(PlayerHand(deuceC, deuceD));
//    plyr2.setFiveCardHand( plyr2.getCard1(), plyr2.getCard2(), tenH, kingC, kingD );
//    
//    assert( plyr1.evaluateHand() > HandRanking::TWOPAIR );
//    assert( plyr1.evaluateHand() < HandRanking::FOUROFAKIND );
//    
//    assert( plyr1.evaluateHand() > plyr2.evaluateHand() );
//    
//    assert( quads.evaluateHand() == HandRanking::FOUROFAKIND );
//    FiveCardHand broadway = FiveCardHand( aceC, queenD, kingC, jackH, tenC );
//    
//    assert( broadway.evaluateHand() == HandRanking::STRAIGHT );
//    assert( straight.evaluateHand() == HandRanking::STRAIGHT );
//    assert( royal.evaluateHand() == HandRanking::ROYALFLUSH );
//    
//    assert( twoPair.whatPair() == Face::KING );
//    assert( twoPair.whatSecondPair() == Face::THREE );
//    
//    assert( boat.whatThreeOfAKind() == Face::ACE );
//    assert( boat.whatFullOf() == Face::EIGHT );
//    
//    
//    
//    FiveCardHand twoPair1 = FiveCardHand( aceD, aceC, fiveC, fiveD, sevenC );
//    assert( twoPair1.whatKicker() == Face::SEVEN );
    
    vector<Player> players;
    players.push_back( Player( "Player 1" ) );
    players.push_back( Player( "Player 2" ) );
    players.push_back( Player( "Player 3" ) );
    Table table = Table( players, 1000 );
    table.deal();
    table.runFlop();
    table.runTurn();
    table.runRiver();
    table.evaluateHands();
    cout << endl;
    table.printFiveCardHands();
    table.printWinner();
    cout << endl;
    table.printHands();
    cout << endl;
    for( int i = 0; i < players.size(); ++i ) {
        cout << "Player " << static_cast<int>(i+1) << ":" << endl;
        table.getPlayers()[i].getFiveCardHand().printCards();
        cout << endl;
    }
    
    
    return ( 0 );
}
