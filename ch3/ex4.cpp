/*
 * Read a sequence of double values into a vector. Think of each value as the
distance between two cities along a given route. Compute and print the total
distance (the sum of all dis tances). Find and print the smallest and greatest
distance between two neighboring cities. Find and print the mean distance
between two neighboring cities.
 * */

#include <iostream>
#include <vector>

int main(void) {
  std::vector<double> distances; // keep record of distances
  double sum_d = 0, d, greatest_d, smallest_d;
  bool first_input = true; // true if it is the first input

  std::cout << "Enter distances of neighboring cities. Then the program will "
               "print distance of the whole trajectorie, will find the "
               "greatest and smallest distance between two neighboring cities "
               "and calculate the mean of all the distances given."
            << std::endl;

  // read distances
  for (d; std::cin >> d;) {
    if (first_input) { // in case of first input, initialize greatest and
                       // smallest distances recorded to it
      greatest_d = smallest_d = d;
      first_input = false;

    } else { // update greatest and smallest distances recorded
      if (d > greatest_d)
        greatest_d = d;
      else if (d < smallest_d)
        smallest_d = d;
    }

    // increment "d" to "sum_d"
    sum_d += d;

    // add distance to record
    distances.push_back(d);
  }

  // print results
  std::cout << "Total distance -> " << sum_d << "\n"
            << "Smallest distance -> " << smallest_d << "\n"
            << "Greatest distance -> " << greatest_d << "\n"
            << "Mean -> " << sum_d / distances.size() << std::endl;
}
