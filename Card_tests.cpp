// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;


TEST(test_card_ctor) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
  
}


// Add more test cases here

TEST(does_get_rank_work){
    
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
}

TEST(does_get_suit_work){
    
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
}


TEST(does_get_suit){
    
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
}


TEST(does_isFaceorAce){
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(true, c.is_face_or_ace());
}


TEST(does_isFaceorAce2){
    Card c(Card::RANK_NINE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(false, c.is_face_or_ace());
}


TEST(does_isFaceorAce3){
    Card c(Card::RANK_TEN, Card::SUIT_HEARTS);
    ASSERT_EQUAL(false, c.is_face_or_ace());
}


TEST(does_isFaceorAce4){
    Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_EQUAL(true, c.is_face_or_ace());
}
//
//
TEST(does_is_right_bower){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_EQUAL(true , c.is_right_bower(trump.get_suit()));
}


TEST(does_is_right_bower2){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card c(Card::RANK_EIGHT, Card::SUIT_HEARTS);
    ASSERT_EQUAL(false , c.is_right_bower(trump.get_suit()));
}


TEST(does_is_right_bower3){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card c(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(false , c.is_right_bower(trump.get_suit()));
}
TEST(does_is_left_bower){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card c(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(true , c.is_left_bower(trump.get_suit()));
}


TEST(does_is_left_bower2){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_EQUAL(false , c.is_left_bower(trump.get_suit()));
}


TEST(does_is_left_bower3){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_EQUAL(false , c.is_left_bower(trump.get_suit()));
}

TEST(does_is_left_bower4){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card c(Card::RANK_NINE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(false , c.is_left_bower(trump.get_suit()));
}


TEST(does_is_trump){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card c(Card::RANK_NINE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(true , c.is_trump(trump.get_suit()));
}


TEST(does_is_trump2){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card c(Card::RANK_NINE, Card::SUIT_CLUBS);
    ASSERT_EQUAL(false , c.is_trump(trump.get_suit()));
}


TEST(does_is_trump3){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card c(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(false , c.is_trump(trump.get_suit()));
}


TEST(does_is_trump4){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card c(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(true , c.is_trump(trump.get_suit()));
}


TEST(does_is_card_less){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(false,
                 Card_less(c,b, trump.get_suit()));
}


TEST(does_is_card_less2){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(true,
                 Card_less(c,b, trump.get_suit()));
}


TEST(does_is_card_less3){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(true,
                 Card_less(c,b, trump, trump.get_suit()));
}


TEST(does_is_card_less4){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_EQUAL(true,
                 Card_less(c,b, trump, trump.get_suit()));
}


TEST(does_less_than){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_EQUAL(b < c, true);
}

TEST(does_less_than2){
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(b < c, false);
}

TEST(does_less_than_or_equal_to){
    Card trump(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_EQUAL(b <= c, true);
}


TEST(does_less_than_or_equal_to2){
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(b <= c, true);
}

TEST(does_greater_than){
    Card b(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card c(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(b > c, false);
}

TEST(does_greater_than2){
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(b > c, false);
}

TEST(does_greater_than_or_equal_to){
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(b >= c, true);
}

TEST(does_greater_than_or_equal_to2){
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_EQUAL(b >= c, false);
}

TEST(does_equal_to){
    Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_EQUAL(b == c, false);
}

TEST(does_equal_to2){
     Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(b == c, true);
}

TEST(does_not_equal_to){
     Card b(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(b != c, false);
}

TEST(does_not_equal_to2){
     Card b(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(b != c, true);
}
/*
TEST(does_card_next){
     Card b(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Suit_next(Card::SUIT_CLUBS), Card::SUIT_SPADES);
    ASSERT_EQUAL(Suit_next(Card::SUIT_SPADES), Card::SUIT_CLUBS);
}

TEST(does_card_next2){
     Card b(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Suit_next(Card::SUIT_DIAMONDS), Card::SUIT_HEARTS);
    ASSERT_EQUAL(Suit_next(Card::SUIT_HEARTS), Card::SUIT_DIAMONDS);
}
*/
TEST_MAIN()




