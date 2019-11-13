#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include "deck.h"
#include "card.h"

using namespace std;

Deck::Deck() {
	int myIndex = 0;
	for(int i = 1;i<=13;i++) {
		myCards[myIndex] = Card(i,Card::spades);
		myIndex++;
	}
        for(int i = 1;i<=13;i++) {
                myCards[myIndex] = Card(i,Card::hearts);
		myIndex++;
        }
        for(int i = 1;i<=13;i++) {
                myCards[myIndex] = Card(i,Card::diamonds);
		myIndex++;
        }
        for(int i = 1;i<=13;i++) {
                myCards[myIndex] = Card(i,Card::clubs);
        	myIndex++;
	}
	myIndex = 0;  //top of deck pointer
}

void Deck::shuffle() {
	//cout << "before shuffle: " << myIndex << endl;
	unsigned int currentTime = (unsigned)time(0);
        srand(currentTime);
	
	for(int i = 0;i < 2*SIZE;i++) {
		long swap1 = rand() % SIZE;
		long swap2 = rand() % SIZE;
		Card temp;
		temp = myCards[swap1];
		myCards[swap1] = myCards[swap2];
		myCards[swap2] = temp;
	}
	//cout << "after shuffle: " << myIndex << endl;
}

Card Deck::dealCard() {
//cout << "dealing a card" << endl;
	//cout << "index " << myIndex << "end" << endl;
	if(myIndex < SIZE && myIndex >= 0) {
		myIndex++;
		return(myCards[myIndex-1]);
	}
//cout << "card dealt" << endl;
}

int Deck::size() const {
	return(SIZE-myIndex);
}
