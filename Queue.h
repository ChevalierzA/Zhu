

// Class Invariant:  FIFO order
 

/* None of the provided code (basecode) may be modified. */


#pragma once

#include "Node.h"
#include "EmptyDataCollectionException.h"

#include <cstdio>

using namespace std;

template <class T>
class Queue {
private:
    static int const INITIAL_SIZE = 1;
    T* arr = new T[INITIAL_SIZE];
    int capacity;
    int front;
    int back;
    int size;
public:

        // Desc: Constructor. (O(1))
        Queue();


        // Desc: Returns true if Queue is empty. (O(1))
        bool isEmpty() const;

   
        // Desc: Inserts x at the "back" of this Queue. (O(1))
        void enqueue(const T& x);

   
        // Desc: Removes the element at the "front". (O(1))
        //  Pre: Queue not empty.
        //       Throws EmptyDataCollectionException if Queue empty.
        void dequeue() throw(EmptyDataCollectionException);
   

        // Desc: Returns the element at the "front". (O(1))
        //  Pre: Queue not empty.
        //       Throws EmptyDataCollectionException if Queue empty.
        // Post: Queue is unchanged.
        T& peek() const throw(EmptyDataCollectionException);  



        /* you may add more methods */


};


// Desc: Constructor. (O(1))
template <class T>
Queue<T>::Queue() {
    size = 0; 
    capacity = INITIAL_SIZE;
    front = 0;
    back = 0;
} // constructor



// Desc: Returns true if Queue is empty. (O(1))
template <class T>
bool Queue<T>::isEmpty() const {
    return size == 0;
} // isEmpty



// Desc: Inserts x at the "back" of this Queue. (O(1))
template <class T>
void Queue<T>::enqueue(const T& x) {
    if(size >= capacity){
    capacity++;
    T *temp = new T[capacity];
    for(int i = 0; i < back; i++)
        temp[i] = arr[i];
    delete [] arr;
    arr = temp;
    arr[back++] = x;
    }
    else{
        arr[back++] = x;
    }
    size++;
} // enqueue



// Desc: Removes the element at the "front". (O(1))
//  Pre: Queue not empty.
//       Throws EmptyDataCollectionException if Queue empty.
template <class T>
void Queue<T>::dequeue() throw(EmptyDataCollectionException) {
    int i = 0;
    while(i < back)
    {
        arr[i++] = arr[i+1];
    }
    back--;
    size--;
} // dequeue



// Desc: Returns the element at the "front". (O(1))
//  Pre: Queue not empty.
//       Throws EmptyDataCollectionException if Queue empty.
// Post: Queue is unchanged.
template <class T>
T& Queue<T>::peek() const throw(EmptyDataCollectionException) {
    return arr[front];
} // peek


