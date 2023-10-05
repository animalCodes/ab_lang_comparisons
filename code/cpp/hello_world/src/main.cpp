#include <iostream>

int main() {
  // << = 'Insertion operator'. So this is 'inserting' the text "Hello World!" to std::cout.
  // You could alternatively put "using namespace std;" at the top-level, and just write `cout << ""`. But this is a little more concise.
  std::cout << "Hello World!\n";
  return 0;
}