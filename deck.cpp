#include <time.h>
#include "deck.h"

deck::deck(){
       	num_cards=52;
	card * d = make_deck();
	set_deck(d); 

} 

deck::~deck(){
}

int deck::get_num_cards(){
	return num_cards;
}

card * deck::make_deck(){
   	card *d = new card[52];
	for(int i=0; i<52; i++)
	  	d[i].faced_up = true; 
	for(int i=0; i<13; i++)
      		d[i].suit = "spades";
	for(int i=13; i<26; i++)
   		d[i].suit = "hearts";
	for(int i=26; i<39; i++)
   		d[i].suit = "clubs";
	for(int i=39; i<52; i++)
   		d[i].suit = "diamonds";
	for(int i=0; i<52;){
		for(int k=0; k<4; k++){
			for(int n=1; n<11; n++){
				d[i].value=n; 
				i++;
			}for(int n=0; n<3; n++){
				d[i].value=10;
				i++;
			}  
		} 
	}for(int i=0; i<52;){
		for(int k=0; k<4; k++){
			d[i].face='A';
			i+=10;
			d[i].face='J'; i++;
			d[i].face='Q'; i++;
			d[i].face='K'; i++;
		}	
	}return d;  	
};

void deck::set_deck(card *d){
	for(int i=0; i<52; i++){
		cards[i] = d[i]; 
	}delete [] d; 
} 

void deck::shuffle_deck(deck &d){
	cout << "The dealer shuffles the cards..." << endl; 
   	srand(time(0));
       	for(int i=0; i<1000; i++){
		int c1 = rand() % d.get_num_cards(); 
	       	int c2 = rand() % d.get_num_cards();
		card temp = d.cards[c1];
		d.cards[c1] = d.cards[c2];
		d.cards[c2] = temp;	
	} 	
}

void deck::print_deck(deck d){
	for(int i=0; i<num_cards; i++){
		cout << d.cards[i].face << " of " << d.cards[i].suit; 
		cout << d.cards[i].value << endl; 
	} 
}

card deck::remove_card(){
	num_cards = num_cards-1;
	return cards[num_cards]; 
} 