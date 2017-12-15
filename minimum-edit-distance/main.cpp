#include <string>
#include <iostream>

void minimumEditCount(const std::string &first, const std::string &second);
int minimum(int a, int b, int c);

int main(int argc, char **argv) {
  std::string intention = "intention",
              execution = "execution";

  minimumEditCount(intention, execution);

  return 0;
}

void minimumEditCount(const std::string &first, const std::string &second) {
  int row = first.size()+1,
      col = second.size()+1,
      *editCountMatrix = (int*)calloc(1, sizeof(int)*row*col);

  for (int i = 0; i < col; i++) {
    editCountMatrix[i] = editCountMatrix[i*row] = i;
  }

  for (int i = col; i < row*col; i++) {
    if (i%col == 0) { continue; }
    
    int diagonal = editCountMatrix[i-1-col];

    if (first.at((i/col)-1) != second.at((i%col)-1)) {
      diagonal += 2;
    }

    editCountMatrix[i] = minimum(diagonal, editCountMatrix[i-1]+1, editCountMatrix[i-col]+1);
  }

  std::cout << editCountMatrix[row*col-1] << std::endl;
}

int minimum(int a, int b, int c) {
  return ((a < b) ? ((a < c) ? a : c) : b);
}

