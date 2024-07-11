/**
 * Two shoppers adding items to a shared notepad
 */
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include <iostream>
#include <sstream>

unsigned int garlic_count = 0;
std::mutex pencil;

void shopper() {
    for (int i=0; i<5; i++) {
        std::ostringstream oss;
        oss << std::this_thread::get_id();
        std::string printOut = "Shopper " + oss.str() + " is thinking.\n";
        std::cout << printOut;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        pencil.lock();
        garlic_count++;
        pencil.unlock();
    }
}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    std::string printOut = "We should buy " + std::to_string(garlic_count) + " garlic.\n";
    std::cout << printOut;
}
