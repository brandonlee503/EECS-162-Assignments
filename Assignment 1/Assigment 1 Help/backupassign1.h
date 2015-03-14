#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>

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
void fail_input_info();

//Print Board Prototypes
char **create_board(int rows, int cols);
void print_board(int rows, int cols, char **array);
void delete_array(int **array, int rows, int cols);

//Gameplay Prototypes
void start_game(int r, int c, int p);
int p1move(int r, int c, char **s_board, game s_game);
int p2move(int r, int c, char **s_board, game s_game);
int place_piece_p1(int colm, int r, char **s_board, game s_game);
int place_piece_p2(int colm, int r, char **s_board, game s_game);
int drop_check(int r, int c, char **s_board);
int drop_check_ai(int r, int c, char **s_board);

//Checking Prototypes
void check_tie(int r, int c, char **s_board, game s_game);

//Player 1
int check_winner_h(int r, int c, int p, char **s_board, game s_game);
int check_winner_v(int r, int c, int p, char **s_board, game s_game);
int check_winner_LD(int r, int c, int p, char **s_board, game s_game);
int check_winner_RD(int r, int c, int p, char **s_board, game s_game);

//Player 2
int check_winner_h2(int r, int c, int p, char **s_board, game s_game);
int check_winner_v2(int r, int c, int p, char **s_board, game s_game);
int check_winner_LD2(int r, int c, int p, char **s_board, game s_game);
int check_winner_RD2(int r, int c, int p, char **s_board, game s_game);

//Gameover Prototypes
void tie_end();
void p1_win();
void p2_win();

using namespace std;

int main(int argc, char*argv[])
{
	all_input(argc, argv);
}

//User Input Functions

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
		p1move(r, c, s_board, s_game);
			check_winner_h(r, c, p, s_board, s_game);
			check_winner_v(r, c, p, s_board, s_game);
			check_winner_LD(r, c, p, s_board, s_game);
			check_winner_RD(r, c, p, s_board, s_game);
			check_tie(c, r, s_board, s_game);
		p2move(r, c, s_board, s_game);
			check_winner_h2(r, c, p, s_board, s_game);
			check_winner_v2(r, c, p, s_board, s_game);
			check_winner_LD2(r, c, p, s_board, s_game);
			check_winner_RD2(r, c, p, s_board, s_game);
			check_tie(c, r, s_board, s_game);
	}
}

//Player 1 Check Win
int check_winner_h(int r, int c, int p, char **s_board, game s_game)
{
	int counter = 0; //Counter for number of filled pieces
	
	for (int i=0; i < r; i++)
	{
		for (int j=0; j < c; j++)
		{
			//Horizontal Check
			if (s_board[i][j] == 'r')
			{
				counter++;
				for (int h=1; h < p; h++)
				{
					if (s_board[i][j+h] == 'r')
					{
						counter++;
						if (p == counter)
						{
							p1_win();
						}

					}
					if (s_board[i][j+h] == 'y' || s_board[i][j+h] == '0')
					{
						counter = 0;
						break;
					}
				}
			counter = 0;
			}

		}
	}
}

int check_winner_v(int r, int c, int p, char **s_board, game s_game)
{
	int counter = 0; //Counter for number of filled pieces
	
	for (int i=0; i < r; i++)
	{
		for (int j=0; j < c; j++)
		{
			//Vertical Check
			if (s_board[i][j] == 'r')
			{
				counter++;
				for (int h=1; h < p; h++)
				{
					if ((h+i) == r)
					{
						break;
					}
					if (s_board[i+h][j] == 'r')
					{
						counter++;
						if (p == counter)
						{
							p1_win();
						}
					}
					if (s_board[i+h][j] == 'y' || s_board[i+h][j] == '0')
					{
						counter = 0;
						break;
					}
				}
			counter = 0;
			}
		}
	}
}

int check_winner_LD(int r, int c, int p, char **s_board, game s_game)
{
	int counter = 0; //Counter for number of filled pieces

	for (int i=0; i < r; i++) //Initalizes board for checking
	{
		for (int j=0; j < c; j++)
		{
			//Left Diag Check
			if (s_board[i][j] == 'r')
			{
				counter++; //One piece here already
				for (int h=1; h < p; h++) //Checking begins here
				{
					if ((h+i) == r || (j-h < 0))
					{
						break;
					}
					if (s_board[i+h][j-h] == 'r')//Determines direction of checking
					{
						counter++;
						if (p == counter)
						{
							p1_win();
						}
					}
					if (s_board[i+h][j-h] == 'y' || s_board[i+h][j-h] == '0') // Checks for other pieces in between
					{
						counter = 0;
						break;
					}
				}
			counter = 0;
			}
		}
	}
	return 0;
}

int check_winner_RD(int r, int c, int p, char **s_board, game s_game)
{
	int counter = 0;

	for (int i=0; i < r; i++)
	{
		for (int j=0; j < c; j++)
		{
			//Right Diag check
			if (s_board[i][j] == 'r')
			{
				counter++; //Account for the first piece
				for (int h=1; h < p; h++)
				{
					if ((h+i == r) || (h+j) == c) //Seg fault check
					{
						break;
					}
					if (s_board[i+h][j+h] == 'r')
					{
						counter++;
						if (p == counter)
						{
							p1_win();
						}
					}
					if (s_board[i+h][j+h] == 'y' || s_board[i+h][j+h] == '0')
					{
						counter = 0;
						break;
					}
				}
			}
		}
	}
}

//Player 2 Check Win
int check_winner_h2(int r, int c, int p, char **s_board, game s_game)
{
	int counter = 0; //Counter for number of filled pieces
	
	for (int i=0; i < r; i++)
	{
		for (int j=0; j < c; j++)
		{
			//Horizontal Check
			if (s_board[i][j] == 'y')
			{
				counter++;
				for (int h=1; h < p; h++)
				{
					if (s_board[i][j+h] == 'y')
					{
						counter++;
						if (p == counter)
						{
							p2_win();
						}

					}
					if (s_board[i][j+h] == 'r' || s_board[i][j+h] == '0')
					{
						counter = 0;
						break;
					}
				}
			counter = 0;
			}

		}
	}
}

int check_winner_v2(int r, int c, int p, char **s_board, game s_game)
{
	int counter = 0; //Counter for number of filled pieces
	
	for (int i=0; i < r; i++)
	{
		for (int j=0; j < c; j++)
		{
			//Vertical Check
			if (s_board[i][j] == 'y')
			{
				counter++;
				for (int h=1; h < p; h++)
				{
					if ((h+i) == r)
					{
						break;
					}
					if (s_board[i+h][j] == 'y')
					{
						counter++;
						if (p == counter)
						{
							p2_win();
						}
					}
					if (s_board[i+h][j] == 'r' || s_board[i+h][j] == '0')
					{
						counter = 0;
						break;
					}
				}
			counter = 0;
			}
		}
	}
}

int check_winner_LD2(int r, int c, int p, char **s_board, game s_game)
{
	int counter = 0; //Counter for number of filled pieces

	for (int i=0; i < r; i++) //Initalizes board for checking
	{
		for (int j=0; j < c; j++)
		{
			//Left Diag Check
			if (s_board[i][j] == 'y')
			{
				counter++; //One piece here already
				for (int h=1; h < p; h++) //Checking begins here
				{
					if ((h+i) == r || (j-h < 0))
					{
						break;
					}
					if (s_board[i+h][j-h] == 'y')//Determines direction of checking
					{
						counter++;
						if (p == counter)
						{
							p1_win();
						}
					}
					if (s_board[i+h][j-h] == 'r' || s_board[i+h][j-h] == '0') // Checks for other pieces in between
					{
						counter = 0;
						break;
					}
				}
			counter = 0;
			}
		}
	}
	return 0;
}

int check_winner_RD2(int r, int c, int p, char **s_board, game s_game)
{
	int counter = 0;

	for (int i=0; i < r; i++)
	{
		for (int j=0; j < c; j++)
		{
			//Right Diag check
			if (s_board[i][j] == 'y')
			{
				counter++; //Account for the first piece
				for (int h=1; h < p; h++)
				{
					if ((h+i == r) || (h+j) == c) //Seg fault check
					{
						break;
					}
					if (s_board[i+h][j+h] == 'y')
					{
						counter++;
						if (p == counter)
						{
							p2_win();
						}
					}
					if (s_board[i+h][j+h] == 'r' || s_board[i+h][j+h] == '0')
					{
						counter = 0;
						break;
					}
				}
			}
		}
	}
}

//Gameplay functions

int p1move(int r, int c, char **s_board, game s_game)
{
	int colm1;
	cout << "Player 1's Turn" << endl;
	print_board(r, c, s_board); //Show board
	colm1 = drop_check(r, c, s_board); //User input for move and error checking
	place_piece_p1(colm1, r, s_board, s_game);
	cout << endl << endl;

	return colm1;
}

//UNCOMMENT TO INCLUDE AI HERE!!!!!!

int p2move(int r, int c, char **s_board, game s_game)
{
	int colm;
	cout << "Player 2's Turn" << endl;
	print_board(r, c, s_board); //Show board
	colm = drop_check(r, c, s_board); //User input for move and error checking
	//colm = drop_check_ai(r, c, s_board);
	place_piece_p2(colm, r, s_board, s_game);
	cout << endl << endl;
}

int drop_check(int r, int c, char **s_board)
{
	int colm_input;
	cout << "Which column do you want to drop your piece in?: ";
	cin >> colm_input;
	
	//Checks if input is even valid
	while(colm_input > c || colm_input < 0)
	{
		cout << "Please enter valid input: ";
		cin >> colm_input;
	}

	//Checks if user inputted column selection is full
	while(s_board[0][colm_input-1] != '0')
	{
		cout << "The column is full, please enter a new column: ";
		cin >> colm_input;
	}
	
	return colm_input;
}

int drop_check_ai(int r, int c, char **s_board)
{
	int colm_input;
	cout << "Which column do you want to drop your piece in?: ";
	srand (time(NULL));
	colm_input = (rand() % c + 1);
	cout << colm_input;
	return colm_input;
}

void check_tie(int r, int c, char **s_board, game s_game)
{
	int counter = 0; //Counter for number of filled cols
	//Checks if all column moves are full
	for (int i=0; i < c; i++)
	{ 
		if ((s_board[0][i] == 'r') || (s_board[0][i] == 'y'))
		{
			counter++;
		}
		if (counter == c)
		{
			cout << "TIE" << endl;
			tie_end();
			break;
		}
	}
}

int place_piece_p1(int colm, int r, char **s_board, game s_game)
{
	for(int i=r-1; i >= 0; i--) //Looks through row in here
	{
		if(s_board[i][colm-1] != 'r' && s_board[i][colm-1] != 'y') //Checks if space is empty
		{
			s_board[i][colm-1] = s_game.p1; //Places piece
			i=0;
		}
	}
}

int place_piece_p2(int colm, int r, char **s_board, game s_game)
{
	for(int i=r-1; i >= 0; i--)
	{
		if(s_board[i][colm-1] != 'r' && s_board[i][colm-1] != 'y') //Checks if space is empty
		{
			s_board[i][colm-1] = s_game.p2;
			i=0;
		}
	}
}

//Board Functions

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

void fail_input_info()
{
	cout << "How to input command line input example:  -r (input) -c (input) -p (input)" << endl;
	cout << "\t-r is the number of rows" << endl;
	cout << "\t-c is the number of columns" << endl;
	cout << "\t-p is the number of pieces needed to win" << endl;
}

void tie_end()
{
	int x;
	cout << "TIE! No more possible moves remaining.." << endl;
	cout << "Do you want to play again? (1 = yes, 2 = no)" << endl;
	cin >> x;
	if (x == 1)
	{
		int r, c, p;
		cout << "Please input number of rows: ";
		cin >> r;
		cout << "Please input number of columns: ";
		cin >> c;
		cout << "Please input number of pieces needed to win: ";
		cin >> p;
		start_game(r, c, p);
	}
	if (x == 2)
	{
		exit(1);
	}
}

void p1_win()
{
	int x;
	cout << "PLAYER 1 WINS!" << endl;
	cout << "Do you want to play again? (1 = yes, 2 = no)" << endl;
	cin >> x;
	if (x == 1)
	{
		int r, c, p;
		cout << "Please input number of rows: ";
		cin >> r;
		cout << "Please input number of columns: ";
		cin >> c;
		cout << "Please input number of pieces needed to win: ";
		cin >> p;
		start_game(r, c, p);
	}
	if (x == 2)
	{
		exit(1);
	}
}

void p2_win()
{
	int x;
	cout << "PLAYER 2 WINS!" << endl;
	cout << "Do you want to play again? (1 = yes, 2 = no)" << endl;
	cin >> x;
	if (x == 1)
	{
		int r, c, p;
		cout << "Please input number of rows: ";
		cin >> r;
		cout << "Please input number of columns: ";
		cin >> c;
		cout << "Please input number of pieces needed to win: ";
		cin >> p;
		start_game(r, c, p);
	}
	if (x == 2)
	{
		exit(1);
	}
}
