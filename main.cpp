//Written by Jongmin Han
//jongmin.han17@gmail.com
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr)
    {
        //Empty
    }

    ~LinkedList()
    {
        if (head == nullptr)
        {
            return;
        }

        Node* t1;
        Node* t2;

        t1 = head;
        t2 = t1->next;

        while (t1 != nullptr)
        {
            delete t1;

            t1 = t2;

            if (t2 != nullptr)
            {
                t2 = t2->next;
            }
        }
    }

    void AddNode(int num);
    Node* GetHead() const;
    void Display(Node* n) const;
};

void LinkedList::AddNode(int num)
{
    Node* tmp = new Node();
    tmp->data = num;
    tmp->next = nullptr;

    if (head == nullptr)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

Node* LinkedList::GetHead() const
{
    return head;
}

void LinkedList::Display(Node* n) const
{
    if (n == nullptr)
    {
        cout << "End of list.\n";
    }
    else
    {
        cout << n->data << endl;
        Display(n->next);
    }
}

int main()
{
    LinkedList* list = new LinkedList();

    for (int i=0; i<100; i++)
        list->AddNode(i*3);

    list->Display(list->GetHead());

    delete list;
    return 0;
}
