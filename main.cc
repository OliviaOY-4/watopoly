#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "board.h"
#include "player.h"
#include "board.h"
#include "game.h"
#include "dice.h"
#include "dctimsline.h"
using namespace std;

int main(int argc,char* argv[]) {
    // initialize game
    Game g;

    // command line options
    bool testMode = false;
    bool loadFile = false;
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-test") {
            testMode = true;
        } else if (arg == "-load") {
            if (++i < argc) {
                ifstream f{argv[i]};
                g.load(f);
                cout << endl << "==========================" << endl;
                cout << endl << "==> Current Players: " << endl;
                g.printPlayers();
                cout << endl << "==========================" << endl;
                g.gameStart();
                g.printMap();
                loadFile = true;
            }
        }
    }





    // initialize players
    if (!loadFile){
        int num_of_players = 0;
        cout << endl << "==> " << "Welcome to the game of Monopoly!" << endl;
        cout << endl <<  "==> " << "Number of players must be between 2 and 7." << endl;
        cout << endl <<  "==> " << "Please enter the number of players: " << endl;
        string tmp;
        getline(cin, tmp);
        istringstream iss{tmp};
        iss >> num_of_players;
        for (int i = 0; i < num_of_players; i++) {
            cout << endl << "==> " << "Enter the name of Player " << i + 1 << ": " << endl;
            string name = " ";
            if (getline(cin, name)) {
                if (!g.initPlayer(name)) {
                    cout << endl << "==> " << "Invalid player name, input a valid name: " << endl;
                    i--;
                }
            }
            // g.initPlayer need to check it's a valid name and char
        } 
        cout << endl << "==========================" << endl;
        cout << endl << "==> Current Players: " << endl;
        g.printPlayers();
        cout << endl << "==========================" << endl;
        g.gameStart();
        g.printMap();
    }




    // game start
    string cmd = " ";
    int doubleroll = 0;
    bool rollFlag = false;
    cout << endl << "==> " << "The game begins." << endl;
    while (true) {

        cout << endl << "|-----------------------------------------------------------------------------------------------------------------|" << endl;
        cout <<         "| Commands: [roll], [next], [trade <name> <give> <receive>], [improve <property> buy/sell], [mortgage <prpperty>] |" << endl; 
        cout <<         "|           [unmortgage <property>], [bankrupt], [assets], [all], [save <filename>], [print], [quit]              |" << endl;
        cout <<         "|-----------------------------------------------------------------------------------------------------------------|" << endl;
        cout << endl << "==> " << "Player this turn: " << g.getCurrentPlayer().getName() << endl;
        cout << endl << "==> " << "Please Enter Command: " << endl;
        
        if (g.endGame()) {
            cout << endl << "==> " << "Winner is :" << g.getWinner() << endl;
            break;
        } 

        if (cin.eof()){
            return 0;
        } else if (!(cin>>cmd)) {
            cout << endl << "==> " << "Invalid input." << endl;
            continue;
        }

        if (g.getCurrentPlayer().getCashAmount()<0) {
            // owe to bank;
            g.bankruptcy(g.getCurrentPlayer().getName(), "Bank", g.getCurrentPlayer().getCashAmount());
        }

        
        // In DC Tims Line
        if (cmd == "roll") {
            if (rollFlag) {
                // already rolled
                cout << endl << "==> You cannot roll more." << endl;
                continue;
            }
            if (g.getCurrentPlayer().getsentToDCTL() == true) {
                // if last turn is also at DCTL
                //cout << endl << "You are in DC Tims Line." << endl;
                int n = g.getActiverRim();
                DCTimsLine tmp1{0, "dc times line"};
                Player& p = g.getCurrentPlayer();
                int m = tmp1.action(p, n);
                g.printMap();
                g.setActiverRim(m);
                int movenum = tmp1.getNextMove();
                if (movenum != 0) {
                    g.move(movenum);
                    cout << endl << "==> " << "You cannot roll more." << endl;
                    cout << endl << "==> " << "Enter a command or end your turn by 'next'." << endl;
                    rollFlag = true;
                    continue;
                } else {
                    cout << endl << "==> " << "You can roll to leave." << endl;
                    cout << endl << "==> " << "Enter a command or end your turn by 'next'." << endl;
                    continue;
                }
            }
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
            } 
            cout << endl << "==> " << "Roll result: " << num1 << " " << num2 << endl;
            if (doubleroll >= 2 && num1 == num2) {
                // cout << "==> " << "You have been sent to DC Tims Line." << endl;
                //g.printMap();
                cout << endl << "==> " << "Roll result: " << num1 << " " << num2 << endl;
                g.move(30 - g.getCurrentPlayer().getPosition());
                cout << endl << "==> " << "You can not roll more." << endl;
                cout << endl << "==> " << "Enter a command or end your turn by 'next'." << endl;
                rollFlag = true;
                doubleroll++;
                continue;
            } else {
                g.move(num1 + num2);
            }
            if (num1 == num2 && g.getCurrentPlayer().getsentToDCTL() != true) {
                cout << endl << "==> " << "You rolled double." << endl;
                cout << endl << "==> " << "You can roll again by 'roll'." << endl;
                doubleroll++;
                continue;
            } else {
                cout << endl << "==> " << "You cannot roll more." << endl;
                cout << endl << "==> " << "Enter a command or end your turn by 'next'." << endl;
                rollFlag = true;
                continue;
            }
            
            

        } else if (cmd == "next") {
            // move to next 
            g.nextPlayer();
            cout << endl << "==> " << "It's " << g.getCurrentPlayer().getName() << "'s turn." << endl;
            doubleroll = 0;
            rollFlag = false;
            


        } else if (cmd == "trade") {
            string name = " ";
            string give = " ";
            string receive = " ";
            cin >> name >> give >> receive;
            // check it's a valid player name
            if (!(g.isValidPlayer(name))) {
                cerr << "Invalid Player." << endl;
                continue;
            }

            if ((give[0] >= '0' && give[0] <= '9') && 
            !(receive[0] >= '0' && receive[0] <= '9')) {
                // trade money to building
                // check receive is valid property name 
                if (!(g.isValidProperty(receive))) {
                    cout << endl << "==> " << "Invalid property name." << endl;
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
                    cout << endl << "==> " << "reject" << endl;
                }

            } else if (!(give[0] >= '0' && give[0] <= '9') && 
            (receive[0] >= '0' && receive[0] <= '9')) {
                // trade building to money
                // check give is valid property name
                if (!(g.isValidProperty(give))) {
                    cout << endl << "==> " << "Invalid property name." << endl;
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
                    cout << endl << "==> " << "reject" << endl;
                }              

            } else if (!(give[0] >= '0' && give[0] <= '9') && 
            !(receive[0] >= '0' && receive[0] <= '9')) {
                // trade from building to building
                // check both are valid property name
                if (!(g.isValidProperty(give)) || !(g.isValidProperty(receive))) {
                    cout << endl << "==> " << "Invalid property name." << endl;
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
                    cout << endl << "==> " << "reject" << endl;
                } 

            } else {
                // give money and receive money
                cout << endl << "==> You cannot trade money with money." << endl;
                cout << endl << "==> " << "reject" << endl;
            }

        } else if (cmd == "improve") {
            cout << endl << "==> <Property> buy/sell" << endl;
            string property = " ";
            string behaviour = " ";
            cin >> property >> behaviour;
            // check property is a valid property name
            if (!(g.isValidProperty(property))) {
                cout << endl << "==> " << "Invalid property name." << endl;
                continue;
            }
            //Board& b = g.getBoard(property);

            if (behaviour == "buy") {
                // game function need to check property is a property
                // and player owns it
                // and it can buy improve
                // attempt to buy improvement
                if (!(g.improve(property, true))) {
                    cout << endl << "==> " << "Unable to buy improve." << endl;
                }

            } else if (behaviour == "sell") {
                // game function need to check property is a property
                // and player owns it
                // and it can sell improve
                // attempt to sell improvement
                if (!(g.improve(property, false))) {
                    cout << endl << "==> " << "Unable to sell improve." << endl;
                }

            } else {
                cerr << "Invalid behaviour." << endl;
            } 
            g.printMap();

        } else if (cmd == "mortgage") {
            string property = " ";
            cin >> property;
            // check property is a valid property name
            if (!(g.isValidProperty(property))) {
                cout << endl << "==> " << "Invalid property name." << endl;
                continue;
            }
            //Board& b = g.getBoard(property);

            // attempt to mortgage property
            // check property is owned by player, and can mortgage 
            // (not already mortgaged, has no improvements)
            if (!(g.mortgage(property))) {
                cout << endl << "==> " << "Unable to mortgage." << endl;
                cout << endl << "==> " << "Enter a command or end your turn by 'next'." << endl;
            }

        } else if (cmd == "unmortgage") {
            string property = " ";
            cin >> property;
            // check property is a valid property name
            if (!(g.isValidProperty(property))) {
                cout << endl << "==> " << "Invalid property name." << endl;
                continue;
            }
            //Board& b = g.getBoard(property);

            // attempt to unmortgage property
            // check property used to owned by player, and can unmortgage 
            // (not already unmortgaged)
            if (!(g.unmortgage(property))) {
                cout << endl << "==> " << "Unable to unmortgage." << endl;
            }

        } else if (cmd == "backrupt") {
            // if money is negative, own money
            // if can still sell properties, can't declare
            //bool isBankrupted = g.checkIfBankruptcy();

            // if ( g.getCurrentPlayer->getCashAmount < 0) {
            //     // need to find out who the player own money to 
            //     // (another player or bank), then do someting to properties
            //     // (giving the property to another player, auction, ...)
            //     string name = g.getCurrentPlayer->getName();
            //     g.bankruptcy(name);
            // } else {
            //     cerr << "Cannot declare bankruptcy" << endl;
            // }
            
        } else if (cmd == "assets") {
            // displays the assets of the current player. 
            // Does not work if the player is deciding how to pay Tuition
            // if (!(g.asset())) {
            //     cout << "==> " << "Cannot display your assets at this stage" << endl;
            // }
            g.asset();

        } else if (cmd == "all") {
            // displays the assets of every player. For verifying the 
            // correctness of your transactions. 
            // Does not work if a player is deciding how to pay Tuition. 
            // if (!(g.all())) {
            //     cout << "==> " << "Cannot display everyone's asset at this stage" << endl;
            // }
            g.all();

        } else if (cmd == "save") {
            string filename;
            cin >> filename;
            g.save(filename);

        } else if (cmd == "print") {
            g.printMap();
            
        } else if (cmd == "quit") {
            return 0;

        } else {
            cerr << "==> Invalid Command." << endl;
        }
    }
}
