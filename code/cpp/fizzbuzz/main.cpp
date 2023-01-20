#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    // argc = "ARGument Count"
    if (argc <= 1) {
        cout << "No argument specified, exiting.";
        // What the main method returns will be the exit code, so no need for 
        // an exit() call.
        return 1;
    }

    int num = atoi(argv[1]);

    // `atoi` will return 0 if unable to convert input to an int, which is a problem
    // here as 0 is valid input. To get around this check if input is also '0'.
    // (`*argv[1]` will get the first character of the *second* argument..
    // somehow)
    if (num == 0 && *argv[1] != '0') {
        cout << "Unable to convert \""
             << argv[1] 
             << "\" to a number, exiting.";

        return 2;
    }

    // Trying to avoid having to concatenate any strings.
    if (num != 0) {
        // 'FizzBuzz NUMber', if number is divisible by 3 or 5.
        bool fbnum = false;
        if (num % 3 == 0) {
            cout << "Fizz";
            fbnum = true;
        }
        if (num % 5 == 0) {
            cout << "Buzz";
            fbnum = true;
        }
        // If not divisible by 3 or 5, print number.
        if (!fbnum) {
            cout << num;
        }
        // Special case for 0
    } else {cout << num;}

    return 0;
}
