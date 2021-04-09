#include <iostream>
#include <libchessviz/error.h>
using namespace std;
void error(int number)
{
    switch (number) {
    case 1:
        cout << "error1-invalid input" << endl;
        break;
    }
}
