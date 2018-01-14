#include <iostream>
#include <fstream>
#include <string>

void reverse(std::string &to_reverse);

int main(int argc, char **argv) {
  int i = 0, j = 0;
  std::string buffer, lines[3];
  std::ifstream in(argv[1], std::ios::binary);

  if (in.is_open()) {
    while (std::getline(in, buffer)) {
      if (!buffer.empty()) {
        lines[i] = buffer;
    
        i = (i < 2) ? i+1 : 0;
      }
    }
  }

  reverse(lines[i]);
  reverse(lines[(i+1)%3]);
  reverse(lines[(i+2)%3]);

  std::cout << lines[i] << " "
            << lines[(i+1)%3] << " "
            << lines[(i+2)%3] << " "
            << std::endl;

  return 0;
}

void reverse(std::string &to_reverse) {
  unsigned int i = 0, j = to_reverse.size()-1;

  while (i < j) {
    to_reverse.at(i) ^= to_reverse.at(j);
    to_reverse.at(j) ^= to_reverse.at(i);
    to_reverse.at(i) ^= to_reverse.at(j);

    i++;
    j--;
  }
}
