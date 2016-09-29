#ifndef STACKADT_H
#define STACKADT_H

#include <iostream>
#include <string>

using namespace std;

typedef int xType;

class StackADT{
    public:
        StackADT();
        ~StackADT();
        bool isEmpty() const;
        bool isFull() const;
        void push(xType);
        void pop();
        xType top() const;
        int Size() const;
    protected:
    private:
        struct Stack_Node{
            xType element;
            Stack_Node* next;
        };
        typedef Stack_Node* Stack_Ptr;

        Stack_Ptr TOS;

};

#endif
