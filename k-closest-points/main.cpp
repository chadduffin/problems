#include <cmath>
#include <queue>
#include <vector>
#include <iostream>

void kClosestPoints(const std::vector< std::pair< int, int > > &points, int amount);

int main(int argc, char **argv) {
  int n, value, amount;
  std::pair< int, int > pair;
  std::vector< std::pair< int, int > > points;

  std::cin >> amount >> n;

  while (n-- > 0) {
    std::cin >> pair.first;
    std::cin >> pair.second;

    points.push_back(pair);
  }

  kClosestPoints(points, amount);

  return 0;
}

void kClosestPoints(const std::vector< std::pair< int, int > > &points, int amount) {
  double distance;
  auto lambda = [](const std::pair< double, int > &left, const std::pair< double, int > &right) -> bool {
    return left.first < right.first;
  };

  std::priority_queue< std::pair< double, int >,
                       std::vector< std::pair< double, int > >,
                       decltype(lambda) > closestPoints(lambda);

  for (auto it = points.begin(); it != points.end(); it++) {
    distance = sqrt(it->first*it->first+it->second*it->second);

    if (closestPoints.size() >= amount) {
      if (distance < closestPoints.top().first) {
        closestPoints.pop();
        closestPoints.push(std::pair< double, int>(distance, it-points.begin()));
      }
    } else {
      closestPoints.push(std::pair< double, int>(distance, it-points.begin()));
    }
  }

  std::cout << "The closes points are ";

  while (!closestPoints.empty()) {
    std::cout << "(" << points.at(closestPoints.top().second).first
              << ", "<< points.at(closestPoints.top().second).second
              << ")" << ((closestPoints.size() > 1) ? ", " : ".\n");
    closestPoints.pop();
  }
}
