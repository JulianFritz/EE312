#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song {

	private:
		string artist;
		string title;
		int size;

		static const int MAX_SIZE = 512;

	public:
		Song();
		Song(string _artist, string _title, int _size);
		
		string getTitle() const; 
		
		void setTitle(string n); 

		string getArtist() const;

		void setArtist(string n); 

		int getSize() const; 

		void setSize(int n);

		bool operator >(Song const &rhs);
		bool operator <(Song const &rhs);
		bool operator ==(Song const &rhs);

		~Song();

};

ostream& operator << (ostream& out, const Song &s);


#endif
