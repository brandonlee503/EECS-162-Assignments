

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