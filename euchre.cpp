//Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "Pack.h"
#include "Player.h"
#include <array>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Game {
 public:
  Game(vector<Player*> playergroup, Pack packname, int points, bool noshuffle){
    for (int i = 0; i < playergroup.size();i++){
        players.push_back(playergroup[i]);
    }
    pack = packname;
    winPoints = points;
    shuffle = noshuffle;
    }
  void play(){
      
//    cout << winPoints << "Points\n";
    dealernum = 0;
    pointsTeamOne = 0;
    pointsTeamTwo = 0;
    numofhands = 0;
    while(pointsTeamOne < winPoints
          && pointsTeamTwo < winPoints){
        cout << "Hand "<< numofhands << endl;
        deal(dealernum, shuffle);
        currentCard = pack.deal_one();
      
        make_trump(currentCard);
        winninghand = dealernum + 1;
        if( winninghand == 4){
            winninghand = 0;
        }
        tricksTeamOne = 0;
        tricksTeamTwo = 0;
        play_hand();
        ++dealernum;
        if( dealernum == 4){
            dealernum = 0;
        }
        pack.reset();
        ++numofhands;
    }
    //cout << players[0]->get_name() << " and "
    //     << players[2]->get_name() << " have "
    //     << pointsTeamOne << " points" << endl;
    //cout << players[1]->get_name() << " and "
    //     << players[3]->get_name() << " have "
    //     << pointsTeamTwo << " points" << endl;
    if ((pointsTeamOne) < (pointsTeamTwo)){
        cout << players[1]->get_name() << " and "
        << players[3]->get_name() << " win!" << endl;
    }
    else if((pointsTeamOne) > (pointsTeamTwo)){
        cout << players[0]->get_name() << " and "
        << players[2]->get_name() << " win!" << endl;
    }

   


  }
  //actually plays the game out.
 private:
  std::vector<Player*> players;
  std::vector<Card> trickWinner;
  std::vector<int> playedplayer;
  Pack pack;
  int winPoints;
  string trump;
  Card currentCard;
  Card ledcard;
  Card biggestcard = {Card::RANK_FOUR, Card::SUIT_CLUBS};
  int dealernum;
  int winninghand;
  //int player0points;
  //int player1points;
  //int player2points;
  //int player3points;
  int pointsTeamOne;
  int pointsTeamTwo;
  bool shuffle;
    int tricksTeamOne;
    int tricksTeamTwo;
    int teamOrderedUp;
    int numofhands;
    //int trickHand;
    //int winPoints;
  
  // ...
  void deal(int dealernum, bool shuffle){
    Card dealCard;
    if( shuffle == true){
        pack.shuffle();
    }
    else{
        pack.reset();
    }
    if(dealernum == 0){
    for(int i = 0; i < 2; i++){
        for(int j = 1; j < players.size()+1; j++){
            if (j%players.size() == 1 && i == 0){
             for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[1]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 1){
                for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[1]->add_card(dealCard);
            }
            }
            if (j%players.size() == 2 && i == 0){
             for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[2]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 2){
                for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[2]->add_card(dealCard);
            }
            }
            if (j%players.size() == 3 && i == 0){
             for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[3]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 3){
                for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[3]->add_card(dealCard);
            }
            }
            if (j%players.size() == 0 && i == 0){
             for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[0]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 0){
                for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[0]->add_card(dealCard);
            }
            }
        }
    }
    }
        if(dealernum == 1){
    for(int i = 0; i < 2; i++){
        for(int j = 2; j < players.size() + 2; j++){
            if (j%players.size() == 2 && i == 0){
             for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 2){
                for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            if (j%players.size() == 3 && i == 0){
             for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 3){
                for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            if (j%players.size() == 0 && i == 0){
             for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[0]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 0){
                for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[0]->add_card(dealCard);
            }
            }
            if (j%players.size() == 1 && i == 0){
             for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 1){
                for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
        }
    }
    }
        if(dealernum == 2){
    for(int i = 0; i < 2; i++){
        for(int j = 3; j < players.size() + 3; j++){
            if (j%players.size() == 3 && i == 0){
             for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 3){
                for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            if (j%players.size() == 0 && i == 0){
             for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 0){
                for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            if (j%players.size() == 1 && i == 0){
             for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 1){
                for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            if (j%players.size() == 2 && i == 0){
             for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 2){
                for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
        }
    }
    }
        if(dealernum == 3){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < players.size(); j++){
            if (j%players.size() == 0 && i == 0){
             for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 0){
                for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            if (j%players.size() == 1 && i == 0){
             for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 1){
                for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            if (j%players.size() == 2 && i == 0){
             for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 2){
                for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            if (j%players.size() == 3 && i == 0){
             for (int k = 0; k < 2; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
            else if(j%players.size() == 3){
                for (int k = 0; k < 3; k++){
                dealCard = pack.deal_one();
                players[j%players.size()]->add_card(dealCard);
            }
            }
        }
    }
    }
  }
    

  void make_trump(Card upcard){

   
    bool trumpYet = false;
    cout << players[dealernum]->get_name() << " deals" << endl;
            cout << upcard.get_rank() << " of " <<
            upcard.get_suit() << " turned up" << endl;
    for( int j = 0; j<2; j++){
        for( int i = dealernum+1; i < dealernum +1+
                            players.size(); i++){
            if(trumpYet == false){
                if( i%players.size() == dealernum){
                    trumpYet = players[i%players.size()]
                                ->make_trump(upcard, true, j+1, trump);
            
                    
                    if(trumpYet == false){
                        cout << players[i%players.size()]
                                        ->get_name() << " passes" << endl;
                    }
                    if(trumpYet == true){
                        cout << players[i % players.size()]
                                        ->get_name() << " orders up "
                             << trump << "\n" << endl;
                         teamOrderedUp = i%2;
                    }
                }
                else{
                    trumpYet = players[i % players.size()]
                                        ->make_trump(upcard, false, j+1, trump);
                
                    
                    if(trumpYet == false){
                        cout << players[i % players.size()]
                                        ->get_name() << " passes" << endl;
                    }
                    if(trumpYet == true){
                        cout << players[i % players.size()]
                                        ->get_name() << " orders up "
                             << trump << "\n" << endl;
                        teamOrderedUp = i%2;
                        if(j == 0){
                            players[dealernum]->add_and_discard(upcard);
                        }
                    }
                }
            }

        }
    }
  }
  void play_hand(/* ... */){
    // Card tricks[TRICK_SIZE];  //which player is dealer
     winninghand = dealernum + 1;
        if( winninghand == 4){
            winninghand = 0;
        }
    //start theround !
  
    ledcard = players[winninghand]->lead_card(trump);
    cout << ledcard.get_rank() << " of " << ledcard.get_suit()
         << " led by " <<
                players[winninghand]->get_name() << endl;
         playedplayer.push_back(winninghand);
         biggestcard = ledcard;
    trickWinner.push_back(ledcard);
    for(int i = 1; i < 4; i++){
        winninghand++;
        if( winninghand == 4){
            winninghand = 0;
        }
        trickWinner.push_back(players[winninghand]
                        ->play_card(ledcard,trump));
        playedplayer.push_back(winninghand);
        // = players[(leaderCount + i) % 4]->play_card(led_card, trump);
        cout << trickWinner[i].get_rank() << " of "
                << trickWinner[i].get_suit() <<
                " played by " << players[playedplayer[i]
                                    ]->get_name() << endl;
        
        if(biggestcard < trickWinner[i] &&
             ledcard.get_suit() == trickWinner[i].get_suit()
             && biggestcard.is_right_bower(trump) == false){
//            cout << "winner 1" << endl;
        biggestcard = trickWinner[i];
        }
        else if(trickWinner[i].is_left_bower(trump) == true &&
                biggestcard.is_right_bower(trump) == false){
//            cout << "winner 2" << endl;
            biggestcard = trickWinner[i];
    }
    else if(trickWinner[i].get_suit() == trump &&
             biggestcard.get_rank() < trickWinner[i].get_rank() &&
            biggestcard.is_right_bower(trump) == false){
                biggestcard = trickWinner[i];
        }
        
//        if(trickWinner[i].is_trump(trump)){
//            if(!biggestcard.is_trump(trump)){
//                biggestcard = trickWinner[i];
//            }else if(biggestcard.is_trump(trump)){
//                if(trickWinner[i].get_rank() == Card::RANK_JACK){
//                    if(biggestcard.get_rank() != trump){
//                        biggestcard = trickWinner[i];
//
//                    }
//
//                }
//            }
//        }
        
        if(trickWinner[i].is_right_bower(trump) == true){
            biggestcard = trickWinner[i];
        }
        else if(biggestcard < trickWinner[i] &&
             biggestcard.get_suit() != trickWinner[i].get_suit()
             && biggestcard.get_rank() < trickWinner[i].get_rank()
             && trickWinner[i].is_trump(trump) == true){
//            cout << "winner 1" << endl;
        biggestcard = trickWinner[i];
        }
        
//        cout << "check winner 3" << trickWinner[i].is_trump(trump) << !biggestcard.is_trump(trump) << endl;
//        if(trickWinner[i].is_trump(trump) && !biggestcard.is_trump(trump)){
////            cout << "winner 3" << endl;
//            biggestcard = trickWinner[i];
//        }
//
//        if(trickWinner[i].is_trump(trump) && biggestcard.is_trump(trump) && ((trickWinner[i] > biggestcard) || (trickWinner[i].is_left_bower(trump)))){
////            cout << "winner 4" << endl;
//            biggestcard = trickWinner[i];
//        }
        
    }
  int counter = 0;
    for(int j = 0; j < 4; j++){
        
        if (biggestcard.get_rank() == trickWinner[j].get_rank() &&
            biggestcard.get_suit() == trickWinner[j].get_suit()){
            cout << players[playedplayer[j]]->get_name()
                                 << " takes the trick\n" << endl;
            if( j == 1 || j == 3){
                tricksTeamTwo++;
                winninghand = playedplayer[j];
                trickWinner.clear();
                playedplayer.clear();
                //cout << "Team Two " << tricksTeamTwo << "points\n";
            }
            if( j == 0 || j == 2){
                tricksTeamOne++;
                winninghand = playedplayer[j];
                trickWinner.clear();
                playedplayer.clear();
                //cout << "Team One " << tricksTeamTwo << "points\n";
            }
        }
        ++counter;
    }
    for(int z = 0; z < 4;++z){
        ledcard = players[winninghand]->lead_card(trump);
    cout << ledcard.get_rank() << " of " << ledcard.get_suit()
         << " led by " << players[winninghand]->get_name() << endl;
         playedplayer.push_back(winninghand);
         biggestcard = ledcard;
    trickWinner.push_back(ledcard);
    for(int j = 1; j < 4; j++){
        winninghand++;
        if( winninghand == 4){
            winninghand = 0;
        }
        trickWinner.push_back(players[winninghand]
                            ->play_card(ledcard,trump));
        playedplayer.push_back(winninghand);
        // = players[(leaderCount + i) % 4]->play_card(led_card, trump);
        cout << trickWinner[j].get_rank() << " of " <<
                            trickWinner[j].get_suit() <<
                " played by " << players[playedplayer[j]]
                                    ->get_name() << endl;
        
        if(biggestcard < trickWinner[j] &&
             ledcard.get_suit() == trickWinner[j].get_suit()
             && biggestcard.is_right_bower(trump) == false){
//            cout << "winner 1" << endl;
        biggestcard = trickWinner[j];
        }
        else if(trickWinner[j].is_left_bower(trump) == true &&
                biggestcard.is_right_bower(trump) == false){
//            cout << "winner 2" << endl;
            biggestcard = trickWinner[j];
    }
    else if(trickWinner[j].get_suit() == trump &&
             biggestcard < trickWinner[j] &&
            biggestcard.is_right_bower(trump) == false){
                biggestcard = trickWinner[j];
        }
    else if(biggestcard.get_suit() != trickWinner[j].get_suit()
             && biggestcard.get_rank() < trickWinner[j].get_rank()
             && trickWinner[j].is_trump(trump) == true){
//            cout << "winner 1" << endl;
        biggestcard = trickWinner[j];
        }
        
//        cout << "check winner 3" << trickWinner[j].is_trump(trump) << !biggestcard.is_trump(trump) << endl;
//        if(trickWinner[j].is_trump(trump) && !biggestcard.is_trump(trump)){
////            cout << "winner 3" << endl;
//            biggestcard = trickWinner[j];
//        }
//
//        if(trickWinner[j].is_trump(trump) && biggestcard.is_trump(trump) && (trickWinner[j] > biggestcard)){
////            cout << "winner 4" << endl;
//            biggestcard = trickWinner[j];
//        }
        }
    for(int k = 0; k < 4; ++k){
        if (biggestcard == trickWinner[k]){
            cout << players[playedplayer[k]]->get_name()
                         << " takes the trick\n" << endl;;
            if( k == 1 || k == 3){
                tricksTeamTwo++;
                winninghand = playedplayer[k];
                trickWinner.clear();
                playedplayer.clear();
                //cout << "Team Two " << tricksTeamTwo << "points\n";
            }
            else if( k == 0 || k == 2){
                tricksTeamOne++;
                winninghand = playedplayer[k];
                trickWinner.clear();
                playedplayer.clear();
                //cout << "Team One " << tricksTeamTwo << "points\n";
            }
        }
    }
    }

    if(tricksTeamOne > tricksTeamTwo){
        if(teamOrderedUp == 1){
            cout << players[0]->get_name() << " and "
                << players[2]->get_name() << " win the hand" << endl;
            cout << "euchred!" << endl;
            pointsTeamOne += 2;
            cout << players[0]->get_name() << " and "
                 << players[2]->get_name() << " have "
                 << pointsTeamOne << " points"<< endl;
            cout << players[1]->get_name() << " and "
                 << players[3]->get_name() << " have "
                 << pointsTeamTwo << " points\n"<< endl;
            
            }
        else if(tricksTeamOne == 5){ //if they have a full hand / march (round is done)
            cout << players[0]->get_name() << " and "
                 << players[2]->get_name() << " win the hand" << endl;
            cout << "march!" << endl;
            cout << players[0]->get_name() << " and "
                 << players[2]->get_name() << " have "
                     << pointsTeamOne << endl;
            cout << players[1]->get_name() << " and "
                 << players[3]->get_name() << " have "
                 << pointsTeamTwo << endl;
        }
        
        else if(tricksTeamOne == 3 || tricksTeamOne == 4){ //if they dont have a full hand (round not done yet)
            cout << players[0]->get_name() << " and "
                 << players[2]->get_name() << " win the hand" << endl;
            pointsTeamOne += 1;
            cout << players[0]->get_name() << " and "
                 << players[2]->get_name() << " have "
                 << pointsTeamOne << " points"<< endl;
            cout << players[1]->get_name() << " and "
                 << players[3]->get_name() << " have "
                 << pointsTeamTwo << " points\n"<< endl;
        }
        }
    if(tricksTeamTwo > tricksTeamOne){
         if(teamOrderedUp == 0){ //need to distenguish this
            cout << players[1]->get_name() << " and "
                 << players[3]->get_name() << " win the hand" << endl;
            cout << "euchred!" << endl;
            pointsTeamTwo += 2;
            cout << players[0]->get_name() << " and "
                 << players[2]->get_name() << " have "
                     << pointsTeamOne << " points"<< endl;
            cout << players[1]->get_name() << " and "
                 << players[3]->get_name() << " have "
                     << pointsTeamTwo << " points\n"<< endl;
            
            }
        else if(tricksTeamTwo == 5){ //if they have a full hand / march (round is done)
            cout << players[1]->get_name() << " and "
                 << players[3]->get_name() << " win the hand" << endl;
            cout << "march!" << endl;
            cout << players[0]->get_name() << " and "
                 << players[2]->get_name() << " have "
                     << pointsTeamOne << endl;
            cout << players[1]->get_name() << " and "
                 << players[3]->get_name() << " have "
                     << pointsTeamTwo << endl;
        }
        
        else if(tricksTeamTwo == 3 || tricksTeamTwo == 4){ //if they dont have a full hand (round not done yet)
            cout << players[1]->get_name() << " and "
                 << players[3]->get_name() << " win the hand"
                 << pointsTeamOne << endl;
            pointsTeamTwo += 1;
            cout << players[0]->get_name() << " and "
                 << players[2]->get_name() << " have "
                     << pointsTeamOne << " points"<< endl;
            cout << players[1]->get_name() << " and "
                 << players[3]->get_name() << " have "
                     << pointsTeamTwo << " points\n"<< endl;
        }
    }
  }
};

    
    
    //if they have max points and win the game
       // if(pointsTeamOne >= winPoints){
       //     cout << players[0]->get_name() << " and " << players[2]->get_name() << " win!" << endl;
       //     return;
       // }
    
       // if(pointsTeamTwo >= winPoints){
       //     cout << players[1]->get_name() << " and " << players[3]->get_name() << " win!" << endl;
       //     return;
       // }
    
    
    
    
    //need to continue the game
        //if(pointsTeamOne < winPoints && pointsTeamTwo < winPoints){
        //    pack.reset();
        //    pack.shuffle();
        //    deal();
        //    play();
        //}


int main(int argc, char *argv[] ){
    if (argc == 12){
        string exename = argv[0];
        string filename = argv[1];
        ifstream fin;
        fin.open(filename.c_str());

        if(!(fin.is_open())){
            cout << "Error opening " << filename << endl;
            return 1;
        }

        Pack pack(fin);
        bool shufflecards;
        string shuffle = argv[2];
        if(shuffle == "shuffle"){
            shufflecards = true;
        }
        else if (shuffle != "shuffle" && shuffle != "noshuffle"){
            cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
                 << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
                 << "NAME4 TYPE4" << endl;
            return 1;
        }
        else{
            shufflecards = false;
        }
        //char * points = argv[3];
        int pointsWin = atoi(argv[3]);
        //cout << pointsWin;
        if(pointsWin < 1 || pointsWin > 100){
            cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
                 << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
                 << "NAME4 TYPE4" << endl;
            return 1;
        }

        std::vector<Player*> playergroup;
        string playerName = argv[4];
        string playerType = argv[5];
        
        Player * player0 = Player_factory(playerName, playerType);
        playerName = argv[6]; //playerName1
        playerType = argv[7]; //playerType1
        Player * player1 = Player_factory(playerName, playerType);
        playerName = argv[8]; //playerName2
        playerType = argv[9]; //playerType2
        Player * player2 = Player_factory(playerName, playerType);
        playerName = argv[10];
        playerType = argv[11];
        Player * player3 = Player_factory(playerName, playerType);

        playergroup.push_back(player0);
        playergroup.push_back(player1);
        playergroup.push_back(player2);
        playergroup.push_back(player3);
//

        cout << exename << " " << filename << " "
             << shuffle << " " << pointsWin << " "
             << player0->get_name() << " " << playerType
             << " " << player1->get_name() << " "
             << playerType  << " " << player2->get_name()
             << " " << playerType << " " << player3->get_name()
              << " " <<  playerType << " " << endl;

        Game game1(playergroup, pack,
                   pointsWin, shufflecards);
        game1.play();
        
    }
    else {
        cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
             << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
             << "NAME4 TYPE4" << endl;
    }
}


        
        
        
        


