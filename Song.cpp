#include "Song.h"

using namespace std;

	Song::Song() { 			//default constructor
		title = "";
		artist = "";
		size = 0;
	}
	
	Song::Song(string _artist, string _title, int _size) {	
		title = _title;
		artist = _artist;
		size = _size;
	}

	string Song::getTitle() const {
		return title;
	}

	void Song::setTitle(string n) {
		title = n;
	}

	string Song::getArtist() const {
		return artist;
	}

	void Song::setArtist(string n) {
		artist = n;
	}

	int Song::getSize() const {
		return size;
	}

	void Song::setSize(int n) {
		size = n;
	}

	bool Song::operator >(Song const &rhs) {
		if(artist < rhs.artist)
			return true;
		else if(artist == rhs.artist) {
			if(title < rhs.title)
				return true;
			else if(title == rhs.title) {
				if(size < rhs.size)
					return true;
			}
		}
		return false;
	}

	bool Song::operator <(Song const &rhs) {
		if(artist > rhs.artist)
                        return true;
                else if(artist == rhs.artist) {
                        if(title > rhs.title)
                                return true;
                        else if(title == rhs.title) {
                                if(size > rhs.size)
                                        return true;
                        }
                }
                return false;
	}

	bool Song::operator ==(Song const &rhs) {
		return(artist == rhs.artist && title == rhs.title && size == rhs.size);
	}

	ostream& operator << (ostream& out, const Song &s) {
		out << s.getTitle() << ", " << s.getArtist() << ", " << s.getSize();
		return out;
	}

	Song::~Song() {
		//cout << "debugging tool: in destructor for " << title << endl;
	}




