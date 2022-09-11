#include "stack.hpp"

#include <iostream>

int main(){

  Stack<int> st;
  st.push(1);  
  st.push(2);  
  st.push(3);  
  st.push(4);  
  st.push(5);  
  st.push(6);  
  st.push(7);  
  st.push(8);  
  st.push(9);  
  
  while(!st.empty()){
    std::cout << st.top() << std::endl;
    st.pop();
  }

  return 0;
}
