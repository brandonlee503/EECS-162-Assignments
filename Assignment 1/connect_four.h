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