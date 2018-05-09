#include "./deck.h"
#include "./player.h"

class game{
	private:
	   	deck d;
		player *players;
		dealer game_dealer;
		int num_players;
		int starting_total;
	public:
		game();
	      	~game();
		game(const game &);
		void operator = (const game &); 	
		void play_game();
		int get_starting_total();
	       	void set_starting_total(); 
		void set_num_players(); 
		int get_num_players(); 
		void print_players(); 
		player* make_players();
	       	void set_players(player *);  	

};