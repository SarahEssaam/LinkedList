#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <cstddef>
#include <cstdlib>
#include<stdlib.h>
#include<iostream>

template <class T> class List{
	private:
		Node<T>* head;
		void swap(Node<T>* n1,Node<T>* n2);
		Node<T>* getNode(int index);
	public:
        List();
        virtual ~List();
        bool isEmpty();
        int getSize();
        T getAverage();
        void reverseList();
        void addFront(T data);
        T removeFront();
        void addEnd(T data);
        //T getEnd();
        T removeEnd();
        void add(int index,T data);
        void remove(int index);
        int find(T data);
        void removeItem(T data);
        void clear();
        void printALll();
};
#endif // LIST_H
