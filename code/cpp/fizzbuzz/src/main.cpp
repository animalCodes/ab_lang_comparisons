#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        cerr << "No number specified, exiting.\n";
        return 1;
    }

    char *end;
    int num = strtol(argv[1], &end, 10);

    // `end` will be set to point to the first nondigit character in `argv[1]`,
    // if there were no digit characters this'll be the start of the string.
    if (end == argv[1]) {
        cerr << argv[1]
             << " cannot be converted into a number, exiting.\n";
        return 1;
    }

    if (num % 3 == 0 && num % 5 == 0) {
        printf("FizzBuzz\n");
        return 0;
    }

    if (num % 3 == 0)
        cout << "Fizz";
    else if (num % 5 == 0)
        cout << "Buzz";
    else
        cout << num;

    cout << "\n";

    return 0;
}
