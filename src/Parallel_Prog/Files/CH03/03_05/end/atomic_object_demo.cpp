/**
 * Two shoppers adding items to a shared notepad
 */
#include <thread>
#include <atomic>
#include <string>
#include <iostream>

std::atomic<unsigned int> garlic_count(0);

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
    printf("We should buy %u garlic.\n", garlic_count.load());
    std::cout << "We should buy " << std::to_string(garlic_count.load()) << " garlic.\n";

}