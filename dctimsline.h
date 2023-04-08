#ifndef DCTIMSLINE_H
#define DCTIMSLINE_H

#include "nonproperty.h"
#include "dice.h"
#include <sstream>

class DCTimsLine: public NonProperty {
    int roll1(int n) {
        srand(static_cast<unsigned>(time(0)));
        int randnum = rand() % n + 1;
        return randnum;
    }
    int nextmove;
public:
    DCTimsLine(int position, std::string name): NonProperty(position, name) {}
    ~DCTimsLine() {};
    int getNextMove() {return nextmove;}
    int dclineaction(Player &p, int n){
        int tmp = n;
        nextmove = 0;
        if (!p.getsentToDCTL()) std::cout << "Nothing happens." << std::endl;
        else {
            std::cout << "You are in DC Tims Line." << std::endl;
            std::cout << "Roll doubles (input 'Roll'), pay $50 (input 'Pay') or use a Roll Up the Rim cup (input 'RimCup') to leave." << std::endl;
            std::cout << "Input: ";
            std::string choice;
            std::cin >> choice;
            
            while (choice != "Roll" && choice != "Pay" && choice != "RimCup") {
                std::cout << std::endl << "Invalid input. Please try again." << std::endl;
                std::cout << "Input: ";
                std::cin >> choice;
            }
            if (choice == "Roll") {
                Dice dice;
                int dice1 = dice.rollDice();
                int dice2 = dice.rollDice();
                if (dice1 == dice2) {
                    std::cout << "You rolled doubles and you may leave the DC Tims Line." << std::endl;
                    p.setsentToDCTL(false);
                    p.setDCTLtimes(0);
                    p.setOSAPcollect(true);
                } else {
                    if (p.getDCTLtimes() == 2) {
                        int sum = dice1 + dice2;
                        std::cout << "You must pay $50 (input 'Pay') or use a Roll Up the Rim cup (input 'RimCup') to leave." << std::endl;
                        std::cout << "Input: ";
                        std::cin >> choice;
                        while (choice != "Pay" && choice != "RimCup") {
                            std::cout << std::endl << "Invalid input. Please try again." << std::endl;
                            std::cout << "Input: ";
                            std::cin >> choice;
                        }
                        if (choice == "Pay") {
                            p.addCash(-50);
                            std::cout << "You paid $50 and you may leave the DC Tims Line." << std::endl;
                            p.setsentToDCTL(false);
                            p.setDCTLtimes(0);
                            p.setOSAPcollect(true);
                            //move???
                        } else {
                            if (p.getRURCup() == 0) {
                                std::cout << "You do not have any Roll Up the Rim cups." << std::endl;
                                std::cout << "You must pay $50." << std::endl;
                                p.addCash(-50);
                                std::cout << "You paid $50 and you may leave the DC Tims Line." << std::endl;
                                p.setsentToDCTL(false);
                                p.setDCTLtimes(0);
                                p.setOSAPcollect(true);
                                //move???
                            } else {
                                std::cout << "You used a Roll Up the Rim cup and left DC Tims Line." << std::endl;
                                p.setsentToDCTL(false);
                                p.setDCTLtimes(0);
                                p.setRURCup(p.getRURCup() - 1);
                                // game->setActiverRim(game->getActiverRim() - 1);
                                tmp--;
                                p.setOSAPcollect(true);
                                //move???
                            }
                        } nextmove = sum;
                    } else {
                        std::cout << "Unfortunately, you will stay in DC Tims Line." << std::endl;
                        p.setDCTLtimes(p.getDCTLtimes() + 1);
                    }
                }
            } else if (choice == "Pay") {
                p.addCash(-50);
                std::cout << "You paid $50 and you may leave the DC Tims Line." << std::endl;
                p.setsentToDCTL(false);
                p.setDCTLtimes(0);
                p.setOSAPcollect(true);
                //move???
            } else {
                if (p.getRURCup() == 0) {
                    std::cout << "You do not have any Roll Up the Rim cups." << std::endl;
                    std::cout << "You will stay." << std::endl;
                    //move???
                } else {
                    std::cout << "You used a Roll Up the Rim cup and left DC Tims Line." << std::endl;
                    p.setsentToDCTL(false);
                    p.setDCTLtimes(0);
                    p.setRURCup(p.getRURCup() - 1);
                    // game->setActiverRim(game->getActiverRim() - 1);
                    tmp--;
                    p.setOSAPcollect(true);
                    //move???
                }
            }
        }
        return tmp;
    }
    void action(Player &p) override {
        return ;
        // if (!p.getsentToDCTL()) std::cout << "Nothing happens." << std::endl;
        // else {
        //     std::cout << "You are in DC Tims Line." << std::endl;
        //     std::cout << "Roll doubles (input 0), pay $50 (input 1) or use a Roll Up the Rim cup (input 2) to leave." << std::endl;
        //     std::cout << "Input: ";
        //     int choice;
        //     std::cin >> choice;
        //     while (choice != 0 && choice != 1 && choice != 2) {
        //         std::cout << std::endl << "Invalid input. Please try again." << std::endl;
        //         std::cout << "Input: ";
        //         std::cin >> choice;
        //     }
        //     if (choice == 0) {
        //         int dice1 = roll1(6);
        //         int dice2 = roll1(6);
        //         if (dice1 == dice2) {
        //             std::cout << "You rolled doubles and you may leave the DC Tims Line." << std::endl;
        //             p.setsentToDCTL(false);
        //             p.setDCTLtimes(0);
        //             p.setOSAPcollect(true);
        //         } else {
        //             if (p.getDCTLtimes() == 2) {
        //                 std::cout << "You must pay $50 (input 1) or use a Roll Up the Rim cup (input 2) to leave." << std::endl;
        //                 std::cout << "Input: ";
        //                 std::cin >> choice;
        //                 while (choice != 1 && choice != 2) {
        //                     std::cout << std::endl << "Invalid input. Please try again." << std::endl;
        //                     std::cout << "Input: ";
        //                     std::cin >> choice;
        //                 }
        //                 if (choice == 1) {
        //                     p.addCash(-50);
        //                     std::cout << "You paid $50 and you may leave the DC Tims Line." << std::endl;
        //                     p.setsentToDCTL(false);
        //                     p.setDCTLtimes(0);
        //                     p.setOSAPcollect(true);
        //                     //move???
        //                 } else {
        //                     std::cout << "You used a Roll Up the Rim cup and left DC Tims Line." << std::endl;
        //                     p.setsentToDCTL(false);
        //                     p.setDCTLtimes(0);
        //                     p.setRURCup(p.getRURCup() - 1);
        //                     // game->setActiverRim(game->getActiverRim() - 1);
        //                     p.setOSAPcollect(true);
        //                     //move???
        //                 }
        //             } else {
        //                 std::cout << "Unfortunately, you will stay in DC Tims Line." << std::endl;
        //                 p.setDCTLtimes(p.getDCTLtimes() + 1);
        //             }
        //         }
        //     } else if (choice == 1) {
        //         p.addCash(-50);
        //         std::cout << "You paid $50 and you may leave the DC Tims Line." << std::endl;
        //         p.setsentToDCTL(false);
        //         p.setDCTLtimes(0);
        //         p.setOSAPcollect(true);
        //         //move???
        //     } else {
        //         std::cout << "You used a Roll Up the Rim cup and left DC Tims Line." << std::endl;
        //         p.setsentToDCTL(false);
        //         p.setDCTLtimes(0);
        //         p.setRURCup(p.getRURCup() - 1);
        //         game->setActiverRim(game->getActiverRim() - 1);
        //         p.setOSAPcollect(true);
        //         //move???
        //     }
        // }
    }
};

#endif
