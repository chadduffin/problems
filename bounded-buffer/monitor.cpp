#include "monitor.h"

Monitor::Monitor(void) {
  max_size = 10;
  producers = 0;
}

Monitor::~Monitor(void) {
  // default destructor
}

int Monitor::Pop(void) {
  std::unique_lock< std::mutex > lock(mtx);

  while (list.empty()) {
    if (producers == 0) {
      return 0;
    }

    std::cout << producers << std::end;

    empty.wait_for(lock, std::chrono::milliseconds(50));
  }

  std::cout << std::this_thread::get_id() << " popped " << list.back() << std::endl;

  list.pop_back();

  if (list.size() == max_size-1) {
    full.notify_all();
  }

  return 1;
}

void Monitor::Push(int item) {
  std::unique_lock< std::mutex > lock(mtx);

  while (list.size() == max_size) {
    full.wait(lock);
  }

  std::cout << std::this_thread::get_id() << " added " << item << std::endl;

  list.push_back(item);

  if (list.size() == 1) {
    empty.notify_all();
  }
}

void Monitor::AddProducer(void) {
  producers++;
}

void Monitor::DelProducer(void) {
  producers--;
}

