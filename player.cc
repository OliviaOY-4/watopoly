#include "player.h"
using namespace std;


Player::Player(string name, char nameChar): name{name}, nameChar{nameChar}, cash{1500}, position{0}, OSAPcollect{false}, sentToDCTL{false}, DCTLtimes{0}, RUR_Cup{0} {
  // dice = new Dice();
  dice = make_shared<Dice>();
  // if (name == "Goose") nameChar = 'G';
  // if (name == "GRT Bus") nameChar = 'B';
  // if (name == "Tim Hortons Doughnut") nameChar = 'D';
  // if (name == "Professor") nameChar = 'P';
  // if (name == "Student") nameChar = 'S';
  // if (name == "Money") nameChar = '$';
  // if (name == "Laptop") nameChar = 'L';
  // if (name == "Pink tie") nameChar = 'T';
}

Player::~Player() {
  delete dice;
}

int Player::roll() {
  return dice->rollDice();
}

int Player::getCashAmount() {
  return cash;
}

int Player::getTotalWorth() {
  int total = cash;
  for (int i = 0; i < property.size(); ++i){
    total += property[i]->getPrice();
  } return total;
}

// void Player::giveCash(Player* other, int amount){
//   other->addCash(amount);
//   cash -= amount;
// }
void Player::giveCash(shared_ptr<Player> other, int amount){
  other->addCash(amount);
  cash -= amount;
}

// void Player::addProperties(Board* b){
//   property.emplace_back(b);
// }
void Player::addProperties(shared_ptr<Board> b){
  property.emplace_back(b);
}

// void Player::sellProperties(Board* b){
//   for (int i = 0; i < property.size(); i++){
//     if (property[i] == b){
//       property.erase(property.begin() + i);
//     }
//   }
// }
void Player::sellProperties(shared_ptr<Board> b){
  for (int i = 0; i < property.size(); i++){
    if (property[i] == b){
      property.erase(property.begin() + i);
    }
  }
}

int Player::getPosition() {
  return position;
}

void Player::setPosition(int position) {
  this->position = position;
}

void Player::addCash(int amount) {
  cash += amount;
}

string Player::getName() {
  return name;
}

char Player::getNameChar() {
  return nameCapital;
}

void Player::ifMonopoly(string type) {
  int count = 0;
  for (int i = 0; i < property.size(); i++){
    if (property[i]->getBlock() == type) count++;
  }
  if (count == 2){
    if (type == "Arts1" || type == "Math") {
      monopoly.emplace_back(type);
    }
  } else if (count == 3) {
    monopoly.emplace_back(type);
  }
}

int Player::getResidenceNum() {
  int count = 0;
  for (int i = 0; i < property.size(); i++){
    if (property[i]->getType() == "Residence") count++;
  } return count;
}

bool getOSAPcollect() {
  return OSAPcollect;
}

void setOSAPcollect(bool boo) {
  OSAPcollect = boo;
}

bool getsentToDCTL() {
  return sentToDCTL;
}

void setsentToDCTL(bool boo) {
  sentToDCTL = boo;
}

int getDCTLtimes() {
  return DCTLtimes;
}

void setDCTLtimes(int times) {
  DCTLtimes = times;
}

int getRURCup() {
  return RUR_Cup;
}

void setRURCup(int cup) {
  RUR_Cup = cup;
}




