package tangible;
import java.util.*;

 /*
    Cards.cpp
    Author: Nicholas Kucek
    Create a deck of 52 cards in C++ using lists and implement print, shuffle, sort by rank, and sort by suit and rank functions
*/


public class Card
{
		// constructor
		public Card(String suit, String rank)
		{
			Suit = suit;
			Rank = rank;
		}
		public String Suit = "";
		public String Rank = "";
}

public class Globals
{
	//Create two string arrays to use for overloaded operator << function
	public static String[] suits = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
	public static String[] ranks = {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};

	// make a new deck with 52 cards
	public static void makeDeck(ArrayList<Card> deck)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				Card card = new Card(suits[i], ranks[j]);
				deck.add(card);
			}
		}
	}

	// print the deck of cards to the console
	public static void printDeck(ArrayList<Card> deck)
	{
		for (int i = 0; i < deck.size(); i++)
		{
			Card card = deck.get(i);
			System.out.print(card.Rank + " of " + card.Suit + "\n");
		}
	}

	// return a shuffled deck
	public static void shuffleDeck(ArrayList<Card> deck)
	{
		tangible.RandomNumbers.seed();
		Collections.shuffle(deck);
	}

	public static void sortByRank(ArrayList<Card> deck)
	{
//C++ TO JAVA CONVERTER TODO TASK: The 'Compare' parameter of std::sort produces a boolean value, while the Java Comparator parameter produces a tri-state result:
//ORIGINAL LINE: std::sort(std::begin(deck), std::end(deck), [] (const Card& a, const Card& b)
	Collections.sort(deck, (Card a, Card b) ->
	{
		return a.Rank.compareTo(b.Rank) > 0;
	});
	}

	public static void sortBySuitAndRank(ArrayList<Card> deck)
	{
//C++ TO JAVA CONVERTER TODO TASK: The 'Compare' parameter of std::sort produces a boolean value, while the Java Comparator parameter produces a tri-state result:
//ORIGINAL LINE: std::sort(std::begin(deck), std::end(deck), [] (const Card& a, const Card& b)
	Collections.sort(deck, (Card a, Card b) ->
	{
		return new tangible.Pair<String, String>(a.Rank,b.Suit) > new tangible.Pair<String, String>(b.Rank,a.Suit);
	});
	}

	public static void main(String[] args)
	{

		ArrayList<Card> deck = new ArrayList<Card>();
		makeDeck(deck);
		System.out.print("52 cards in a deck.\n\n");
		shuffleDeck(deck);
		System.out.print("\nShuffled deck:\n");
		printDeck(new ArrayList<Card>(deck));
		sortByRank(deck);
		System.out.print("\nSorted by Rank:\n");
		printDeck(new ArrayList<Card>(deck));
		sortBySuitAndRank(deck);
		System.out.print("\nSorted by Suit and Rank:\n");
		printDeck(new ArrayList<Card>(deck));
	}
}

//----------------------------------------------------------------------------------------
//	Copyright © 2006 - 2022 Tangible Software Solutions, Inc.
//	This class can be used by anyone provided that the copyright notice remains intact.
//
//	This class provides the ability to replicate the behavior of the C/C++ functions for 
//	generating random numbers.
//	'rand' converts to the parameterless overload of NextNumber
//	'random' converts to the single-parameter overload of NextNumber
//	'randomize' converts to the parameterless overload of Seed
//	'srand' converts to the single-parameter overload of Seed
//----------------------------------------------------------------------------------------
public final class RandomNumbers {
	private static java.util.Random r;

	public static int nextNumber()
	{
		if (r == null)
			Seed();

		return r.nextInt();
	}

	public static int nextNumber(int ceiling)
	{
		if (r == null)
			Seed();

		return r.nextInt(ceiling);
	}

	public static void seed()
	{
		r = new java.util.Random();
	}

	public static void seed(int seed)
	{
		r = new java.util.Random(seed);
	}
}

//----------------------------------------------------------------------------------------
//	Copyright © 2006 - 2022 Tangible Software Solutions, Inc.
//	This class can be used by anyone provided that the copyright notice remains intact.
//
//	This class replaces the C++ std::pair type.
//----------------------------------------------------------------------------------------
public final class Pair<T1, T2>
{
	public T1 first;
	public T2 second;

	public Pair()
	{
		first = null;
		second = null;
	}

	public Pair(T1 firstValue, T2 secondValue)
	{
		first = firstValue;
		second = secondValue;
	}

	public Pair(Pair<T1, T2> pairToCopy)
	{
		first = pairToCopy.first;
		second = pairToCopy.second;
	}
}
//jcar() { javac $1.java && java $1 ; }
//jcar Program