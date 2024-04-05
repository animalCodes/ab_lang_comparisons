#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        cerr << "No argument specified, exiting.\n";
        return 1;
    }

    int num = atoi(argv[1]);
    // `atoi` will return 0 if unable to convert input to an int, which is a problem
    // here as 0 is valid input. To get around this check if input is also '0'.
    // (`argv[1][0]` will get the first character of the *second* argument)
    if (num == 0 && argv[1][0] != '0') {
        cerr << "Unable to convert \""
             << argv[1] 
             << "\" to a number, exiting.\n";
        return 2;
    }

    if (num != 0) { // Could just do `!num`, but that doesn't feel right in C++
        // 'FizzBuzz NUMber', whether number is divisible by 3 or 5.
        bool fb_num = false;
        if (num % 3 == 0) {
            cout << "Fizz";
            fb_num = true;
        }
        if (num % 5 == 0) {
            cout << "Buzz";
            fb_num = true;
        }
        if (!fb_num) {
            cout << num;
        }
        // Special case for 0
    } else {cout << num;}

    cout << "\n";

    return 0;
}
