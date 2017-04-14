#ifndef NODE_H
#define NODE_H
#include<cstdlib>

template <class T> class Node{
	private :
		T data;
		Node* nextNode;
	public:
        Node();
        Node(T d);
        void setData(T d);
        void setNextNode(Node* n);
        T getData();
        Node* getNextNode();
};
#endif // NODE_H
