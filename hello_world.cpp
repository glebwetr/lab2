#include <iostream>
#include <string>

int
main()
{
  std::string name;
  // Запрашиваем имя пользователя через стандартный поток ввода
  std::cout << "Enter your name: ";
  std::cin >> name;
  // Выводим приветствие в стандартный поток вывода
  std::cout << "Hello world from @" << name << std::endl;
  return 0;
}
