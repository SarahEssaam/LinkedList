#include "Node.h"
Node::Node(){
    data = 0;
    nextNode = NULL;
}
Node::Node(float d){
    data = d;
}
void Node::setData(float d){
    data = d;
}
void Node::setNextNode(Node* n){
    nextNode = n;
}
float Node::getData(){
    return data;
}
Node* Node::getNextNode(){
    return nextNode;
}

