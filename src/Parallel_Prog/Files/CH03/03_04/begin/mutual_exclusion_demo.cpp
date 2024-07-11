/**
 * Two shoppers adding items to a shared notepad
 */
#include <thread>
#include <string>
#include <iostream>

unsigned int garlic_count = 0;

void shopper() {
    for (int i=0; i<10000000; i++) {
        garlic_count++;
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
