#include <map>
#include <set>
#include <list>
#include <deque>
#include <array>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>

#include <iostream>

int main(int argc, char **argv) {
  std::map< int, int > my_map;
  std::multimap< int, int > my_multimap;
  std::multimap< int, int >::iterator my_multimap_it;

  my_map[4] = 2; // or my_map.insert(std::pair(4, 2))

  my_multimap_it = my_multimap.insert(std::make_pair(4, 2));

  std::set< int, int > my_set;
  std::multiset< int, int > my_multiset;

  std::unordered_map< int, int > my_unordered_map;
  std::unordered_multimap< int, int > my_unordered_multimap;

  std::unordered_set< int, int > g;
  std::unordered_multiset< int, int > h;

  std::list< int > my_list;
  std::list< int >::iterator my_list_it;
  std::forward_list< int > my_forward_list;
  std::forward_list< int >::iterator my_forward_list_it;

  my_list_it = my_list.insert(my_list.begin(), 10);
  my_list.insert(my_list_it, 20);
  std::cout << my_list.front() << std::endl;

  my_forward_list.push_front(10);
  my_forward_list.insert_after(my_forward_list.begin(), 20);
  std::cout << my_forward_list.front() << std::endl;
  
  std::deque< int > k;
  
  std::array< int, 100 > l;

  std::vector< int > m;

  std::queue< int > n; // queues have fronts, not tops

  std::stack< int > o; // stacks have tops, not fronts

  auto less_than = [](const int &left, const int &right) -> bool {
    return left < right;
  };

  auto greater_than = [](const int &left, const int &right) -> bool {
    return left > right;
  };

  std::priority_queue< int, std::vector< int >, decltype(less_than) > max_pq(less_than);
  std::priority_queue< int, std::vector< int >, decltype(greater_than) > min_pq(greater_than);

  return 0;
}
