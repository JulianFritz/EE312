#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);

int main( ) {

	int numCards = 7;
    
	Player p1("Joe");
	Player p2("Jane");
    
	Deck d;  //create a deck of cards
	d.shuffle();
    
	dealHand(d, p1, numCards);
	dealHand(d, p2, numCards);
       
	ofstream oFile;
	oFile.open("gofish_results.txt");
	
	oFile << p1.getName() << " and " << p2.getName() << " want to play GoFish! Let's begin:" << endl;
	oFile << "The hands are dealt!" << endl;
	oFile << p1.getName() << " has: " << p1.showHand() << endl;
	oFile << p2.getName() << " has: " << p2.showHand() << endl << endl;

	int p1TurnOver = 0;
	int p2TurnOver = 0;
	while (1) {
		if ((d.size() == 0)&&(p1.getHandSize() == 0)&&(p2.getHandSize() == 0))
			break;	
		while(p1TurnOver == 0) {
			Card cPair1;
			Card cPair2;
			while(p1.checkHandForPair(cPair1, cPair2)) {
				p1.bookCards(cPair1, cPair2);
	                        oFile << p1.getName() << " books the pair of " << cPair1.rankString(cPair1.getRank()) << endl;
	                        Card tempCard = p1.removeCardFromHand(cPair1);
	                        tempCard = p1.removeCardFromHand(cPair2);    //the function returns a Card for no reason
			}
				if(p1.getHandSize() == 0) {
				oFile << p1.getName() << "'s hand is empty" << endl;
				if(d.size() != 0) {
					Card cToAdd = d.dealCard();
					p1.addCard(cToAdd);
					oFile << p1.getName() << " draws " << cToAdd << endl;
				}
				oFile << endl;
				break;
			}
			Card cToAsk = p1.chooseCardFromHand();
			oFile << p1.getName() << " asks - Do you have a " << cToAsk.rankString(cToAsk.getRank()) << endl;
			if (!(p2.rankInHand(cToAsk))) {
				oFile << p2.getName() << " says - Go Fish" << endl;
				Card cToAdd = d.dealCard();
				p1.addCard(cToAdd);
				oFile << p1.getName() << " draws " << cToAdd << endl;
				p1TurnOver = 1;
			} else {
				oFile << p2.getName() << " says - Yes. I have a " << cToAsk.rankString(cToAsk.getRank()) << endl;
				Card cReceived = p2.sameRankInHand(cToAsk); //will return p2's card of same rank
				cReceived = p2.removeCardFromHand(cReceived);
				p1.addCard(cReceived);
				p1.bookCards(cToAsk, cReceived);
				oFile << p1.getName() << " books the " << cToAsk.rankString(cToAsk.getRank()) << endl;
				Card tempCard = p1.removeCardFromHand(cToAsk);
				tempCard = p1.removeCardFromHand(cReceived); 	//the function returns a Card for no reason
			}
		oFile << endl;
		}
		p1TurnOver = 0;
		//oFile << endl << p1.getName() << " has: " << p1.showHand() << " and " << p1.showBooks() << endl;
		//oFile << p2.getName() << " has: " << p2.showHand() << " and " << p2.showBooks()  << endl << endl;
		
		if((d.size() == 0)&&(p1.getHandSize() == 0)&&(p2.getHandSize() == 0))
			break;
		while(p2TurnOver == 0) {
	                Card cPair1;
	                Card cPair2;
	                while(p2.checkHandForPair(cPair1, cPair2)) {
	                        p2.bookCards(cPair1, cPair2);
	                        oFile << p2.getName() << " books the pair of " << cPair1.rankString(cPair1.getRank()) << endl;
	                        Card tempCard = p2.removeCardFromHand(cPair1);
	                        tempCard = p2.removeCardFromHand(cPair2);    //the function returns a Card for no reason
	                }
	                if(p2.getHandSize() == 0) {
	                        oFile << p2.getName() << "'s hand is empty" << endl;
				if(d.size() != 0) {
		                        Card cToAdd = d.dealCard();
	       	                	p2.addCard(cToAdd);
	                        	oFile << p2.getName() << " draws " << cToAdd << endl;
				}
				oFile << endl;
	                        break;
	                }
			Card cToAsk = p2.chooseCardFromHand();
	                oFile << p2.getName() << " asks - Do you have a " << cToAsk.rankString(cToAsk.getRank()) << endl;
	                if (!(p1.rankInHand(cToAsk))) {
	                        oFile << p1.getName() << " says - Go Fish" << endl;
	                        Card cToAdd = d.dealCard();
	                        p2.addCard(cToAdd);
	                        oFile << p2.getName() << " draws " << cToAdd << endl;
	                        p2TurnOver = 1;
	                } else {
	                        oFile << p1.getName() << " says - Yes. I have a " << cToAsk.rankString(cToAsk.getRank()) << endl;
	                        Card cReceived = p1.sameRankInHand(cToAsk); //will return p1's card of same rank
				cReceived = p1.removeCardFromHand(cReceived);
	                        p2.addCard(cReceived);
	                        p2.bookCards(cToAsk, cReceived);
	                        oFile << p2.getName() << " books the " << cToAsk.rankString(cToAsk.getRank()) << endl;
	                        Card tempCard = p2.removeCardFromHand(cToAsk);
	                        tempCard = p2.removeCardFromHand(cReceived);    //the function returns a Card for no reason
	                }
		oFile << endl;
		}
		p2TurnOver = 0;
		//oFile << endl << p1.getName() << " has: " << p1.showHand() << " and " << p1.showBooks() << endl;
	        //oFile << p2.getName() << " has: " << p2.showHand() << " and " << p2.showBooks() << endl << endl;
	}
	
	oFile << "Game Over" << endl;
	oFile << "Results:" << endl;

	oFile << endl << p1.getName() << " has: " << p1.showBooks() << endl;
        oFile << p2.getName() << " has: " << p2.showBooks() << endl << endl;

	if(p1.getBookSize() > p2.getBookSize()) {
		oFile << p1.getName() << " wins with " << p1.getBookSize()/2 << " books!" << endl;
	} else if (p1.getBookSize() < p2.getBookSize()) {
		oFile << p2.getName() << " wins with " << p2.getBookSize()/2 << " books!" << endl;
	} else {
		oFile << "It's a tie with 13 books each!" << endl;
	}
	
	oFile.close();
   
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
  

