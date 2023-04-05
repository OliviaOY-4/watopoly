#include "textdisplay.h"

TextDisplay::TextDisplay(int n): gridSize(n) {
    theDisplay = new char*[n];
    for (int i = 0; i < n; ++i) {
        theDisplay[i] = new char[n];
        for (int j = 0; j < n; ++j) {
            theDisplay[i][j] = '0';
        }
    }
}


