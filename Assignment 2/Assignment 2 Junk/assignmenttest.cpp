#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

const int cardsindeck = 52;
const int initcardsinhand = 7;

//Stores card's suit and value info
class CARD{
private:
	string suit;
	string rank;
	//int index;
public:
	CARD(); //Constructor
	CARD(string rankc, string suitc); //Constructor w/ parameters and accessor
	string print_card();

	//string value(); //Returns card value
	//string shape(); //Returns suit value
	//int index1(); //Returns card index
	//void set_card_value(string, string, int); //Sets the card value
	//void get_card_value(); //Obtains card values
};

//Has 1D dynamic array of card objects, where number of card objects is the # of cards that are supposed to be in the deck
class DECK{
private:
	CARD *deck;
	int currentcard;
public:
	DECK(); //Constructor
	void shuffle(); //Shuffles deck
	CARD dealcard(); //Deal cards
	void print_deck(); //Prints deck

	string *create_deck(string CARD); //Creates array and sorts
	string subtract_deck(string *handarray[]); //Resize deck after drawing cards
	//DECK(string *deckarray[51]); //Constructor w/ parameters

};

//Contains overall moves and cards the player has in hand
class PLAYER{
private:
	CARD *handarrayp; //Player's hand
	int player; //Which player this is
public:
	PLAYER(); //Constructor (create player)
	PLAYER(CARD *handarrayp); // Constructor w/ parameters
	//create_PLAYER(CARD *handarrayd); // Constructor w/ parameters
	//string create_player(string *handarray);
	//PLAYER(string *handarray[], int player); // Constructor w/ parameters
	void print_hand();
	int player_turn(int player/*, CARD.rank*/); //Overall turn of the player
	int player_turn2(int player); //Overall turn of the player
	int player_attack(int player, int player_defender/*, CARD.rank*/); //Attack move
	int drawcard(string *handarray[], DECK deckarray[51]); //Draws card when player GOFISH!
	int paircheck(string *handarray[]); //Check if there is pair and remove cards from game if so and let player go again (DISCARDS CARDS)
};

//Contains all main functions for playing the actual game
class GAME{
private:
	int playercount; //Number of players
public:
	GAME(); //Constructor
	void ask_playernum(); //Constructor with parameters
	//int ask_playernum(int playercount/*, DECK.deckarray[51]*/); //Constructor with parameters
	void intitialize_playernum/*gofish*/(int playercount/*, DECK.deckarray[51]*/); //Initialize the game
	void player1_game();
	void player2_game();
	void play(/*PLAYER.player,*/ /*string *handarray[]*/); //Play the game (might need more stuff)
	void check_winner(/*PLAYER.player,*/ string *handarray[]); //Checks if there is a winner
};

CARD::CARD(){

}

CARD::CARD(string rankc, string suitc){ //add void
	rank = rankc;
	suit = suitc;
}

string CARD::print_card(){
	return (rank + " of " + suit);
}

DECK::DECK(){
	string ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
	string suits[4]	= {"Spades", "Hearts", "Clubs", "Diamonds"};
	deck = new CARD[cardsindeck];
	currentcard = 0;
	for (int i=0; i < cardsindeck; i++){ //Fill the deck in order (sort)
		deck[i] = CARD(ranks[i%13], suits[i/13]);
	}
}

void DECK::shuffle(){
	currentcard = 0;
	for(int i=0; i < cardsindeck; i++){
		int j = (rand()+time(0))%cardsindeck; //Shuffling part
		CARD x = deck[i];
		deck[i] = deck[j];
		deck[j] = x;
	}
}

CARD DECK::dealcard(){
	if(currentcard > cardsindeck){ //If we're out of cards, shuffle
		shuffle();
	}
	if(currentcard < cardsindeck){
		return (deck[currentcard++]); //Return the deck and increment the current card
	}
	return (deck[0]); //Return top card
}

void DECK::print_deck(){
	cout <<left;
	for(int i=0; i < cardsindeck; i++){
		cout << setw(19) << deck[i].print_card(); //Set each column to 19
		if((i+1)%4==0) //Print 4 cards per line
			cout << endl;
	}
}

PLAYER::PLAYER(){

}

PLAYER::PLAYER(CARD *handarrayp){
	//CARD handarrayp = handarrayd;
	string ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
	string suits[4]	= {"Spades", "Hearts", "Clubs", "Diamonds"};
	handarrayp = new CARD[7];
	for (int i=0; i < initcardsinhand; i++){ //Fill the deck in order (sort)
		handarrayp[i] = CARD(ranks[i%13], suits[i/13]);
	}
}

/*string PLAYER::create_player(string *handarray){

}*/

void print_hand(){
	cout <<left;
	for(int i=0; i < cardsindeck; i++){
		cout << setw(19) << deck[i].print_card(); //Set each column to 19
		if((i+1)%4==0) //Print 4 cards per line
			cout << endl;
}

GAME::GAME(){

}

void GAME::ask_playernum(){
	int playercount1; //add error checking :)
	cout << "Welcome to Go Fish! Please select the number of players (1-6): ";
	cin >> playercount1;
	cout << "Ok you have chosen to play a " << playercount1 << " player game!";
	intitialize_playernum(playercount1); //Initialize the players
	cout <<"derp1" << endl;
}

void GAME::intitialize_playernum(int playercount1){
	cout << "derp2" << endl;
	switch(playercount1){
	case 1: player1_game();
		break;
	case 2: player2_game();
		break;
	case 3: player2_game();
		break;
	case 4: player2_game();
		break;
	case 5: player2_game();
		break;
	case 6: player2_game();
		break;
	}
}

void GAME::player2_game(){
	cout << "yay it works 2" << endl;
	//PLAYER.create_player(*player1);
	PLAYER player1;
	cout << player1.handarrayp << endl;
	PLAYER player2;
}

void GAME::player1_game(){
	cout << "yay it works 1" << endl;
}

int main(){
	DECK deck;
	CARD currentcard;
	deck.print_deck();
	deck.shuffle();
	cout << endl << endl;
	deck.print_deck();
	for(int i=0; i < cardsindeck; i++){
		currentcard = deck.dealcard();
		cout << currentcard.print_card() << endl;
	}
	GAME gameobj;
	gameobj.ask_playernum();

	//system("Pause");
	return 0;
}
