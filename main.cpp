//Written by Jongmin Han
//jongmin.han17@gmail.com
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
};

class LinkedList
{
private:
    Node * head;
    Node * tail;
public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList()
    {
        Node * t1;
        Node * t2;

        if (head == nullptr)
            return;

        t1 = head;
        t2 = t1->next;

        while (t1 != nullptr)
        {
            delete t1;
            t1 = t2;
            if (t2 != nullptr)
                t2 = t2->next;
        }
    }

    void add_node(int num);
    Node * gethead();
    void display(Node * n);
};

void LinkedList::add_node(int num)
{
    Node * tmp = new Node();
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

Node * LinkedList::gethead()
{
    return head;
}

void LinkedList::display(Node * n)
{
    if (n == nullptr)
        cout << "End of list.\n";
    else
    {
        cout << n->data << endl;
        display(n->next);
    }
}

int main()
{
    LinkedList * list = new LinkedList();

    for (int i=0; i<100; i++)
        list->add_node(i*3);

    list->display(list->gethead());


    delete list;
    return 0;
}
