#include <iostream>
#include <libchessviz/locate.h>
#include <libchessviz/output.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
    char chessboard[11][11]
            = {"1rnbqkbnr",
               "2pppppppp",
               "3        ",
               "4        ",
               "5        ",
               "6        ",
               "7PPPPPPPP",
               "8RNBQKBNR"};
    output(chessboard);
    while (1) {
        locate(chessboard);
    }
    return 0;
}


    cout << "8 r n b q k b n r\n7 p p p p p p p p\n6\n5\n4\n3\n2 P P P P P P P P\n1 R N B Q K B N R\n  a b c d e f g h " << endl;

    return 0;
}

