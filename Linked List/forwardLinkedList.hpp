#pragma once

#include <iostream>
#include <cassert>

/**
 * Single Linked List with tail pointer.
 **/

template<typename T> struct Node {
  T key; 
  Node<T>* nodeptr;
};


template<typename T> class forwardLinkedList {
  Node<T>* head{nullptr};
  Node<T>* tail{nullptr};
  size_t size_list{0};
  public:
    /*
     * list.size() -> return the size of list
     */
    size_t size(){
      return size_list;
    }
    /*
     * list.empty() -> return true if list is empty and false if not
     * Time: O(1)
     */
    bool empty(){
      return head == nullptr;
    }
    /*
     * list.front() -> give the front element of linked list
     * Time: O(1)
     */
    T front(){
      assert(head != nullptr && "Try to get front element from empty list");
      return head->key;
    } 
    /*
     * list.back() -> give the last element of linked list
     * Time: O(1)
     */
    T back(){
      assert(tail != nullptr && "Try to get last element from empty list");
      return tail->key;
    }
    /*
     * list.push_back(x) -> append the key(x) to back of the list
     * Time: O(1), constant
     */
    void push_back(T key){
      Node<T>* node = new Node<T>(); 
      node->key = key; 
      node->nodeptr = nullptr;

      /* No element in list */
      if (tail == nullptr){
        head = tail = node; 
      } else {
        tail->nodeptr = node;
        tail = node;
      }
      size_list++;
    }
    /*
     * list.push_front(x) -> append the key(x) to front of list
     * Time: O(1), constant
     */
    void push_front(T key){
      Node<T>* node = new Node<T>();
      node->key = key;
      node->nodeptr = head;
      head = node;
      if(tail == nullptr) tail = node;
      size_list++;
    }
    /*
     * list.pop_back() -> remove the last element of list
     * Time: O(n)
     * We don't have access to second last element so we need to traverse up to it.
     * Solution: Double Linked list
     */
    void pop_back(){
      assert(tail != nullptr && "Try to remove last element from empty list");
      delete tail;
      /* Only one element in list */
      if(head == tail){
        head = tail = nullptr;
      } else {
        Node<T>* current_node = head;
        while(current_node->nodeptr != tail){
          current_node = current_node->nodeptr;
        }
        /* current node is second last node */
        current_node->nodeptr = nullptr;
        tail = current_node;
      }
      size_list--;
    }
    /*
     * list.pop_front() -> remove the first element of list
     * Time: O(1)
     */
    void pop_front() {
      assert(head != nullptr && "Try to remove first element from empty list");
      Node<T>* first_node = head;
      head = head->nodeptr;
      delete first_node;
      if (head == nullptr) tail = nullptr;
      size_list--;
    }
};
