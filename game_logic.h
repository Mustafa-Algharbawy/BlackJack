//
// Created by dn on 12/31/17.
//

#ifndef TESTINGAREA_GAME_LOGIC_H
#define TESTINGAREA_GAME_LOGIC_H


#include "Deck.h"

void Match();

int round();
int GetPlayerChoice(bool);
int ChooseBettingValue();
bool Frist2CardsAndSpliting(int &, int &, Deck &);
bool BlackJack(int &, int &, int &);
void Hit(int &);
void Stand();
void DoubleDown(int &);
void Split(int &, int &);
void DealerTurn(int &, int &);
void PremiumPlayer(int &, int &);
int RoundWinning(int &, int &, int &);


#endif //TESTINGAREA_GAME_LOGIC_H
