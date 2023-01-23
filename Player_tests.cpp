// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}


TEST(asimple_player_compile){
    Player * player1 = Player_factory("player1", "Simple");
    ASSERT_EQUAL("player1", player1->get_name());
    delete player1;
}


TEST(does_simple_player_compile2){
    Player * player1 = Player_factory("player1", "Simple");
    Player * player2 = Player_factory("player2", "Simple");
    Player * player3 = Player_factory("player3", "Simple");
    Player * player4 = Player_factory("player4", "Simple");
    ASSERT_EQUAL("player1", player1->get_name());
    ASSERT_EQUAL("player2", player2->get_name());
    ASSERT_EQUAL("player3", player3->get_name());
    ASSERT_EQUAL("player4", player4->get_name());
    delete player1;
    delete player2;
    delete player3;
    delete player4;
}
// Add more tests here

//TEST(does_add_discard_card){
//    Player * p1 = Player_factory("p1", "Simple");
//    ASSERT_EQUAL("p1", p1->get_name());
//
//    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
//    Card c2(Card::RANK_TEN, Card::SUIT_CLUBS);
//    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
//    Card c4(Card::RANK_KING, Card::SUIT_DIAMONDS);
//    Card c5(Card::RANK_ACE, Card::SUIT_HEARTS);
//
//    p1->add_card(c1);
//    p1->add_card(c2);
//    p1->add_card(c3);
//    p1->add_card(c4);
//    p1->add_card(c5);
//
//    p1->add_and_discard(c6);
//    Card cplayed = p1->play_card(c7, Card::SUIT_HEARTS);
//
//    ASSERT_EQUAL(c5, cplayed);
//    delete p1;
//}


TEST(does_play_card){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c5(Card::RANK_ACE, Card::SUIT_HEARTS);

    

    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card cplayed = p1->play_card(c2, Card::SUIT_HEARTS);
    
    ASSERT_EQUAL(c2, cplayed);
    delete p1;
}


TEST(does_play_card2){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c5(Card::RANK_ACE, Card::SUIT_HEARTS);
   
    

    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card cplayed = p1->play_card(c2, Card::SUIT_HEARTS);
    
    ASSERT_EQUAL(c3, cplayed);
    delete p1;
}

/*TEST(does_play_card3){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card c5(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c6(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    

    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card cplayed = p1->play_card(c6, Card::SUIT_HEARTS);
    
    ASSERT_EQUAL(c4, cplayed);
    delete p1;
}*/

TEST(does_make_trump){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c5(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card upcard(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    
    ASSERT_EQUAL(false, p1->make_trump(upcard, false, 1, trump));
    delete p1;
}

TEST(does_make_trump2){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_KING, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c5(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card upcard(Card::RANK_ACE, Card::SUIT_SPADES);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    
    ASSERT_EQUAL(true, p1->make_trump(upcard, true, 1, trump));
    delete p1;
}

TEST(does_make_trump3){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c5(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card upcard(Card::RANK_ACE, Card::SUIT_SPADES);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    
    ASSERT_EQUAL(false, p1->make_trump(upcard, true, 1, trump));
    delete p1;
}


TEST(does_lead_card){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c5(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card upcard(Card::RANK_ACE, Card::SUIT_SPADES);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card lead = p1->lead_card(Card::SUIT_SPADES);

    ASSERT_EQUAL(lead, c5);
    delete p1;
}


TEST(does_lead_card2){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_KING, Card::SUIT_SPADES);
    Card c5(Card::RANK_JACK, Card::SUIT_SPADES);
    Card upcard(Card::RANK_ACE, Card::SUIT_SPADES);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card lead = p1->lead_card(Card::SUIT_SPADES);

    ASSERT_EQUAL(lead, c5);
    delete p1;
}

TEST(does_lead_card3){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card c5(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card upcard(Card::RANK_ACE, Card::SUIT_SPADES);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card lead = p1->lead_card(Card::SUIT_SPADES);

    ASSERT_EQUAL(lead, c4);
    delete p1;
}


TEST(does_lead_card4){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_SPADES);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_KING, Card::SUIT_SPADES);
    Card c5(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card upcard(Card::RANK_ACE, Card::SUIT_SPADES);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card lead = p1->lead_card(Card::SUIT_SPADES);

    ASSERT_EQUAL(lead, c5);
    delete p1;
}


TEST(does_name_output){
    Player * player1 = Player_factory("Lucy", "Simple");
    ASSERT_EQUAL("Lucy", player1->get_name());
    cout << *player1 << endl;
    delete player1;
}


TEST(if_all_card_upcard){
    
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c2(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c3(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c4(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c5(Card::RANK_ACE, Card::SUIT_SPADES);
    Card upcard(Card::RANK_ACE, Card::SUIT_SPADES);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card lead = p1->lead_card(Card::SUIT_SPADES);

    ASSERT_EQUAL(lead, c5);
    delete p1;
}

TEST(if_first_choice_best_choice){
    
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c2(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c3(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c4(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c5(Card::RANK_NINE, Card::SUIT_SPADES);

    Card upcard(Card::RANK_ACE, Card::SUIT_CLUBS);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card lead = p1->lead_card(Card::SUIT_SPADES);

    ASSERT_EQUAL(lead, c1);
    delete p1;
}

TEST(if_left_bower_vs_trump){
    
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c2(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card c3(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c4(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card c5(Card::RANK_ACE, Card::SUIT_SPADES);

    Card upcard(Card::RANK_ACE, Card::SUIT_CLUBS);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card lead = p1->lead_card(Card::SUIT_SPADES);

    ASSERT_EQUAL(lead, c2);
    delete p1;
}

TEST(if_bad_rank_upcard_queen){
    
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    Card c1(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c2(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card c3(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c4(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c5(Card::RANK_NINE, Card::SUIT_SPADES);

    Card upcard(Card::RANK_NINE, Card::SUIT_CLUBS);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card lead = p1->lead_card(Card::SUIT_SPADES);

    ASSERT_EQUAL(lead, c4);
    delete p1;
}

TEST(if_bad_rank_upcard_all_nine_all_dia){
    
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    Card c1(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card c2(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    Card c3(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card c4(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    Card c5(Card::RANK_KING, Card::SUIT_DIAMONDS);

    Card upcard(Card::RANK_JACK, Card::SUIT_CLUBS);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card lead = p1->lead_card(Card::SUIT_SPADES);

    ASSERT_EQUAL(lead, c5);
    delete p1;
}


TEST(all_random_test_yay){
    
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    Card c1(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card c2(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card c3(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card c4(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c5(Card::RANK_KING, Card::SUIT_DIAMONDS);

    Card upcard(Card::RANK_JACK, Card::SUIT_CLUBS);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card lead = p1->lead_card(Card::SUIT_CLUBS);

    ASSERT_EQUAL(lead, c5);
    delete p1;
}

TEST(_lead_card){
    
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    Card c1(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card c2(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card c3(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card c4(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card c5(Card::RANK_NINE, Card::SUIT_CLUBS);
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    Card lead = p1->lead_card(Card::SUIT_CLUBS);

    ASSERT_EQUAL(lead, c1);
    delete p1;
}

TEST(trump_test_all_same_card){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_KING, Card::SUIT_SPADES);
    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card c3(Card::RANK_KING, Card::SUIT_SPADES);
    Card c4(Card::RANK_KING, Card::SUIT_SPADES);
    Card c5(Card::RANK_KING, Card::SUIT_SPADES);

    Card upcard(Card::RANK_ACE, Card::SUIT_SPADES);
    string trump = Card::SUIT_CLUBS;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    ASSERT_EQUAL(true, p1->make_trump(upcard, true, 1, trump));
    delete p1;
}

TEST(trump_test_riund_2){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_KING, Card::SUIT_SPADES);
    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card c3(Card::RANK_KING, Card::SUIT_SPADES);
    Card c4(Card::RANK_KING, Card::SUIT_SPADES);
    Card c5(Card::RANK_KING, Card::SUIT_SPADES);

    Card upcard(Card::RANK_ACE, Card::SUIT_SPADES);
    string trump = Card::SUIT_CLUBS;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    ASSERT_EQUAL(false, p1->make_trump(upcard, true, 2, trump));
    delete p1;
}

TEST(trump_test_riund_2_all_upcard){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c2(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c3(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c4(Card::RANK_ACE, Card::SUIT_SPADES);
    Card c5(Card::RANK_ACE, Card::SUIT_SPADES);

    Card upcard(Card::RANK_ACE, Card::SUIT_SPADES);
    string trump = Card::SUIT_CLUBS;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    ASSERT_EQUAL(false, p1->make_trump(upcard, true, 2, trump));
    delete p1;
}



TEST(trump_test_riund_2_all_random){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card c2(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c3(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card c4(Card::RANK_KING, Card::SUIT_SPADES);
    Card c5(Card::RANK_JACK, Card::SUIT_DIAMONDS);

    Card upcard(Card::RANK_NINE, Card::SUIT_CLUBS);
    string trump = Card::SUIT_CLUBS;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    ASSERT_EQUAL(false, p1->make_trump(upcard, false, 1, trump));
    delete p1;
}

TEST(trump_test_round_2_not_dealer_all_upcard){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card c2(Card::RANK_NINE, Card::SUIT_HEARTS);
    Card c3(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card c4(Card::RANK_KING, Card::SUIT_HEARTS);
    Card c5(Card::RANK_NINE, Card::SUIT_HEARTS);

    Card upcard(Card::RANK_NINE, Card::SUIT_HEARTS);
    string trump = Card::SUIT_DIAMONDS;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    ASSERT_EQUAL(true, p1->make_trump(upcard, false, 2, trump));
    delete p1;
}

TEST(trump_test_round_2__true_dealer_upcard){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c2(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c3(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c4(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c5(Card::RANK_ACE, Card::SUIT_HEARTS);

    Card upcard(Card::RANK_ACE, Card::SUIT_HEARTS);
    string trump = Card::SUIT_DIAMONDS;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    ASSERT_EQUAL(false, p1->make_trump(upcard, true, 2, trump));
    delete p1;
}

TEST(does_add_discard_card2){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c4(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card c5(Card::RANK_KING, Card::SUIT_DIAMONDS);
    

    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    p1->add_and_discard(c3);
    Card cplayed = p1->play_card(c3, Card::SUIT_HEARTS);
    
    ASSERT_EQUAL(c3, cplayed);
    delete p1;
}

TEST(does_add_discard_card_all_same_card){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c3(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c4(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c5(Card::RANK_NINE, Card::SUIT_SPADES);
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    p1->add_and_discard(c1);
    Card cplayed = p1->play_card(c3, Card::SUIT_SPADES);
    
    ASSERT_EQUAL(c3, cplayed);
    delete p1;
}

//TEST(does_add_discard_one_card){
//    Player * p1 = Player_factory("p1", "Simple");
//    ASSERT_EQUAL("p1", p1->get_name());
//
//    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
//
//    p1->add_card(c1);
//
//    p1->add_and_discard(c1);
//    Card cplayed = p1->play_card(c1, Card::SUIT_SPADES);
//
//    ASSERT_EQUAL(c1, cplayed);
//    delete p1;
//}

TEST(does_add_discard_one_bowers){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_SPADES);
    Card c3(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c4(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c5(Card::RANK_KING, Card::SUIT_SPADES);


  
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);


    p1->add_and_discard(c1);
    Card cplayed = p1->play_card(c2, Card::SUIT_CLUBS);

    ASSERT_EQUAL(c5, cplayed);
    delete p1;
}

TEST(does_add_discard_again){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_SPADES);
    Card c3(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c4(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card c5(Card::RANK_QUEEN, Card::SUIT_SPADES);
  
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    p1->add_and_discard(c2);
    Card cplayed = p1->play_card(c3, Card::SUIT_CLUBS);

    ASSERT_EQUAL(c5, cplayed);
    delete p1;
}

TEST(does_add_discard_again_all_jacks){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_JACK, Card::SUIT_SPADES);
    Card c2(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card c3(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card c4(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card c5(Card::RANK_JACK, Card::SUIT_HEARTS);
  
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    p1->add_and_discard(c2);
    Card cplayed = p1->play_card(c5, Card::SUIT_CLUBS);

    ASSERT_EQUAL(c5, cplayed);
    delete p1;
}

TEST(more_make_trump){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_NINE, Card::SUIT_HEARTS);
    Card c3(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card c4(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card c5(Card::RANK_NINE, Card::SUIT_SPADES);
   
    Card upcard(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    
    ASSERT_EQUAL(false, p1->make_trump(upcard, true, 2, trump));
    delete p1;
}

TEST(make_trump_again){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_NINE, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card c3(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card c4(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c5(Card::RANK_KING, Card::SUIT_SPADES);
   
    Card upcard(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    
    ASSERT_EQUAL(false, p1->make_trump(upcard, false, 1, trump));
    delete p1;
}

TEST(make_trump_again2){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_TEN, Card::SUIT_SPADES);
    Card c2(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card c3(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card c4(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c5(Card::RANK_KING, Card::SUIT_SPADES);
   
    Card upcard(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    
    ASSERT_EQUAL(false, p1->make_trump(upcard, false, 1, trump));
    delete p1;
}

TEST(make_trump_again3){
    Player * p1 = Player_factory("p1", "Simple");
    ASSERT_EQUAL("p1", p1->get_name());
    
    Card c1(Card::RANK_KING, Card::SUIT_SPADES);
    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card c3(Card::RANK_KING, Card::SUIT_SPADES);
    Card c4(Card::RANK_KING, Card::SUIT_SPADES);
    Card c5(Card::RANK_KING, Card::SUIT_SPADES);
   
    Card upcard(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    string trump;
    
    p1->add_card(c1);
    p1->add_card(c2);
    p1->add_card(c3);
    p1->add_card(c4);
    p1->add_card(c5);

    
    ASSERT_EQUAL(false, p1->make_trump(upcard, false, 1, trump));
    delete p1;
}
TEST_MAIN()



