/*
 * If we define the median of a sequence as ‘‘a number so that exactly as many
 elements come before it in the sequence as come after it,’’ fix the program in
 §3.6.3 so that it always prints out a median. Hint: A median need not be an
 element of the sequence.
 * */

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::vector<double> temps; // temperatures
  for (double temp; std::cin >> temp;)
    temps.push_back(temp); // put temp into vector

  // sort
  std::sort(temps.begin(), temps.end());

  int size = temps.size(); // get vector's size
  double median;

  // calculate median
  if (size % 2 == 0) // even
    median = (temps[(size / 2) - 1] + temps[size / 2]) /
             2; // meadian should be the mean of two numbers in the center of
                // the vector

  else                        // odd
    median = temps[size / 2]; // median should be just the middle value. Using
                              // truncation to our favor

  std::cout << "Median -> " << median << std::endl; // print result
}
