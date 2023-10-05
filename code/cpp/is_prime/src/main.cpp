#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        cout << "No argument specified, exiting.\n";
        return 1;
    }

    int num = atoi(argv[1]);
    if (num == 0 && *argv[1] != '0') {
        cout << "Unable to convert \""
             << argv[1] 
             << "\" to a number, exiting.\n";
        return 2;
    }

    // Do the easy checks first ..
    if (num < 2 || num > 2 && num % 2 == 0 || num > 3 && num % 3 == 0) {
        cout << "False\n";
        return 0;
    }
    
    // Trial division time
    for (int divisor = 5; divisor*divisor < num; divisor += 6) {
        if (num % divisor == 0 || num % (divisor+2) == 0) {
            cout << "False\n";
            return 0;
        }
    }

    cout << "True\n";

    return 0;
}
