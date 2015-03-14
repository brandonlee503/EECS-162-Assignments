#include "DECK.h"

DECK::DECK(){
	string ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
	string suits[4]	= {"Hearts", "Diamonds", "Spades", "Clubs"};
	avaliablecards=51;
	deckarray= new CARD[52];
	cardfill = new CARD[avaliablecards];
	for (int i=0; i < 52; i++){ 
		deckarray[i] = CARD(ranks[i%13], suits[i/13]);
	}
}

/*********************************************************************
 ** Function: shuffle_deck()
 ** Description: Shuffles deck
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: shuffled deck
 *********************************************************************/
void DECK::shuffle_deck(){
	for(int s=0; s < 52; s++){
		int t = (rand()+time(0))%52;
		CARD u = deckarray[s];
		deckarray[s] = deckarray[t];
		deckarray[t] = u;
	}
}

/*********************************************************************
 ** Function: print_deck()
 ** Description: prints deck
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: printed deck
 *********************************************************************/
void DECK::print_deck(){
	for(int i=0; i<avaliablecards+1; i++)
		cout<< deckarray[i].print_card()<<endl;
}


/*********************************************************************
 ** Function: deckreturncard()
 ** Description: Brings in check_input and checks if user inputted integers
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: printed deck
 *********************************************************************/
CARD DECK::deckreturncard(){
	if(avaliablecards<0){
		cout<<"The game is over!"<<endl;
		exit(1);
	}
	index=deckarray[avaliablecards];
	cardfill = new CARD[avaliablecards];
	for(int i=0; i < avaliablecards; i++){
		cardfill[i]=deckarray[i];
	}
	deckarray= new CARD[avaliablecards];
	for(int i=0; i < avaliablecards; i++){
		deckarray[i]=cardfill[i];
	}
	avaliablecards--;
	return index;
}