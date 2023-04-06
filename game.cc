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
  for (auto* p : player) {
    delete p;
  } for (auto* b : board) {
    delete b;
  } 
  delete dice;
  delete td;
}

int Game::roll() {
  return dice->rollDice();
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

void Game::auction(Property& pro) {
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


