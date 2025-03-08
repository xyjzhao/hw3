#include "stack.h"
#include <iostream>
#include <string>

int main() {
    // Test with integers
    std::cout << "Testing Stack with integers:" << std::endl;
    Stack<int> intStack;
    
    std::cout << "Is empty? " << (intStack.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size: " << intStack.size() << std::endl;
    
    std::cout << "Pushing 10, 20, 30" << std::endl;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    std::cout << "Is empty? " << (intStack.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size: " << intStack.size() << std::endl;
    std::cout << "Top: " << intStack.top() << std::endl;
    
    std::cout << "Popping..." << std::endl;
    intStack.pop();
    std::cout << "Top after pop: " << intStack.top() << std::endl;
    std::cout << "Size after pop: " << intStack.size() << std::endl;
    
    // Test with strings
    std::cout << "\nTesting Stack with strings:" << std::endl;
    Stack<std::string> stringStack;
    
    stringStack.push("Hello");
    stringStack.push("World");
    
    std::cout << "Size: " << stringStack.size() << std::endl;
    std::cout << "Top: " << stringStack.top() << std::endl;
    
    // Test exception handling
    std::cout << "\nTesting exception handling:" << std::endl;
    Stack<double> emptyStack;
    
    try {
        emptyStack.top();
    } catch (const std::underflow_error& e) {
        std::cout << "Exception caught for top(): " << e.what() << std::endl;
    }
    
    try {
        emptyStack.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Exception caught for pop(): " << e.what() << std::endl;
    }
    
    return 0;
}