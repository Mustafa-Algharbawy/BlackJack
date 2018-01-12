//
// Created by dn on 12/28/17.
//

#ifndef TESTINGAREA_DECK_H
#define TESTINGAREA_DECK_H

#include <array>
#include "Card.h"

// el class da kol el methods elley fe mmomkn tb2a static ///okay
// msh ht7tag t3ml mno instance <- eh da ?!
// htnady el methods 3la tol mn 3'er ma t3ml nos5a mno aha faker an ael point de
// mmkn t2ra 3n design pattern esmo singelton bardo
//la mish w2to 3lshan ana fe nos el OOP
// tyb any other ideas about how to use create the class fe 7ta mish global
// a3mlo fe el function elley btst5dmo feha
//t2sod fe koll fun a3ml create ll class
// ah, aw low akter mn method fe nfs el class bt7tago 76 mno ns5a fe el class
// ma ana mish bst5dem el object fe class tani ana use it in functios
// bs ta3la ntmsha shoya w hfhmk 3lshan 3aez a5rog
// OK :D
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
