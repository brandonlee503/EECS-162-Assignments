#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
//Struct
/*
struct game{
	char **p1_board;
	char p1;
	char p2;
};
*/



int **createarray(int, int);
void printarray(int, int, int **array);


int main(int argc, char*argv[]){
	string r, c, p, food;
	int pieces, rows, cols;
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
	int **array = createarray(rows, cols);
	printarray(rows, cols, array);

	return 0;
}
void printarray(int rows, int cols, int **array)
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cout<<"|"<< array[i][j];
		}
		cout<<"|"<< endl;
		for(int j=0; j<cols; j++)
		{
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

int newfunction(){
	int things;
	cout<<"What column would you like to place your piece into: "<<endl;
	cin>>things;
	return things;

}





