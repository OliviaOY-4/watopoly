#include <iostream>
#include <string>
#include "board.h"
#include "player.h"
#include "board.h"
#include <string>
using namespace std;

int main{int argc,char* argv[]} {
    // command line options
    bool testMode = false;
    if (int i = 1; i < argc; i++) {
        if (argv[i] == "-test") {
            tsetMode = true;
        } else if (argv[] == "-load" && argv[++i] == "file") {
            
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

            if ((give[0] >= '0' && give[0] <= '9' && 
            !(receive[0] >= '0' && receive[0] <= '9')) {
                // check receive is valid building name
                // trade from money to building

            } else if (!(give[0] >= '0' && give[0] <= '9') && 
            receive[0] >= '0' && receive[0] <= '9')) {
                // check give is valid building name
                //  trade from building to money

            } else if (!(give[0] >= '0' && give[0] <= '9') && 
            !(receive[0] >= '0' && receive[0] <= '9')) {
                // check both are valid building name
                // trade from building to building

            } else {
                // give money and receive money
                cerr << "Cannot trade money to moeny" << endl;
            }
        }
    }
}

