#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next = NULL;
    Node* prev = NULL;
};

struct List
{
    Node* head = NULL;
    Node* end = NULL;
};

List Add_Node(List list, float x)
{
    Node* c = new Node;
    c->next = NULL;
    c->prev = NULL;
    c->data = x;
    if (list.head == NULL)
    {
        list.head = c;
        list.end = c;
    }
    else {
        list.end->next = c;
        list.end = c;
    }
    return list;

}

void Delete(List* list)
{
    Node* current = list->head;
    Node* previous = NULL;
    Node* next = NULL;

    while (current != NULL)
    {
        if (current != list->head)
        {
            if (current->data > 10 && current->data < 20)
            {
                if (previous->prev != NULL)
                {
                    previous->prev->next = current;
                    current->prev = previous->prev;
                    next = current->prev;
                    delete previous;
                }
                else {
                    list->head = current;
                    delete current->prev;
                }
            }
            current = current->next;
            previous = previous->next;

        }
        else
        {
            current = current->next;
            if (current != NULL) {
                previous = list->head;
                current->prev = previous;
            }
        }
        if (current == NULL)
            return;
        if (current->prev != next || current->prev == NULL)
            current->prev = previous;
    }
}


void Delete2(List* list)
{
    Node* current = list->head;
    Node* toDelete = NULL;

    while (!(current == NULL || current->next == NULL))
    {
        if (current->next->data > 10 && current->next->data < 20)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                list->head = current->next;
            }

            current->next->prev = current->prev;

            toDelete = current;
        }
        
        current = current->next;
        delete toDelete;
        toDelete = NULL;
    }
}

void Print_List(List list)
{
    Node* c = list.head;
    while (c != NULL) {
        cout << c->data << " ";
        c = c->next;
    }
}

int main()
{
    float x = 0;
    List node;
    while (x != 999) {
        cout << "Enter a number: ";
        cin >> x;
        node = Add_Node(node, x);
    }
    Delete2(&node);
    Print_List(node);

    return 0;
}
