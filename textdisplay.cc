#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay(int n): gridSize(n) {
    theDisplay = new char*[n];
    for (int i = 0; i < n; ++i) {
        theDisplay[i] = new char[n];
        for (int j = 0; j < n; ++j) {
            theDisplay[i][j] = '0';
        }
    }
}

vector<pair<int, string>> type1 = {
    {0, "|COLLECT|"}, //OSAP

    {2, "|SLC    "},
    // {3, "ML     "},
    {4, "|TUITION"},
    {5, "|MKV    "},
    // {6, "ECH    "},
    {7, "|NEEDLES"},
    // {8, "PAS    "},
    // {9, "HH     "},
    {10, "|DC Tims"}, // Line
    // {11, "RCH    "},
    {12, "|PAC    |"},
    // {13, "DWE    "},
    // {14, "CPH    "},
    {15, "|UWP    |"},
    // {16, "LHI    "},
    {17, "|SLC    |"},
    // {18, "BMH    "},
    // {19, "OPT    "},
    {20, "|Goose  |"},//Nesting
    // {21, "EV1    "},
    {22, "NEEDLES|"},
    // {23, "EV2    "},
    // {24, "EV3    "},
    {25, "V1     |"},
    // {26, "PHYS   "},
    // {27, "B1     "},
    {28, "CIF    |"},
    // {29, "B2     "},
    {30, "Go To  |"}, //TIMS
    // {31, "EIT    "},
    // {32, "ESC    "},
    {33, "|SLC    |"},
    // {34, "C2     "},
    {35, "|REV    |"},
    {36, "|NEEDLES|"}, //HALL
    // {37, "MC     "},
    {38, "|COOP   |"},//FEE
    // {39, "DC     "}
};

vector<pair<int, string>> type2 = {
    {1, "|AL     "},
    {3, "|ML     "},
    {6, "|ECH    "},
    {8, "|PAS    "},
    {9, "|HH     "},
    {11, "|RCH    |"},
    {13, "|DWE    |"},
    {14, "|CPH    |"},
    {16, "|LHI    |"},
    {18, "|BMH    |"},
    {19, "|OPT    |"},
    {21, "EV1    |"},
    {23, "EV2    |"},
    {24, "EV3    |"},
    {26, "PHYS   |"},
    {27, "B1     |"},
    {29, "B2     |"},
    {31, "|EIT    |"},
    {32, "|ESC    |"},
    {34, "|C2     |"},
    {37, "|MC     |"},
    {39, "|DC     |"}
}


TextDisplay::TextDisplay(){
    string boarder = "_________";
    string endboarder = "|_______|";
    string space = "|       |";
    string space2 = "       |";
    string line = "|-------|";
    string dC = "|Line   |";
    string goose = "|Nesting|";
    string ne = "|HALL   |";
    string tims = "|Tims   |";
    string coop = "|FEE    |";
    string osap = "|OSAP   |";

    for(int i = 0; i < 40; i++){
        auto it = type1.find(i);
        if(it != type1.end()){
            if(it->second == "COLLECT"){
                boardMap[i][0]=boarder;
                boardMap[i][1]="|"+it->second+"|";
                boardMap[i][2]=osap;
                boardMap[i][3]=space;
                boardMap[i][4]=space;
                boardMap[i][5]=endboarder;
            }else if(it->second == "DC Tims"){
                boardMap[i][0]=boarder;
                boardMap[i][1]="|"+it->second+"|";
                boardMap[i][2]="|"+dC + "|";
                boardMap[i][3]=space;
                boardMap[i][4]=space;
                boardMap[i][5]=endboarder;
            }else if(it->second == "Goose  "){
                boardMap[i][0]=boarder;
                boardMap[i][1]="|"+it->second+"|";
                boardMap[i][2]="|"+ goose+"|";
                boardMap[i][3]=space;
                boardMap[i][4]=space;
                boardMap[i][5]=endboarder;
            }else if(it->second == "Go To  "){
                boardMap[i][0]=boarder;
                boardMap[i][1]="|"+it->second+"|";
                boardMap[i][2]="|"+ tims + "|";
                boardMap[i][3]=space;
                boardMap[i][4]=space;
                boardMap[i][5]=endboarder;
            }else if(it->second == "NEEDLES"){
                boardMap[i][0]=boarder;
                boardMap[i][1]="|"+it->second+"|";
                boardMap[i][2]="|"+ ne + "|";
                boardMap[i][3]=space;
                boardMap[i][4]=space;
                boardMap[i][5]=endboarder;
            }else if(it->second == "COOP   "){
                boardMap[i][0]=boarder;
                boardMap[i][1]="|"+it->second+"|";
                boardMap[i][2]="|"+ coop + "|";
                boardMap[i][3]=space;
                boardMap[i][4]=space;
                boardMap[i][5]=endboarder;
            }else{
                boardMap[i][0]=boarder;
                boardMap[i][1]="|"+it->second+"|";
                boardMap[i][2]=space;
                boardMap[i][3]=space;
                boardMap[i][4]=space;
                boardMap[i][5]=endboarder;
            }
        }else{
            it = type2.find(i);
            boardMap[i][0]=boarder;
            boardMap[i][1]=space;
            boardMap[i][2]=line;
            boardMap[i][3]="|"+ it->second + "|";
            boardMap[i][4]=space;
            boardMap[i][5]=endboarder;
        }
    }
}

void TextDisplay::addPlayer(int pos, char symbol){
    for(int i = 1; i < 8; i+=2){
            if(boardMap[pos][4][i] == ' '){
                boardMap[pos][4][i] = symbol;
                return;
            }else if(boardMap[pos][5][i] == ' '){
                boardMap[pos][5][i] = symbol;
                return;
            }
    }
}
void TextDisplay::deletePlayer(int pos, char symbol){
    // char symbol = name[0];
    for(int i = 1; i < 8; i+=2){
            if(boardMap[pos][4][i] == symbol){
                boardMap[pos][4][i] = ' ';
                return;
            }else if(boardMap[pos][5][i] == symbol){
                boardMap[pos][5][i] = ' ';
                return;
            }
    }
}

void TextDisplay::addImprovement(board& a){
    int improvementL=a.getImprovementLevel();
    int pos = a.getPosition();
    string replace = "|       |";
    for(int i = 1; i < improvementL - 1; i++){
        replace[i] = "I";
    }
    boardMap[pos][1]=replace;
}

void TextDisplay::drawBoard(std::ostream& out){
    string empty = "       ";
    for(int i = 20; i <31; i++){
        for(int j = 0; j < 7; j++){
            out<<board[i][j];
        }
        out<<"\n";
    }
    for(int i = 19; i > 10; i--){
        for(int j = 0; j < 7; j++){
            out<<board[i][j];
            out<<setw(90);
            out<<board[50-i][j];
            out << "\n";
        }
        out<<"\n";
    }
    for(int i = 10; i >=0; i--){
        for(int j = 0; j < 7; j++){
            out<<board[i][j];
        }
        out<<"\n";
    }
}

void TextDisplay::TextDisplay(){
     boardMap={
        "_________________________________________________________________________________________\n",
        "|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GO TO  |\n",
        "|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |\n",
        "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |\n",
        "|       |       |       |       |       |       |       |       |       |       |       |\n",
        "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n",
        "|       |                                                                       |       |\n",
        "|-------|                                                                       |-------|\n",
        "|OPT    |                                                                       |EIT    |\n",
        "|       |                                                                       |       |\n",
        "|_______|                                                                       |_______|\n",
        "|       |                                                                       |       |\n",
        "|-------|                                                                       |-------|\n",
        "|BMH    |                                                                       |ESC    |\n",
        "|       |                                                                       |       |\n",
        "|_______|                                                                       |_______|\n",
        "|SLC    |                                                                       |SLC    |\n",
        "|       |                                                                       |       |\n",
        "|       |                                                                       |       |\n",
        "|       |                                                                       |       |\n",
        "|_______|                                                                       |_______|\n",
        "|       |                                                                       |       |\n",
        "|-------|                                                                       |-------|\n",
        "|LHI    |                                                                       |C2     |\n",
        "|       |              _______________________________________________          |       |\n",
        "|_______|             |                                               |         |_______|\n",
        "|UWP    |             | #   #  ##  #####   ###   ###   #     #     #  |         |REV    |\n",
        "|       |             | #   # #  #   #    #   #  #  #  #     #     #  |         |       |\n",
        "|       |             | # # # ####   #    #   #  ###   #      #   #   |         |       |\n",
        "|       |             | # # # #  #   #    #   #  #     #        #     |         |       |\n",
        "|_______|             | ##### #  #   #     ###   #     ####     #     |         |_______|\n",
        "|       |             |_______________________________________________|         |NEDDLES|\n",
        "|-------|                                                                       |HALL   |\n",
        "|CPH    |                                                                       |       |\n",
        "|       |                                                                       |       |\n",
        "|_______|                                                                       |_______|\n",
        "|       |                                                                       |       |\n",
        "|-------|                                                                       |-------|\n",
        "|DWE    |                                                                       |MC     |\n",
        "|       |                                                                       |       |\n",
        "|_______|                                                                       |_______|\n",
        "|PAC    |                                                                       |COOP   |\n",
        "|       |                                                                       |FEE    |\n",
        "|       |                                                                       |       |\n",
        "|       |                                                                       |       |\n",
        "|_______|                                                                       |_______|\n",
        "|       |                                                                       |       |\n",
        "|-------|                                                                       |-------|\n",
        "|RCH    |                                                                       |DC     |\n",
        "|       |                                                                       |       |\n",
        "|_______|_______________________________________________________________________|_______|\n",
        "|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|\n",
        "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |\n",
        "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |\n",
        "|       |       |       |       |       |       |       |       |       |       |       |\n",
        "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n",
    }
}

void TextDisplay::addPlayer(int pos, char symbol){
    //h,w
    vector<pair<int,int>> playerpos = {{54,81},{54,73},{54,65},{54,57},{54,49},{54,41},{54,33},{54,25},{54,17},{54,9},{54,1},
                                 {49,1}, {44,1},{39,1},{34,1},{29,1},{24,1},{19,1},{14,1},{9,1},{4,1},{4,9},{4,17},{4,25},
                                 {4,33},{4,41},{4,49},{4,57},{4,65},{4,73},{4,81},
                                 {9,81},{14,81},{19,81},{24,81},{29,81},
                                 {34,81},{39,81},{44,81},{49,81}
                                };
    vector<pair<int,int>> impropos = {{51,81},{51,73},{51,65},{51,57},{51,49},{51,41},{51,33},{51,25},{51,17},{51,9},{51,1},
                                 {46,1}, {41,1},{36,1},{31,1},{26,1},{21,1},{16,1},{11,1},{6,1},{1,1},{1,9},{1,17},{1,25},
                                 {1,33},{1,41},{1,49},{1,57},{1,65},{1,73},{1,81},
                                 {6,81},{11,81},{16,81},{21,81},{26,81},
                                 {31,81},{36,81},{41,81},{46,81}
                                };

        auto it = playerpos[pos];
        int h = it->first;
        int w = it->second;
        while(boardMap[h][w]!=' '){
            w++;
        }
        boardMap[h][w] = symbol;
    
}
void TextDisplay::deletePlayer(int pos, char symbol){
        auto it = playerpos[pos];
        int h = it->first;
        int w = it->second;
        while(boardMap[h][w]!=symbol){
            w++;
        }
        boardMap[h][w] = ' ';
}

void TextDisplay::addImprovement(board& a){
    int improvementL=a.getImprovementLevel();
    int pos = a.getPosition();
        auto it = impropos[pos];
        int h = it->first;
        int w = it->second;
        for(int i = 0; i<improvementL; i++){
            if(boardMap[h][w+i-1]==' '){
                boardMap[h][w+i-1]='I';
            }
        }
}
void TextDisplay::removeImprovement(board& a){
    int improvementL=a.getImprovementLevel();
    int pos = a.getPosition();
        auto it = impropos[pos];
        int h = it->first;
        int w = it->second+4;
        for(int i = w; i >= improvementL+it->second; i++){
            if(boardMap[h][i]=='I'){
                boardMap[h][i]=' ';
            }
        }
}


void TextDisplay::drawBoard(std::ostream& out, vector<Player*> player, vector<board*> board){
    for (auto it : player) {
        int pos = it->getPosition();
        char symbol = it->getSymbol();
        addPlayer(pos, symbol);
    }
    for  (auto it1 : board) {
        addImprovement(*it1);
    }
    for(int i = 0; i<boardMap.size(); i++){
        out<<boardMap[i];
    }
    out<<endl;
}
