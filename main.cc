#include <iostream>
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
        }
    }
}