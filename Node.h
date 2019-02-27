/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list (template)
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 
 * Author: 
 */
 
#pragma once

#include <cstdio>  // Needed for NULL

using namespace std;


template <class T>
class Node {
    public:                                                                  
        T data;
        Node<T>* next;

        Node(){next = nullptr;}
		Node(T d) { data = d; next = nullptr; }
        Node(T d, Node<T>* NextNode){data = d; next = NextNode;}
}; // Node


