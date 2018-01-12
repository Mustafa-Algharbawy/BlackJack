//
// Created by dn on 12/28/17.
//

#include <string>


#ifndef TESTINGAREA_CARD_H
#define TESTINGAREA_CARD_H


class Card
{
  public:
    enum class CardRank
    {
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_10,
        RANK_JACK,
        RANK_QUEEN,
        RANK_KING,
        RANK_ACE,
        MAX_RANKS
    };

    enum class CardSuit
    {
        SUIT_CLUB,
        SUIT_DIAMOND,
        SUIT_HEART,
        SUIT_SPADE,
        MAX_SUITS
    };


  private:
    CardRank m_rank;
    CardSuit m_suit;
  public:
    Card(Card::CardRank rank = CardRank::RANK_ACE,
         Card::CardSuit suit = CardSuit::SUIT_HEART);
    std::string printCard() const;

    int getCardValue() const;

};


#endif //TESTINGAREA_CARD_H
