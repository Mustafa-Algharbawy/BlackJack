//
// Created by dn on 12/31/17.
//

#ifndef TESTINGAREA_GAME_LOGIC_H
#define TESTINGAREA_GAME_LOGIC_H


#include "Deck.h"

 // enta 7atet sa6r zy da fe file kman
//laaa w 23dt adwar ml2tsh
// ana shakek en mynf3sh a7oto hina
//3lshan lma bgeb ek incloude fe kza file tany b create el
// aywa , lma t include el file da fe kza mkan bt3ml mno ns5teen
//tyb swani
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
