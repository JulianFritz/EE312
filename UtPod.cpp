#include <cstdlib>
#include <iostream>
#include <ctime>
#include "UtPod.h"
#include "Song.h"

using namespace std;

	UtPod::UtPod() { 		//default constructor
		memSize = MAX_MEMORY;
		songs = NULL;		//starts with empty linked list
	}

	UtPod::UtPod(int _memSize) {
		if(_memSize < 0 || _memSize > MAX_MEMORY)
			memSize = MAX_MEMORY;
		else
			memSize = _memSize;
		songs = NULL;		//starts with empty linked list
	}

	int UtPod::addSong(Song const &_s) {
		if(getRemainingMemory() >= _s.getSize()) {
			SongNode *p = new SongNode;
			p->s = _s;
			p->next = songs;
			songs = p;
			return SUCCESS;
		} else 
			return NO_MEMORY;		
	}

	int UtPod::removeSong(Song const &_s) {
	//traverse the linked list looking for that song
	//then delete it by making the previous pointer skip over it
		if(songs == NULL)
			return NOT_FOUND;

		SongNode *ptr = songs;		//ptr points to head of linked list
		SongNode *prevPtr = ptr;
		if(ptr->s == _s) {
			songs = songs->next;	//special case if it's the first song
			delete ptr;
			return SUCCESS;
		}
		while(ptr != NULL) {
			if(ptr->s == _s) {			//overloaded == for Song objects
				prevPtr->next = ptr->next;	//previous next will skip over
				delete ptr;
				return SUCCESS;
			} else {
				prevPtr = ptr;
				ptr = ptr->next;		//traverse to the next song
			}
		}
		return NOT_FOUND;	//if the code reaches here then unsuccessful
	}

	void UtPod::shuffle() {
		unsigned int currentTime = (unsigned)time(0);
		srand(currentTime);
		int numSongs = 0;
		SongNode *ptr = songs;
		//count numSongs:
		while(ptr != NULL) {
			numSongs++;
			ptr = ptr->next;
		}
		//shuffle:
		for(int i = 0; i < 2*numSongs; i++) {
			long swap1 = (rand() % numSongs);
			long swap2 = (rand() % numSongs);
			SongNode *p1 = songs;
			for(int i = 0; i < swap1; i++) {
				p1 = p1->next;
			} //now p1 is a pointer to the first song to swap
			SongNode *p2 = songs;
			for(int i = 0; i < swap2; i++) {
				p2 = p2->next;
			} //now p2 is a pointer to the second song to swap
			Song temp = p1->s;
			p1->s = p2->s;
			p2->s = temp;	//swapped them
		}
	}

	void UtPod::showSongList() {
		if(songs == NULL) {
			cout << "No Songs to show!" << endl;
			return;
		}
		SongNode *ptr = songs;
		while(ptr != NULL) {
			cout << ptr->s << endl;
			ptr = ptr->next;
		}
	}

	void UtPod::sortSongList() {
		//bubble sort:
		SongNode *ptr = songs;
		int numSongs = 0;
		while(ptr != NULL) {		//count the number of Songs
			numSongs++;
			ptr = ptr->next;
		}

		Song temp;
		for(int i = 0; i <= numSongs; i++) {
			ptr = songs;
			while(ptr->next != NULL) {
				if(ptr->s < ptr->next->s) {
					//Swap the songs
					temp = ptr->s;
					ptr->s = ptr->next->s;
					ptr->next->s = temp;
				}
				ptr = ptr->next;
			}
		}
	}

	void UtPod::clearMemory() {	
		while(songs != NULL) {
			SongNode *ptr = songs;
			songs = songs->next;
			delete ptr;
		}
	}

	int UtPod::getTotalMemory() {
		return memSize;
	}

	int UtPod::getRemainingMemory() {
		SongNode *ptr = songs;
		int usedMem = 0;
		while(ptr != NULL){
			usedMem += ptr->s.getSize();
			ptr = ptr->next;
		}
		return(memSize - usedMem);
	}

	UtPod::~UtPod() {
		//cout << "debug - in destructor" << endl;
		clearMemory(); //this will delete all the pointers which is what a destructor should do
	}


