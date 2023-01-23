// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "Card.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>
#include <vector>
#include <iostream>
using namespace std;


class SimplePlayer: public Player{
    private:
    string name;
    std::vector<Card> hand;
    string type = "Simple";
    
    public:
    SimplePlayer(const string &name): name(name) {}
    
const string & get_name() const {
        return name;
    }
    
void add_card(const Card &c){
    hand.push_back(c);
}

const string & get_type() const {
        return type;
    }


    
bool make_trump(const Card &upcard, bool is_dealer,
                int round, std::string &order_up_suit) const{
    int counter = 0;
    if(round == 1){
        for(int i = hand.size() - 1; i >= 0; i--){
            if((hand[i].is_face_or_ace()) && (hand[i].get_suit() ==
                                                upcard.get_suit())){
                counter++;
            }else if((hand[i].get_rank() == Card::RANK_JACK) &&
                                (hand[i].is_left_bower(order_up_suit))){
                counter++;
            }

        }
        if(counter >= 2){
            order_up_suit = upcard.get_suit();
            return true;
        }else{
            return false;
        }

    }
    if(round == 2){
        if(is_dealer == false){
            for(int i = hand.size() - 1; i >= 0; i--){
                if((hand[i].is_face_or_ace())){
                    counter++;
                }else if((hand[i].get_rank() ==
                        Card::RANK_JACK) &&
                             (hand[i].is_left_bower(order_up_suit))){
                    counter++;
                }
                
            }
            if(counter >= 1){
                order_up_suit = hand[hand.size()-1].get_suit();
          return true;
            }else{
                   
          return false;
            }
        }
        }else{
            if(upcard.get_suit() == Card::SUIT_HEARTS){
                order_up_suit = Card::SUIT_DIAMONDS;
            }else if(upcard.get_suit() == Card::SUIT_DIAMONDS){
                order_up_suit = Card::SUIT_HEARTS;
            }else if(upcard.get_suit() == Card::SUIT_CLUBS){
                order_up_suit = Card::SUIT_SPADES;
            }else if(upcard.get_suit() == Card::SUIT_SPADES){
                order_up_suit = Card::SUIT_CLUBS;
            }else{
                cout << "Invalid Suit" << endl;;
            }
        }
    return false;
}
                   
void add_and_discard(const Card &upcard){
    sort(hand.begin(), hand.end());
    if(type == "Simple"){
    for(int i = MAX_HAND_SIZE - 1; i >= 0; i--){
        if(hand[i].is_left_bower(upcard.get_suit()) == true){
            Card temp = hand[i];
            hand.erase(hand.begin() + i);
            hand.push_back(temp);
        }
        if(hand[i].is_right_bower(upcard.get_suit()) == true){
            Card temp = hand[i];
            hand.erase(hand.begin() + i);
            hand.push_back(temp);
        }
    }
    if(hand[3].is_right_bower(upcard.get_suit()) == true ||
       hand[4].is_left_bower(upcard.get_suit())){
        Card temp = hand[3];
        hand.erase(hand.begin() + 3);
        hand.push_back(temp);
       }
     for(int i =0 ; i >= 2; i++){
    if(hand[i].get_rank() < upcard.get_rank()
       && hand[i].get_suit() == upcard.get_suit() &&
       hand[i].is_right_bower(upcard.get_suit()) == false){
        hand[i] = upcard;
    }
     }
    if(hand[0].get_suit() != upcard.get_suit() &&
            hand[0].is_left_bower(upcard.get_suit()) == false ){
        hand[0] = upcard;
    }
    }
}
    
Card lead_card(const std::string &trump){
    sort(hand.begin(), hand.end());
    for(int i = hand.size() - 1; i >= 0; i--){
        if(hand[i].is_left_bower(trump) == true){
            Card temp = hand[i];
            hand.erase(hand.begin() + i);
            hand.push_back(temp);
        }
        if(hand[i].is_right_bower(trump) == true){
            Card temp = hand[i];
            hand.erase(hand.begin() + i);
            hand.push_back(temp);
        }
    }
    if(hand[3].is_right_bower(trump) == true &&
       hand[4].is_left_bower(trump) == true){
        Card temp = hand[3];
        hand.erase(hand.begin() + 3);
        hand.push_back(temp);
       }
    //Card temp = hand[0];
    //cout << hand[0].get_suit();
    
    for(int i = hand.size() - 1; i >= 0; i--){
        if(hand[i].is_left_bower(trump) == false){
            if(hand[i].get_suit() != trump){
            //        cout << hand[i].get_rank() << " of "
            //        << hand[i].get_suit() << " is played by " << name;
                Card holder = hand[i];
                hand.erase(hand.begin() + i);
                return holder;
            }
        }
    }
    for(int i = hand.size() - 1; i >= 0; i--){
        if(hand[i].is_right_bower(trump) == true){
        //        cout << hand[i].get_rank() << " of "
        //        << hand[i].get_suit() << " is played by " << name;
            Card holder = hand[i];
            hand.erase(hand.begin() + i);
            return holder;
        }
        if(hand[i].is_left_bower(trump) == true){
         //       cout << hand[i].get_rank() << " of "
         //       << hand[i].get_suit() << " is played by " << name;
            Card holder = hand[i];
            hand.erase(hand.begin() + i);
            return holder;
        }
    }
    Card holder = hand[hand.size() - 1];
    hand.erase(hand.begin() + (hand.size() - 1));
    return holder;
    
}
    
    
    
Card play_card(const Card &led_card, const std::string &trump){

    sort(hand.begin(), hand.end());
    if(led_card.get_suit() == trump){
        for(int i = hand.size() - 1; i >= 0; i--){
            if(hand[i].is_right_bower(led_card.get_suit()) == true){
                Card holder = hand[i];
                hand.erase(hand.begin() + i);
                return holder;
            }
        }
        for(int i = hand.size() - 1; i >= 0; i--){
            if(hand[i].is_left_bower(led_card.get_suit())){
                Card holder = hand[i];
                hand.erase(hand.begin() + i);
                return holder;
            }
        
        }
        for(int i = hand.size() - 1; i >= 0; i--){
            if(hand[i].get_suit() == led_card.get_suit()){
                Card holder = hand[i];
                hand.erase(hand.begin() + i);
                return holder;
            }
        
        }
        
        Card holder = hand[0];
        hand.erase(hand.begin());
        return holder;
    }else{
        
        
        for(int i = hand.size() - 1; i >= 0; i--){
            if(hand[i].is_left_bower(trump) == true){
                Card temp = hand[i];
                hand.erase(hand.begin() + i);
                hand.push_back(temp);
            }

        }
        for(int i = hand.size() - 1; i >= 0; i--){
        if(hand[i].is_right_bower(trump) == true){
            Card temp = hand[i];
            hand.erase(hand.begin() + i);
            hand.push_back(temp);
        }
        }
        
        for(int i = hand.size() - 1; i >= 0; i--){
            if(hand[i].get_suit() == led_card.get_suit()
                && !hand[i].is_left_bower(trump)){
                Card holder = hand[i];
                hand.erase(hand.begin() + i);
                return holder;
            }
 
        }
        //checking worst card not trump suit
        for(int i = 0; i < hand.size(); i++){
            if((hand[i].get_suit() != trump) &&
                (!hand[i].is_left_bower(trump))){
                    Card holder = hand[i];
                hand.erase(hand.begin() + i);
                return holder;
            }
        }
        if(hand[0].get_suit() == hand[1].get_suit() &&
            hand[0].get_rank() > hand[1].get_rank() ) {
                Card holder = hand[1];
                hand.erase(hand.begin());
                return holder;
            }
        Card holder = hand[0];
        hand.erase(hand.begin());
        return holder;
    }

}
    

//    if(hand[3].is_right_bower(trump) == true &&
//       hand[4].is_left_bower(trump) == true){
//        Card temp = hand[3];
//        hand.erase(hand.begin() + 3);
//        hand.push_back(temp);
//       }
//    if(led_card.get_suit() == trump){
//        for(int i = hand.size() - 1; i >= 0; i--){
//        if(hand[i].is_right_bower(trump) == true){
//            //    cout << hand[i].get_rank() << " of "
//            //    << hand[i].get_suit() << " is played by " << name;
//            Card holder = hand[i];
//            hand.erase(hand.begin() + i);
//            return holder;
//        }
//        if(hand[i].is_left_bower(trump) == true){
//            //    cout << hand[i].get_rank() << " of "
//            //    << hand[i].get_suit() << " is played by " << name;
//            Card holder = hand[i];
//            hand.erase(hand.begin() + i);
//            return holder;
//        }
//        }
//    }
//    for(int i = hand.size() - 1; i >= 0; i--){
//            if(hand[i].get_suit() == led_card.get_suit()){
//            //        cout << hand[i].get_rank() << " of "
//             //            << hand[i].get_suit()
//                                << " is played by " << name;
//            Card holder = hand[i];
//            hand.erase(hand.begin() + i);
//            return holder;
//            }
//     }
//    Card holder = hand[0];
//    hand.erase(hand.begin());
//    return holder;


    
static const int MAX_HAND_SIZE = 5;
~SimplePlayer() {}
    

//        return os;
        
    
//class Human: public Human{};

};
//
//


std::ostream & operator<<(std::ostream &os, const Player &p){
       return os << p.get_name();
    
}

class HumanPlayer: public Player{
    private:
    string name;
    std::vector<Card> hand;
    string type = "Human";

    void print_hand() const{
    for (size_t i=0; i < hand.size(); ++i)
    cout << "Human player " << name << "'s hand: "
         << "[" << i << "] " << hand[i] << "\n";
    }

    
    public:
    HumanPlayer(const string &name): name(name) {}
    const string & get_name() const {
        return name;
    }
    
    void add_card(const Card &c){
        hand.push_back(c);
        sort(hand.begin(), hand.end());
    }

    const string & get_type() const {
        return type;
    }
    void add_and_discard(const Card &upcard){
        sort(hand.begin(), hand.end());
        int cardnum;
        if(type == "Human"){
            print_hand();
            cout << "Discard upcard: [-1]\n";
            cout << "Human player " << name <<
            ", please select a card to discard:\n";
            cin >> cardnum;
            if(cardnum != -1){
                hand.erase(hand.begin() + cardnum);
            }
        }
    }
    Card lead_card(const std::string &trump){
        
        sort(hand.begin(), hand.end());
        print_hand();
        cout << "Human player " << name <<
                 ", please select a card:\n";
        int cardnum;
        cin >> cardnum;
        Card leadcard = hand[cardnum];
        hand.erase(hand.begin() + cardnum);
        return leadcard;
    }
    
    bool make_trump(const Card &upcard, bool is_dealer,
                    int round, std::string &order_up_suit) const{
        
        print_hand();
        cout << "Human player " << name <<
                 ", please enter a suit, or \"pass\":\n";
        string suitOrPass;
        cin >> suitOrPass;
        
        if(round == 1){
            if(suitOrPass != "pass"){
                order_up_suit = upcard.get_suit();
                return true;
            }else{
                return false;
            }
        }else{
            if(suitOrPass != "pass"){
                order_up_suit = suitOrPass;
                return true;
            }else{
                return false;
            }
        }

    }
        
    Card play_card(const Card &led_card, const std::string &trump){

        sort(hand.begin(), hand.end());
        print_hand();
        cout << "Human player " << name <<
                 ", please select a card:\n";
        int cardnum;
        cin >> cardnum;
        Card playcard = hand[cardnum];
        hand.erase(hand.begin() + cardnum);
        return playcard;
    }

};

Player * Player_factory(const std::string &name, const std::string &strategy){

    if(strategy == "Simple"){
        return new SimplePlayer(name);
    }
    if(strategy == "Human"){
        return new HumanPlayer(name);
    }
    return NULL;
    
}


