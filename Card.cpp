//
// Created by dn on 12/28/17.
//

#include "Card.h"
#include <iostream>


Card::Card(CardRank rank, CardSuit suit): m_rank(rank), m_suit(suit)
{

}
std::string Card::printCard() const
{
    switch (m_rank) {
        case CardRank::RANK_2:
            return "2";
            break;
        case CardRank::RANK_3:
            return "3";
            break;
        case CardRank::RANK_4:
            return "4";
            break;
        case CardRank::RANK_5:
            return "5";
            break;
        case CardRank::RANK_6:
            return "6";
            break;
        case CardRank::RANK_7:
            return "7";
            break;
        case CardRank::RANK_8:
            return "8";
            break;
        case CardRank::RANK_9:
            return "9";
            break;
        case CardRank::RANK_10:
            return "T";
            break;
        case CardRank::RANK_JACK:
            return "J";
            break;
        case CardRank::RANK_QUEEN:
            return "Q";
            break;
        case CardRank::RANK_KING:
            return "K";
            break;
        case CardRank::RANK_ACE:
            return "A";
            break;
    }

  
}

int Card::getCardValue() const
{
    switch (m_rank) {
        case CardRank::RANK_2:
            return 2;
        case CardRank::RANK_3:
            return 3;
        case CardRank::RANK_4:
            return 4;
        case CardRank::RANK_5:
            return 5;
        case CardRank::RANK_6:
            return 6;
        case CardRank::RANK_7:
            return 7;
        case CardRank::RANK_8:
            return 8;
        case CardRank::RANK_9:
            return 9;
        case CardRank::RANK_10:
            return 10;
        case CardRank::RANK_JACK:
            return 10;
        case CardRank::RANK_QUEEN:
            return 10;
        case CardRank::RANK_KING:
            return 10;
        case CardRank::RANK_ACE:
            return 11;
    }

    return 0;
}

