#include <iostream>

// conversion factors to meters
constexpr int cm2m = 1 / 100;
constexpr double in2m = 2.54 / 100;
constexpr double ft2m = 30.48 / 100;

int main(void) {
  // read double and it's units
  std::cout << "Enter number followed by it's units ('cm', 'm', 'in' or 'ft', "
               "if no, or invalid, unit is given, the program will assume to "
               "be in 'm')"
            << std::endl;

  double n, largest, smallest, sum = 0, n_values = 1;
  std::string unit;

  // read input
  std::cin >> n >> unit;
  largest = smallest = n;
  while (std::cin >> n >> unit) {
    n_values++; // update number of values entered

    // conversion system
    if (unit == "m")
      n = n;
    else if (unit == "cm")
      n = n * cm2m;
    else if (unit == "in")
      n = n * in2m;
    else if (unit == "ft")
      n = n * ft2m;
    else
      std::cout << "Unknown or no unit was given: Considering that value was "
                   "given in meters\n";

    sum += n; // sum the converted values

    // uptade "largest" and "smallest" depending on the value converted
    if (n > largest)
      largest = n;
    else if (n < smallest)
      smallest = n;
  }

  // print the result
  unit = "m";
  std::cout << "Sum of values entered: " << sum << unit
            << "Largest: " << largest << unit << "Smallest = " << smallest
            << unit << "Number of values entered: " << n_values << std::endl;
}
