//
//  5CardHand.cpp
//  PokerSimulator
//
//  Created by Ryan Carney on 11/6/23.
//

#include "./../include/FiveCardHand.h"

using namespace std;

FiveCardHand::FiveCardHand() {}
FiveCardHand::FiveCardHand( Card c1, Card c2, Card c3, Card c4, Card c5 ) {
    mCards[0] = c1;
    mCards[1] = c2;
    mCards[2] = c3;
    mCards[3] = c4;
    mCards[4] = c5;
}

void FiveCardHand::setHandRank( HandRanking h ) {
    mHandRank = h;
}

void FiveCardHand::sortLtoH() {
    Card temp;
    for( int i = 0; i < 4; ++i ) {
        for( int j = 0; j < 4; ++j ) {
            if( mCards[j].getValue() > mCards[j+1].getValue() ) {
                temp = mCards[j];
                mCards[j] = mCards[j+1];
                mCards[j+1] = temp;
            }
        }
    }
}

bool FiveCardHand::equals( FiveCardHand h ) {
    sortLtoH();
    h.sortLtoH();
    for( int i = 0; i < 5; ++i ) {
        // checks if each corresponding card is the same (FACEWISE)
        if( !mCards[i].equals( h.getCard(i) ) ) {
            return false;
        }
    }
    return true;
}

//                                              *****HAND EVALUATION METHODS*****

bool FiveCardHand::isPair() {
    for( int i = 0; i < 4; ++i ) {
        for( int j = i + 1; j < 5; ++j ) {
            if( mCards[i].getFace() == mCards[j].getFace() )
                return true;
        }
    }
    return false;
}


bool FiveCardHand::isTwoPair() {
    if( (mCards[0].getFace() == mCards[1].getFace()) && (mCards[2].getFace() == mCards[3].getFace()) )
        return true;
    if( (mCards[0].getFace() == mCards[1].getFace()) && (mCards[2].getFace() == mCards[4].getFace()) )
        return true;
    if( (mCards[0].getFace() == mCards[1].getFace()) && (mCards[3].getFace() == mCards[4].getFace()) )
        return true;
    if( (mCards[0].getFace() == mCards[2].getFace()) && (mCards[1].getFace() == mCards[3].getFace()) )
        return true;
    if( (mCards[0].getFace() == mCards[2].getFace()) && (mCards[1].getFace() == mCards[4].getFace()) )
        return true;
    if( (mCards[0].getFace() == mCards[2].getFace()) && (mCards[3].getFace() == mCards[4].getFace()) )
        return true;
    if( (mCards[0].getFace() == mCards[3].getFace()) && (mCards[1].getFace() == mCards[2].getFace()) )
        return true;
    if( (mCards[0].getFace() == mCards[3].getFace()) && (mCards[1].getFace() == mCards[4].getFace()) )
        return true;
    if( (mCards[0].getFace() == mCards[3].getFace()) && (mCards[2].getFace() == mCards[4].getFace()) )
        return true;
    if( (mCards[0].getFace() == mCards[4].getFace()) && (mCards[1].getFace() == mCards[2].getFace()) )
        return true;
    if( (mCards[0].getFace() == mCards[4].getFace()) && (mCards[1].getFace() == mCards[3].getFace()) )
        return true;
    if( (mCards[0].getFace() == mCards[4].getFace()) && (mCards[2].getFace() == mCards[3].getFace()) )
        return true;
    if( (mCards[1].getFace() == mCards[2].getFace()) && (mCards[3].getFace() == mCards[4].getFace()) )
        return true;
    if( (mCards[1].getFace() == mCards[3].getFace()) && (mCards[2].getFace() == mCards[4].getFace()) )
        return true;
    if( (mCards[1].getFace() == mCards[4].getFace()) && (mCards[2].getFace() == mCards[3].getFace()) )
        return true;
    return false;
}
bool FiveCardHand::isThreeOfAKind( ) {
    if ( ( mCards[0].getFace() == mCards[1].getFace() ) && ( mCards[1].getFace() == mCards[2].getFace() ) )
        return true;
    if ( ( mCards[0].getFace() == mCards[1].getFace() ) && ( mCards[1].getFace() == mCards[3].getFace() ) )
        return true;
    if ( ( mCards[0].getFace() == mCards[1].getFace() ) && ( mCards[1].getFace() == mCards[4].getFace() ) )
        return true;
    if ( ( mCards[0].getFace() == mCards[2].getFace() ) && ( mCards[2].getFace() == mCards[3].getFace() ) )
        return true;
    if ( ( mCards[0].getFace() == mCards[2].getFace() ) && ( mCards[2].getFace() == mCards[4].getFace() ) )
        return true;
    if ( ( mCards[0].getFace() == mCards[3].getFace() ) && ( mCards[3].getFace() == mCards[4].getFace() ) )
        return true;
    if ( ( mCards[1].getFace() == mCards[2].getFace() ) && ( mCards[2].getFace() == mCards[3].getFace() ) )
        return true;
    if ( ( mCards[1].getFace() == mCards[2].getFace() ) && ( mCards[2].getFace() == mCards[4].getFace() ) )
        return true;
    if ( ( mCards[1].getFace() == mCards[3].getFace() ) && ( mCards[3].getFace() == mCards[4].getFace() ) )
        return true;
    if ( ( mCards[2].getFace() == mCards[3].getFace() ) && ( mCards[3].getFace() == mCards[4].getFace() ) )
        return true;
    return false;
}
bool FiveCardHand::isStraight() {
    sortLtoH();
    if( mCards[0].getFace() == Face::DEUCE ) {
        if( mCards[1].getFace() == Face::THREE )
            if( mCards[2].getFace() == Face::FOUR )
                if( mCards[3].getFace() == Face::FIVE )
                    if( mCards[4].getFace() == Face::ACE )
                        return true;
    }
    if( (mCards[0].getValue() == mCards[1].getValue() - 1) ) {
        if( (mCards[1].getValue() == mCards[2].getValue() - 1) )
            if( (mCards[2].getValue() == mCards[3].getValue() - 1) )
                if( (mCards[3].getValue() == mCards[4].getValue() - 1) )
                    return true;
    }
    return false;
}
bool FiveCardHand::isFlush() {
    Suit s = mCards[0].getSuit();
    for( int i = 1; i < 5; ++i ) {
        if( mCards[i].getSuit() != s )
            return false;
    }
    return true;
}
bool FiveCardHand::isFullHouse() {
    if(isThreeOfAKind() && isTwoPair())
        return true;
    return false;
}
bool FiveCardHand::isFourOfAKind() {
    if( mCards[0].getFace() == mCards[1].getFace() )
        if( mCards[1].getFace() == mCards[2].getFace() )
            if( mCards[2].getFace() == mCards[3].getFace() )
                return true;
    if( mCards[0].getFace() == mCards[1].getFace() )
        if( mCards[1].getFace() == mCards[3].getFace() )
            if( mCards[3].getFace() == mCards[4].getFace() )
                return true;
    if( mCards[0].getFace() == mCards[1].getFace() )
        if( mCards[1].getFace() == mCards[2].getFace() )
            if( mCards[2].getFace() == mCards[4].getFace() )
                return true;
    if( mCards[0].getFace() == mCards[2].getFace() )
        if( mCards[2].getFace() == mCards[3].getFace() )
            if( mCards[3].getFace() == mCards[4].getFace() )
                return true;
    if( mCards[1].getFace() == mCards[2].getFace() )
        if( mCards[2].getFace() == mCards[3].getFace() )
            if( mCards[3].getFace() == mCards[4].getFace() )
                return true;
    
    return false;
}
bool FiveCardHand::isStraightFlush() {
    if( isStraight() && isFlush() )
        return true;
    return false;
}
bool FiveCardHand::isRoyalFlush() {
    if( isFlush() )
        if( isStraight() ) {
            sortLtoH();
            if( mCards[0].getFace() == Face::TEN )
                if( getHighCard() == Face::ACE )
                    return true;
        }
    return false;
}

bool FiveCardHand::contains( Card c ) {
    for( int i = 0; i < 5; ++i ) {
        if( mCards[i].equals( c ) )
            return true;
    }
    return false;
}

Face FiveCardHand::whatPair() {
    sortLtoH();
    for( int i = 4; i > 0; --i ) {
        for( int j = (i-1); j >= 0; --j ) {
            if( mCards[i].getFace() == mCards[j].getFace() )
                return mCards[i].getFace();
        }
    }
    cerr << "whatPair() called incorrectly! Returning Face::DEUCE" << endl;
    return Face::DEUCE;
}
Face FiveCardHand::whatKicker() {
    sortLtoH();
    if( evaluateHand() == HandRanking::HIGHCARD ){
        return mCards[3].getFace();
    }
    if( evaluateHand() == HandRanking::PAIR ) {
        if( getHighCard() == whatPair() ) {
            return mCards[2].getFace();
        }
        else
            return mCards[4].getFace();
        
    }
    else if( evaluateHand() == HandRanking::TWOPAIR ){
        for( int i = 0; i < 5; ++i ) {
            if( ( mCards[i].getFace() != whatPair() ) && ( mCards[i].getFace() != whatSecondPair() ))
                return mCards[i].getFace();
        }
        cerr << "whatKicker() went to HandRanking::TWOPAIR incorrectly. This control branch should not be reached. Returning Face::DEUCE" << endl;
        return Face::DEUCE;
    }
    else if( evaluateHand() == HandRanking::THREEOFAKIND ) {
        if( getHighCard() == whatThreeOfAKind() ) {
            return mCards[1].getFace();
        }
        else
            return mCards[5].getFace();
    }
    else if( evaluateHand() == HandRanking::FOUROFAKIND) {
        if( getHighCard() == whatFourOfAKind() ) {
            return mCards[0].getFace();
        }
        else
            return mCards[4].getFace();
    }
    else {
        cerr << "Kicker not needed! Returning Face::DEUCE." << endl;
        return Face::DEUCE;
    }
}

// to be called in 2Pair HandRanking
Face FiveCardHand::whatSecondPair() {
    for( int i = 0; i < 4; ++i ) {
        for( int j = i + 1; j < 5; ++j ) {
            if( mCards[i].getFace() == mCards[j].getFace() ) {
                if( mCards[i].getFace() != whatPair() ) {
                    return mCards[i].getFace();
                }
            }
        }
    }
    cerr << "whatSecondPair() called incorrectly! Returning Face::DEUCE" << endl;
    return Face::DEUCE;
}

Face FiveCardHand::whatThreeOfAKind() {
    if ( ( mCards[0].getFace() == mCards[1].getFace() ) && ( mCards[1].getFace() == mCards[2].getFace() ) )
        return mCards[0].getFace();
    if ( ( mCards[0].getFace() == mCards[1].getFace() ) && ( mCards[1].getFace() == mCards[3].getFace() ) )
        return mCards[0].getFace();
    if ( ( mCards[0].getFace() == mCards[1].getFace() ) && ( mCards[1].getFace() == mCards[4].getFace() ) )
        return mCards[0].getFace();
    if ( ( mCards[0].getFace() == mCards[2].getFace() ) && ( mCards[2].getFace() == mCards[3].getFace() ) )
        return mCards[0].getFace();
    if ( ( mCards[0].getFace() == mCards[2].getFace() ) && ( mCards[2].getFace() == mCards[4].getFace() ) )
        return mCards[0].getFace();
    if ( ( mCards[0].getFace() == mCards[3].getFace() ) && ( mCards[3].getFace() == mCards[4].getFace() ) )
        return mCards[0].getFace();
    if ( ( mCards[1].getFace() == mCards[2].getFace() ) && ( mCards[2].getFace() == mCards[3].getFace() ) )
        return mCards[1].getFace();
    if ( ( mCards[1].getFace() == mCards[2].getFace() ) && ( mCards[2].getFace() == mCards[4].getFace() ) )
        return mCards[1].getFace();
    if ( ( mCards[1].getFace() == mCards[3].getFace() ) && ( mCards[3].getFace() == mCards[4].getFace() ) )
        return mCards[1].getFace();
    if ( ( mCards[2].getFace() == mCards[3].getFace() ) && ( mCards[3].getFace() == mCards[4].getFace() ) )
        return mCards[2].getFace();
    cerr << "whatThreeOfAKind() called incorrectly! Returning Face::Deuce" << endl;
    return Face::DEUCE;
}


Face FiveCardHand::whatFullOf() {
    if ( ( mCards[0].getFace() == mCards[1].getFace() ) && ( mCards[1].getFace() == mCards[2].getFace() ) )
        return mCards[3].getFace();
    if ( ( mCards[0].getFace() == mCards[1].getFace() ) && ( mCards[1].getFace() == mCards[3].getFace() ) )
        return mCards[2].getFace();
    if ( ( mCards[0].getFace() == mCards[1].getFace() ) && ( mCards[1].getFace() == mCards[4].getFace() ) )
        return mCards[3].getFace();
    if ( ( mCards[0].getFace() == mCards[2].getFace() ) && ( mCards[2].getFace() == mCards[3].getFace() ) )
        return mCards[1].getFace();
    if ( ( mCards[0].getFace() == mCards[2].getFace() ) && ( mCards[2].getFace() == mCards[4].getFace() ) )
        return mCards[1].getFace();
    if ( ( mCards[0].getFace() == mCards[3].getFace() ) && ( mCards[3].getFace() == mCards[4].getFace() ) )
        return mCards[1].getFace();
    if ( ( mCards[1].getFace() == mCards[2].getFace() ) && ( mCards[2].getFace() == mCards[3].getFace() ) )
        return mCards[0].getFace();
    if ( ( mCards[1].getFace() == mCards[2].getFace() ) && ( mCards[2].getFace() == mCards[4].getFace() ) )
        return mCards[0].getFace();
    if ( ( mCards[1].getFace() == mCards[3].getFace() ) && ( mCards[3].getFace() == mCards[4].getFace() ) )
        return mCards[0].getFace();
    if ( ( mCards[2].getFace() == mCards[3].getFace() ) && ( mCards[3].getFace() == mCards[4].getFace() ) )
        return mCards[0].getFace();
    cerr << "whatFullOf() called incorrectly! Returning Face::Deuce" << endl;
    return Face::DEUCE;
}

Face FiveCardHand::whatFourOfAKind() {
    if( mCards[0].getFace() == mCards[1].getFace() )
        if( mCards[1].getFace() == mCards[2].getFace() )
            if( mCards[2].getFace() == mCards[3].getFace() )
                return mCards[0].getFace();
    if( mCards[0].getFace() == mCards[1].getFace() )
        if( mCards[1].getFace() == mCards[3].getFace() )
            if( mCards[3].getFace() == mCards[4].getFace() )
                return mCards[0].getFace();
    if( mCards[0].getFace() == mCards[1].getFace() )
        if( mCards[1].getFace() == mCards[2].getFace() )
            if( mCards[2].getFace() == mCards[4].getFace() )
                return mCards[0].getFace();
    if( mCards[0].getFace() == mCards[2].getFace() )
        if( mCards[2].getFace() == mCards[3].getFace() )
            if( mCards[3].getFace() == mCards[4].getFace() )
                return mCards[0].getFace();
    if( mCards[1].getFace() == mCards[2].getFace() )
        if( mCards[2].getFace() == mCards[3].getFace() )
            if( mCards[3].getFace() == mCards[4].getFace() )
                return mCards[1].getFace();
    
    cerr << "whatFourOfAKind() called incorrectly! Returning Face::Deuce" << endl;
    return Face::DEUCE;

}

bool FiveCardHand::checkHandAgainst( FiveCardHand hand ) {
    
    sortLtoH();
    hand.sortLtoH();
    
    if( evaluateHand() > hand.evaluateHand() )
        return true;
    else if( evaluateHand() < hand.evaluateHand() )
        return false;
    
    // if the hand rankings are equal
    // if the HandRanking is HIGHCARD
    if( evaluateHand() == HandRanking::HIGHCARD ) {
        // goes with for loop
        for(int j = 4; j >= 0 ; --j ) {
        // if player's high card is higher at any point
            if( hand.getCard(j).getValue() > getCard(j).getValue() ) {
                return false;
            }
            // goes with if player's high card is higher at any point
        } //  goes with for loop
        return true;
    } // goes with HIGHCARD
    
    // if the HandRanking is a PAIRs
    else if( evaluateHand() == HandRanking::PAIR ) {
        // player pair beats highestRankingHand's pair
        if( hand.whatPair() > whatPair() ) {
            return false;
        }
        // if the pair is the same
        else if( hand.whatPair() == whatPair() ) {
            // if the player's high card beats highestRankingHand's
            if( hand.whatKicker() > whatKicker() ) {            // NEED TO ADD CHECKING LAST 2 CARDS HERE
                return false;
            }
            else if( hand.whatKicker() == whatKicker() ) {
                for( int j = 4; j >= 0; --j ) {
                    if( ( hand.getCard(j).getFace() != whatPair() ) && ( hand.getCard(j).getFace() != whatKicker() ) ){
                        if( hand.getCard(j).getValue() > getCard(j).getValue() )
                            return false;
                    }
                }
            }
                                                                            // CASE WHERE THEY HAVE THE SAME KICKER HERE
        } // matches with if pair is the same
        else
            return true;
    } // matches with PAIR
    
    // if their hand is a TWOPAIR
    else if( evaluateHand() == HandRanking::TWOPAIR ) {
        // if player's top player is better than highestRankingHands
        if( hand.whatPair() > whatPair() ) {
            return false;
        }
        // if player's top pair is same as highestRankingHands
        else if( hand.whatPair() == whatPair() ) {
            // if the player's second pair is better than highestRankingHand's
            if( hand.whatSecondPair() > whatSecondPair() ) {
                return false;
            } // goes with if( whatSecondPair > )
            // if the player's second pair is the same as the highestRankingHand's
            if( hand.whatSecondPair() == whatSecondPair() ) {
                // if the player's kicker is better than the highestRankingHand's
                if( hand.whatKicker() > whatKicker() ) {
                    return false;
                } // goes with if( whatKicker > )
                else {
                    return true;
                }
            } // goes with if( whatSecondPair == )
        } // goes with if( whatPair == )
        else {
            return true;
        }
    } // goes with if handRanking is TWOPAIR
    
    // if the handRanking is THREEOFAKIND
    else if( evaluateHand() == HandRanking::THREEOFAKIND ) {
        // if the player's THREEOFAKIND is better than the highestRankingHand's
        if( hand.whatThreeOfAKind() > whatThreeOfAKind() ) {
            return false;
        }// matches with if THREEOFAKIND is better
        // if the THREEOFAKINDs are the same
        else if( hand.whatThreeOfAKind() == whatThreeOfAKind() ) {
            // if the player's kicker beats the highestRankingHand's
            if( hand.whatKicker() > whatKicker() ) {
                return false;
            }
            // if the kickers are the same
            else if( hand.whatKicker() == whatKicker() ) {
                for( int j = 4; j >= 0; --j ) {
                    if( ( hand.getCard(j).getFace() != hand.whatThreeOfAKind() ) && ( hand.getCard(j).getFace() != whatKicker() ) ){
                        if( hand.getCard(j).getValue() > getCard(j).getValue() )
                            return false;
                    }
                }                                                                          // NEED TO CHECK LAST CARD HERE
            } // matches with if the kickers are the same
            else
                return true;
        } // matches with if the three of a kinds are the same
        else {
            return true;
        }
    } // matches with THREEOFAKIND
    
    // if the hand is a STRAIGHT
    else if( evaluateHand() == HandRanking::STRAIGHT ) {
        // if the player's STRAIGHT is better than the highestRankingHand's
        if( hand.getHighCard() > getHighCard() ) {
            return false;
        }// matches with if STRAIGHT is better than highestRankingHand's
        else
            return true;
    }// matches with STRAIGHT
    
    
    // if the hand is a FLUSH
    else if( evaluateHand() == HandRanking::FLUSH ) {
        sortLtoH();
        hand.sortLtoH();
        // goes with for loop
        for(int j = 4; j >= 0 ; --j ) {
            // if player's high card is higher at any point
            if( hand.getCard(j).getValue() > getCard(j).getValue() ) {
                return false;
            }
            // goes with if player's high card is higher at any point
        } //  goes with for loop
        return true;
    }
    
    
    // if the hand is a FULLHOUSE
    else if( evaluateHand() == HandRanking::FULLHOUSE ) {
        // if the player's flush is better than the highestRankingHand's
        if( hand.whatThreeOfAKind() > whatThreeOfAKind() ) {
            return false;
        }// matches with if flush is better than highestRankingHand's
        //if the player's flush is the same as the highestRankingHand's
        else if( hand.whatThreeOfAKind() == whatThreeOfAKind() ) {
            // if the player's whatFullOf() is better than highestRankingHand's
            if( hand.whatFullOf() > whatFullOf() ) {
                return false;
            } // matches with if ( fullof() > )
            else
                return true;
        }// matches with if ( whatThreeOfAKind() == );
        else
            return true;
    }// matches with FULLHOUSE
    
    // if hand is FOUROFAKIND
    else if( evaluateHand() == HandRanking::FOUROFAKIND ) {
        // if the player's FOUROFAKIND is better than the highestRankingHand's
        if( hand.whatFourOfAKind() > whatFourOfAKind() ) {
            return false;
        }// matches with if FOUROFAKIND is better
        // if the FOUROFAKIND are the same
        else if( hand.whatFourOfAKind() == whatFourOfAKind() ) {
            // if the player's kicker beats the highestRankingHand's
            if( hand.whatKicker() > whatKicker() ) {
                return false;
            } // goes with if player's kicker beats highestRankingHand's
            else
                return true;
        } // matches with if the FOUROFAKIND are the same
        else
            return true;
    } // matches with FOUROFAKIND
    
    //if hand is STRAIGHTFLUSH
    else if( evaluateHand() == HandRanking::STRAIGHTFLUSH ) {
        // if the player's STRAIGHTFLUSH is better than the highestRankingHand's
        if( hand.getHighCard() > getHighCard() ) {
            return false;
        }// matches with if STRAIGHTFLUSH is better than highestRankingHand's
        else
            return true;
    }// matches with STRAIGHTFLUSH
    return true;
}



HandRanking FiveCardHand::evaluateHand() {
    sortLtoH();
    mHandRank = HandRanking::HIGHCARD;
    if( isPair() )
        mHandRank = HandRanking::PAIR;
    if( isTwoPair() )
        mHandRank = HandRanking::TWOPAIR;
    if( isThreeOfAKind() )
        mHandRank = HandRanking::THREEOFAKIND;
    if( isStraight() )
        mHandRank = HandRanking::STRAIGHT;
    if( isFlush() )
        mHandRank = HandRanking::FLUSH;
    if( isFullHouse() )
        mHandRank = HandRanking::FULLHOUSE;
    if( isFourOfAKind() )
        mHandRank = HandRanking::FOUROFAKIND;
    if( isStraightFlush() )
        mHandRank = HandRanking::STRAIGHTFLUSH;
    if( isRoyalFlush() )
        mHandRank = HandRanking::ROYALFLUSH;
    return mHandRank;
}
HandRanking FiveCardHand::getHandRank() {
    return mHandRank;
}

Face FiveCardHand::getHighCard() {
    sortLtoH();
    return mCards[4].getFace();
}

void FiveCardHand::printCards() {
    for( int i = 0; i < 5; ++i )
        cout << mCards[i].to_string() << endl;
}

string FiveCardHand::to_string() {
    string result;
    switch( evaluateHand() ) {
        case HandRanking::HIGHCARD :
            result = "High Card" ;
//            switch( getHighCard() ) {
//                case Face::DEUCE:
//                    result += "2";
//                    break;
//                case Face::THREE:
//                    result += "3";
//                case Face::FOUR:
//                    result += "4";
//                    break;
//                case Face::FIVE:
//                    result += "5";
//                    break;
//                case Face::SIX:
//                    result += "6";
//                    break;
//                case Face::SEVEN:
//                    result += "7";
//                    break;
//                case Face::EIGHT:
//                    result += "8";
//                    break;
//                case Face::NINE:
//                    result += "9";
//                    break;
//                case Face::TEN:
//                    result += "10";
//                    break;
//                case Face::JACK:
//                    result += "Jack";
//                    break;
//                case Face::QUEEN:
//                    result += "Queen";
//                    break;
//                case Face::KING:
//                    result += "King";
//                    break;
//                case Face::ACE:
//                    result += "Ace";
//                    break;
//            }
            break;
        case HandRanking::PAIR :
            result = "Pair";
            switch( whatPair() ) {
                case Face::DEUCE:
                    result += " of Dueces";
                    break;
                case Face::THREE:
                    result += " of Threes";
                    break;
                case Face::FOUR:
                    result += " of Fours";
                    break;
                case Face::FIVE:
                    result += " of Fives";
                    break;
                case Face::SIX:
                    result += " of Sixes";
                    break;
                case Face::SEVEN:
                    result += " of Sevens";
                    break;
                case Face::EIGHT:
                    result += " of Eights";
                    break;
                case Face::NINE:
                    result += " of Nines";
                    break;
                case Face::TEN:
                    result += " of Tens";
                    break;
                case Face::JACK:
                    result += " of Jacks";
                    break;
                case Face::QUEEN:
                    result += " of Queens";
                    break;
                case Face::KING:
                    result += " of Kings";
                    break;
                case Face::ACE:
                    result += " of Aces";
                    break;
            }
            break;
        case HandRanking::TWOPAIR :
            result = "Two Pair";
            switch( whatPair() ) {
                case Face::DEUCE:
                    result += ": Deuces and ";
                    break;
                case Face::THREE:
                    result += ": Threes and ";
                    break;
                case Face::FOUR:
                    result += ": Fours and ";
                    break;
                case Face::FIVE:
                    result += ": Fives and ";
                    break;
                case Face::SIX:
                    result += ": Sixes and ";
                    break;
                case Face::SEVEN:
                    result += ": Sevens and ";
                    break;
                case Face::EIGHT:
                    result += ": Eights and ";
                    break;
                case Face::NINE:
                    result += ": Nines and ";
                    break;
                case Face::TEN:
                    result += ": Tens and ";
                    break;
                case Face::JACK:
                    result += ": Jacks and ";
                    break;
                case Face::QUEEN:
                    result += ": Queens and ";
                    break;
                case Face::KING:
                    result += ": Kings and ";
                    break;
                case Face::ACE:
                    result += ": Aces and ";
                    break;
            }
            switch( whatSecondPair() ) {
                case Face::DEUCE:
                    result += "Deuces";
                    break;
                case Face::THREE:
                    result += "Threes";
                    break;
                case Face::FOUR:
                    result += "Fours";
                    break;
                case Face::FIVE:
                    result += "Fives";
                    break;
                case Face::SIX:
                    result += "Sixes";
                    break;
                case Face::SEVEN:
                    result += "Sevens";
                    break;
                case Face::EIGHT:
                    result += "Eights";
                    break;
                case Face::NINE:
                    result += "Nines";
                    break;
                case Face::TEN:
                    result += "Tens";
                    break;
                case Face::JACK:
                    result += "Jacks";
                    break;
                case Face::QUEEN:
                    result += "Queens";
                    break;
                case Face::KING:
                    result += "Kings";
                    break;
                case Face::ACE:
                    result += "Aces";
                    break;
            }
            break;
        case HandRanking::THREEOFAKIND:
            result = "Three of a Kind";
            switch( whatThreeOfAKind() ) {
                case Face::DEUCE:
                    result += ": Deuces";
                    break;
                case Face::THREE:
                    result += ": Threes";
                    break;
                case Face::FOUR:
                    result += ": Fours";
                    break;
                case Face::FIVE:
                    result += ": Fives";
                    break;
                case Face::SIX:
                    result += ": Sixes";
                    break;
                case Face::SEVEN:
                    result += ": Sevens";
                    break;
                case Face::EIGHT:
                    result += ": Eights";
                    break;
                case Face::NINE:
                    result += ": Nines";
                    break;
                case Face::TEN:
                    result += ": Tens";
                    break;
                case Face::JACK:
                    result += ": Jacks";
                    break;
                case Face::QUEEN:
                    result += ": Queens";
                    break;
                case Face::KING:
                    result += ": Kings";
                    break;
                case Face::ACE:
                    result += ": Aces";
                    break;
            }
            break;
        case HandRanking::STRAIGHT :
            result = "Straight";
            switch( getHighCard() ) {
                case Face::DEUCE:
                    result += ": Deuce High";
                    break;
                case Face::THREE:
                    result += ": Three High";
                    break;
                case Face::FOUR:
                    result += ": Four High";
                    break;
                case Face::FIVE:
                    result += ": Five High";
                    break;
                case Face::SIX:
                    result += ": Six High";
                    break;
                case Face::SEVEN:
                    result += ": Seven High";
                    break;
                case Face::EIGHT:
                    result += ": Eight High";
                    break;
                case Face::NINE:
                    result += ": Nine High";
                    break;
                case Face::TEN:
                    result += ": Ten High";
                    break;
                case Face::JACK:
                    result += ": Jack High";
                    break;
                case Face::QUEEN:
                    result += ": Queen High";
                    break;
                case Face::KING:
                    result += ": King High";
                    break;
                case Face::ACE:
                    if( mCards[3].getFace() == Face::FIVE ) {
                        result += ": Five High";
                    }
                    if( mCards[3].getFace() == Face::KING ) {
                        result += ": Ace High";
                    }
                    break;
            }
            break;
        case HandRanking::FLUSH :
            switch( getHighCard() ) {
                case Face::DEUCE:
                    result = "Deuce High ";
                    break;
                case Face::THREE:
                    result = "Three High ";
                    break;
                case Face::FOUR:
                    result = "Four High ";
                    break;
                case Face::FIVE:
                    result = "Five High ";
                    break;
                case Face::SIX:
                    result = "Six High ";
                    break;
                case Face::SEVEN:
                    result = "Seven High ";
                    break;
                case Face::EIGHT:
                    result = "Eight High ";
                    break;
                case Face::NINE:
                    result = "Nine High ";
                    break;
                case Face::TEN:
                    result = "Ten High ";
                    break;
                case Face::JACK:
                    result = "Jack High ";
                    break;
                case Face::QUEEN:
                    result = "Queen High ";
                    break;
                case Face::KING:
                    result = "King High ";
                    break;
                case Face::ACE:
                    result = "Ace High ";
                    break;
            }
            result += "Flush";
            break;
        case HandRanking::FULLHOUSE :
            switch( whatThreeOfAKind() ) {
                case Face::DEUCE:
                    result += "Deuces full of ";
                    break;
                case Face::THREE:
                    result += "Threes full of ";
                    break;
                case Face::FOUR:
                    result += "Fours full of ";
                    break;
                case Face::FIVE:
                    result += "Fives full of ";
                    break;
                case Face::SIX:
                    result += "Sixes full of ";
                    break;
                case Face::SEVEN:
                    result += "Sevens full of ";
                    break;
                case Face::EIGHT:
                    result += "Eights full of ";
                    break;
                case Face::NINE:
                    result += "Nines full of ";
                    break;
                case Face::TEN:
                    result += "Tens full of ";
                    break;
                case Face::JACK:
                    result += "Jacks full of ";
                    break;
                case Face::QUEEN:
                    result += "Queens full of ";
                    break;
                case Face::KING:
                    result += "Kings full of ";
                    break;
                case Face::ACE:
                    result += "Aces full of ";
                    break;
            }
            switch( whatFullOf() ) {
                case Face::DEUCE:
                    result += "Deuces";
                    break;
                case Face::THREE:
                    result += "Threes";
                    break;
                case Face::FOUR:
                    result += "Fours";
                    break;
                case Face::FIVE:
                    result += "Fives";
                    break;
                case Face::SIX:
                    result += "Sixes";
                    break;
                case Face::SEVEN:
                    result += "Sevens";
                    break;
                case Face::EIGHT:
                    result += "Eights";
                    break;
                case Face::NINE:
                    result += "Nines";
                    break;
                case Face::TEN:
                    result += "Tens";
                    break;
                case Face::JACK:
                    result += "Jacks";
                    break;
                case Face::QUEEN:
                    result += "Queens";
                    break;
                case Face::KING:
                    result += "Kings";
                    break;
                case Face::ACE:
                    result += "Aces";
                    break;
            }
            break;
        case HandRanking::FOUROFAKIND :
            result = "Quad ";
            switch( whatFourOfAKind() ) {
                case Face::DEUCE:
                    result += "Deuces";
                    break;
                case Face::THREE:
                    result += "Threes";
                    break;
                case Face::FOUR:
                    result += "Fours";
                    break;
                case Face::FIVE:
                    result += "Fives";
                    break;
                case Face::SIX:
                    result += "Sixes";
                    break;
                case Face::SEVEN:
                    result += "Sevens";
                    break;
                case Face::EIGHT:
                    result += "Eights";
                    break;
                case Face::NINE:
                    result += "Nines";
                    break;
                case Face::TEN:
                    result += "Tens";
                    break;
                case Face::JACK:
                    result += "Jacks";
                    break;
                case Face::QUEEN:
                    result += "Queens";
                    break;
                case Face::KING:
                    result += "Kings";
                    break;
                case Face::ACE:
                    result += "Aces";
                    break;
            }
            break;
        case HandRanking::STRAIGHTFLUSH :
            switch( getHighCard() ) {
                case Face::DEUCE:
                    result = "Deuce High ";
                    break;
                case Face::THREE:
                    result = "Three High ";
                    break;
                case Face::FOUR:
                    result = "Four High ";
                    break;
                case Face::FIVE:
                    result = "Five High ";
                    break;
                case Face::SIX:
                    result = "Six High ";
                    break;
                case Face::SEVEN:
                    result = "Seven High ";
                    break;
                case Face::EIGHT:
                    result = "Eight High ";
                    break;
                case Face::NINE:
                    result = "Nine High ";
                    break;
                case Face::TEN:
                    result = "Ten High ";
                    break;
                case Face::JACK:
                    result = "Jack High ";
                    break;
                case Face::QUEEN:
                    result = "Queen High ";
                    break;
                case Face::KING:
                    result = "King High ";
                    break;
                case Face::ACE:
                    result = "Ace High ";
                    break;
            }

            result += "Straight Flush";
            break;
            
        case HandRanking::ROYALFLUSH :
            result = "Royal Flush";
            break;
    }
    return result;
}
