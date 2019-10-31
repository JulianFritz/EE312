/* 
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t(-30000);

    //Julian's Driver:

    Song s1("Beatles", "Sgt. Pepper", 4);
    int result = t.addSong(s1);
    
    cout << "  The list should have 1 song, addSong result = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList();
    t.clearMemory();
    t.addSong(s1);
    cout << "  Showing song list again" << endl;
    t.showSongList();
          
    Song s2("Beatles", "With a Little Help", 5);
    result = t.addSong(s2);
    //cout << "result = " << result << endl;
    
    cout << "  The list should have 2 songs, addSong result = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList();
    cout << "  Showing song list again" << endl;
    t.showSongList();
       
    Song s3("Beatles", "Lucy In The Sky With Diamonds", 6);
    result = t.addSong(s3);
    //cout << "result = " << result << endl;
       
    cout << "  The list should have 3 songs, addSong result = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList();
    cout << "  Showing song list again" << endl;
    t.showSongList();

    Song s4("Beatles", "Getting Better", 3);
    result = t.addSong(s4);
    //cout << "result = " << result << endl;
    
    cout << "  The list should have 4 songs, addSong result = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList();
    cout << "  Showing song list again" << endl;
    t.showSongList();
   
    Song s5("Beatles", "She's Leaving Home", 2);
    result = t.addSong(s5);
    //cout << "add result = " << result << endl;

    cout << "  The list should have 5 songs, addSong result = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList();
    cout << "  Showing song list again" << endl;
    t.showSongList();

    Song s6("Beatles", "Being For the Benefit", 4);
    result = t.addSong(s6);
    //cout << "add result = " << result << endl;

    cout << "  The list should have 6 songs, addSong result = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList();
    cout << "  Showing song list again" << endl;
    t.showSongList();

    Song s7("Beatles", "Within You Without You", 3);
    result = t.addSong(s7);
    //cout << "add result = " << result << endl;

    cout << "  The list should have 7 songs, addSong result = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList();
    cout << "  Showing song list again" << endl;
    t.showSongList();

    Song s8("Beatles", "When I'm Sixty Four", 12);
    result = t.addSong(s8);
    //cout << "add result = " << result << endl;

    cout << "  The list should have 8 songs, addSong result = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList();
    cout << "  Showing song list again" << endl;
    t.showSongList();

    Song s9("Beatles", "Lovely Rita", 20);
    result = t.addSong(s9);
    //cout << "add result = " << result << endl;

    cout << "  The list should have 9 songs, addSong result = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList();
    cout << "  Showing song list again" << endl;
    t.showSongList();

    Song s10("Queen", "Bohemian Rhapsody", 24);
    result = t.addSong(s10);
    //cout << "add result = " << result << endl;

    cout << "  The list should have 10 songs, addSong result = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList();
    cout << "  Showing song list again" << endl;
    t.showSongList();

    Song s11("Queen", "Don't Stop Me Now", 24);
    result = t.addSong(s11);
    //cout << "add result = " << result << endl;

    cout << "  The list should have 11 songs, addSong result = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList();
    cout << "  Showing song list again" << endl;
    t.showSongList();

    Song s12("Juice WRLD", "Lucid Dreams", 24);
    result = t.addSong(s12);
    //cout << "add result = " << result << endl;

    cout << "  The list should have 12 songs, addSong result = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList();
    cout << "  Showing song list again" << endl;
    t.showSongList();

    Song s13("Juice WRLD", "Lucid Dreams", 30);
    result = t.addSong(s13);
    //cout << "add result = " << result << endl;

    cout << "  The list should have 13 songs, addSong resutl = " << result << endl;
    t.showSongList();
    t.shuffle();
    t.sortSongList(); 
    cout << "  Showing song list again" << endl;
    t.showSongList();

	t.shuffle();
	cout << "  Shuffled:" << endl;
	t.showSongList();
	t.shuffle();
	cout << "  Shuffled:" << endl;
	t.showSongList();
        t.shuffle();
        cout << "  Shuffled:" << endl;
        t.showSongList();
        t.shuffle();
        cout << "  Shuffled:" << endl;
        t.showSongList();
        t.shuffle();
        cout << "  Shuffled:" << endl;
        t.showSongList();
	t.sortSongList();
	cout << "  Sorted:" << endl;
	t.showSongList();
	//t.clearMemory();
	//t.showSongList();
    
    result = t.removeSong(s2);
    cout << "  Removing With A Little Help, delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "  Removing Lucy in the Sky, delete result = " << result << endl;
    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "  Removing s1, delete result = " << result << endl;
    t.showSongList(); 

    result = t.removeSong(s6);
    cout << "  Removing s6, delete result = " << result << endl;
    t.showSongList();    

    result = t.removeSong(s10);
    cout << "  Removing s10, delete result = " << result << endl;
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "  Adding a copy of s5, add result = " << result << endl;
    t.showSongList();
    t.sortSongList();
    cout << "  Sorting:" << endl;
    t.showSongList();
    t.shuffle();
    cout << "  Shuffling:" << endl;
    t.showSongList();
    
    cout << "  Remaining Memory = " << t.getRemainingMemory() << endl;  
    
    Song ss("Ur Mom", "What's Up", 392);
    result = t.addSong(ss);
    cout << "  Adding song What's Up, addSong result = " << result  << endl;
    t.showSongList();
    cout << "  Remaining Memory = " << t.getRemainingMemory() << endl;
    cout << "  Total Memory is " << t.getTotalMemory() << endl;
    cout << "  Attempting to add another song...:" << endl;
    result = t.addSong(s1);
    cout << "addSong result = " << result << endl;
    t.showSongList();

}
