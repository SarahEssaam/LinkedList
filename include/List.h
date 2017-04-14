#ifndef LIST_H
#define LIST_H
#include "Node.h"
//#include <cstddef>
#include <cstdlib>
//#include<tdlib.h>
#include<iostream>

class List{
	private:
		Node* head;
		void swap(Node* n1,Node* n2);
		Node* getNode(int index);
		Node* removeFrontNode();
        void addEndNode(Node* n);
	public:
        List();
        virtual ~List();
        bool isEmpty();
        int getSize();
        float getAverage();
        void reverseList();
        void addFront(float data);
        float removeFront();
        void addEnd(float data);
        //T getEnd();
        float removeEnd();
        void add(int index,float data);
        void remove(int index);
        int find(float data);
        void removeItem(float data);
        void clear();
        void printALll();
};
#endif // LIST_H
