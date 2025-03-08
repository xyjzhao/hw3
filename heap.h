#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  PComparator comp;
  int m_ary;

  // Helper function to trickle up an element
  void heapifyUp(int index);

  // Helper function to trickle down an element
  void heapifyDown(int index);

  // Helper to get parent index
  int parent(int index) const;

  // Helper to get kth child index
  int kthChild(int index, int k) const;

  // Helper to find the highest priority child
  int highestPriorityChild(int index) const;
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
  : comp(c), m_ary(m)
{
  // Ensure m is at least 2
  if (m < 2) {
    m_ary = 2;
  }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
  // Nothing needs to be done - vector will clean itself up
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  // Add the item to the end of the vector
  data.push_back(item);
  
  // Heapify up to maintain the heap property
  heapifyUp(data.size() - 1);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return data.size();
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::parent(int index) const
{
  return (index - 1) / m_ary;
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::kthChild(int index, int k) const
{
  return m_ary * index + k;
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::highestPriorityChild(int index) const
{
  int firstChild = kthChild(index, 1);
  
  if (firstChild >= data.size()) {
    return -1; // No children
  }
  
  int bestChild = firstChild;
  
  // Check all possible children (up to m_ary)
  for (int i = 2; i <= m_ary; ++i) {
    int childIndex = kthChild(index, i);
    
    if (childIndex < data.size()) {
      // If this child has higher priority than our current best
      if (comp(data[childIndex], data[bestChild])) {
        bestChild = childIndex;
      }
    } else {
      break; // No more children to check
    }
  }
  
  return bestChild;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(int index)
{
  if (index <= 0) {
    return; // At root, nothing to do
  }
  
  int parentIndex = parent(index);
  
  // If the current node has higher priority than its parent
  if (comp(data[index], data[parentIndex])) {
    // Swap with parent
    std::swap(data[index], data[parentIndex]);
    
    // Recursively heapify up
    heapifyUp(parentIndex);
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(int index)
{
  int highestChild = highestPriorityChild(index);
  
  // If no children or at a leaf node
  if (highestChild == -1) {
    return;
  }
  
  // If the highest priority child has higher priority than current node
  if (comp(data[highestChild], data[index])) {
    // Swap with highest priority child
    std::swap(data[index], data[highestChild]);
    
    // Recursively heapify down
    heapifyDown(highestChild);
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  
  // Replace the root with the last element
  data[0] = data.back();
  
  // Remove the last element
  data.pop_back();
  
  // If heap is not empty, heapify down from the root
  if (!empty()) {
    heapifyDown(0);
  }
}

#endif