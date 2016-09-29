#include "StackADT.h"

StackADT::StackADT(){
    TOS = NULL;
}

StackADT::~StackADT(){
    TOS = NULL;
}

bool StackADT::isEmpty() const{
    return(TOS == NULL);
}

bool StackADT::isFull() const{

    return false;
}

int StackADT::Size() const{
    int counter = 0;
    Stack_Ptr Sptr = TOS;

    while(Sptr != NULL){
        ++counter;
        Sptr = Sptr->next;
    }

    return counter;
}

void StackADT::push(xType item){
    if(!this->isFull()){
        Stack_Ptr Sptr = new Stack_Node;
        Sptr->element = item;
        Sptr->next = TOS;
        TOS = Sptr;
    }
}

void StackADT::pop(){

    if(!this->isEmpty()){
        TOS = TOS->next;
    }
}

xType StackADT::top() const{

    if(!this->isEmpty()){
        return(TOS->element);
    }

}
