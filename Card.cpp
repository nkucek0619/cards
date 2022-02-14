 /*
    Cards.cpp
    Author: Nicholas Kucek
    Create a deck of 52 cards in C++ using lists and implement print, shuffle, sort by rank, and sort by suit and rank functions
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <utility>

class Card {
    public:
        // constructor
        Card(std::string suit, std::string rank) {
            Suit = suit;
            Rank = rank;
        }
        std::string Suit;
        std::string Rank;
};

//Create two string arrays to use for overloaded operator << function
std::string suits[] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
std::string ranks[] = {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN",
"EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};

// make a new deck with 52 cards
void makeDeck(std::vector<Card>& deck) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            Card card(suits[i], ranks[j]);
            deck.push_back(card);
        }
    }
}

// print the deck of cards to the console
void printDeck(std::vector<Card> deck) {
    for(int i = 0; i < deck.size(); i++) {
        Card card = deck[i];
        std::cout << card.Rank << " of " << card.Suit << "\n";
    }
}

// return a shuffled deck
void shuffleDeck(std::vector<Card>& deck) {
    srand(time(NULL));
    std::random_shuffle(deck.begin(), deck.end());
}

void sortByRank(std::vector<Card>& deck) {
    std::sort( std::begin(deck), std::end(deck), [] ( const Card& a, const Card& b ) {
        return a.Rank > b.Rank; } );
}

void sortBySuitAndRank(std::vector<Card>& deck) {
    std::sort( std::begin(deck), std::end(deck), [] ( const Card& a, const Card& b ) {
        return std::make_pair(a.Rank,b.Suit) > std::make_pair(b.Rank,a.Suit); } );
}

int main() {

    std::vector<Card> deck;
    makeDeck(deck);
    std::cout << "52 cards in a deck.\n\n";
    shuffleDeck(deck);
    std::cout << "\nShuffled deck:\n";
    printDeck(deck);
    sortByRank(deck);
    std::cout << "\nSorted by Rank:\n";
    printDeck(deck);
    sortBySuitAndRank(deck);
    std::cout << "\nSorted by Suit and Rank:\n";
    printDeck(deck);
}