#include <vector>
#include <iostream>
#include <algorithm>

void knapsackBestValue(const std::vector< int > &itemWeights,
                       const std::vector< int > &itemValues,
                       int maxWeight);
void outputBacktracking(const std::vector< std::vector< int > > &backtracking,
                        const std::vector< int > &itemWeights,
                        const std::vector< int > &itemValues,
                        int maxWeight);

int main(int argc, char **argv) {
  std::vector< int > itemWeights = {1, 3, 4, 5}, itemValues = {1, 4, 5, 7};

  knapsackBestValue(itemWeights, itemValues, 7);

  return 0;
}

void knapsackBestValue(const std::vector< int > &itemWeights,
                       const std::vector< int > &itemValues,
                       int maxWeight) {
  // create a vector of vectors to act as our floodfill matrix
  std::vector< std::vector< int > > bestValues(itemWeights.size(), std::vector< int >(maxWeight+1, 0.0)),
                                    backtracking(itemWeights.size(), std::vector< int >(maxWeight+1, 0.0));

  // iterate through each item
  for (auto row = bestValues.begin(); row != bestValues.end(); row++) {
    // iterate from 0 to the maximum weight
    for (auto col = row->begin(); col != row->end(); col++) {
      // extract the current item / weight from the iterators
      int currentItem = row-bestValues.begin(),
          currentWeight = col-row->begin(),
          valueIfNoTake = 0.0,
          valueIfTake = 0.0;

      // if we can take this item
      if (itemWeights.at(currentItem) <= currentWeight) {
        valueIfTake += itemValues.at(currentItem);

        // if this is not the first item
        if (currentItem > 0) {
          valueIfTake += bestValues.at(currentItem-1).at(currentWeight-itemWeights.at(currentItem));
        }
      }

      // if this is not the first item, again
      if (currentItem > 0) {
        valueIfNoTake = bestValues.at(currentItem-1).at(currentWeight);
      }

      // figure out if we should take the item, and fill in backtracking
      if (valueIfTake > valueIfNoTake) {
        *col = valueIfTake;
        backtracking.at(currentItem).at(currentWeight) = currentWeight-itemWeights.at(currentItem);
      } else {
        *col = valueIfNoTake;
        backtracking.at(currentItem).at(currentWeight) = currentWeight;
      }
    }
  }

  std::cout << "The most value we can acheive is " << bestValues.back().back() << ".\n\n";

  outputBacktracking(backtracking, itemWeights, itemValues, maxWeight);
}

void outputBacktracking(const std::vector< std::vector< int > > &backtracking,
                        const std::vector< int > &itemWeights,
                        const std::vector< int > &itemValues,
                        int maxWeight) {
  int currentItem = itemWeights.size()-1,
      currentWeight = maxWeight;

  for (auto it = backtracking.at(currentItem);;) {
    if (it.at(currentWeight) == currentWeight) {
    // did not take this item
      currentItem--;
    } else {
    // took this item
      std::cout << "Item #" << currentItem << "; weight " << itemWeights.at(currentItem)
                            << ", value " << itemValues.at(currentItem) << ".\n";
      currentWeight -= itemWeights.at(currentItem);
      currentItem--;
    }

    if (currentItem < 0) {
      break;
    } else {
      it = backtracking.at(currentItem);
    }
  }
}

