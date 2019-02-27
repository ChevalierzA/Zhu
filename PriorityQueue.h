/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
 *
 */



/* None of the provided code (basecode) may be modified. */



#pragma once

#include "Node.h"
#include "EmptyDataCollectionException.h"

#include <cstdio>

using namespace std;


template <class T>
class PriorityQueue {

    private:
        // singly-linked list
        Node<T>* head;
        int len;


        /* You may add private methods to this class */


    public:
        // Desc: Default Constructor. (O(1))
        PriorityQueue();
 

        // Desc: Copy Constructor. (O(N))
        PriorityQueue(const PriorityQueue& rhs);


        // Desc: Destructor. (O(N))
        ~PriorityQueue();


        // Desc: Returns true if Priority Queue empty. (O(1))
        bool isEmpty() const;


        // Desc: Returns length of the Priority Queue. (O(1))
        int getLength() const;


        // Desc: Inserts x in sorted order. (O(N))
        //  Pre: Priority Queue is sorted.
        // Post: Priority Queue remains sorted.
        void enqueue(const T& x);
    

        // Desc: Removes the element with "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        void dequeue() throw(EmptyDataCollectionException);


        // Desc: Returns the element with the "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        // Post: Priority Queue is unchanged.
        T& peek() const throw(EmptyDataCollectionException);

}; // PriorityQueue

template <class T>
PriorityQueue<T>::PriorityQueue(){
    head = nullptr;
    len = 0;
}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& rhs){
    head = rhs.head;
    len = rhs.len;
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
	head = nullptr;
	len = 0;
}

template <class T>
bool PriorityQueue<T>::isEmpty()const
{
	return len == 0;
}

template <class T>
int PriorityQueue<T>::getLength() const
{
	return len;
}

template <class T>
void PriorityQueue<T>::enqueue(const T& x)
{
	if (head == nullptr)
	{
		Node<T> temp;
		temp->data = x;
		temp->next = nullptr;
		head = temp;
		len++;
	}
	else
	{	
		Node<T> iter = this->head;
		while (iter->next != nullptr)
		{
			iter = iter->next;
		}
		Node<T> temp;
		temp->data = x;
		temp->next = nullptr;
		iter->next = temp;
		len++;
	}
}

template <class T>
void PriorityQueue<T>::dequeue() throw(EmptyDataCollectionException)
{
		head = head->next;
}

template <class T>
T& PriorityQueue<T>::peek() const throw(EmptyDataCollectionException)
{
		return head->data;
}
