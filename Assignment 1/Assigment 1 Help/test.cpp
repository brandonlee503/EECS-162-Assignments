#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
//Struct

struct game{
	char **p1_board;
	char p1;
	char p2;
};
int checkgameover(int, int, game, int **array);
int drop_piece1(int, int, int **array, game);
int drop_piece2(int, int, int **array, game);
int p1turn(int, int, int **array, game);
int p2turn(int, int, int **array, game);
int **createarray(int, int);
void printarray(int, int, int **array);
int makemove(int, int **array);
int playgame(int, int, int);
int check_winner1(int, int, int, game, int **array);

int main(int argc, char*argv[]){
	string r, c, p, food;
	int pieces, rows, cols, inputcol;
	if(argc<7){
		cout<<"Error, not enough arguments supplied"<<endl;
		return 0;
	}
	if(argc>7){
		cout<<"Error, too many arguments supplied"<<endl;
		return 0;
	}
	for(int i=1; i<=6; i=i+2){
		food=argv[i];
		if(food.at(1)=='r'){
			r=argv[i+1];
			rows=atoi(r.c_str());
			while(rows<=0){
				cout<<"Thats not a valid value for rows, enter a new one: ";
				cin>>rows;
			}
			cout<<"Number of rows: "<<rows<<endl;
		}
		if(food.at(1)=='c'){
			c=argv[i+1];
			cols=atoi(c.c_str());
			while(cols<=0){
				cout<<"Thats not a valid value for columns, enter a new one: ";
				cin>>cols;
			}
			cout<<"Number of columns: "<<cols<<endl;
		}
		if(food.at(1)=='p'){
			p=argv[i+1];
			pieces=atoi(p.c_str());
			while(pieces<=0){
				cout<<"Thats not a valid value for pieces, enter a new one: ";
				cin>>pieces;
			}
			cout<<"Number of pieces needed to win: "<<pieces<<endl;
		}
	}
	playgame(rows, pieces, cols);
}
int playgame(int rows, int pieces, int cols){
	//setup game
	int gamestatus=0;
	int **array = createarray(rows, cols);
	printarray(rows, cols, array);
	game blank;
	blank.p1=1;
	blank.p2=2;
	//----------------
	//game starts here
	while(gamestatus==0){
		p1turn(cols, rows, array, blank);
		gamestatus=checkgameover(rows, cols, blank, array);
		gamestatus=check_winner1(rows, cols, pieces, blank, array);
		p2turn(cols, rows, array, blank);
		gamestatus=checkgameover(cols, rows, blank, array);
	}
	/*if(gamestatus==1){
		gamewinner();
	}*/
	return 0;
	
}
int check_winner1(int rows, int cols, int pieces, game blank, int **array){
	int win=0;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
//-------------------------horizontal check----------------------------------
			if(array[i][j]==1){
				//one piece so far
				win++;
				for(int h=0; h<pieces-1; h++){
					cout<<h<<" this is h "<<endl;
					cout<<i<< " this is I in loop 2"<<endl<<endl;;
					if(array[i][j+h]==1){
						//cout<<j+h<<"this is j+h"<<endl;
						//cout<<win<<"WIN beginning of the loop"<<endl;
						win++;
						//cout<<win<<"WIN after win++"<<endl;
					}
					else{
						win=0;
						break;			
					}

				}
			}
//--------------------Vertical check --------------------------------------------
			if(array[i][j]==1){
				//one piece thus far
				win++;
				for(int v=0; v<pieces-1; v++)
					if(array[i][j+v]==1){
						win++;
					}
					else{
						win=0;
						break;
					}
			}
		}
	}
	cout<<win<<"WIN"<<endl;
	if(win==0){
		return 0;
	}
	if(win==pieces){	
		return 1;
	}

		
}
int checkgameover(int rows, int cols, game blank, int **array){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(array[i][j]==0){
				return 0;
			}
		}
	}
	cout<<"The board is full! Looks like a tie..."<<endl;
	return 1;
}
int p1turn(int cols, int rows, int **array, game blank){
	int columninput;
	//show board to player
	cout<<"Its player 1's turn!"<<endl<<endl;
	printarray(rows, cols, array);
	//ask for a input for a move
	columninput=makemove(cols, array);
	//make the move
	drop_piece1(columninput, rows, array, blank);
}
int p2turn(int cols, int rows, int **array, game blank){
	int columninput;
	//show board to player
	cout<<"Its player 2's turn!"<<endl<<endl;
	printarray(rows, cols, array);
	//ask for a input for a move
	columninput=makemove(cols, array);
	//make the move
	drop_piece2(columninput, rows, array, blank);
}
int drop_piece1(int columninput, int rows, int **array, game blank){
	for(int i=rows-1; i>=0; i--){
		if(array[i][columninput]!=1&&array[i][columninput]!=2){
			array[i][columninput]=blank.p1;
			i=0;
		}
	}
}
int drop_piece2(int columninput, int rows, int **array, game blank){
	for(int i=rows-1; i>=0; i--){
		if(array[i][columninput]!=1&&array[i][columninput]!=2){
			array[i][columninput]=blank.p2;
			i=0;
		}
	}
}

void printarray(int rows, int cols, int **array){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout<<"|"<< array[i][j];
		}
		cout<<"|"<< endl;
		for(int j=0; j<cols; j++){
			cout<<"--";
		}
		cout<<"-"<<endl;	
	}
}
int **createarray(int rows, int cols){
	int **array = new int*[rows];

	for(int x=0; x<rows; x++){
		array[x] = new int[cols];
	}

	int i=0;
	for(int r=0; r<rows; ++r){
		for(int c=0; c< cols; ++c){
			array[r][c]=0;
		}
	}
	return array;
}

int makemove(int cols, int **array){
	int things;
	cout<<"What column would you like to make your move on?: ";
	cin>>things;
	while(things>cols|| things<=0){
		cout<<"Not valid input, reenter the column: ";
		cin>>things;
	}
	while(array[0][things-1]==1||array[0][things-1]==2){
		cout<<"That column is full! Re-enter the column: ";
		cin>>things;
	}
	return things-1;
}



