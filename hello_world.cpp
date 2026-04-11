#include <iostream>
#include <string>

int
main()
{
  std::string name;
  // Request user name from standard input stream.
  std::cout << "Enter your name: ";
  std::cin >> name;
  // Print greeting to standard output stream.
  std::cout << "Hello world from @" << name << std::endl;
  return 0;
}
