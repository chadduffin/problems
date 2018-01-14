#include "monitor.h"

void Producer(Monitor *monitor) {
  monitor->AddProducer();

  for (int i = 0; i < 16; i++) {
    monitor->Push(i); 
  }

  monitor->DelProducer();
}

void Consumer(Monitor *monitor) {
  while (monitor->Pop());
}

int main(int argc, char **argv) {
  Monitor monitor;

  std::thread producer_a(Producer, &monitor),
              producer_b(Producer, &monitor),
              consumer_a(Consumer, &monitor),
              consumer_b(Consumer, &monitor),
              consumer_c(Consumer, &monitor);

  producer_a.join();
  producer_b.join();
  consumer_a.join();
  consumer_b.join();
  consumer_c.join();

  return 0;
}
