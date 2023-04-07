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

Game::Game(): activeRim{0} {
  vector<string> names = {"COLLECT OSAP", "AL", "SLC", "ML", "TUITION", "MKV", "ECH", "NEEDLES HALL", "PAS", "HH", "DC Tims Line", "RCH", "PAC", "DWE", "CPH", "UWP", "LHI", "SLC", "BMH", "OPT", "Goose Nesting", "EV1", "NEEDLES HALL", "EV2", "EV3", "V1", "PHYS", "B1", "CIF", "B2", "GO TO TIMS", "EIT", "ESC", "SLC", "C2", "REV", "NEEDLES HALL", "MC", "COOP FEE", "DC"};
  // for (int i = 0; i < 40; ++i) {
  //   Board *b = new Board{i, names[i]};
  //   board.emplace_back(b);
  // }
  dice = make_unique<Dice>();
  td = make_unique<TextDisplay>();
  currentPlayer = *(player.begin() + 0);
  // auto osap = make_shared<OSAP>(0, "COLLECT OSAP");
  // board.emplace_back(osap);
  board.emplace_back(make_shared<OSAP>(0, "COLLECT OSAP")); //unique or shared?

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

Game::~Game() {
  // for (auto* p : player) {
  //   delete p;
  // } for (auto* b : board) {
  //   delete b;
  // } 
  // delete dice;
  // delete td;
}

int Game::roll() {
  return dice->rollDice();
}

// void Game::move(int num, Player *p) {
//   int curPos = p->getPosition();
//   int newPos = curPos + num;
//   if (newPos >= 40) {
//     p->addCash(200);
//     newPos -= 40;
//   }
//   p->setPosition(newPos);
  
//   bool buy = false;
//   for (int i = 0; i < )

// }
void Game::move(int num, shared_ptr<Player> p) {
  if (p == nullptr) p = currentPlayer;
  int curPos = p->getPosition();
  int newPos = curPos + num;
  if (newPos >= 40) {
    p->addCash(200);
    newPos -= 40;
  }
  p->setPosition(newPos);
  
  bool buy = false;
  shared_ptr<Board> now = board[newPos];
  string nowType = now->getType();

  if (nowType == "AcademicBuilding" || nowType == "Gym" || nowType == "Residence") {
    if (now->getOwner() == nullptr) {
      cout << "You can buy it for " << now->getPrice() << endl;
      cout << "Choose: 'buy' or 'auction'" << endl;
      string choice;
      cin >> choice;
      if (choice == "buy") {
        if (p->getCashAmount() >= now->getPrice()) {
          string name = now->getName();
          purchase(name, *p);
          buy = true;
        } else cout << "You don't have enough money" << endl;
        buy = false;
      } else if (choice == "auction" || buy == false) {
        string name = now->getName();
        auction(name);
        buy = true;
      } else {
        cout << "Invalid input" << endl;
      }
    } else {
      int visitPrice = now->getVisitPrice(*p);
      p->addCash(-visitPrice);
      cout << "You paid " << visitPrice << " to " << (now->getOwner())->getName() << endl;
      if (p->getCashAmount() >= 0) return;
      else {
        cout << "You are in debt" << endl;
        cout << "Choose: 'mortgage' or 'trade' or 'degrade'" << endl;
        string choice;
        cin >> choice;
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
      } 
    }
  } else {
    string nowName = now->getName();
    if (nowName == "SLC") {
      SLC tmp{0, "slc"};
      int n = getActiverRim();
      int m = tmp.slcaction(*p, n);
      setActiverRim(m);
    } else if (nowName == "TUITION") {
      Tuition tmp{0, "tuition"};
      tmp.action(*p);
    } else if (nowName == "GO TO TIMS") {
      GoToTims tmp{0, "go to tims"};
      tmp.action(*p);
      int n = getActiverRim();
      DCTimsLine tmp1{0, "dc times line"};
      int m = tmp1.dclineaction(*p, n);
      setActiverRim(m);
    } else if (nowName == "COOP FEE") {
      CoopFee tmp{0, "coop fee"};
      tmp.action(*p);
    } else if (nowName == "NEEDLES HALL") {
      NeedleHall tmp{0, "needles hall"};
      int n = getActiverRim();
      int m = tmp.nhaction(*p, n);
      setActiverRim(m);
    } else if (nowName == "Goose Nesting") {
      GooseNesting tmp{0, "goose nesting"};
      tmp.action(*p);
    } td->drawBoard(cout, player, board);
  }
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

void Game::initPlayer(string name) {
  shared_ptr<Player> p = make_shared<Player>(name);
  player.emplace_back(p);
  td->drawBoard(cout, player, board);
}

shared_ptr<Player> Game::getOwner(const Board& b) {
  return b.getOwner();
}

void Game::purchase(string b, Player& p) {
  shared_ptr<Board> tmp = nullptr;
  for(auto it:board){
      if(it->getName()==b){
        p.addProperties(it);
        p.addCash(-it->getPrice());
        tmp = it;
      }
    }
  if (tmp->getOwner() == nullptr) {
    shared_ptr<Player> sharedp = make_shared<Player>(p);
    tmp->setOwner(sharedp);
    // shared_ptr<Board> sharedb = make_shared<Board>(b);
    // auto sharedb = std::dynamic_pointer_cast<Board>(b);
    // shared_ptr<Board> sharedb = b;
    // p.addProperties(sharedb);
    // p.addCash(-b.getPrice());
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

Board& Game::getBoard(string bName) {
  for (auto &b : this->board) {
    if (b->getName() == bName) return *b;
  }
  cerr << "can't find the Board" << endl;
  return *(board[0]);
}

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

bool Game::improve(Board& b, bool improve) {
  if (b.getOwner() == currentPlayer) {
    if (improve) {
      if (b.getImproveLevel() < 5) {
        if (currentPlayer->getCashAmount() >= b.getImproveCost()) {
          currentPlayer->addCash(-b.getImproveCost());
          b.improve();
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
      if (b.getImproveLevel() > 0) {
        currentPlayer->addCash(b.getImproveCost() / 2);
        b.degrade();
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

bool Game::mortgage(Board& b) {
  if (b.getOwner() == currentPlayer) {
    if (b.getImproveLevel() == 0 && !b.isMortgaged()) {
      currentPlayer->addCash(b.getPrice() / 2);
      b.changeMortgage();
      return true;
    } else {
      cout << "You can't mortgage this property because it has improvements or it is already mortgaged" << endl;
      return false;
    }
  } else {
    cout << "You don't own it" << endl;
    return false;
  }
}

bool Game::unmortgage(Board& b) {
  if (b.getOwner() == currentPlayer) {
    if (b.isMortgaged()) {
      if (currentPlayer->getCashAmount() >= b.getPrice() / 10 * 6) {
        currentPlayer->addCash(-b.getPrice() / 10 * 6);
        b.changeMortgage();
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
    return false;
  }
}

bool Game::checkAssetVSLiability() {
  return 1;
}

bool Game::checkIfBankruptcy() {
  return 0;
}

void Game::removePlayer() {
  for (size_t i = 0; i < player.size(); ++i) {
    if (player[i] == currentPlayer) {
      cout << currentPlayer->getName() << " is bankrupted" << endl;
      player.erase(player.begin() + i);
    }
  }
}

bool Game::asset() {
  return 0;
}

bool Game::all() {
  return 0;
}

ofstream Game::save(string filename) {
  ofstream n(filename);
  return n;
}

void Game::load(ifstream &file) {
  return;
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
        if(it->getName()==pro){
          sharedb=it;
          break;
        }
      }
  cout << "Auction for " << sharedb->getName() << "starts" << endl;
  int max = 0;
  string bider = " ";
  vector<shared_ptr<Player>> participants = player;
  int n = participants.size();
  for (int i = 0; i < n; i++) {
    if (n == 1) break;
    cout << participants[i]->getName() << ", it is your turn" << endl;
    cout << "Choose between: bid or quit" << endl;
    string choice;
    cin >> choice;
    if (choice == "quit") {
      cout << "You quit the auction" << endl;
      participants.erase(participants.begin() + i);
      i--;
      n--;
      continue;
    } else if (choice == "bid") {
      cout << "Input your bid. Your bid must be higher than " << max << endl;
      int bid;
      cin >> bid;
      if (bid > max) {
        max = bid;
        bider = participants[i]->getName();
        continue;
      }
    } else {
      cout << "Invalid input" << endl;
      return;
    } 
  }
  cout << "The final bid is " << max << " from " << bider << endl;
  for (auto p : player) {
    if (p->getName() == bider) {
      p->addCash(-max);
      // shared_ptr<Board> sharedb = make_shared<Board>(pro);
      p->addProperties(sharedb);
      sharedb->setOwner(p);
      return;
    }
  }
}

void Game::printMap(){
  td->drawBoard(std::cout, player, board);
}

