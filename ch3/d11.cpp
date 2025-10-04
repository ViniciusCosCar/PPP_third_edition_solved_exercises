#include <algorithm>
#include <iostream>
#include <vector>

// conversion factors to meters
constexpr double cm2m = 1.0 / 100, in2m = 2.54 / 100, ft2m = 30.48 / 100;

int main(void) {
  // read double and it's units
  std::cout << "Enter number followed by it's units ('cm', 'm', 'in' or 'ft')."
            << " If other unit is given, the program will assume to "
               "be in meters. If no unit is given, the program will assume "
               "the next input to be the unit.\n"
            << "To exit, type <C-Z> if you are on Windows or <C-D> if you are "
               "on a Linux/Mac machine."
            << std::endl;

  double n, largest, smallest, sum = 0;
  int n_values = 0;
  std::string unit = "";

  /*
   * TODO: Handle cases where user types a number and enter.
   * The user migh assume that he given a value which will be interpreted to
   * be in meters, but in reality, the next number will be considered it's unit,
   * since no input has been given the "while" loop does not exit the condition
   * and so reads the next value into "units"
   * */
  std::vector<double> numbers; // keep record of every number given in meters
  while (std::cin >> n >> unit) {
    n_values++; // update number of values given

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
      std::cout << "Unknown or no unit was given ('" << unit
                << "'): Considering that '" << n
                << "' was "
                   "given in meters (m)\n";

    numbers.push_back(n); // add number in meters to record
    sum += n;             // increment by the number in meters

    // uptade "largest" and "smallest" depending on the value (m)
    if (n > largest || n_values == 1)
      largest = n;
    if (n < smallest || n_values == 1)
      smallest = n;
  }
  unit = "m";

  // sort record
  std::sort(numbers.begin(), numbers.end());

  // print numbers given
  std::cout << "Numbers given" << std::endl;
  for (double ni : numbers)
    std::cout << ni << " ";
  std::cout << " (m)" << std::endl;

  // print results
  std::cout << "Number of values given: " << n_values << "\n"
            << "Sum of values given: " << sum << " " << unit << "\n"
            << "Largest: " << largest << " " << unit << "\n"
            << "Smallest: " << smallest << " " << unit << std::endl;
}
