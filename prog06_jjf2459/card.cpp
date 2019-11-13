#include <iostream>
#include <cstdlib>
#include <string>
#include "card.h"

using namespace std;

Card::Card() {
	mySuit = spades;
	myRank = 1;
}

Card::Card(int rank, Suit s) {
	mySuit = s;
	myRank = rank;
}

string Card::toString() const {
	string suit = suitString(mySuit);
	string rank = rankString(myRank);
	return(rank + suit);
//	cout << suit << " " << rank << endl;
	//return "card tostring";
}

bool Card::sameSuitAs(const Card& c) const {
	return(mySuit == c.mySuit);
}

int Card::getRank() const {
	return(myRank);
}

string Card::suitString(Suit s) const {
	switch(s) {
		case spades: return("s");
		break;
		case hearts: return("h");
		break;
		case diamonds: return("d");
		break;
		case clubs: return("c");
		break;
	}
}

string Card::rankString(int r) const {
	//cout << "r: " <<  r << endl;
	switch(r) {
		case 1: return("A");
		case 11: return("J");
		case 12: return("Q");
		case 13: return("K");
		case 2: return("2");
		case 3: return("3");
		case 4: return("4");
                case 5: return("5");
		case 6: return("6");
                case 7: return("7");
		case 8: return("8");
                case 9: return("9");
		case 10: return("10");
		default: return "null";
	}
}

bool Card::operator ==(const Card& rhs) const {
	return(mySuit == rhs.mySuit && myRank == rhs.myRank);
}

bool Card::operator !=(const Card& rhs) const {
	return(!(mySuit == rhs.mySuit && myRank == rhs.myRank));
}


ostream& operator << (ostream& out, const Card& c) {
	out << c.toString();
	return out;
}




