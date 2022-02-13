/*
    Author: Nicholas Kucek
    Date: 02/12/22
    
    @Interview Coding Test for Open Practice Solutions:
    @Create a deck of cards which will be shuffled and sorted
    @Card.cpp: definition file for Card class
*/

#include <time.h>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>

// Card class with Suit and Rank listed in order as strings
class Card {
    private:
        std::string Suit, Rank;
        std::map<std::string, int> suits {{"CLUBS", 1}, {"DIAMONDS", 2}, {"HEARTS", 3}, {"SPADES", 4}};
        std::map<std::string, int> ranks {{"TWO", 1}, {"THREE", 2}, {"FOUR", 3}, {"FIVE", 4}, {"SIX", 5}, {"SEVEN", 6}, {"EIGHT", 7},
        {"NINE", 8}, {"TEN", 9}, {"JACK", 10}, {"QUEEN", 11}, {"KING", 12}, {"ACE", 13}};
        std::map<std::string, int>::iterator its, itr;

    public:
        // constructor
        Card(std::string suit, std::string rank) {
            Suit = suit;
            Rank = rank;
        }

        // make a new deck with 52 cards
        void makeDeck(std::list<Card>& deck) {
            for(its = suits.begin(); its != suits.end(); its++) {
                for(itr = ranks.begin(); itr != ranks.end(); itr++) {
                    Card card(its->first, itr->first);
                    deck.push_back(card);
                }
            }
        }

        // print the deck of cards to the console
        void printDeck(std::list<Card> deck) {
            for(std::list<Card>::iterator it = deck.begin(); it != deck.end(); ++it) {
                Card card = *it; 
                std::string suit = card.Suit, rank = card.Rank;
                std::cout << rank << " of " << suit << "\n";
            }
        }

        // return a shuffled deck
        void shuffleDeck(std::list<Card>& deck) {
            srand(time(NULL));
            std::vector<Card> temp(deck.begin(), deck.end());
            std::random_shuffle(temp.begin(), temp.end());
            std::copy(temp.begin(), temp.end(), deck.begin());
        }

        // creates custom sort operator that allows a sorting algorithm to sort the cards by either rank or suit
        struct {
        bool operator()(Card a, Card b) const { return a.Rank > b.Rank; }
        } rankSort;

        // sort the deck of cards by rank and print to the console
        void sortByRank(std::list<Card>& deck) {
            std::vector<Card> cardsList{ std::make_move_iterator(std::begin(deck)), 
                                         std::make_move_iterator(std::end(deck)) };
            std::sort(cardsList.begin(), cardsList.end(), rankSort);
            std::copy(cardsList.begin(), cardsList.end(), deck.begin());
        }

        // sort the deck of cards by suit then rank and print to the console
        void sortBySuitAndRank(std::list<Card>& deck) {
            
        }

};

// tests
int main(int argc, char *argv[]) {

    std::cout << "52 cards in a deck.\n";
    Card card("Empty Suit", "Empty Rank"); // make an empty card to use class functions
    std::list<Card> deck;
    card.makeDeck(deck);
    // print
    card.printDeck(deck);
    // shuffle
    card.shuffleDeck(deck);
    std::cout << "\nShuffled Deck:\n";
    card.printDeck(deck);
    // sort by rank
    card.sortByRank(deck);
    std::cout << "\nSorted by Rank:\n";
    card.printDeck(deck);
    // sort by suit and rank
    /*card.sortBySuitAndRank(deck);
    std::cout << "\nSorted by Suit and Rank:\n";
    card.printDeck(deck);*/
    
    return 0;
}
