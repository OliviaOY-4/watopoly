#include "game.h"
#include "board.h"
using namespace std;

Game::Game(): activeRim{0} {
  vector<string> names = {"COLLECT OSAP", "AL", "SLC", "ML", "TUITION", "MKV", "ECH", "NEEDLES HALL", "PAS", "HH", "DC Tims Line", "RCH", "PAC", "DWE", "CPH", "UWP", "LHI", "SLC", "BMH", "OPT", "Goose Nesting", "EV1", "NEEDLES HALL", "EV2", "EV3", "V1", "PHYS", "B1", "CIF", "B2", "GO TO TIMS", "EIT", "ESC", "SLC", "C2", "REV", "NEEDLES HALL", "MC", "COOP FEE", "DC"};
  for (int i = 0; i < 40; ++i) {
    Board *b = new Board{i, names[i]};
    board.emplace_back(b);
  }
}

Game::~Game() {
  for (auto &p : players) {
    delete p;
  } for (auto &b : boards) {
    delete b;
  } for (auto &b : buildings) {
    delete b;
  } delete dice;
  delete currentPlayer;
  delete td;
}

int Game::roll() {
  return dice->roll();
}

void Game::move(int num, Player *p) {
  int curPos = p->getPosition();
  int newPos = curPos + num;
  if (newPos >= 40) {
    p->addCash(200);
    newPos -= 40;
  }
  p->setPosition(newPos);
  
  bool buy = false;
  for (int i = 0; i < )

}


Board& moveToCertain(Board& b);

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
  for (auto &p : player) {
    if (p->getName() == name) return true;
  }
  return false;
}

bool Game::isValidProperty(string b) {
  for (auto &b : buildings) {
    if (p->getName() == b) return true;
  }
  return false;
}

Board& Game::getBoard(string board); {
  for (auto &b : this->board) {
    if (b->getName() == board) return *b;
  }
}

Player& Game::getPlayer(string name) {
  for (auto &p : player) {
    if (p->getName() == name) return *p;
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
    if (improve && b.getImproveLevel() < 5) {
      if (currentPlayer->getCash() >= b.getImproveCost()) {
        currentPlayer->addCash(-b.getImproveCost());
        b.improve();
        return true;
      } else {
        cout << "You don't have enough money to improve this property" << endl;
        return false;
      }
    }else{
        cout << "It is already full grade!" << endl;
        return false;
      }
    } else {
      if (b.getImproveLevel() > 0) {
        currentPlayer->addCash(b.getImproveCost() / 2);
        b.setImprove(b.getImprove() - 1);
        return true;
      } else {
        cout << "You can't downgrade this property anymore" << endl;
        return false;
      }
    }
  } else {
    cout << "You don't own this property" << endl;
    return false;
  }
}

bool Game::mortgage(Board& b); 
bool Game::unmortgage(Board& b); 
bool Game::checkAssetVSLiability();
bool Game::checkIfBankruptcy();
void Game::removePlayer();
bool Game::asset(); 
bool Game::all(); 
ofstream& Game::save(std::string filename);
void Game::load(ifstream &file);
int Game::getActiverRim();
void Game::changeActiverRim();
void Game::auction(Property& pro);


