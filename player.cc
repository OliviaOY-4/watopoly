#include "player.h"
using namespace std;
#include "board.h"

Player::Player(string name): name{name}, cash{1500}, position{0}, OSAPcollect{false}, sentToDCTL{false}, DCTLtimes{0}, RUR_Cup{0} {
  // dice = new Dice();
  dice = make_shared<Dice>();
  if (name == "Goose") nameChar = 'G';
  if (name == "GRT Bus") nameChar = 'B';
  if (name == "Tim Hortons Doughnut") nameChar = 'D';
  if (name == "Professor") nameChar = 'P';
  if (name == "Student") nameChar = 'S';
  if (name == "Money") nameChar = '$';
  if (name == "Laptop") nameChar = 'L';
  if (name == "Pink tie") nameChar = 'T';
}

Player::Player(string name, char nameChar, int RUR_Cup, int cash, int position, bool sentToDCTL, int DCTLtimes): name{name}, nameChar{nameChar}, cash{cash}, position{position}, OSAPcollect{false}, sentToDCTL{sentToDCTL}, DCTLtimes{DCTLtimes}, RUR_Cup{RUR_Cup} {}

vector<shared_ptr<Board>> Player::getProperty(){
  return property;
}

Player::~Player() {
}


int Player::getCashAmount() {
  return cash;
}

int Player::getTotalWorth() {
  int total = cash;
  int p_len = property.size();
  for (int i = 0; i < p_len; ++i){
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
  int p_len = property.size();
  for (int i = 0; i < p_len; i++){
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
  return nameChar;
}

bool Player::ifMonopoly(string type) {
  for (auto it: monopoly) {
    if (it == type) {
      return true;
    }
  }
  return false
  /*int count = 0;
  int p_len =  property.size();
  for (int i = 0; i < p_len; i++){
    if (property[i]->getBlock() == type) count++;
  }
  if (count == 2){
    if (type == "Arts1" || type == "Math") {
      monopoly.emplace_back(type);
    }
  } else if (count == 3) {
    monopoly.emplace_back(type);
  }*/
}

int Player::getResidenceNum() {
  int count = 0;
  int p_len =  property.size();
  for (int i = 0; i < p_len; i++){
    if (property[i]->getType() == "Residence") count++; ///// type 只能分辨是不是property，本来一个存在monopoly里面，到时候再商量一下
  } return count;
}

bool Player::getOSAPcollect() {
  return OSAPcollect;
}

void Player::setOSAPcollect(bool boo) {
  OSAPcollect = boo;
}

bool Player::getsentToDCTL() {
  return sentToDCTL;
}

void Player::setsentToDCTL(bool boo) {
  sentToDCTL = boo;
}

int Player::getDCTLtimes() {
  return DCTLtimes;
}

void Player::setDCTLtimes(int times) {
  DCTLtimes = times;
}

int Player::getRURCup() {
  return RUR_Cup;
}

void Player::setRURCup(int cup) {
  RUR_Cup = cup;
}

int Player::getPropertySize(){
  return property.size();
}

int Player::getGymNum(){
  int count = 0;
  int p_len = property.size();
  for (int i = 0; i < p_len; i++){
    if (property[i]->getType() == "Gym") count++;
  } return count;
}


