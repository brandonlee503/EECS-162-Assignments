

using namespace std;


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
