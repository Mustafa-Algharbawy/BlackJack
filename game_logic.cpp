//
// Created by dn on 12/31/17.
//
#include <iostream>
#include "game_logic.h"
Deck deck;//tkbeeeeeeeeeeeeer
// mt3mlsh 7aga global tany w belzat fe .h
// ok but now ana m7tag el class da fe kza function a3mlo ezay ?
//
void Match()
{
    std::string match_result {"Tourament Complete\nYou finished this tourament with "};
//    Deck deck;
    deck.shuffleDeck();

    int mount_money = 5000;
    while (mount_money > 0) {
        mount_money += round();

    }
    std::cout << match_result<< mount_money<<'\n';


}



int round()
{

    int value_of_bet = ChooseBettingValue();
//    int roundResult = 0;
    int player_total = 0;
    int splited_player = 0;
    int dealer_total = 0;
    bool spliting = Frist2CardsAndSpliting(player_total, dealer_total, deck);
    if (BlackJack(player_total, dealer_total, value_of_bet)) {
        //if there is blackjack we ignore ther rest of the round
        // and return the betting value
        return value_of_bet;

    }
//    int player_choise = GetPlayerChoice(spliting);
    while (GetPlayerChoice(spliting) == 1 and player_total < 21) {
        switch (GetPlayerChoice(spliting)) {
            case 1: {
                Hit(player_total);
                break;
            }
            case 2: {
                Stand();
                break;
            }
            case 3: {
                DoubleDown(player_total);
                break;
            }
            case 4: {
                Split(player_total, splited_player);
                break;
            }
            default:
                break;
        }

    }
    PremiumPlayer(player_total, splited_player);
    DealerTurn(player_total, dealer_total);
    return RoundWinning(value_of_bet, player_total , dealer_total);

}

void PremiumPlayer(int &premium_player, int &splited_player)
{

    if (splited_player > premium_player and splited_player <= 21) {
        int temp = premium_player;
        premium_player = splited_player;
        splited_player = temp;
    }

}

int ChooseBettingValue()
{
    std::cout << "Choose beting Value of these values :-\n\t10\t25\t100\t250\tMaxVlue" << '\n';
    int choice;
    do {
        std::cin >> choice;
    }
    while (
        choice != 10 &&
            choice != 25 &&
            choice != 100 &&
            choice != 250 &&
            choice != 500
        );
    return choice;

}
bool Frist2CardsAndSpliting(int &player_total, int &dealer_total, Deck &deck)
{

    Card hit_card = deck.dealCard();

    int frist_card = hit_card.getCardValue();
    std::string player_frist_card = hit_card.printCard();

    dealer_total += deck.dealCard().getCardValue();

    hit_card = deck.dealCard();
    int secont_card = hit_card.getCardValue();
    std::string player_second_card = hit_card.printCard();

    hit_card = deck.dealCard();
    std::string dealer_card = hit_card.printCard();
    dealer_total += hit_card.getCardValue();

    std::string player_card_printing = "You have: " + player_frist_card + " and " + player_second_card + "\n";
    std::string dealer_card_printing = "The dealer is showing: " + dealer_card + "\n";

    player_total = frist_card + secont_card;

    return player_frist_card == player_second_card;

}
bool BlackJack(int &player_total, int &dealer_total, int &value_of_bet)
{
    if (player_total == 21 or dealer_total == 21) {
        if (player_total == 21) {
            value_of_bet += (value_of_bet / 2);
            std::cout << "***BlackJack***\n";

        }
        else if (dealer_total == 21) {
            value_of_bet = (value_of_bet + value_of_bet / 2) * -1;
            std::cout << "DEALER WON\n";

        }
        return 1;
    }
    return 0;
}
int GetPlayerChoice(bool split)
{

// 1- Hit.
// 2- Stand.
// 3-Double down.
// 4- Splite.

    if (split) {
        int choice;
        while (1) {
            std::cout << "Enter the numper of you choise :\n1- Hit.\n2- Stand.\n3- Double down.\n4- Splite.\n";
            std::cin >> choice;
            if (choice > 0 and choice < 5) {
                break;
            }
            else {
                for (int i = 0; i < 15; ++i) {
                    std::cout << '\n';
                }
            }
        }
        return choice;
    }
    else {
        int choice;
        while (1) {
            std::cout << "Enter the numper of you choise :\n1- Hit.\n2- Stand.\n3- Double down.\n";
            std::cin >> choice;
            if (choice > 0 and choice < 4) {
                break;
            }
            else {
                for (int i = 0; i < 15; ++i) {
                    std::cout << '\n';
                }
            }
        }
        return choice;
    }
}
void Split(int &player_total, int &splited_player)
{
    splited_player = player_total / 2;
    while (GetPlayerChoice(0) == 1 and splited_player < 21) {
        switch (GetPlayerChoice(0)) {
            case 1: {
                Hit(splited_player);
                break;
            }
            case 2: {
                Stand();
                break;
            }
            case 3: {
                DoubleDown(splited_player);
                break;
            }
                //should be deleted coz unneeded case
//            case 4: {
//                Split();
//                break;
//            }
            default:
                break;
        }

    }

}

void Hit(int &total)
{
//    return Deck::dealCard().getCardValue();
    total += deck.dealCard().getCardValue();
    //check crossing 21
}
void Stand()
{
    //nothing to do just for the beauty of the program :D

}
void DoubleDown(int &player_total)
{
    Hit(player_total);
}
void DealerTurn(int &player_total, int &dealer_total)
{
    while (dealer_total < player_total) {
        Hit(dealer_total);
    }
}
int RoundWinning(int &bet_value, int &player, int &dealer)
{

    if (player > dealer) {
        std::cout << "YOU WIN!" << '\n';

        std::cout << '+' << bet_value << '\n';
        return bet_value;
    }
    else if (player < dealer) {
        std::cout << "DEALER WON" << '\n';
        std::cout << '-' << bet_value << '\n';
        return -1 * bet_value;

    }
    else {
        std::cout << "PUSH" << '\n';
        return 0;
    }
}