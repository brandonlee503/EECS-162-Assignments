#include "PLAYER.h"


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