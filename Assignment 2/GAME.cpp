#include "GAME.h"

GAME::GAME(){

}

/*********************************************************************
 ** Function: ask_playernum(DECK deckobj, CARD currentcard)
 ** Description: ask for number of players
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: int
 *********************************************************************/
void GAME::ask_playernum(DECK deckobj, CARD currentcard){
	int playercount1; //add error checking :)
	cout << "Welcome to Go Fish! Please select the number of players (1-6): ";
	cin >> playercount1;
	cout << "Ok you have chosen to play a " << playercount1 << " player game!" << endl;
	intitialize_playernum(deckobj, currentcard, playercount1); //Initialize the players
	cout <<"derp1" << endl;
}

/*********************************************************************
 ** Function: intitialize_playernum(DECK deckobj, CARD currentcard, int playercount1)
 ** Description: ask for number of players
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: int
 *********************************************************************/
void GAME::intitialize_playernum(DECK deckobj, CARD currentcard, int playercount1){
	cout << "derp2" << endl;
	switch(playercount1){
	case 1: player1_game(deckobj, currentcard);
		break;
	case 2: player2_game(deckobj, currentcard);
		break;
	case 3: player2_game(deckobj, currentcard);
		break;
	case 4: player2_game(deckobj, currentcard);
		break;
	case 5: player2_game(deckobj, currentcard);
		break;
	case 6: player2_game(deckobj, currentcard);
		break;
	}
}

/*********************************************************************
 ** Function: player1_game(DECK deckobj, CARD currentcard)
 ** Description: initilze player game
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: game
 *********************************************************************/
void GAME::player1_game(DECK deckobj, CARD currentcard){
	PLAYER p1, p2;
	for(int j=0; j<7; j++){
	currentcard=deckobj.deckreturncard();
	p1.draw_card(currentcard);
	currentcard=deckobj.deckreturncard();
	p2.draw_card(currentcard);
	}
	cout<<"Player 1's hand: ";
	p1.print_hand();
	cout<<endl;
	cout<<"Player 2's hand: ";
	p2.print_hand();	

	int user_input = rand()%13+1;
	while(true){
	cout<<"PLAYER 1'S TURN! What card do you want to take from Player 2?: ";
	for(int y=0; y<3; y++){
		currentcard=p2.playercardtake(user_input);
		p1.draw_card(currentcard);
		if(currentcard.get_rank()==theemptycard.get_rank())
			y++;
	}
	cout<<"Player 2's new hand: "<<endl;
	p2.print_hand();
	p2.checkGameOver();
	p1.remove_pair();
	cout << endl;
	cout<<"Player 1's hand:"<<endl;
	p1.print_hand();
	p1.checkGameOver();

	cout<<"PLAYER 2'S TURN! What card do you want to take from Player 1?: ";
	cin>>user_input;
	
	for(int y=0; y<3; y++){
		currentcard=p1.playercardtake(user_input);
		p2.draw_card(currentcard);
	}
	cout<<"Player 1's new hand: "<<endl;
	p1.print_hand();
	p1.checkGameOver();
	p2.remove_pair();
	cout << endl;
	cout<<"Player 2's hand:"<<endl;
	p2.print_hand();
	p2.checkGameOver();
	}
}

void GAME::player2_game(DECK deckobj, CARD currentcard){
	PLAYER p1, p2;
	for(int j=0; j<7; j++){
	currentcard=deckobj.deckreturncard();
	p1.draw_card(currentcard);
	currentcard=deckobj.deckreturncard();
	p2.draw_card(currentcard);
	}
	cout<<"Player 1's hand: ";
	p1.print_hand();
	cout<<endl;
	cout<<"Player 2's hand: ";
	p2.print_hand();	

	int user_input;
	while(true){
	cout<<"PLAYER 1'S TURN! What card do you want to take from Player 2?: ";
	cin >> user_input;
	for(int y=0; y<3; y++){
		currentcard=p2.playercardtake(user_input);
		p1.draw_card(currentcard);
		if(currentcard.get_rank()==theemptycard.get_rank())
			y++;
	}
	cout<<"Player 2's new hand: "<<endl;
	p2.print_hand();
	p2.checkGameOver();
	p1.remove_pair();
	cout << endl;
	cout<<"Player 1's hand:"<<endl;
	p1.print_hand();
	p1.checkGameOver();

	cout<<"PLAYER 2'S TURN! What card do you want to take from Player 1?: ";
	cin>>user_input;
	
	for(int y=0; y<3; y++){
		currentcard=p1.playercardtake(user_input);
		p2.draw_card(currentcard);
	}
	cout<<"Player 1's new hand: "<<endl;
	p1.print_hand();
	p1.checkGameOver();
	p2.remove_pair();
	cout << endl;
	cout<<"Player 2's hand:"<<endl;
	p2.print_hand();
	p2.checkGameOver();
	}
}