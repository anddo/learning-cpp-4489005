
#include <iostream> 
#include <thread> 
#include <mutex> 

int number = 0; 
std::mutex additionInProgress;
  
// function to increment the number 
void increment(const char* name){ 
      
    // increment number by 1 for 1000000 times 
    for(int i=0; i<1000000; i++){ 
        additionInProgress.lock();
        number++; 
        additionInProgress.unlock();
    } 
}

int main(){
    float num_1, num_2, result;
    std::thread olivia(increment, "Olivia");
    std::thread jay(increment, "Jay");

    olivia.join(); 
    jay.join(); 
    std::cout << "The result of the addition is: " << number << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}