#include "CARD.h"

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