//
// Created by dn on 12/28/17.
//
#include <iostream>
#include <cassert>
#include "Deck.h"

// deck , 2sdo meen ?
std::array<Card, 52> Deck::m_deck ;
int Deck::m_cardIndex ;
//get ERROR if i tried to make it static
int Deck::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Deck::swapCard(Card &a, Card &b)
{
    Card temp = a;
    a = b;
    b = temp;
}

Deck::Deck()
{
    int card = 0;
    for (int suit = 0; suit < static_cast<int>(Card::CardSuit::MAX_SUITS); ++suit) {
        for (int rank = 0; rank < static_cast<int>(Card::CardRank::MAX_RANKS); ++rank) {
            m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
            ++card;
        }
    }

    //is it the right way to call a member function inside the constractor
//    Deck::shuffleDeck();
//no need for shuffling inside the constractor coz we may need deck of card in any other games

}

void Deck::printDeck()
{
    for (const auto &card : m_deck) {
        card.printCard();
        std::cout << ' ';
    }

    std::cout << '\n';
}

void Deck::shuffleDeck()
{
    for (int index = 0; index < 52; ++index) {
        int swapIndex = getRandomNumber(0, 51);
        swapCard(m_deck[index], m_deck[swapIndex]);
    }
}
 const Card &Deck::dealCard()
{
    assert (m_cardIndex < 52);
    return m_deck[m_cardIndex++];
}