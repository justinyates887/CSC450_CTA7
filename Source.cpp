#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
std::mutex mtx;

void countUp() {
    for (int i = 1; i <= 20; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "First Thread (1) - Count +: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void countDown() {
    for (int i = 20; i >= 0; --i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Second Thread (2) - Count -: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    std::thread t1(countUp);

    t1.join(); //wait for thread 1
    std::thread t2(countDown);

    t2.join(); //wait for thread 2

    std::cout << "Counting complete!" << std::endl;

    return 0;
}