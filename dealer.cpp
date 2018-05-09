#include "dealer.h"

dealer::dealer(){
	num_cards = 0;
} 

dealer::~dealer(){
}

void dealer::print_dhand(){
	cout << "Dealer has one card faced down, the other showing... " <<endl; 
  	d_hand.print_cards(); 
	card_total = d_hand.count_total(d_hand); 
	bool aces = false;
	int ace_card_total = card_total; 
      	cout << "Current dealer shown card worth: " << card_total;
	for(int i=0; i<d_hand.get_num_cards(); i++){
		if(d_hand.get_cards()[i].face =='A' && d_hand.get_cards()[i].faced_up == true ){
		   	aces = true;
			ace_card_total += 10;
			break; 
		}
	}if(aces == true){
		cout << " or " << ace_card_total; 
	}cout << endl;  	
}

int dealer::get_dcard_total(){
	return card_total;
}

void dealer::show_cards(){
	cout << "Dealer flips over card" << endl;
       	d_hand.flip_card(); 	
	d_hand.print_cards();
       	card_total = d_hand.count_total(d_hand);
	cout << "Current dealer card worth: " << card_total << endl << endl;
} 

void dealer::dhit(deck &d){
   	bool stay = false;
	while(stay == false && card_total<17){ 
	  	cout << "Dealer hits..." << endl;  
		d_hand.add_card(d.remove_card()); 
		d_hand.print_cards(); 
		card_total = d_hand.count_total(d_hand); 
		int ace_card_total = card_total;
		bool aces = false;
		for(int i=0; i<d_hand.get_num_cards(); i++){
			if(d_hand.get_cards()[i].face =='A'){
				aces =true; 
			   	ace_card_total += 10;
				break; 
			}	       
		}cout << "Current dealer worth: " << card_total; 
		if(aces == true)
			cout << " or " << ace_card_total;
		cout << endl; 
		if(card_total>=17 || (ace_card_total>=17 && ace_card_total<=21)){
			if(ace_card_total >= 17 && ace_card_total <= 21)
	    			card_total = ace_card_total;  
		   	stay = true; 
		}if(card_total>21){
			cout << "Dealer busted!" << endl;
			stay = true;
		}cout << endl;
	}		
}