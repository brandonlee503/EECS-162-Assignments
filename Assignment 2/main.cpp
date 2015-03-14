#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

using namespace std;

int main(){
	DECK deckobj;
	CARD currentcard;
	deckobj.print_deck();
	deckobj.shuffle_deck();
	GAME gameobj;
	gameobj.ask_playernum(deckobj, currentcard);	
	return 0;
}