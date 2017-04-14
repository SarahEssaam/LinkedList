#ifndef NODE_H
#define NODE_H
//#include <cstddef>
#include <cstdlib>
//#include<stdlib.h>

class Node{
	private :
		float data;
		Node* nextNode;
	public:
        Node();
        Node(float d);
        void setData(float d);
        void setNextNode(Node* n);
        float getData();
        Node* getNextNode();
        friend class List;
};
#endif // NODE_H
