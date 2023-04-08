#include "game.h"
#include "board.h"
using namespace std;
class OSAP;
class CoopFee;
class DCTimsLine;
class GoToTims;
class NeedleHall;
class SLC;
class Tuition;
class GoToTims;
class AcademicBuilding;
class Gym;
class Residence;
class GooseNesting;

// ctor of Game
Game::Game(): activeRim{0} {
  vector<string> names = {"COLLECT OSAP", "AL", "SLC", "ML", "TUITION", "MKV", "ECH", "NEEDLES HALL", "PAS", "HH", "DC Tims Line", "RCH", "PAC", "DWE", "CPH", "UWP", "LHI", "SLC", "BMH", "OPT", "Goose Nesting", "EV1", "NEEDLES HALL", "EV2", "EV3", "V1", "PHYS", "B1", "CIF", "B2", "GO TO TIMS", "EIT", "ESC", "SLC", "C2", "REV", "NEEDLES HALL", "MC", "COOP FEE", "DC"};

  dice = make_unique<Dice>();
  currentPlayer = nullptr;
  // auto osap = make_shared<OSAP>(0, "COLLECT OSAP");
  // board.emplace_back(osap);
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<OSAP>(0, "COLLECT OSAP"))); //unique or shared?
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(1, "AL", 40, 0, vector<unsigned int>{2, 10, 30, 90, 160, 250}, 50, "Arts1")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<SLC>(2, "SLC")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(3, "ML", 60, 0, vector<unsigned int>{4, 20, 60, 180, 320, 450}, 50, "Arts1")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Tuition>(4, "TUITION")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Residence>(5, "MKV", 200, 25)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(6, "ECH", 100, 0, vector<unsigned int>{6, 30, 90, 270, 400, 550}, 50, "Arts2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<NeedleHall>(7, "NEEDLES HALL")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(8, "PAS", 100, 0, vector<unsigned int>{6, 30, 90, 270, 400, 550}, 50, "Arts2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(9, "HH", 120, 0, vector<unsigned int>{8, 40, 100, 300, 450, 600}, 50, "Arts2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<DCTimsLine>(10, "DC Tims Line")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(11, "RCH", 140, 0, vector<unsigned int>{10, 50, 150, 450, 625, 750}, 100, "Eng")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Gym>(12, "PAC", 150, 0)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(13, "DWE", 140, 0, vector<unsigned int>{10, 50, 150, 450, 625, 750}, 100, "Eng")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(14, "CPH", 160, 0, vector<unsigned int>{12, 60, 180, 500, 700, 900}, 100, "Eng")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Residence>(15, "UWP", 200, 25)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(16, "LHI", 180, 0, vector<unsigned int>{14, 70, 200, 550, 750, 950}, 100, "Health")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<SLC>(17, "SLC")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(18, "BMH", 180, 0, vector<unsigned int>{14, 70, 200, 550, 750, 950}, 100, "Health")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(19, "OPT", 200, 0, vector<unsigned int>{16, 80, 220, 600, 800, 1000}, 100, "Health")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<GooseNesting>(20, "GOOSE NESTING")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(21, "EV1", 220, 0, vector<unsigned int>{18, 90, 250, 700, 875, 1050}, 150, "Env")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<NeedleHall>(22, "NEEDLES HALL")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(23, "EV2", 220, 0, vector<unsigned int>{18, 90, 250, 700, 875, 1050}, 150, "Env")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(24, "EV3", 240, 0, vector<unsigned int>{20, 100, 300, 750, 925, 1100}, 150, "Env")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Residence>(25, "V1", 200, 25)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(26, "PHYS", 260, 0, vector<unsigned int>{22, 110, 330, 800, 975, 1150}, 150, "Sci1")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(27, "B1", 260, 0, vector<unsigned int>{22, 110, 330, 800, 975, 1150}, 150, "Sci1")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Gym>(28, "PAC", 150, 0)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(29, "B2", 280, 0, vector<unsigned int>{24, 120, 360, 850, 1025, 1200}, 150, "Sci1")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<GoToTims>(30, "GO TO TIMS")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(31, "EIT", 300, 0, vector<unsigned int>{26, 130, 390, 900, 1100, 1275}, 200, "Sci2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(32, "ESC", 300, 0, vector<unsigned int>{26, 130, 390, 900, 1100, 1275}, 200, "Sci2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<SLC>(33, "SLC")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(34, "C2", 320, 0, vector<unsigned int>{28, 150, 450, 1000, 1200, 1400}, 200, "Sci2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Residence>(35, "REV", 200, 25)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<NeedleHall>(36, "NEEDLES HALL")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(37, "MC", 350, 0, vector<unsigned int>{35, 175, 500, 1100, 1300, 1500}, 200, "Math")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<CoopFee>(38, "Coop Fee")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(39, "DC", 400, 0, vector<unsigned int>{50, 200, 600, 1400, 1700, 2000}, 200, "Math")));
}

// dctor of Game
Game::~Game() {}

// roll dice in Game
int Game::roll() {
  return dice->rollDice();
}

// initialize currentPlayer
void Game::gameStart() {
  currentPlayer = player[0];
}

Player& Game::getCurrentPlayer() {
  return *currentPlayer;
}

// check if there is only one player left
bool Game::endGame() {
  return player.size() == 1;
}

// print all Players' name and char
void Game::printPlayers() {
  for (auto p : player) {
    cout << "Name: " << p->getName() << endl << "Char:" << p->getNameChar() << endl;
  }
}

// get the winner
string Game::getWinner() {
  return (player[0])->getName();
}

// move the player num steps and do corresponding actions
void Game::move(int num, shared_ptr<Player> p) {
  if (p == nullptr) p = currentPlayer;
  int curPos = p->getPosition();
  int newPos = curPos + num;
  // Check if get OSAP
  if (newPos >= 40) {
    p->addCash(200);
    cout << "You passed OSAP and got $200" << endl;
    newPos -= 40;
  }
  p->setPosition(newPos);
  
  
  bool buy = false;
  shared_ptr<Board> now = board[newPos];
  string nowType = now->getType();

  if (nowType == "AcademicBuilding" || nowType == "Gym" || nowType == "Residence") {
    if (now->getOwner() == nullptr) { // No owner Property
      printMap();
      cout << "You can buy " << now->getName() << " for " << now->getPrice() << endl;
      cout << "Choose: 'buy' or 'auction'" << endl;
      string choice;
      
      while (cin >> choice) {
        if (choice == "buy") {
          if (p->getCashAmount() >= now->getPrice()) {
            string name = now->getName();
            purchase(name, *p);
            buy = true;
            cout << "You bought " << name << endl;
          } else {
            cout << "You don't have enough money" << endl;
            buy = false;
          } break;
        } else if (choice == "auction" || buy == false) {
          string name = now->getName();
          auction(name);
          buy = true;
          break;
        } else {
          cout << "Invalid input, choose again." << endl;
        }
      }

    } else { // Has owner Property
      printMap();
      if (now->isMortgaged()) return;
      if (now->getOwner() == p) {
        cout << "Land on your own Property" << endl;
        return;
      }
      int visitPrice = now->getVisitPrice(*p);
      p->addCash(-visitPrice);
      cout << "You paid " << visitPrice << " to " << (now->getOwner())->getName() << endl;
      if (p->getCashAmount() >= 0) return;
      else { // in debt
        cout << "You are in debt" << endl;
        cout << "Choose: 'mortgage' or 'trade' or 'degrade'" << endl;
        string choice;
        cin >> choice;
        ////////////////////////////////////////////////////////////////////////////
        // input property name and check
        // if (choice == "mortgage") {
        //   mortgage(now);
        // } else if (choice == "trade") {
        //   trade(now);
        // } else if (choice == "degrade") {
        //   degrade(now);
        // } else {
        //   cout << "Invalid input" << endl;
        // }
        ////////////////////////////////////////////////////////////////////////////////
      } 
    }
  } else { // NonProperty //////////////////////////////////////////////////
    string nowName = now->getName();
    if (nowName == "SLC") {
      SLC tmp{0, "slc"};
      int n = getActiverRim();
      int m = tmp.slcaction(*p, n);
      setActiverRim(m);
      printMap();
      move(tmp.getNextMove(), p);
    } else if (nowName == "TUITION") {
      Tuition tmp{0, "tuition"};
      tmp.action(*p);
      printMap();
    } else if (nowName == "GO TO TIMS") {
      GoToTims tmp{0, "go to tims"};
      tmp.action(*p);
      int n = getActiverRim();
      DCTimsLine tmp1{0, "dc times line"};
      int m = tmp1.dclineaction(*p, n);
      printMap();
      setActiverRim(m);
    } else if (nowName == "COOP FEE") {
      CoopFee tmp{0, "coop fee"};
      tmp.action(*p);
      printMap();
    } else if (nowName == "DC Tims Line") {
      cout << "Lands on DC Tims Line, nothing happens." << endl;
      printMap();
    } else if (nowName == "NEEDLES HALL") {
      NeedleHall tmp{0, "needles hall"};
      int n = getActiverRim();
      int m = tmp.nhaction(*p, n);
      setActiverRim(m);
      printMap();
    } else if (nowName == "Goose Nesting") {
      GooseNesting tmp{0, "goose nesting"};
      tmp.action(*p);
      printMap();
    } 
  }
  //////////////////////////////////////////////////////////////////////////
}


void Game::nextPlayer() {
  for (size_t i = 0; i < player.size(); ++i) {
    if (player[i] == currentPlayer) {
      if (i == player.size() - 1) currentPlayer = player[0];
      else currentPlayer = player[i + 1];
      break;
    }
  }
}

bool Game::initPlayer(string name) {
  bool flag = false;
  for (auto p: player) {
    if (p->getName() == name) {
      return false;
    }
  }
  if (name == "Goose") flag = true;
  if (name == "GRT Bus") flag = true;
  if (name == "Tim Hortons Doughnut") flag = true;
  if (name == "Professor") flag = true;
  if (name == "Student") flag = true;
  if (name == "Money") flag = true;
  if (name == "Laptop") flag = true;
  if (name == "Pink tie") flag = true;
  if (!flag) {
    return false;
  }
  shared_ptr<Player> p = make_shared<Player>(name);
  player.emplace_back(p);
  return true;
  //td->drawBoard(cout, player, board);
}

shared_ptr<Player> Game::getOwner(const Board& b) {
  return b.getOwner();
}

void Game::purchase(string b, Player& p) {
  shared_ptr<Board> tmp = nullptr;
  shared_ptr<Player> tmp1 = nullptr;
  for(auto it:board){
      if(it->getName()==b){
    //    p.addProperties(it);
        //p.addCash(-it->getPrice());
        tmp = it;
      }
    }

  if (tmp->getOwner() == nullptr) {
    if (p.getCashAmount() >= tmp->getPrice()) {
      for (auto it1:player) {
        if (it1->getName() == p.getName()) {
          tmp1 = it1;
        }
      }
      tmp->setOwner(tmp1);
      p.addProperties(tmp);
      p.addCash(-tmp->getPrice());
    } else {
      cout << "You don't have enough money" << endl;
    }
    
    // shared_ptr<Board> sharedb = make_shared<Board>(b);
    // auto sharedb = std::dynamic_pointer_cast<Board>(b);
    // shared_ptr<Board> sharedb = b;
    
  } else cout << "This property is already owned by " << (tmp->getOwner())->getName() << endl;
}

bool Game::isValidPlayer(string name) {
  for (auto& p : player) {
    if (p->getName() == name) return true;
  }
  return false;
}

bool Game::isValidProperty(string bName) {
  for (auto& b : board) {
    if (b->getName() == bName && b->getType() != "NonProperty") return true;
  }
  return false;
}

/*Board& Game::getBoard(string bName) {
  for (auto &b : this->board) {
    if (b->getName() == bName) return *b;
  }
  cerr << "can't find the Board" << endl;
  return *(board[0]);
}*/

Player& Game::getPlayer(string name) {
  for (auto &p : player) {
    if (p->getName() == name) return *p;
  }
  cerr << "can't find the Player" << endl;
  return *(player[0]);
}

bool Game::trade(Player& p, string b, unsigned int n) {
  shared_ptr<Board> sharedb = nullptr;
  for(auto it : board){
    if(it->getName()==b){
      sharedb = it;
      break;
    }
  }
  if (sharedb->getOwner() == currentPlayer) {
    cout << currentPlayer->getName() << " is trading " << sharedb->getName() << " with " << p.getName() <<  " for " << n << endl;
    cout << "Choose: 'accept' or 'reject'" << endl;
    string choice;
    cin >> choice;
    if (choice == "accept") {
      shared_ptr<Player> sharedp = make_shared<Player>(p);
      sharedb->setOwner(sharedp);
      // shared_ptr<Board> sharedb = make_shared<Board>(b);
      p.addProperties(sharedb);
      p.addCash(-n);
      currentPlayer->sellProperties(sharedb);
      currentPlayer->addCash(n);
      return true;
    } else if (choice == "reject") {
      cout << "Trade rejected" << endl;
      return false;
    } else {
      cout << "Invalid input" << endl;
      return false;
    }
  } else return false;
}

bool Game::trade(Player& p, string b_give, string b_receive) {
      shared_ptr<Board> sharedb = nullptr;
      for(auto it : board){
        if(it->getName()==b_give){
          sharedb = it;
          break;
        }
      }
  shared_ptr<Board> sharedb2 = nullptr;
      for(auto it2 : board){
        if(it2->getName()==b_receive){
          sharedb2 = it2;
          break;
        }
      }
  if (sharedb->getOwner() == currentPlayer) {
    cout << currentPlayer->getName() << " is trading " << sharedb->getName() << " with " << p.getName() <<  " for " << sharedb2->getName() << endl;
    cout << "Choose: 'accept' or 'reject'" << endl;
    string choice;
    cin >> choice;
    if (choice == "accept") {
      shared_ptr<Player> sharedp = make_shared<Player>(p);
      sharedb->setOwner(sharedp);
      // shared_ptr<Board> sharedb = make_shared<Board>(b_give);
      p.addProperties(sharedb);
      // shared_ptr<Board> sharedb2 = make_shared<Board>(b_receive);
      p.sellProperties(sharedb2);
      sharedb2->setOwner(currentPlayer);
      currentPlayer->addProperties(sharedb2);
      currentPlayer->sellProperties(sharedb);
      return true;
    } else if (choice == "reject") {
      cout << "Trade rejected" << endl;
      return false;
    } else {
      cout << "Invalid input" << endl;
      return false;
    }
  } else return false;
}

bool Game::trade(Player& p, unsigned int n, string b) {
  shared_ptr<Board> sharedb = nullptr;
  for(auto it : board){
    if(it->getName()==b){
      sharedb = it;
      break;
    }
  }

  shared_ptr<Player> sharedp = make_shared<Player>(p);
  if (sharedb->getOwner() == sharedp) {
    cout << currentPlayer->getName() << " is trading " << n << " with " << p.getName() <<  " for " << sharedb->getName() << endl;
    cout << "Choose: 'accept' or 'reject'" << endl;
    string choice;
    cin >> choice;
    if (choice == "accept") {
      sharedb->setOwner(currentPlayer);
    
      // shared_ptr<Board> sharedb = make_shared<Board>(b);
      currentPlayer->addProperties(sharedb);
      currentPlayer->addCash(-n);
      p.sellProperties(sharedb);
      p.addCash(n);
      return true;
    } else if (choice == "reject") {
      cout << "Trade rejected" << endl;
      return false;
    } else {
      cout << "Invalid input" << endl;
      return false;
    }
  } else return false;
}

bool Game::improve(string b_name, bool improve) {
  shared_ptr<Board> b = nullptr;
  for(auto it : board){
    if(it->getName()==b_name){
      b = it;
      break;
    }
  }

  if (b->getType() != "AcademicBuilding") {
    cout << "Not an Academic Building" << endl;
    return false;
  }

  if (b->getOwner() == currentPlayer) {
    if (improve) {
      if (b->getImproveLevel() < 5) {
        if (currentPlayer->getCashAmount() >= b->getImproveCost()) {
          currentPlayer->addCash(-b->getImproveCost());
          b->improve();
          return true;
        } else {
          cout << "You don't have enough money to improve this property" << endl;
          return false;
        }
      } else{
        cout << "It is already full grade!" << endl;
        return false;
      }
    } else { // degrade
      if (b->getImproveLevel() > 0) {
        currentPlayer->addCash(b->getImproveCost() / 2);
        b->degrade();
        return true;
      } else {
        cout << "It can't be degraded anymore" << endl;
        return false;
      }
    }
  } else {
    cout << "You don't own this property" << endl;
    return false;
  }
}

bool Game::mortgage(string b_name) {
  shared_ptr<Board> b = nullptr;
  for(auto it : board){
    if(it->getName()==b_name){
      b = it;
      break;
    }
  }

  if (b->getOwner() == currentPlayer) {
    if (b->getImproveLevel() == 0 && !b->isMortgaged()) {
      int m = b->getPrice() / 2;
      currentPlayer->addCash(m);
      b->changeMortgage();
      cout<< "You've mortgaged succesfully and received: $" << m <<endl;
      cout << "Enter a command or end your turn by 'next'." << endl;
      return true;
    } else {
      if (b->getImproveLevel() != 0) {
        cout << "You can't mortgage this property because it has improvements" << endl;
        cout << "Enter a command or end your turn by 'next'." << endl;
      } else {
        cout << "You can't mortgage this property because it is already mortgaged" << endl;
        cout << "Enter a command or end your turn by 'next'." << endl;
      }
      return false;
    }
  } else {
    cout << "You don't own it" << endl;
    cout << "Enter a command or end your turn by 'next'." << endl;
    return false;
  }
}

bool Game::unmortgage(string b_name) {
  shared_ptr<Board> b = nullptr;
  for(auto it : board){
    if(it->getName()==b_name){
      b = it;
      break;
    }
  }
  if (b->getOwner() == currentPlayer) {
    if (b->isMortgaged()) {
      if (currentPlayer->getCashAmount() >= b->getPrice() / 10 * 6) {
        int m = -b->getPrice() / 10 * 6;
        currentPlayer->addCash(m);
        b->changeMortgage();
        cout << "You've unmortgaged by using $" << m << endl;
        return true;
      } else {
        cout << "You don't have enough money to unmortgage" << endl;
        return false;
      }
    } else {
      cout << "This property is not mortgaged" << endl;
      return false;
    }
  } else {
     cout << "You are not the owner" << endl;
    return false;
  }
}

bool Game::checkAssetVSLiability() {
  return 1;
}

bool Game::checkIfBankruptcy() {
  return 0;
}

void Game::bankruptcy(string playerName){
  shared_ptr<Player> p = nullptr;
  for(auto a : player){
    if(a->getName() == playerName){
      p = a;
    }
  }
  if(p->getCashAmount() < 0){
    int choice;
    cout << "Your cash is negative, you need to sell (input 0), or mortgage (input 1), or bankrupt (input 2)" <<endl;
    cin >> choice;
    if(choice == 2){
      removePlayer(playerName);
    }else{
      do{
        if(choice == 0){
          cout << "Input the name of the property you want to sell " << endl;
          string pro;
          cin >> pro;
          for(auto it : p->getProperty()){
            if(it->getName() == pro){
              if(it->getImproveLevel() != 0){
                p->addCash(it->getImproveCost());
                it->setImproveLevel(it->getImproveLevel()-1);
                cout << "You've sell 1 improvement";
                break;
              }
            }
          }
        }else if(choice == 1){
          cout << "Input the name of the property you want to mortgage " << endl;
          string pro;
          cin >> pro;
          for(auto it : p->getProperty()){
            if(it->getName() == pro){
              if(!it->isMortgaged()){
                p->addCash(it->getPrice()/2);
                it->changeMortgage();
                cout << "You've mortgage the property";
                break;
              }else{
                cout << "The property is already mortgaged";
              }
            }
          }
        }
        while(p->getCashAmount() < 0){
          cout << "Your cash is still negative, you need to sell (input 0), or mortgage (input 1)" <<endl;
          cin >> choice;
        }
      }while(p->getCashAmount() < 0);
    }
  } 
}

void Game::removePlayer(string name) {
  //
  ///
  //// 拍卖！！！！
  ///
  for (size_t i = 0; i < player.size(); ++i) {
    if (player[i] == currentPlayer) {
      cout << currentPlayer->getName() << " is bankrupted" << endl;
      player.erase(player.begin() + i);
    }
  }
}

void Game::asset() {
  cout << currentPlayer->getName()<<", your assets:" << endl;
  cout << "Cash: " << currentPlayer->getCashAmount() << endl;
  cout << "Properties: ";
  for (auto it : currentPlayer->getProperty()) {
    cout << it->getName() << " ";
  }
  cout <<endl;
  cout << "Roll up the Rim Cup: " << currentPlayer->getRURCup() << endl;
  cout << "Enter a command or end your turn by 'next'." << endl;
}

void Game::all() {
  for (auto it : player) {
    cout << it->getName()<<", your assets:" << endl;
    cout << "Cash: " << it->getCashAmount() << endl;
    cout << "Properties: " ;
    for (auto it : it->getProperty()) {
      cout << it->getName() << " ";
    }
    cout << endl;
    cout << "Roll up the Rim Cup: " << currentPlayer->getRURCup() << endl;
    cout << "Enter a command or end your turn by 'next'." << endl;
  }
}

ofstream Game::save(string filename) {
  ofstream file(filename);
  file << player.size() << endl;
  for (auto it : player) {
    file << it->getName() << " " << it->getNameChar() << " " << it->getRURCup() << " " << it->getCashAmount()<< " " << it->getPosition();
    if(it->getPosition() == 10){
      if (it->getsentToDCTL()){
        file << " 1" << " " << it->getDCTLtimes();
      }else{
        file << " 0";
      }
    }
    file << endl;
  }
  for (auto it2 : board) {
    file << it2->getName() << " " ;
    auto tmp = dynamic_pointer_cast<Property>(it2);
    if(tmp){
      if(tmp->getOwner() != nullptr){
        file << it2->getOwner()->getName() << " " ;
      }else{
        file << "BANK ";
      }
      if(tmp->isMortgaged()){
        file << "-1" << " "<< endl;
      }else{
        auto tmp2 = dynamic_pointer_cast<AcademicBuilding>(tmp);
        if(tmp2){
          file << tmp2->getImproveLevel() << endl;
        }else{
          file << "0" << endl;
        }
      }
    }else{
      file << "BANK 0" << endl;
    } 
  }
  cout<<"Game saved!"<<endl;
  return file;
}

void Game::load(ifstream& f) {
  int num = 0;
  string name = " ";
  char namechar = ' ';
  int rurcup = 0;
  int cash = 0;
  int pos = 0;
  f >> num;
  for (int i = 0; i < num; i++) {
    string tmp;
    getline(f, tmp);
    istringstream ss(tmp);
    ss >> name >> namechar >> rurcup >> cash >> pos;
    if (pos == 10) {
      int sent;
      f >> sent;
      if (sent == 0) {
        player.push_back(make_shared<Player>(name, namechar, rurcup, cash, pos, false, 0));
      } else {
        int times;
        f >> times;
        player.push_back(make_shared<Player>(name, namechar, rurcup, cash, pos, true, times));
      }
    } else {
      player.push_back(make_shared<Player>(name, namechar, rurcup, cash, pos, false, 0));
    }
  }
  for(int i = 0; i < 40; i++){
    auto it = board[i];
    string tmp;
    getline(f, tmp);
    istringstream ss{tmp};
    string name;
    string owner;
    int level;
    ss >> name >> owner;
    if(owner != "BANK"){
      ss >> level;
      auto p = dynamic_pointer_cast<Property>(it);
      if(level == -1){
        level = 0;
        if (p != nullptr) p->changeMortgage();
      }
      shared_ptr<Player> owner1 = nullptr;
      for(auto it2 : player){
        if(it2->getName() == owner){
          owner1 = it2;
          break;
        }
      }
      if (owner1 != nullptr) {
        p->setOwner(owner1);
        owner1->addProperties(it);
      }
      auto academic = dynamic_pointer_cast<AcademicBuilding>(it);
      if(academic){
        academic->setImproveLevel(level);
      }
    }
  }
  cout<<"Game loaded!"<<endl;
}

int Game::getActiverRim() {
  return activeRim;
}

void Game::setActiverRim(int n) {
  activeRim = n;
}

void Game::auction(string pro) {
  shared_ptr<Board> sharedb= nullptr;
  for(auto it : board){
    if(it->getName() == pro){
      sharedb=it;
      break;
    }
  }
  cout << "Auction for " << sharedb->getName() << " starts!" << endl;
  int max = 0;
  string bider = " ";
  vector<shared_ptr<Player>> participants = player;
  int n = participants.size();
  while(n != 1) {
    if (n == 0) {
      cout << "No one wants to buy this property" << endl;
      return;
    }
    cout << "There are " << n << " players in the auction." << endl;
    for (int i = 0; i < n; ++i) {
      if(n==1){
        break;
      }
      cout << participants[i]->getName() << ", it is your turn" << endl;
      cout << "Choose between: bid or quit" << endl;
      string choice;
      while (cin >> choice) {
        if (choice == "quit") {
          cout << "You quit the auction." << endl;
          participants.erase(participants.begin() + i);
          n--;
          i--;
          cout << "There are " << n << " players in the auction." << endl;
          break;
        } else if (choice == "bid") {
          cout << "Input your bid. Your bid must be higher than " << max << endl;
          int bid;
          cin >> bid;
          if (bid > max) {
            max = bid;
            bider = participants[i]->getName();
            cout << "Your bid is accepted" << endl;
            break;
          } else {
            cout << "Your bid is not accepted" << endl;
            break;
          }
        } else {
          cout << "Invalid input, input again." << endl;
        }
      }
    }
  }
  cout << "The final bid is " << max << " from " << bider << endl;
  for (auto p : player) {
    if (p->getName() == bider) {
      p->addCash(-max);
      p->addProperties(sharedb);
      sharedb->setOwner(p);
      // check Brankruptcy
      return;
    }
  }
}

void Game::printMap(){
  TextDisplay td;
  td.drawBoard(std::cout, player, board);
}

