/*
 *  Write a program that reads a string from input and then, for each character
 read, prints out the character and its integer value on a line.
 * */

#include <iostream>

int main(void) {
  for (std::string s; std::cin >> s;) { // read input string
    for (char c : s) {                  // read each character of input string
      std::cout << c << " " << int(c)
                << std::endl; // print character and integer value
    }
  }
}
