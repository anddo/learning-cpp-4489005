/**
 * Two shoppers adding items to a shared notepad
 */
#include <iostream> 
#include <thread>

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
    std::cout << "We should buy " << garlic_count << " garlic." << std::endl;
}