//
// Created by dn on 12/28/17.
//

#ifndef TESTINGAREA_DECK_H
#define TESTINGAREA_DECK_H

#include <array>
#include "Card.h"

class Deck
{
  private:
    static std::array<Card, 52> m_deck; // lma t3ml static variable lazem t3rfo fe el cpp
    //tmam la7za kida
    //ha3rfo ezay a
    static int m_cardIndex;

    static int getRandomNumber(int, int);
    void swapCard(Card &, Card &);
  public:
    Deck();
    void printDeck();
    void shuffleDeck();
    static const Card &dealCard();

};

#endif //TESTINGAREA_DECK_H
