#include "manager.h"

// Waits for condition variable, blocking other threads
void Manager::Wait() {
    // Acquire mutex, to protect shared variable
    std::unique_lock<std::mutex> lock(mutex);
    // Lock the mutex and wait, until notified
    cv.wait(lock);
}

// Notifies all the threads that are waiting, unblock threads
void Manager::NotifyAll() {
    std::unique_lock<std::mutex> lock(mutex);
    cv.notify_all();
}

void Manager::NotifyOne() {
    std::unique_lock<std::mutex> lock(mutex);
    cv.notify_one();
}
