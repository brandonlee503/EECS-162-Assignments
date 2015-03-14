#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

using namespace std;


/********************************************************************* 
 ** Program Filename: main.cpp
 ** Author: Brandon Lee
 ** Date: 4/25/14
 ** Description: Assignment 2 Go fish
 ** Input: Number of players and ints for rank
 ** Output: Array of card objects
 *********************************************************************/ 




class CARD{
private:
	string rank;
	string suit;
public:
	CARD();
	CARD(string rankc, string suitc);
	string print_card();
	string get_rank();
};

CARD::CARD(){

}

CARD::CARD(string rankc, string suitc){
	rank = rankc;
	suit = suitc;
}

/*********************************************************************
 ** Function: print_card()
 ** Description: Brings in check_input and checks if user inputted integers
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: String
 *********************************************************************/
string CARD::print_card(){
	return (rank + " of "+ suit);
}
/*********************************************************************
 ** Function: get_rank()
 ** Description: Brings in check_input and checks if user inputted integers
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: String
 *********************************************************************/
string CARD::get_rank(){
	return rank;
}


class DECK{
private:
	CARD *deckarray;
	CARD *cardfill;
	CARD index;
	int avaliablecards;
public:
	DECK();
	void shuffle_deck();
	void print_deck();
	CARD deckreturncard();
};

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


class PLAYER{
private:
	CARD *hand;
	CARD card_return;
	CARD empty_card;
	CARD index;
	int cardsinhand;
public:
	PLAYER();
	void draw_card(CARD);
	void print_hand();
	void checkGameOver();
	void remove_pair();
	void ace_remove(int);
	void jack_remove(int);
	void queen_remove(int);
	void king_remove(int);
	void num_remove(int);

	CARD playercardtake(int);
	CARD check_hand();
	CARD check_hand(int);
	CARD ace_check(int);
	CARD jack_check(int);
	CARD queen_check(int);
	CARD king_check(int);
	CARD num_check(int);

};

PLAYER::PLAYER(){
	cardsinhand=0; //Prints as many CARD as there are in the hand
	hand= new CARD[52];
}


/*********************************************************************
 ** Function: draw_card(CARD newcard)
 ** Description: Draws card
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: cards
 *********************************************************************/
void PLAYER::draw_card(CARD newcard){
	hand[cardsinhand] = newcard;
	cardsinhand++;
}

/*********************************************************************
 ** Function: print_hand(CARD newcard)
 ** Description: prints card
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: printed card
 *********************************************************************/
void PLAYER::print_hand(){
	for(int k=0; k<cardsinhand; k++){
		if(hand[k].get_rank()!=empty_card.get_rank())
			cout<<hand[k].print_card()<<endl;
	}
}


/*********************************************************************
 ** Function: checkGameOver()
 ** Description: Checks if game is over
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: ends game
 *********************************************************************/
void PLAYER::checkGameOver(){
	for(int i=0; i<100; i++){
		if(hand[i].get_rank()!=empty_card.get_rank())
			return;
	}
	cout << "GAMEOVER, No more Cards..." << endl;
	exit(1);
}

/*********************************************************************
 ** Function: remove_pair()
 ** Description: removes cards once pair is found
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: ends game
 *********************************************************************/
void PLAYER::remove_pair(){
	int card_asked=1;
	while(card_asked<14){
		num_remove(card_asked);
		jack_remove(card_asked);
		queen_remove(card_asked);
		king_remove(card_asked);
		ace_remove(card_asked);
		card_asked++;
	}
}

/*********************************************************************
 ** Function: num_remove()
 ** Description: removes cards once pair is found
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: ends game
 *********************************************************************/
void PLAYER::num_remove(int card_asked){
	int counter=0, k1, k2, k3, k4, x;
	for(int q=0; q < cardsinhand; q++){
		string z=hand[q].get_rank();
		x=atoi(z.c_str());
		if(card_asked>1 && card_asked < 11){
			if(x==card_asked){
			counter++;
			if(counter==1)
				k1=q;
			if(counter==2)
				k2=q;
			if(counter==3)
				k3=q;
			if(counter==4){
				k4=q;
				hand[k1]=empty_card;
				hand[k2]=empty_card;
				hand[k3]=empty_card;
				hand[k4]=empty_card;
				}
			}
		}
	}
}

/*********************************************************************
 ** Function: num_remove()
 ** Description: removes cards once pair is found
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: ends game
 *********************************************************************/
void PLAYER::jack_remove(int card_asked){
	int k1, k2, k3, k4, counter=0;
	for(int q=0; q < cardsinhand; q++){
		if(card_asked==11){
			if(hand[q].get_rank()=="Jack"){
				counter++;
				if(counter==1)
					k1=q;
				if(counter==2)
					k2=q;
				if(counter==3)
					k3=q;
				if(counter==4){
					k4=q;
					hand[k1]=empty_card;
					hand[k2]=empty_card;
					hand[k3]=empty_card;
					hand[k4]=empty_card;
				}
			}
		}
	}
}

void PLAYER::queen_remove(int card_asked){
	int k1, k2, k3, k4, counter=0;
	for(int q=0; q < cardsinhand; q++){
		if(card_asked==12){
			if(hand[q].get_rank()=="Queen"){
				counter++;
				if(counter==1)
					k1=q;
				if(counter==2)
					k2=q;
				if(counter==3)
					k3=q;
				if(counter==4){
					k4=q;
					hand[k1]=empty_card;
					hand[k2]=empty_card;
					hand[k3]=empty_card;
					hand[k4]=empty_card;
				}
			}
		}
	}
}

void PLAYER::king_remove(int card_asked){
	int k1, k2, k3, k4, counter=0;
	for(int q=0; q < cardsinhand; q++){
		if(card_asked==13){
			if(hand[q].get_rank()=="King"){
				counter++;
				if(counter==1)
					k1=q;
				if(counter==2)
					k2=q;
				if(counter==3)
					k3=q;
				if(counter==4){
					k4=q;
					hand[k1]=empty_card;
					hand[k2]=empty_card;
					hand[k3]=empty_card;
					hand[k4]=empty_card;
				}
			}
		}
	}
}

void PLAYER::ace_remove(int card_asked){
	int k1, k2, k3, k4, counter=0;
	for(int q=0; q < cardsinhand; q++){
		if(card_asked==1){
			if(hand[q].get_rank()=="Ace"){
				counter++;
				if(counter==1)
					k1=q;
				if(counter==2)
					k2=q;
				if(counter==3)
					k3=q;
				if(counter==4){
					k4=q;
					hand[k1]=empty_card;
					hand[k2]=empty_card;
					hand[k3]=empty_card;
					hand[k4]=empty_card;
				}
			}
		}
	}
}

/*********************************************************************
 ** Function: check_hand(int card_asked)
 ** Description: checks hand
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: cards
 *********************************************************************/
CARD PLAYER::check_hand(int card_asked){
	if(card_asked > 1 && card_asked < 11)
		return num_check(card_asked);
	if(card_asked==13)
		return king_check(card_asked);
	if(card_asked==12)
		return queen_check(card_asked);
	if(card_asked==11)
		return jack_check(card_asked);
	if(card_asked==1)
		return ace_check(card_asked);
}

/*********************************************************************
 ** Function: num_check(int card_asked)
 ** Description: checks numbers
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: the card rank
 *********************************************************************/
CARD PLAYER::num_check(int card_asked){
	for(int i=0; i<cardsinhand; i++){
		string z=hand[i].get_rank();
		if(z=="2"||z=="3"||z=="4"||z=="5"||z=="6"||z=="7"||z=="8"||z=="9"||z=="10"){
			int x=atoi(z.c_str());
			if(x==card_asked){
				index=hand[i];
				hand[i]=empty_card;
				return index;
			}
		}
	}
	return empty_card;
}

CARD PLAYER::king_check(int card_asked){
	for(int i=0; i<cardsinhand; i++){
		if(hand[i].get_rank()=="King"){
			index=hand[i];
			hand[i]=empty_card;
			return index;
		}
	}
	return empty_card;
}

CARD PLAYER::queen_check(int card_asked){
	for(int i=0; i<cardsinhand; i++){
		 if(hand[i].get_rank()=="Queen"){
			index=hand[i];
			hand[i]=empty_card;
			return index;
		}
	}
	return empty_card;
}

CARD PLAYER::jack_check(int card_asked){
	for(int i=0; i<cardsinhand; i++){
		if(hand[i].get_rank()=="Jack"){
			index=hand[i];
			hand[i]=empty_card;
			return index;
		}
	}
	return empty_card;
}

CARD PLAYER::ace_check(int card_asked){
	for(int i=0; i<cardsinhand; i++){
		if(hand[i].get_rank()=="Ace"){
			index=hand[i];
			hand[i]=empty_card;
			return index;
		}
	}
	return empty_card;
}

/*********************************************************************
 ** Function: playercardtake(int card_asked)
 ** Description: takes player card 
 ** Parameters: N/A
 ** Preconditions: Argments have been passed
 ** Return: card
 *********************************************************************/
CARD PLAYER::playercardtake(int card_asked){
	card_return=check_hand(card_asked);
	if(card_return.get_rank()==empty_card.get_rank())
		cout<<"NOPE, GO FISH!"<< endl;
	return card_return;
}

class GAME{
private:
	CARD theemptycard;
public:
	GAME(); //Constructor
	void ask_playernum(DECK, CARD); //Constructor with parameters
	void intitialize_playernum(DECK, CARD, int);
	void player1_game(DECK, CARD);
	void player2_game(DECK, CARD);
};

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

int main(){
	DECK deckobj;
	CARD currentcard;
	deckobj.print_deck();
	deckobj.shuffle_deck();
	GAME gameobj;
	gameobj.ask_playernum(deckobj, currentcard);	
	return 0;
}
