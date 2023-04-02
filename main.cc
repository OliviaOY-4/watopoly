#include <iostream>
#include <string>
#include "board.h"
#include "player.h"
#include "board.h"
#include "game.h"
using namespace std;

int main(int argc,char* argv[]) {
    // command line options
    bool testMode = false;
    for (int i = 1; i < argc; i++) {
        if (argv[i] == "-test") {
            testMode = true;
        } else if (argv[i] == "-load" && argv[i + 1] == "file") {
            
            // load file operations

        }
    }

    // initialization
    Game g;
    string cmd = " ";
    while (cin >> cmd) {
        if (cmd == "roll") {
            // roll dice and move

        } else if (cmd == "next") {
            // move to next 
            
        } else if (cmd == "trade") {
            string name = " ";
            string give = " ";
            string receive = " ";
            cin >> name >> give >> receive;
            // check it's a valid player name

            if ((give[0] >= '0' && give[0] <= '9') && 
            !(receive[0] >= '0' && receive[0] <= '9')) {
                // check receive is valid building name
                // attempt to trade from money to building

            } else if (!(give[0] >= '0' && give[0] <= '9') && 
            (receive[0] >= '0' && receive[0] <= '9')) {
                // check give is valid building name
                // attempt to trade from building to money

            } else if (!(give[0] >= '0' && give[0] <= '9') && 
            !(receive[0] >= '0' && receive[0] <= '9')) {
                // check both are valid building name
                // attempt to trade from building to building

            } else {
                // give money and receive money
                cerr << "Cannot trade money to moeny" << endl;
            }

        } else if (cmd == "improve") {
            string property = " ";
            string behaviour = " ";
            cin >> property >> behaviour;

            if (behaviour == "buy") {
                // check property is a valid property name
                // attempt to buy improvement
            } else if (behaviour == "sell") {
                // check property is a valid property name
                // attempt to sell improvement
            } else {
                cerr << "Invalid behaviour";
            }

        } else if (cmd == "mortgage") {
            string property = " ";
            cin >> property;
            // check property is a valid property name
            // attempt to mortgage property

        } else if (cmd == "unmortgage") {
            string property = " ";
            cin >> property;
            // check property is a valid property name
            // attempt to unmortgage property

        } else if (cmd == "backrupt") {
            bool isBankrupted = false;
            // check if player must pay more money then they currently have.
            if (isBankrupted) {
                // remove player
            } else {
                cerr << "Cannot declare bankruptcy" << endl;
            }
            
        } else if (cmd == "assets") {
            // displays the assets of the current player. Does not work if the player is deciding how to pay Tuition.

        } else if (cmd == "all") {
            // displays the assets of every player. For verifying the correctness of your transactions. Does not work if a player is
            //    deciding how to pay Tuition.  

        } else if (cmd == "save") {
            string filename;
            cin >> filename;
        }
    }
}

