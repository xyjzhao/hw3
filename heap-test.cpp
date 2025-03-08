#include "heap.h"
#include <iostream>
#include <string>
#include <functional>

// A simple comparator for testing max-heap with integers
struct GreaterThan {
    bool operator()(int a, int b) const {  
        return a > b;
    }
};

int main() {
    // Test 1: Binary Min-Heap with integers
    std::cout << "===== Test 1: Binary Min-Heap with integers =====" << std::endl;
    Heap<int> minHeap;
    
    std::cout << "Pushing: 5, 3, 8, 1, 2, 7, 6, 4" << std::endl;
    minHeap.push(5);
    minHeap.push(3);
    minHeap.push(8);
    minHeap.push(1);
    minHeap.push(2);
    minHeap.push(7);
    minHeap.push(6);
    minHeap.push(4);
    
    std::cout << "Size: " << minHeap.size() << std::endl;
    std::cout << "Elements in sorted order: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;
    
    // Test 2: Binary Max-Heap with integers using std::greater
    std::cout << "\n===== Test 2: Binary Max-Heap with integers (using std::greater) =====" << std::endl;
    Heap<int, std::greater<int>> maxHeapStd;
    
    std::cout << "Pushing: 5, 3, 8, 1, 2, 7, 6, 4" << std::endl;
    maxHeapStd.push(5);
    maxHeapStd.push(3);
    maxHeapStd.push(8);
    maxHeapStd.push(1);
    maxHeapStd.push(2);
    maxHeapStd.push(7);
    maxHeapStd.push(6);
    maxHeapStd.push(4);
    
    std::cout << "Size: " << maxHeapStd.size() << std::endl;
    std::cout << "Elements in sorted order: ";
    while (!maxHeapStd.empty()) {
        std::cout << maxHeapStd.top() << " ";
        maxHeapStd.pop();
    }
    std::cout << std::endl;
    
    // Test 3: Binary Max-Heap with integers using custom comparator
    std::cout << "\n===== Test 3: Binary Max-Heap with integers (using custom comparator) =====" << std::endl;
    GreaterThan gt;
    Heap<int, GreaterThan> maxHeapCustom(2, gt);
    
    std::cout << "Pushing: 5, 3, 8, 1, 2, 7, 6, 4" << std::endl;
    maxHeapCustom.push(5);
    maxHeapCustom.push(3);
    maxHeapCustom.push(8);
    maxHeapCustom.push(1);
    maxHeapCustom.push(2);
    maxHeapCustom.push(7);
    maxHeapCustom.push(6);
    maxHeapCustom.push(4);
    
    std::cout << "Size: " << maxHeapCustom.size() << std::endl;
    std::cout << "Elements in sorted order: ";
    while (!maxHeapCustom.empty()) {
        std::cout << maxHeapCustom.top() << " ";
        maxHeapCustom.pop();
    }
    std::cout << std::endl;
    
    // Test 4: 3-ary Min-Heap with strings
    std::cout << "\n===== Test 4: 3-ary Min-Heap with strings =====" << std::endl;
    Heap<std::string> minHeapStrs(3);
    
    std::cout << "Pushing: 'hello', 'world', 'this', 'is', 'a', 'test'" << std::endl;
    minHeapStrs.push("hello");
    minHeapStrs.push("world");
    minHeapStrs.push("this");
    minHeapStrs.push("is");
    minHeapStrs.push("a");
    minHeapStrs.push("test");
    
    std::cout << "Size: " << minHeapStrs.size() << std::endl;
    std::cout << "Elements in sorted order: ";
    while (!minHeapStrs.empty()) {
        std::cout << "'" << minHeapStrs.top() << "' ";
        minHeapStrs.pop();
    }
    std::cout << std::endl;
    
    // Test 5: Exception handling for empty heap
    std::cout << "\n===== Test 5: Exception handling for empty heap =====" << std::endl;
    Heap<int> emptyHeap;
    
    try {
        std::cout << "Trying to access top of empty heap..." << std::endl;
        emptyHeap.top();
    } catch (const std::underflow_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Trying to pop from empty heap..." << std::endl;
        emptyHeap.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}