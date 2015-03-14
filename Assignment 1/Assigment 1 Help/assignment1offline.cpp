#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//STRUCTS
struct game
{
	char **s_board;
	char p1;
	char p2;
};

//FUNCTION PROTOTYPES
//Error Checking Prototypes
bool check_input(int argc, char*argv[]);
void check_order(int argc, char*argv[]);
void all_input(int argc, char*argv[]);
//int redo_input(int argc, char*argv[]);
void fail_input_info();

//Print Board Prototypes
char **create_board(int rows, int cols);
void print_board(int rows, int cols, char **array);
void delete_array(int **array, int rows, int cols);

void make_board(int, int);

//Gameplay Prototypes
void start_game(int r, int c, int p);
int place_piece(game *piece);

using namespace std;

int main(int argc, char*argv[])
{
	//Create our game and players
	//game->p1 = "11";
	//game->p2 = "22";

	all_input(argc, argv);
}

void all_input(int argc, char *argv[]) //Contains all user input stuff
{
    //Make sure user parameters are valid
    if(check_input(argc, argv))
    {
		cout << "You inputted integers!" << endl;
    	check_order(argc, argv);
	}
	else
	{
		cout << "Nope, please enter valid inputs" << endl;
		fail_input_info();
		//redo_input(argc, argv);
	}
}

bool check_input(int argc, char *argv[])
{
    //Did the user input any command line args?
    if(argc > 2)
    {
       //Check if user input is integers 1-9 with ASCII 49-57 (1-9)
		if((*argv[2] >= 49 && *argv[2] <= 57) && (*argv[4] >= 49 && *argv[4] <= 57) && (*argv[6] >= 49 && *argv[6] <= 57))
        {
            return true;
        }
    }
    return false;
}

void check_order(int argc, char *argv[])
{
	int r, c, p;
	string rows, cols, pieces, test;

		for (int i=1; i <= 6; i=i+2)
		{
			test=argv[i];
		
			if(test.at(1)=='r')
			{
				rows=argv[i+1];
				r=atoi(rows.c_str());
				while (r <= 0) //CHANGE THIS STUFF LATER
				{
					cout << "Please enter valid input for rows: " << endl;
					cin >> r;
				}
			}

			if(test.at(1)=='c')
			{
				cols=argv[i+1];
				c=atoi(cols.c_str());
			}

			if(test.at(1)=='p')
			{
				pieces=argv[i+1];
				p=atoi(pieces.c_str());
			}
		}

	cout << "Number of rows: " << r << endl;
	cout << "Number of cols: " << c << endl;
	cout << "Number of pieces needed to win: " << p << endl;

	start_game(r, c, p);
}

void start_game(int r, int c, int p)
{
	//Win condition
	int ingame = 0;
	//Make board and print
	char **s_board = create_board(r, c);
	print_board(r, c, s_board);

	//Initialize
	game s_game;
	s_game.p1 = 'r';
	s_game.p2 = 'y';

	while (ingame == 0)
	{
		p1move(c, r, s_board, s_game);
		//Do p2 move here too later
		// ingame = checkifgameisover(p, s_game);
	}
	/*if (ingame == 1)
	{
		win();
	}*/

	return 0;
}

int p1move(int r, int c, int **s_board, game s_game)
{
	int colm;
	cout << "Player 1's Turn" << endl;
	print_board(r, c, s_board); //Show board
	colm = drop_error_check(c); //User input for move and error checking
	place_piece(colm, r, s_board, s_game);
	cout << endl << endl;
}

int drop_error_check(int c)
{
	int colm_input
	cout << "Which column do you want to drop your piece in?: ";
	cin >> colm_input;
	while(colm_input > c || colm_input < 0)
	{
		cout << "Please enter valid input: ";
		cin >> colm_input;
	}
	return colm_input;
}


void make_board(int r, int c)//Create 2d array
{
	int **board = new int*[r]; //Makes rows in array
	for (int i=0; i < r; i++)
	{
		board[i] = new int[c];
	}
	for (int i=0; i < r; i++)
	{
		for (int j=0; j < c; j++)
		{
			board[r][c] = EMPTY;
		}
	}
}

//redo_input stuff
/*
int redo_input(int argc, char *argv[])
{
	int redo_r, redo_c, redo_p;
	r = redo_input_r();
	c = redo_input_c();
	p = redo_input_p();
	int redo_r = 0, redo_c = 0, redo_p = 0;
	cout << "Ok, since you messed up, lets do it again" << endl;
	cout << "Please enter R value: " << endl;
		while(redo_r <= 0)
		{
		cout << "Please enter R value: " << endl;
		cin >> redo_r;
		}
	cout << "Please enter C value: " << endl;
		while(redo_c <= 0)
		{
		cout << "Please enter C value: " << endl;
		cin >> redo_c;
		}
	cout << "Please enter P value: " << endl;
		while(redo_p <= 0)
		{
		cout << "Please enter P value: " << endl;
		cin >> redo_p;
		}
}
*/
/*
int redo_input_r()
{
	int redo_r;
	while (*redo_r !>= 49 && *redo_r !<= 57)
	{
	cout << "Please enter R value: ";
	cin >> redo_r;
	}
	return redo_r
}
*/
void fail_input_info()
{
	cout << "How to input command line input example:  -r (input) -c (input) -p (input)" << endl;
	cout << "\t-r is the number of rows" << endl;
	cout << "\t-c is the number of columns" << endl;
	cout << "\t-p is the number of pieces needed to win" << endl;
}

int place_piece(int colm, int r, int **s_board, game s_game)
{
	/*for (int i=r-1; i > 0; i--)
	{
		if
	}
	*/
}

// int place_piece
/*
int place_piece(game *piece)
{
	//cout << "Player " << game->p1 << "'s turn!" << endl;
	int colm = c;

	//Error checking for piece column placement
	while(true)
	{
		cout << "Where would you like to place your piece?" << endl;
		cin >> colm;

		if ((colm !>= 1) && (colm !<= c))
		{
			cout << "Please place a valid column" << endl;
			continue;
			//place_piece(game *piece);
		}
	}

	//Actual Piece placement stuff
	if (array[0][colm] == '0')
	{
		int i;
		for (i=0; array[i][colm] == '0'; i++)
		if (i == r)
		{
			array[r][colm] = game.p1;
			return game.p2;
		}

		i--;
		array[r][colm] = piece;
		return i;

		else
		{
			return -1;
		}
	}
}
*/

char **create_board(int rows, int cols)
{
	char **array = new char*[rows]; //Makes rows in array
	for (int i=0; i < rows; i++)
	{
		array[i] = new char[cols];
	}
	char i='0';
	for (int r=0; r < rows; ++r) //Fills array with 0
	{
		for (int c=0; c < cols; ++c)
		{
			array[r][c]=i;
		}
	}
	return array;
}

void print_board(int rows, int cols, char **array)
{
	for (int i=0; i < rows; i++)//Prints array using double pointer
	{
		for (int j=0; j < cols; j++)
		{
			cout << "|" << array[i][j];
		}
		cout << "|" << endl;
		for (int j=0; j < cols; j++)
		{
			cout << "--";
		}

	cout << "-" << endl;
	}
}

void delete_array(int **array, int rows, int cols)
{
	for (int i=0; i< rows; i++)
	{
		delete array[i];
	}
	delete_array;
}