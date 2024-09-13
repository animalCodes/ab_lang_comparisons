#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        cerr << "No number specified, exiting.\n";
        return 1;
    }

    int num = atoi(argv[1]);
    // `atoi` will return 0 if unable to convert input to an int, which is a
    // problem here as 0 is valid input. To get around this check if input is
    // also '0'. (`argv[1][0]` will get the first character of the *second*
    // argument)
    if (num == 0 && argv[1][0] != '0') {
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
