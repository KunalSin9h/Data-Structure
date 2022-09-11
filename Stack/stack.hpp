#include "../Linked List/forwardLinkedList.hpp"

/*
 * We use forward Linked List for implementing stack
 */

template<typename T> class Stack {
  forwardLinkedList<T> base; 
  public: 
    /*
     * stack.size() -> return the size of stack
     */
    size_t size(){
      return base.size();
    }
    /*
     * stack.empty() -> return true if stack is empty
     */
    bool empty(){
      return base.empty();
    }
    /*
     * stack.top() -> return the top most element of stack
     */
    T top(){
      assert(!empty() && "Try to get element from empty stack");
      return base.back();
    }
    /*
     * stack.push(x) -> push x to top of stack
     */
    void push(T key){
      base.push_back(key);
    }
    /*
     * stack.pop() -> remove the top most element of stack
     */
    void pop(){
      assert(!empty() && "Try to remove element from empty stack");
      base.pop_back();
    }
};
