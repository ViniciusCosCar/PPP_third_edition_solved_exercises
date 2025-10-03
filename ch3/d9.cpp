#include <iostream>

// conversion factors to meters
constexpr double cm2m = 1.0 / 100, in2m = 2.54 / 100, ft2m = 30.48 / 100;

int main(void) {
  // read double and it's units
  std::cout << "Enter number followed by it's units ('cm', 'm', 'in' or 'ft')."
            << " If other unit is given, the program will assume to "
               "be in meters.\n"
            << "To exit, type <C-Z> if you are on Windows or <C-D> if you are "
               "on a Linux/Mac machine."
            << std::endl;

  double n, largest, smallest, sum = 0;
  int n_values = 0;
  std::string unit = "";

  /*
   * TODO: Handle cases where user types a number and enter.
   * The user migh assume that he entered a value which will be interpreted to
   * be in meters, but in reality, the next number will be considered it's unit,
   * since no input has been given the "while" loop does not exit the condition
   * and so reads the next value into "units"
   * */
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
    if (n > largest || n_values == 1)
      largest = n;
    if (n < smallest || n_values == 1)
      smallest = n;
  }

  // print the result
  unit = "m";
  std::cout << "Sum of values entered: " << sum << " " << unit << "\n"
            << "Largest: " << largest << " " << unit << "\n"
            << "Smallest = " << smallest << " " << unit << "\n"
            << "Number of values entered: " << n_values << std::endl;
}
