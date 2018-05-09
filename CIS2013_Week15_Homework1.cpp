#include "./game.h" 

using namespace std;

game::game(){
	cout << "Welcome to BlackJack!" << endl; 
	set_num_players(); 
	set_starting_total();
       	players = make_players();
	
} 

game::~game(){
   	cout << "Now leaving BlackJack" << endl;
	delete [] players; 	
}

game::game(const game &other){
	d = other.d;
	game_dealer = other.game_dealer;
	num_players = other.num_players;
	starting_total = other.starting_total;
	players = new player[num_players];
	for(int i=0; i<num_players; i++){
		players[i] = other.players[i];
	} 	
}

void game::operator = (const game & other){ 
	d = other.d;
	game_dealer = other.game_dealer;
	num_players = other.num_players;
	starting_total = other.starting_total;
	players = new player[num_players];
	for(int i=0; i<num_players; i++){
		players[i] = other.players[i];
	}delete [] other.players; 	
}

int game::get_num_players(){ 
	return num_players;
} 

void game::set_num_players(){
	cout << "How many players will be with us today?: ";	
	while(!(cin >> num_players) || (num_players<1) || (num_players>5)){
		cin.clear();
		cin.ignore(); 
		cout << "No players more than 5 or less than 1 at the table. ";
		cout << "Sorry, house rules. \nEnter a new number: ";	
	} 
}

player * game::make_players(){
	player *p = new player [num_players];
	for(int i=0; i<num_players; i++);
	return p;
}

void player::get_inital_hand(deck &d){
   	p_hand.create_hand();
	p_hand.add_card(d.remove_card());
	p_hand.add_card(d.remove_card()); 	
} 

void dealer::get_dealer_hand(deck &d){
	d_hand.create_hand();
   	cout << endl << "Dealer deals his own hand..." << endl; 
	d_hand.add_card(d.remove_card());
	d_hand.add_card(d.remove_card()); 
	d_hand.flip_card(); 	
} 

void player::hit(deck &d, bool &stay){
	p_hand.add_card(d.remove_card()); 
	int card_total = p_hand.count_total(p_hand);  
	if(card_total>21){
		cout << "You Busted!" << endl;
		stay = true;
	}	   
}

void game::play_game(){
   	d.shuffle_deck(d); 	       	
	cout << "Dealer deals out hand..." << endl;
	for(int i=0; i<num_players; i++){
	   	cout << endl << "For Player " << i+1 << ": " <<endl;  
		players[i].get_inital_hand(d);
	      	players[i].print_hand(); 	
	}game_dealer.get_dealer_hand(d);
     	game_dealer.print_dhand(); 
	for(int i=0; i<num_players; i++){ 
	   	int choice;
		bool stay = false;
		cout << endl << "Player " << i+1 << ": " << endl;
	     	while(stay == false){ 
		  	cout << "Would you like to hit(1), stay(2)";  
			cout << " or see hand(3): ";
			while(!(cin>>choice) && choice!=1 && choice!=2 && choice!=3){
				cin.clear(); 
			      	cin.ignore();
				cout << "Please pick 1, 2, or 3: "; 	
			}if(choice == 1){
				players[i].hit(d, stay); 
				if(stay ==false) 
				   	players[i].print_hand(); 
			}else if(choice == 2){
				stay = true; 
			}else{ 
			  	cout << "Current card worth: ";
		       		cout <<	players[i].get_card_total() << endl;
			}if(stay == true){
				players[i].determine_bust();
			}				    
		}	
	}game_dealer.show_cards(); 
	game_dealer.dhit(d);  
	for(int i=0; i<num_players; i++){ 
		if(players[i].get_card_total() <= 21){ 
		   	cout << "Player " << i+1 << ": " << endl;
			if(game_dealer.get_dcard_total() > 21) 
				players[i].won();
		      	else if(game_dealer.get_dcard_total() < players[i].get_card_total()){
				players[i].won();  
			}else if(game_dealer.get_dcard_total() > players[i].get_card_total()){
			   	players[i].lost(); 
			}else if(game_dealer.get_dcard_total() == players[i].get_card_total())
		   		players[i].tie(); 	   
		}cout << endl; 		
	}  	



} 






