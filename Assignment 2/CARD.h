
using namespace std;


class CARD{
private:
	string rank;
	string suit;
public:
	CARD();
	CARD(string rankc, string suitc);
	string print_card();
	string get_rank();
};