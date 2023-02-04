#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    // Check argument is given
    if (argc <= 1) {
        cout << "No argument specified, exiting.\n";
        return 1;
    }

    // Check argument is valid
    int num = atoi(argv[1]);
    if (num == 0 && *argv[1] != '0') {
        cout << "Unable to convert \""
             << argv[1] 
             << "\" to a number, exiting.\n";
        return 2;
    }

    // Skip if impossible to be prime
    if (num < 2) {
        cout << "False\n";
        return 0;
    }
    
    // Figure out if prime
    for (int divisor = num-1; divisor > 1; divisor--) {
        if (num % divisor == 0) {
            cout << "False\n";
            return 0;
        }
    }

    cout << "True\n";
    return 0;
}
