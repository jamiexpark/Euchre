// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include "Card.h"

using namespace std;
// add any necessary #include or using directives here

// rank and suit names -- do not remove these
constexpr const char* const Card::RANK_TWO;
constexpr const char* const Card::RANK_THREE;
constexpr const char* const Card::RANK_FOUR;
constexpr const char* const Card::RANK_FIVE;
constexpr const char* const Card::RANK_SIX;
constexpr const char* const Card::RANK_SEVEN;
constexpr const char* const Card::RANK_EIGHT;
constexpr const char* const Card::RANK_NINE;
constexpr const char* const Card::RANK_TEN;
constexpr const char* const Card::RANK_JACK;
constexpr const char* const Card::RANK_QUEEN;
constexpr const char* const Card::RANK_KING;
constexpr const char* const Card::RANK_ACE;

constexpr const char* const Card::SUIT_SPADES;
constexpr const char* const Card::SUIT_HEARTS;
constexpr const char* const Card::SUIT_CLUBS;
constexpr const char* const Card::SUIT_DIAMONDS;

// add your code below
//EFFECTS Initializes Card to the Two of Spades
Card::Card(){
    
    rank = RANK_TWO;
    suit = SUIT_SPADES;
}

//REQUIRES rank is one of "Two", "Three", "Four", "Five", "Six", "Seven",
//  "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"
//  suit is one of "Spades", "Hearts", "Clubs", "Diamonds"
//EFFECTS Initializes Card to specified rank and suit
Card::Card(const std::string &rank_in, const std::string &suit_in){
    
    assert(rank_in == RANK_TWO || RANK_THREE || RANK_FOUR );
    
    rank = rank_in;
    suit = suit_in;
    
}

//EFFECTS Returns the rank
string Card::get_rank() const{
    return rank;
}

//EFFECTS Returns the suit.  Does not consider trump.
string Card::get_suit() const{
    return suit;
}

//REQUIRES trump is a valid suit
//EFFECTS Returns the suit
//HINT: the left bower is the trump suit!
string Card::get_suit(const std::string &trump) const{
    if(is_left_bower(trump) == true){
        return trump;
    }
    else{
        return suit;
    }
}

//EFFECTS Returns true if card is a face card (Jack, Queen, King or Ace)
bool Card::is_face_or_ace() const{
    if(Card::rank == RANK_JACK || Card::rank == RANK_QUEEN
     || Card::rank == RANK_KING || Card::rank == RANK_ACE){
        
        return true;
    }
    return false;
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if card is the Jack of the trump suit
bool Card::is_right_bower(const std::string &trump) const{
    
    if(trump == suit && rank == RANK_JACK){
        return true;
        
    }
    
    return false;
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if card is the Jack of the next suit
bool Card::is_left_bower(const std::string &trump) const{
    if(rank == RANK_JACK){
        if(trump == suit){
            return false;
        }
        if(trump == SUIT_SPADES || trump == SUIT_CLUBS){
            if(suit == SUIT_CLUBS && trump == SUIT_SPADES){
                return true;
            }
            if(suit == SUIT_SPADES && trump == SUIT_CLUBS){
                return true;
            }
            return false;
        }
        if(trump == SUIT_HEARTS || trump == SUIT_DIAMONDS){
            if(suit == SUIT_DIAMONDS && trump == SUIT_HEARTS){
                return true;
            }
            if(suit == SUIT_HEARTS && trump == SUIT_DIAMONDS){
                return true;
            }
            return false;
        }
    }
    return false;
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if the card is a trump card.  All cards of the trump
// suit are trump cards.  The left bower is also a trump card.
bool Card::is_trump(const std::string &trump) const{
    if(trump == Card::suit){
        return true;
    }
    if(is_left_bower(trump) == true){
        return true;
    }
    return false;
}


//EFFECTS Returns true if lhs is lower value than rhs.
//  Does not consider trump.
bool operator<(const Card &lhs, const Card &rhs){
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    int temp4 = 0;
    if (lhs.is_face_or_ace() == true){
        if (lhs.get_rank() == Card::RANK_JACK){
            temp1 = 11;
        }
        if (lhs.get_rank() == Card::RANK_QUEEN){
            temp1 = 12;
        }
        if (lhs.get_rank() == Card::RANK_KING){
            temp1 = 13;
        }
        if (lhs.get_rank() == Card::RANK_ACE){
            temp1 = 14;
        }
    }
    if (lhs.is_face_or_ace() == false){
        if (lhs.get_rank() == Card::RANK_TWO){
            temp1 = 2;
        }
        if (lhs.get_rank() == Card::RANK_THREE){
            temp1 = 3;
        }
        if (lhs.get_rank() == Card::RANK_FOUR){
            temp1 = 4;
        }
        if (lhs.get_rank() == Card::RANK_FIVE){
            temp1 = 5;
        }
        if (lhs.get_rank() == Card::RANK_SIX){
            temp1 = 6;
        }
        if (lhs.get_rank() == Card::RANK_SEVEN){
            temp1 = 7;
        }
        if (lhs.get_rank() == Card::RANK_EIGHT){
            temp1 = 8;
        }
        if (lhs.get_rank() == Card::RANK_NINE){
            temp1 = 9;
        }
        if (lhs.get_rank() == Card::RANK_TEN){
            temp1 = 10;
        }
    }
    if (rhs.is_face_or_ace() == true){
        if (rhs.get_rank() ==Card::RANK_JACK){
            temp2 = 11;
        }
        if (rhs.get_rank() == Card::RANK_QUEEN){
            temp2 = 12;
        }
        if (rhs.get_rank() == Card::RANK_KING){
            temp2 = 13;
        }
        if (rhs.get_rank() == Card::RANK_ACE){
            temp2 = 14;
        }
    }
        if (rhs.is_face_or_ace() == false){
        if (rhs.get_rank() == Card::RANK_TWO){
            temp2 = 2;
        }
        if (rhs.get_rank() == Card::RANK_THREE){
            temp2 = 3;
        }
        if (rhs.get_rank() == Card::RANK_FOUR){
            temp2 = 4;
        }
        if (rhs.get_rank() == Card::RANK_FIVE){
            temp2 = 5;
        }
        if (rhs.get_rank() == Card::RANK_SIX){
            temp2 = 6;
        }
        if (rhs.get_rank() == Card::RANK_SEVEN){
            temp2 = 7;
        }
        if (rhs.get_rank() == Card::RANK_EIGHT){
            temp2 = 8;
        }
        if (rhs.get_rank() == Card::RANK_NINE){
            temp2 = 9;
        }
        if (rhs.get_rank() == Card::RANK_TEN){
            temp2 = 10;
        }
    }
    if (lhs.get_suit() == Card::SUIT_SPADES){
        temp3 = 1;
    }
    if (lhs.get_suit() == Card::SUIT_HEARTS){
        temp3 = 2;
    }
    if (lhs.get_suit() == Card::SUIT_CLUBS){
        temp3 = 3;
    }
    if (lhs.get_suit() == Card::SUIT_DIAMONDS){
        temp3 = 4;
    }
    if (rhs.get_suit() == Card::SUIT_SPADES){
        temp4 = 1;
    }
    if (rhs.get_suit() == Card::SUIT_HEARTS){
        temp4 = 2;
    }
    if (rhs.get_suit() == Card::SUIT_CLUBS){
        temp4 = 3;
    }
    if (rhs.get_suit() == Card::SUIT_DIAMONDS){
        temp4 = 4;
    }
    if (temp1 == temp2){
        if (temp3 < temp4){
            return true;
        }
        if (temp3 == temp4){
            return false;
        }
        else{
            return false;
        }
    }
    return temp1 < temp2;
}





//EFFECTS Returns true if lhs is lower value than rhs or the same card as rhs.
//  Does not consider trump.
bool operator<=(const Card &lhs, const Card &rhs){
    return lhs < rhs || lhs == rhs;
}

//EFFECTS Returns true if lhs is higher value than rhs.
//  Does not consider trump.
bool operator>(const Card &lhs, const Card &rhs){
    if( lhs.get_rank() == rhs.get_rank()){
        return (lhs < rhs);
    }
    return !(lhs < rhs);
}

//EFFECTS Returns true if lhs is higher value than rhs or the same card as rhs.
//  Does not consider trump.
bool operator>=(const Card &lhs, const Card &rhs){
    if( lhs == rhs){
        return true;
    }
    return !(lhs < rhs);
}

//EFFECTS Returns true if lhs is same card as rhs.
//  Does not consider trump.
bool operator==(const Card &lhs, const Card &rhs){
    
    if(lhs.get_rank() == rhs.get_rank()){
        if(lhs.get_suit() == rhs.get_suit()){
        return true;
        }
    }
    return false;
}

//EFFECTS Returns true if lhs is not the same card as rhs.
//  Does not consider trump.
bool operator!=(const Card &lhs, const Card &rhs){
    return !(lhs == rhs);
}

//REQUIRES suit is a valid suit
//EFFECTS returns the next suit, which is the suit of the same color
std::string Suit_next(const std::string &suit){
    if(suit == Card::SUIT_CLUBS){
        return Card::SUIT_SPADES;
    }
    
    if(suit ==Card::SUIT_SPADES){
        return Card::SUIT_CLUBS;
    }
        
    if(suit == Card::SUIT_HEARTS){
        return Card::SUIT_DIAMONDS;
    }
    if(suit == Card::SUIT_DIAMONDS){
        return Card::SUIT_HEARTS;
   
    }
    return 0;
}
//EFFECTS Prints Card to stream, for example "Two of Spades"
std::ostream & operator<<(std::ostream &os, const Card &card){
    
    return os << card.get_rank() << " of " << card.get_suit();
}
        
//REQUIRES trump is a valid suit
//EFFECTS Returns true if a is lower value than b.  Uses trump to determine
// order, as described in the spec.
bool Card_less(const Card &a, const Card &b, const std::string &trump){
    if(a.is_left_bower(trump) == true){
        if(b.is_left_bower(trump) == false){
            return false;
        }
    }

    if(a.is_right_bower(trump) == true){
        if(b.is_right_bower(trump) == false){
            return false;
           }
       }
          
          
          
    if(a.is_right_bower(trump) == false){
                 if(b.is_right_bower(trump) == true){
                     return true; //true
                 }
             }
           
                
    if(b.is_left_bower(trump) == false){
        if(a.is_left_bower(trump) == true){
            return false;
        }
    }
                
                if(b.is_left_bower(trump) == true){
                    if(a.is_left_bower(trump) == true){
                        return true;
                    }
                }
                
                
                if(b.is_left_bower(trump) == true){
                    if(a.is_left_bower(trump) == true){
                        return false;
                    }
                }
                
                
                
                
                
                
                if(b.is_right_bower(trump) == true){
                    if(a.is_right_bower(trump) == false){
                        return true;
                    }
                }
                
                
                
                
                
                
                if(b.is_right_bower(trump) == false){
                    if(a.is_right_bower(trump) == true){
                        return false;
                    }
                }
                

                if(b.is_right_bower(trump) == true){
                    if(a.is_right_bower(trump) == true){
                        return false;
                    }
                }
                if(a.is_trump(trump) == true && b.is_trump(trump) == true){
                    if(a.get_rank() < b.get_rank()){
                        return true;
                    }
                    else return false;
                }
                if(a.is_trump(trump) == true && b.is_trump(trump) == false){
                    return false;
                }
                if(a.is_trump(trump) == false && b.is_trump(trump) == true){
                    return true;
                }
                if (a < b){
                    return true;
                }
                else return false;
                }
//REQUIRES trump is a valid suit
//EFFECTS Returns true if a is lower value than b.  Uses both the trump suit
//  and the suit led to determine order, as described in the spec.
bool Card_less(const Card &a, const Card &b, const Card &led_card,
               const std::string &trump){
        
        if(a.is_right_bower(trump) == true){
            if(b.is_right_bower(trump) == false){
                return false;
            }
        }
        
        if(a.is_right_bower(trump) == false){
            if(b.is_right_bower(trump) == true){
                return true;
            }
        }
        
        
   
        if(a.is_left_bower(trump) == false){
            if(b.is_left_bower(trump) == true){
                return true;
            }
        }
        
   
        if(a.is_left_bower(trump) == true){
            if(b.is_left_bower(trump) == false){
                return false;
            }
        }
        
   
        if(b.is_left_bower(trump) == true){
            if(a.is_left_bower(trump) == true){
                return false;
            }
        }
        
        
        
   
        if(b.is_right_bower(trump) == true){
            if(a.is_right_bower(trump) == false){
                return true;
            }
        }
       
        
        
        
        
        if(b.is_right_bower(trump) == false){
            if(a.is_right_bower(trump) == true){
                return false;
            }
        }
        
        
        
        
        if(b.is_right_bower(trump) == true){
            if(a.is_right_bower(trump) == true){
                return false;
            }
        }
        
        
        
        
        
        if(b.is_left_bower(trump) == false){
            if(a.is_left_bower(trump) == true){
                return false;
            }
        }
        
        
        
        if(b.is_left_bower(trump) == true){
            if(a.is_left_bower(trump) == false){
                return true;
            }
        }
        
        if(a.is_trump(trump) == true && b.is_trump(trump) == true){
                    if(a.get_rank() < b.get_rank()){
                        return true;
                    }
                    else return false;
                }
                if(a.is_trump(trump) == true && b.is_trump(trump) == false){
                    return false;
                }
                if(a.is_trump(trump) == false && b.is_trump(trump) == true){
                    return true;
                }
                if (a < b){
                    return true;
                }
                else return false;
        
    
    }
        






        // NOTE: We HIGHLY recommend you check out the operator overloading
        // tutorial in the project spec before implementing
        // the following operator overload functions:
        //   operator<<
        //   operator<
        //   operator<=
        //   operator>
        //   operator>=
        //   operator==
        //   operator!=
    

