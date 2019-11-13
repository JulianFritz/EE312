
final: gamedriver.o player.o deck.o card.o
	g++ -o GoFish gamedriver.o player.o deck.o card.o
	rm *.o 
driver: gamedriver.cpp player.h deck.h card.h
	g++ gamedriver.cpp
player: player.cpp player.h deck.h card.h
	g++ -c player.cpp
deck: deck.cpp deck.h card.h
	g++ -c deck.cpp
card: card.cpp card.h
	g++ -c card.cpp

