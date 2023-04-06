#include "game.h"
#include "board.h"
using namespace std;
class OSAP;
class CoopFee;
class DCTimsLine;
class GoToTims;
class NeedlesHall;
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
  currentPlayer = *(player.begin());
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<OSAP>(0, "COLLECT OSAP"))); //unique or shared?
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(1, "AL", 40, 0, vector<unsigned int>{2, 10, 30, 90, 160, 250}, 50, "Arts1")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<SLC>(2, "SLC")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(3, "ML", 60, 0, vector<unsigned int>{4, 20, 60, 180, 320, 450}, 50, "Arts1")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Tuition>(4, "TUITION")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<Residence>(5, "MKV", 200, 25)));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<AcademicBuilding>(6, "ECH", 100, 0, vector<unsigned int>{6, 30, 90, 270, 400, 550}, 50, "Arts2")));
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<NeedlesHall>(7, "NEEDLES HALL")));
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
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<NeedlesHall>(22, "NEEDLES HALL")));
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
  board.emplace_back(std::static_pointer_cast<Board>(make_shared<NeedlesHall>(36, "NEEDLES HALL")));
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
          purchase(*now, *p);
          buy = true;
        } else cout << "You don't have enough money" << endl;
        buy = false;
      } else if (choice == "auction" || buy == false) {
        auction(*now);
        buy = true;
      } else {
        cout << "Invalid input" << endl;
      }
    } else {
      int visitPrice = now->getVisitPrice(*p);
      p->addCash(-visitPrice);
      cout << "You paid " << visitPrice << " to " << (now->getOwner())->getName() << endl;
      if (p->getCash() >= 0) return;
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
      SLC::action(p);
    } else if (nowName == "TUITION") {
      Tuition::action(p);
    } else if (nowName == "GO TO TIMS") {
      GoToTims::action(p);
    } else if (nowName == "COOP FEE") {
      CoopFee::action(p);
    } else if (nowName == "NEEDLES HALL") {
      NeedlesHall::action(p);
    } else if (nowName == "Goose Nesting") {
      GooseNesting::action(p);
    } td->drawBoard(cout, player, board);
  }
}


void Game::nextPlayer() {
  for (int i = 0; i < player.size(); ++i) {
    if (player[i] == currentPlayer) {
      if (i == player.size() - 1) currentPlayer = player[0];
      else currentPlayer = player[i + 1];
      break;
    }
  }
}

void Game::initPlayer(string name, char playerChar) {
  Player *p = new Player(name, playerChar);
  player.emplace_back(p);
  td->drawBoard(cout, player, board);
}

string Game::getOwner(const Board& b) {
  return b.getOwner();
}

void Game::purchase(Board& b, Player& p) {
  if (b.getOwner() == nullptr) {
    b.setOwner(&p);
    p.addProperties(&b);
    p.addCash(-b.getPrice());
  } else cout << "This property is already owned by " << (b.getOwner())->getName() << endl;
}

bool Game::isValidPlayer(string name) {
  for (auto* p : player) {
    if (p->getName() == name) return true;
  }
  return false;
}

bool Game::isValidProperty(string bName) {
  for (auto* b : board) {
    if (b->getName() == bName && b->getType() != "NonProperty") return true;
  }
  return false;
}

Board& Game::getBoard(string bName); {
  for (auto &b : this->board) {
    if (b.getName() == bName) return b;
  }
}

Player& Game::getPlayer(string name) {
  for (auto &p : player) {
    if (p->getName() == name) return p;
  }
}

bool Game::trade(Player& p, Board& b, unsigned_int n) {
  if (b.getOwner() == currentPlayer) {
    cout << currentPlayer->getName() << " is trading " << b.getName() << " with " << p.getName() <<  " for " << n << endl;
    cout << "Choose: 'accept' or 'reject'" << endl;
    string choice;
    cin >> choice;
    if (choice == "accept") {
      b.setOwner(&p);
      p.addProperties(&b);
      p.addCash(-n);
      currentPlayer->sellProperties(&b);
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

bool Game::trade(Player& p, Board& b_give, Board& b_receive) {
  if (b_give.getOwner() == currentPlayer) {
    cout << currentPlayer->getName() << " is trading " << b_give.getName() << " with " << p.getName() <<  " for " << b_receive.getName() << endl;
    cout << "Choose: 'accept' or 'reject'" << endl;
    string choice;
    cin >> choice;
    if (choice == "accept") {
      b_give.setOwner(&p);
      p.addProperties(&b_give);
      p.sellProperties(&b_receive);
      b_receive.setOwner(&currentPlayer);
      currentPlayer->addProperties(&b_receive);
      currentPlayer->sellProperties(&b_give);
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

bool Game::trade(Player& p, unsigned_int n, Board& b) {
  if (b.getOwner() == &p) {
    cout << currentPlayer->getName() << " is trading " << n << " with " << p.getName() <<  " for " << b.getName() << endl;
    cout << "Choose: 'accept' or 'reject'" << endl;
    string choice;
    cin >> choice;
    if (choice == "accept") {
      b.setOwner(currentPlayer);
      currentPlayer->addProperties(&b);
      currentPlayer->addCash(-n);
      p.sellProperties(&b);
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
        if (currentPlayer->getCash() >= b.getImproveCost()) {
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
  if (b.getOwner() == currentPlayer) [
    if (b.isMortgaged()) {
      if (currentPlayer->getCash() >= b.getPrice() / 10 * 6) {
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
  ]
}

bool Game::checkAssetVSLiability();

bool Game::checkIfBankruptcy();

void Game::removePlayer() {
  for (auto p : player) {
    if (p == currentPlayer) {
      cout << p->getName() << " is bankrupted" << endl;
      player.erase(p);
    }
  }
}

bool Game::asset(); 
bool Game::all(); 

ofstream& Game::save(std::string filename);
void Game::load(ifstream &file);

int Game::getActiverRim() {
  return activeRim;
}

void Game::setActiverRim(int n) {
  activeRim = n;
}

void Game::auction(Board& pro) {
  cout << "Auction for " << pro.getName() << "starts" << endl;
  int max = 0;
  string bider = " ";
  vecntor<Player*> participants = player;
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
      p->addProperties(&pro);
      pro.setOwner(p);
      return;
    }
  }
  
}

void Game::printMap(){
  td->drawBoard(std::cout, player, board);
}

