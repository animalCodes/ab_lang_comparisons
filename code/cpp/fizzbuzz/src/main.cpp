#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

// C++ fizzbuzz

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        cerr << "No number specified, exiting.\n";
        return 1;
    }

    char *end;
    double n = strtof(argv[1], &end);

    if (end == argv[1]) {
        cerr << '"' << argv[1] << '"'
             << " cannot be converted into a number, exiting.\n";
        return 1;
    }

    if (floor(n) != n) {
        cerr << argv[1] << "\n";
        return 1;
    }

    int m = n;

    if (m % 3 == 0 && m % 5 == 0) {
        printf("FizzBuzz\n");
        return 0;
    }

    if (m % 3 == 0)
        cout << "Fizz";
    else if (m % 5 == 0)
        cout << "Buzz";
    else
        cout << m;

    cout << "\n";

    return 0;
}
