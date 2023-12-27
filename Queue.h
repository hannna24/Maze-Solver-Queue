#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "point.h"
using namespace std;


class Node
{
public:
    CPoint c1;
    Node* next;
    Node()
    {
        CPoint c1;
        next = NULL;
    }
};

class queue
{
public:
    Node* front;
    Node* end;
    queue()
    {
        front = end = NULL;
    }
    void enqueue(CPoint newpoint)
    {
        Node* newnode = new Node();
        newnode->c1 = newpoint;
        newnode->next = NULL;
        if (isempty())
        {
            front = newnode;
            end = newnode;
        }
        else
        {
            end->next = newnode;
            end = newnode;
        }
    }
    CPoint dequeue()
    {
        Node* temp = front;
        CPoint point = front->c1;
        front = front->next;  // Update front first
        delete temp;
        if (front == NULL) {
            end = NULL;  // Update end if necessary
        }
        return point;
    }
    void pop()
    {
        Node* temp = front;
        front = front->next;  // Update front first
        delete temp;
        if (front == NULL) {
            end = NULL;  // Update end if necessary
        }
        return;
    }
    bool isempty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }

    void display()
    {
        Node* temp = front;
        if (isempty())
        {
            cout << "the queue is empty" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->c1.x() << "  " << temp->c1.y() << endl;
                temp = temp->next;
            }
        }
    }
    CPoint getfront()
    {
        return front->c1;
    }
    CPoint getend()
    {
        return end->c1;
    }

    int counter()
    {
        int count = 0;
        Node* temp = front;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isfound(CPoint point)
    {
        Node* temp = front;
        if (isempty())
        {
            cout << "the queue is empty" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                if (temp->c1==point)
                    return true;
                temp = temp->next;
            }
            return false;
        }
    }

};


#endif // QUEUE_H
