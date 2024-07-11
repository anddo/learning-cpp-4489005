/**
 * Two threads chopping vegetables
 */
#include <thread>
#include <chrono>
#include <iostream>

bool chopping = true;

void vegetable_chopper(const char* name) {
    unsigned int vegetable_count = 0;
    while (chopping) {
        vegetable_count++;
    }
    std::string result = std::string(name) + " chopped " + std::to_string(vegetable_count) + " vegetables.\n";
    std::cout << result;
}

int main() {
    std::thread olivia(vegetable_chopper, "Olivia");
    std::thread barron(vegetable_chopper, "Barron");
    
	printf("Barron and Olivia are chopping vegetables...\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    chopping = false;
    barron.join();
    olivia.join();
}