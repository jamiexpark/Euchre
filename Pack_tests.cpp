// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Pack.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;

TEST(test_pack_default_ctor) {
    Pack pack;
    Card first = pack.deal_one();
    ASSERT_EQUAL(Card::RANK_NINE, first.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, first.get_suit());
}


TEST(test_shuffle){
    
    
    Pack pack;
    pack.shuffle();
    Card first = pack.deal_one();
    
    

    bool isSameCard = (Card::RANK_NINE != first.get_rank()) && (Card::SUIT_SPADES !=first.get_suit());
    ASSERT_FALSE(isSameCard);
    
    
    
    
}



TEST(test_deal_one){
    
    
    Pack pack;
    pack.shuffle();
    Card first = pack.deal_one();
    cout << pack.deal_one();

    
}
// Add more tests here

TEST_MAIN()
