#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "player.h"

using namespace std;

Player::Player() {
	myName = "";
}

Player::Player(string name) {
	myName = name;
}

string Player::getName() const {
	return myName;
//cout << "myName" << endl;
}

void Player::addCard(Card c) {
	myHand.push_back(c);
//	cout << c.getRank() << endl; 
	//myHand.insert(myHand.begin(),c);
}

void Player::bookCards(Card c1, Card c2) {
	myBook.push_back(c1);
	myBook.push_back(c2);
}

bool Player::rankInHand(Card c) const {
	for(int i = 0;i < myHand.size();i++) {
		if(myHand[i].getRank() == c.getRank())
			return true;
	}	
	return false;
}

Card Player::chooseCardFromHand() const {
	if(myHand.size() != 0) 
		return(myHand[0]);
}

bool Player::cardInHand(Card c) const {
	for(int i = 0;i < myHand.size();i++) {
		if(myHand[i] == c)
			return true;
	}
	return false;
}

Card Player::removeCardFromHand(Card c) {
	int i;
	for(i = 0;i < myHand.size();i++) {
		if (myHand[i] == c)
			break;
	}
	myHand.erase(myHand.begin()+i);
	return c;
}

string Player::showHand() const {
	string result;
	string space = " ";
	for(int i = 0;i < myHand.size();i++) {
//cout << "5" << endl;
//cout << myHand[i].toString() << endl;
		result = result + myHand[i].toString();
		result = result + space;
	}
//cout << "success" << endl;
//cout << myHand.front().toString() << endl;
	return result;
}

string Player::showBooks() const {
	string result;
	string space = " ";
	for(int i = 0;i < myBook.size();i++) {
		result = result + myBook[i].toString();
		result = result + space;
	}
	return result;
}

int Player::getHandSize() const {
	return(myHand.size());
}

int Player::getBookSize() const {
	return(myBook.size());
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
	for(int i = 0;i < myHand.size();i++) {
		for(int j = 0;j < myHand.size();j++) {
			if(i != j && myHand[i].getRank() == myHand[j].getRank()) {
				c1 = myHand[i];
				c2 = myHand[j];
				return true;
			}
		}
	}
	return false;
}

Card Player::sameRankInHand(Card c) const {
	for(int i = 0;i < myHand.size();i++) {
		if(myHand[i].getRank() == c.getRank())
			return myHand[i];
	}
}





