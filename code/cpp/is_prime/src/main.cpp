#include <cstdlib>
#include <iostream>
using namespace std;

// C++ is_prime

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        cerr << "No number specified, exiting.\n";
        return 1;
    }

    char *end;
    int num = strtol(argv[1], &end, 10);

    if (end == argv[1]) {
        cerr << '"' << argv[1] << '"'
             << " cannot be converted into a number, exiting.\n";
        return 2;
    }

    if (*end == '.') {
        cout << "False\n";
        return 0;
    }

    if (num < 2 || num > 2 && num % 2 == 0 || num > 3 && num % 3 == 0) {
        cout << "False\n";
        return 0;
    }

    for (int divisor = 5; divisor*divisor <= num; divisor += 6) {
        if (num % divisor == 0 || num % (divisor+2) == 0) {
            cout << "False\n";
            return 0;
        }
    }

    cout << "True\n";

    return 0;
}
