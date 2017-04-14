#include "Node.h"
template<class T> Node<T>::Node(){
    data = 0;
    nextNode = NULL;
}
template<class T> Node<T>::Node(T d){
    data = d;
}
template<class T> void Node<T>::setData(T d){
    data = d;
}
template<class T> void Node<T>::setNextNode(Node* n){
    nextNode = n;
}
template<class T> T Node<T>::getData(){
    return data;
}
template<class T> Node<T>* Node<T>::getNextNode(){
    return nextNode;
}

