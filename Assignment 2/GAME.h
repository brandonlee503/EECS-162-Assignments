
using namespace std;


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