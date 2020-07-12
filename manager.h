#pragma once
#include <mutex>
#include <condition_variable>
#include <atomic>

class Manager {
public:
    void Wait();
    void NotifyAll();
    void NotifyOne();

    std::mutex mutex;
    std::condition_variable cv;
};

//struct CommChannel {
 //   Manager coordinator;
 //   std::atomic<bool> exchange_closed{false};
//};