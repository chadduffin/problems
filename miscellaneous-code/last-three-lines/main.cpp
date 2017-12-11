#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
  int i = 0;
  std::ifstream in("input");

  if (in.is_open()) {
    std::string line, lines[3];

    while (std::getline(in, line)) {
      if (!line.empty()) {
        lines[i] = line;
        i = (i+1)%3;
      } else {
        break;
      }
    }

    std::cout << lines[i] << std::endl
              << lines[(i+1)%3] << std::endl
              << lines[(i+2)%3] << std::endl;
  }

  return 0;
}

