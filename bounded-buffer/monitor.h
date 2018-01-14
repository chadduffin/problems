#ifndef __MONITOR__
#define __MONITOR__

#include <mutex>
#include <atomic>
#include <vector>
#include <thread>
#include <iostream>
#include <condition_variable>

#include <chrono>

class Monitor {
  public:
    Monitor(void);
    ~Monitor(void);
    int Pop(void);
    void Push(int item);
    void AddProducer(void);
    void DelProducer(void);

  private:
    int max_size;

    std::mutex mtx;
    std::atomic< int > producers;
    std::condition_variable full, empty;

    std::vector< int > list;
};

#endif /* MONITOR */
