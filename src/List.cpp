#include "List.h"

List::List(){
    head = NULL;
}
List::~List(){
    clear();
}
bool List::isEmpty(){
    return(head==NULL);
}
int List::getSize(){
    int size = 0;
    Node* temp = head;
    while(temp!=NULL){
        size++;
        temp = temp->getNextNode();
    }
    return size;
}
float List::getAverage(){
    if(isEmpty()) return 0;
    float sum = 0;
    int size = 0;
    Node* temp = head;
    while(temp!=NULL){
        size++;
        sum += temp->getData();
        temp = temp->nextNode;
    }
    sum = sum/size;
    return sum;
}
void List::reverseList(){
    if((isEmpty())||(head->getNextNode()==NULL))  //one element or none
            return;
    int size = getSize();
    int last = size/2 + size%2;
    int first = last -1;
    while(1){
        if(last>=size)
        break;
    swap(getNode(first),getNode(last));
    first--;
    last++;
    }
    //handling odd size
    if(first==0){
        addEndNode(removeFrontNode());
    }
}
Node* List::removeFrontNode(){
    if(head==NULL)
        return NULL;
    Node* temp = head;
    head = head->nextNode;
    temp->nextNode = NULL;
    return temp;
}
void List::addEndNode(Node* n){
    if(isEmpty()){
         head = n;
         n->nextNode = NULL;
    }
    Node* lastNode = head;
    while((lastNode->nextNode)!=NULL){
        lastNode = lastNode->nextNode;
    }
    lastNode->nextNode = n;
    n->nextNode = NULL;
}
void List::swap(Node* n1,Node* n2){
    float temp = n1->getData();
    n1->setData(n2->getData());
    n2->setData(temp);
}
Node* List::getNode(int index){
    if((isEmpty())||(index<0))
        return NULL;
    Node* temp = head;
    while(temp!=NULL){
        if(index==0)
            return temp;
        index--;
        temp = temp->getNextNode();
    }
    return NULL;
}
void List::addFront(float data){
    Node* np = new Node(data);
    //allocated right?

    np->setNextNode(head);
    head = np;

}
float List::removeFront(){
    if(!isEmpty()){
        float tmp = head->getData();
        Node* np = head;
        head = head->getNextNode();
        delete(np);
        return tmp;
    }
    return -1;
}
/* bayza
void List::addEnd(float data){
    Node* np = new Node(data);
    Node* tmp = head;
    if(!isEmpty()){
        while((tmp->nextNode)!=NULL)
            tmp = tmp->nextNode;
        tmp->setNextNode(np);
    }
    else{
        head = np;
    }
}

*/
float List::removeEnd(){
    float value ;
    if(isEmpty())
        value = -1;
    Node* tmp = head;
    if(head->getNextNode()==NULL){  //one node only
        value = head->getData();
        delete(head);
        head = NULL;
    }
    else{
        while(((tmp->getNextNode())->getNextNode())!=NULL)
        tmp = tmp->getNextNode();
        //htl3 kda b l abl l a5ira = tmp
        Node* deletePtr = tmp->getNextNode();
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

void List::add(int index,float data){
    if(index==0){
        addFront(data);
        return;
    }
    Node* np = new Node(data);
    int i = 0;
    Node* prev = head;
    while(prev!=NULL){
          if((index-1)==i){
            np->setNextNode(prev->getNextNode());
            prev->setNextNode(np);
          }
        prev=prev->getNextNode();
        i++;
    }
}

void List::remove(int index){
    if(index==1)
        removeFront();
    int i = 1;
    Node* prev = head;
    while((prev->getNextNode())&&(index>i)){
        prev=prev->getNextNode();
        i++;
    }
    if(index>i)
        return;
    Node* tmp = prev->getNextNode();
    prev->setNextNode(tmp->getNextNode());
    delete(tmp);
}
 int List::find(float data){
    int i = 0;
    Node* tmp = head;
    while(tmp){
        if((tmp->getData())==data)
            return i;
        tmp = tmp->getNextNode();
        i++;
    }
    return -1;
}
 void List::removeItem(float data){
    if (isEmpty()) return;
    int index = find(data);
    if(index>=0)
        remove(index);
}
void List::clear(){
    Node* tmp = head;
    while(head){
        tmp = head->getNextNode();
        delete(head);
        head = tmp;
    }
}
void List::printALll(){
    Node* tmp = head;
    while(tmp !=NULL){
        std::cout<<tmp->getData()<<", ";
        tmp = tmp->getNextNode();
    }
}
