// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "Pack.h"
#include <array>
#include <string>
#include <iostream>
#include <vector>
using namespace std;


// EFFECTS: Initializes the Pack to be in the following standard order:
//          the cards of the lowest suit arranged from lowest rank to
//          highest rank, followed by the cards of the next lowest suit
//          in order from lowest to highest rank, and so on.
// NOTE: The standard order is the same as that in pack.in.
// NOTE: Do NOT use pack.in in your implementation of this function

Pack::Pack(){
    int counter = 0;
    for(int i = 0; i < NUM_SUITS; i++){
        for(int j = 7; j < NUM_RANKS; j++){

            Card c= Card(RANK_NAMES_BY_WEIGHT[j], SUIT_NAMES_BY_WEIGHT[i]);
            cards[counter++] = c;
      
        }
    }

    next = 0;

}
    
    
Pack::Pack(std::istream& pack_input){
        std::string rank;
        std::string suit;
        std::string of;
        int i = 0;
        while(pack_input >> rank >> of >> suit){
        Card c(rank, suit);
        cards[i++] = c;
        }
        next = 0;
    }

    
Card Pack::deal_one(){
    Card dealing = cards.at(next++);
    return dealing;
           // std::array<Card, PACK_SIZE> cards;
}

    
    
void Pack::reset(){
    next = 0;
}


void Pack::shuffle(){
//    cout << "unshuffled" << endl;
//    for(int i = 0; i < cards.size(); i++){
//
//        cout << cards[i].get_rank() << " of " << cards[i].get_suit() << endl;

    int counter = 0;
    array <Card, 24> shuffled;
    for(int j = 0; j < 7; ++j){
        for(int i = 0; i < 12 ; i++){
        shuffled[counter++] = cards[i + 12];
        shuffled[counter++] = cards[i];
        }
        cards = shuffled;
        counter = 0;
    }


//    cout << "shuffled" << endl;
//    for(int i = 0; i < cards.size(); i++){
//
//        cout << cards[i].get_rank() << " of " << cards[i].get_suit() << endl;
//
//
//    }
//
}




bool Pack::empty() const{
    if(next >= 24){
        return true;
    }
    return false;
}

