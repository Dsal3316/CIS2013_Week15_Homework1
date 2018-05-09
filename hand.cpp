#include "./hand.h"

hand::hand(){
	num_cards = 0; 
} 

hand::~hand(){
	delete [] cards;
}

hand::hand(const hand & other){
	num_cards = other.num_cards;
	cards = new card[num_cards];
	for(int i=0; i<num_cards; i++){
		cards[i] = other.cards[i];
	}
};

void hand::operator = (const hand & other){
	num_cards = other.num_cards;
	cards = new card[num_cards];
	for(int i=0; i<num_cards; i++)
      		cards[i] = other.cards[i];
	delete [] other.cards;	
} 

void hand::create_hand(){
   	num_cards = 0;
	cards = new card[num_cards];
} 

void hand::add_card(card c){
	card *temp;
	num_cards = num_cards+1;
	temp=cards; 
	cards=new card[num_cards];
	for(int i=0; i<num_cards-1; i++){
		cards[i]=temp[i];
	}delete [] temp;
       	cards[num_cards-1]=c; 
}

int hand::get_num_cards(){
	return num_cards;
}

card * hand::get_cards() const{
	return cards;
} 

void hand::print_cards(){
	cout << "Current hand:" << endl;
	for(int i=0; i<num_cards; i++){
       		if(cards[i].faced_up != false){
			if(cards[i].face == 'J')
			 	cout << "Jack"; 
		     	else if(cards[i].face == 'Q')
		   		cout << "Queen";
     			else if(cards[i].face == 'K')
   				cout << "King";
			else if(cards[i].face == 'A')
   				cout << "Ace";
			else
   				cout << cards[i].value;
			cout << " of " << cards[i].suit << endl;		
		}
	}
}

int hand::count_total(hand h){
	int total=0;
   	for(int i=0; i<h.get_num_cards(); i++){
		if(h.cards[i].faced_up != false) 
		  	total += h.cards[i].value; 
	}
       	return total;
}

void hand::flip_card(){ 
	if(cards[num_cards-1].faced_up == true) 
	   	cards[num_cards-1].faced_up = false;
	else
	   	cards[num_cards-1].faced_up = true;
	   	
}		