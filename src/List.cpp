#include "List.h"

template<class T> List<T>::List(){
    head = NULL;
}
template<class T> List<T>::~List(){
    clear();
}
template<class T> bool List<T>::isEmpty(){
    return(head==NULL);
}
template<class T> int List<T>::getSize(){
    int size = 0;
    Node<T>* temp = head;
    while(temp!=NULL){
        size++;
        temp = temp->getNextNode();
    }
    return size;
}
template<class T> T List<T>::getAverage(){
    if(isEmpty()) return 0;
    T sum = 0;
    int size = 0;
    Node<T>* temp = head;
    while(temp!=NULL){
        size++;
        sum += temp->getData();
        temp = temp->next;
    }
    sum = sum/size;
    return sum;
}
template<class T> void List<T>::reverseList(){
    if((isEmpty())||(head->getNextNode()==NULL))  //one element or none
            return;
    int size = getSize();
    int last = size/2 + size%2;
    int first = last -1;
    while(true){
        if(last>=size)
        break;
    swap(getNode(first),getNode(last));
    first--;
    last++;
    }
    //handling odd size
    if(first==0){
        addEnd(removeFront());
    }
}
template <class T> void List<T>::swap(Node<T>* n1,Node<T>* n2){
    T temp = n1->getData();
    n1->setData(n2->getData());
    n2->setData(temp);
}
template <class T> Node<T>* List<T>::getNode(int index){
    if((isEmpty())||(index<0))
        return NULL;
    Node<T>* temp = head;
    while(temp!=NULL){
        if(index==0)
            return temp;
        index--;
        temp = temp->getNextNode();
    }
    return NULL;
}
template<class T> void List<T>::addFront(T data){
    Node<T>* np = new Node<T>(data);
    //allocated right?
    if(!np){
    np->setNextNode(head);
    head = np;
    }
}
template<class T> T List<T>::removeFront(){
    if(!isEmpty()){
        T tmp = head->getData();
        Node<T>* np = head;
        head = head->getNextNode();
        free(np);
        return tmp;
    }
}
template<class T> void List<T>::addEnd(T data){
    Node<T>* np = new Node<T>(data);
    Node<T>* tmp = head;
    if(!isEmpty()){
        while(tmp->getNextNode())
            tmp = tmp->getNextNode();
        tmp->setNextNode(np);
    }
    else{
        head = np;
    }
}
template<class T> T List<T>::removeEnd(){
    T value ;
    if(isEmpty())
        value = -1;
    Node<T>* tmp = head;
    if(head->getNextNode()==NULL){
        value = head->getData();
        free(head);
        head = NULL;
    }
    else{
        while(((tmp->getNextNode())->getNextNode())!=NULL)
        tmp = tmp->getNextNode();
        //htl3 kda b l abl l a5ira = tmp
        Node<T>* deletePtr = tmp->getNextNode();
        value = deletePtr->getData();
        tmp->setNextNode(NULL);
        delete(deletePtr);
    }
    return value;
}
/*template<class T> T List<T>::getEnd(){
    T value ;
    if(isEmpty())
        value = -1;
    Node<T>* tmp = head;
    if(head->getNextNode()==NULL){
        value = head->getData();
    }
    else{
        while((tmp->getNextNode())!=NULL)
        tmp = tmp->getNextNode();
        //htl3 kda b l abl l a5ira = tmp
        value = tmp->getData();
    }
    return value;
}*/
//assuming index starts from 1 not 0
template<class T> void List<T>::add(int index,T data){
    if(index==1){
        addFront(data);
        return;
    }
    Node<T>* np = new Node<T>(data);
    int i = 1;
    Node<T>* prev = head;
    while((prev->getNextNode())&&(index>i)){
        prev=prev->getNextNode();
        i++;
    }
    if(index>i)
        return;
    np->setNextNode(prev->getNextNode());
    prev->setNextNode(np);
}
template<class T> void List<T>::remove(int index){
    if(index==1)
        removeFront();
    int i = 1;
    Node<T>* prev = head;
    while((prev->getNextNode())&&(index>i)){
        prev=prev->getNextNode();
        i++;
    }
    if(index>i)
        return;
    Node<T>* tmp = prev->getNextNode();
    prev->setNextNode(tmp->getNextNode());
    delete(tmp);
}
template<class T> int List<T>::find(T data){
    int i = 1;
    Node<T>* tmp = head;
    while(tmp){
        if((tmp->getData())==data)
            return i;
        tmp = tmp->getNextNode();
        i++;
    }
    return -1;
}
template<class T> void List<T>::removeItem(T data){
    if (isEmpty()) return;
    int index = find(data);
    if(index>0)
        remove(index);
}
template<class T> void List<T>::clear(){
    Node<T>* tmp = head;
    while(head){
        tmp = head->getNextNode();
        delete(head);
        head = tmp;
    }
}
template<class T> void List<T>::printALll(){
    Node<T>* tmp = head;
    while(tmp){
        std::cout<<tmp->getData()<<std::endl;
        tmp = tmp->getNextNode();
    }
}
