#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "board.h"
#include "player.h"
#include "board.h"
#include "game.h"
#include "dice.h"
using namespace std;

int main(int argc,char* argv[]) {
    // initialize game
    Game g;

    // command line options
    bool testMode = false;
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-test") {
            testMode = true;
        } else if (arg == "-load") {
            if (++i < argc) {
                ifstream f{argv[i]};
                g.load(f);
            }
        }
    }

    // initialize players
    int num_of_players = 0;
    cout << "Welcome to the game of Monopoly!" << endl;
    cout << "Number of players must be between 2 and 7." << endl;
    cout << "Please enter the number of players: " << endl;
    string tmp;
    getline(cin, tmp);
    istringstream iss{tmp};
    iss >> num_of_players;
    for (int i = 0; i < num_of_players; i++) {
        cout << "Enter the name of Player " << i + 1 << ": " << endl;
        string name = " ";
        if (getline(cin, name)) {
            if (!g.initPlayer(name)) {
                cout << "Invalid player name, input a valid name: " << endl;
                i--;
            }
        }
        // g.initPlayer need to check it's a valid name and char
    } 
    cout << endl << "Current Players: " << endl;
    g.printPlayers();
    g.gameStart();
    g.printMap();

    // game start
    string cmd = " ";
    int doubleroll = 0;
    cout << "It's " << g.getCurrentPlayer().getName() << "'s turn." << endl;
    while (cin >> cmd) {
        
        if (g.endGame()) {
            cout << "Winner is :" << g.getWinner() << endl;
            break;
        } cout << "It's " << g.getCurrentPlayer().getName() << "'s turn." << endl;
        cout << "Enter a command: " << endl;

        if (cmd == "roll") {
            
            // roll dice and move
            // check if has passed over OSAP
            // if don't buy, auction.
            int num1 = 0;
            int num2 = 0;
            if (testMode) {
                cin >> num1 >> num2;
            } else {
                num1 = g.roll();
                num2 = g.roll();
                cout << num1 << " " << num2 << endl;
            } g.printMap();
            cout << "You rolled " << num1 + num2 << endl;
            if (doubleroll == 3 && (num1 + num2) % 2 == 0) {
                cout << "You have been sent to DC Tims Line." << endl;
                g.move(10);
                cout << "It is now the next player's turn. Enter 'next'." << endl;
                continue;
            } else g.move(num1 + num2);
            if (num1 == num2) {
                cout << "You can roll again. Enter 'roll'." << endl;
                doubleroll++;
                continue;
            } else {
                cout << "It is now the next player's turn. Enter 'next'." << endl;
                continue;
            }
            

        } else if (cmd == "next") {
            // move to next 
            g.nextPlayer();
            doubleroll = 0;
            
        } else if (cmd == "trade") {
            string name = " ";
            string give = " ";
            string receive = " ";
            cin >> name >> give >> receive;
            // check it's a valid player name
            if (!(g.isValidPlayer(name))) {
                cerr << "Invalid Player" << endl;
                continue;
            }

            if ((give[0] >= '0' && give[0] <= '9') && 
            !(receive[0] >= '0' && receive[0] <= '9')) {
                // trade money to building
                // check receive is valid property name 
                if (!(g.isValidProperty(receive))) {
                    cout << "Invalid property name" << endl;
                    continue;
                }

                Player& p = g.getPlayer(name);
                istringstream iss{give};
                int money = 0;
                iss >> money;
                //Board& b = g.getBoard(receive);

                // game functin need to check:
                // property is owned by the given player
                // and all properties in the monopoly have no improvements
                // and player need to have enough money
                //string name = b.getName();
                if (!(g.trade(p, money, receive))) {
                    cout << "reject" << endl;
                }

            } else if (!(give[0] >= '0' && give[0] <= '9') && 
            (receive[0] >= '0' && receive[0] <= '9')) {
                // trade building to money
                // check give is valid property name
                if (!(g.isValidProperty(give))) {
                    cout << "Invalid property name" << endl;
                    continue;
                }

                Player& p = g.getPlayer(name);
                //Board& b = g.getBoard(give);
                istringstream iss{receive};
                int money = 0;
                iss >> money;

                // game functin need to check:
                // property is owned by the given player
                // and all properties in the monopoly have no improvements
                // and player need to have enough money
                //string name = b.getName();
                if (!(g.trade(p, give, money))) {
                    cout << "reject" << endl;
                }              

            } else if (!(give[0] >= '0' && give[0] <= '9') && 
            !(receive[0] >= '0' && receive[0] <= '9')) {
                // trade from building to building
                // check both are valid property name
                if (!(g.isValidProperty(give)) || !(g.isValidProperty(receive))) {
                    cout << "Invalid property name" << endl;
                    continue;
                }

                Player& p = g.getPlayer(name);
                //Board& b_give = g.getBoard(give);
                //Board& b_receive = g.getBoard(give);

                // game functin need to check:
                // property is owned by the given player
                // and all properties in the monopoly have no improvements
                //string name1 = b_give.getName();
                //string name2 = b_receive.getName();
                if (!(g.trade(p, give, receive))) {
                    cout << "reject" << endl;
                } 

            } else {
                // give money and receive money
                cout << "reject" << endl;
            }

        } else if (cmd == "improve") {
            string property = " ";
            string behaviour = " ";
            cin >> property >> behaviour;
            // check property is a valid property name
            if (!(g.isValidProperty(property))) {
                cout << "Invalid property name" << endl;
                continue;
            }
            //Board& b = g.getBoard(property);

            if (behaviour == "buy") {
                // game function need to check property is a property
                // and player owns it
                // and it can buy improve
                // attempt to buy improvement
                if (!(g.improve(property, true))) {
                    cout << "Unable to buy improve" << endl;
                }

            } else if (behaviour == "sell") {
                // game function need to check property is a property
                // and player owns it
                // and it can sell improve
                // attempt to sell improvement
                if (!(g.improve(property, false))) {
                    cout << "Unable to sell improve" << endl;
                }

            } else {
                cerr << "Invalid behaviour" << endl;
            }

        } else if (cmd == "mortgage") {
            string property = " ";
            cin >> property;
            // check property is a valid property name
            if (!(g.isValidProperty(property))) {
                cout << "Invalid property name" << endl;
                continue;
            }
            //Board& b = g.getBoard(property);

            // attempt to mortgage property
            // check property is owned by player, and can mortgage 
            // (not already mortgaged, has no improvements)
            if (!(g.mortgage(property))) {
                cout << "Unable to mortgage" << endl;
            }

        } else if (cmd == "unmortgage") {
            string property = " ";
            cin >> property;
            // check property is a valid property name
            if (!(g.isValidProperty(property))) {
                cout << "Invalid property name" << endl;
                continue;
            }
            //Board& b = g.getBoard(property);

            // attempt to unmortgage property
            // check property used to owned by player, and can unmortgage 
            // (not already unmortgaged)
            if (!(g.unmortgage(property))) {
                cout << "Unable to unmortgage" << endl;
            }

        } else if (cmd == "backrupt") {
            // if money is negative, own money
            // if can still sell properties, can't declare
            bool isBankrupted = g.checkIfBankruptcy();

            if (isBankrupted) {
                // need to find out who the player own money to 
                // (another player or bank), then do someting to properties
                // (giving the property to another player, auction, ...)
                g.removePlayer();
            } else {
                cerr << "Cannot declare bankruptcy" << endl;
            }
            
        } else if (cmd == "assets") {
            // displays the assets of the current player. 
            // Does not work if the player is deciding how to pay Tuition
            if (!(g.asset())) {
                cout << "Cannot display your assets at this stage" << endl;
            }

        } else if (cmd == "all") {
            // displays the assets of every player. For verifying the 
            // correctness of your transactions. 
            // Does not work if a player is deciding how to pay Tuition. 
             if (!(g.all())) {
                cout << "Cannot display everyone's asset at this stage" << endl;
            }

        } else if (cmd == "save") {
            string filename;
            cin >> filename;
            g.save(filename);

        } else if (cmd == "print") {
            g.printMap();
            
        } else {
            cerr << "Invalid Command" << endl;
        }
    }
}
