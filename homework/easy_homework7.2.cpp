// Deck of cards
//each card is a 3 digit number, the first one being the Suit, the second and third are the Face of the CARD
//example: 101 - ace of spades; 206 - six of hearts; 312 - queen of diamonds; 411 - jack of clubs
#include <iostream>
#include <time.h>
using namespace std;

int const MAX_SIZE = 52;

void fillDeck(int deck[]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << "card[" << i << "] -- ";
		cin >> deck[i];
	}
}

void swap(int arr[], unsigned i, unsigned j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void sortDeck(int deck[]) {
	bool changed = false; 
	unsigned sorted = 0;
	do {
		changed = false;
		for (unsigned i = MAX_SIZE - 1; i > sorted; i--) {
			if ((deck[i] % 100) < (deck[i - 1] % 100)) {
				swap(deck, i, i - 1);
				changed = true;
			}
		}
		sorted++;
	} while (changed);

	bool changedSuit = false;
	unsigned sortedSuit = 0;

	do {
		changedSuit = false;
		for (unsigned i = MAX_SIZE - 1; i > sortedSuit; i--) {
			if ((deck[i] % 100) == (deck[i - 1] % 100)) {
				if ((deck[i] / 100) > (deck[i - 1] / 100)) {
					swap(deck, i, i - 1);
					changedSuit = true;
				}
			}
		}
		sortedSuit++;
	} while (changedSuit);
}

void printDeck(int deck[]) {
	cout << "**DECK**" << endl;
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << "Card " << i << ": " << deck[i] << endl;
	}
}

void shuffle(int deck[]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		int index = rand() % 52;
		swap(deck, i, index);
		cout << "Card on position: " << i << " is going on position: " << index << endl;
	}
}

int main()
{
	srand(time(NULL));
	int deck[MAX_SIZE];

	fillDeck(deck);

	sortDeck(deck);

	shuffle(deck);
	printDeck(deck);

	sortDeck(deck);
	printDeck(deck);

	return 0;
}

