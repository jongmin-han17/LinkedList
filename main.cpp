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
public:
	LinkedList() : mHead(nullptr), mTail(nullptr) {}
	~LinkedList()
	{
		if (mHead == nullptr)
		{
			return;
		}

		Node* t1 = mHead;
		Node* t2 = mHead->next;

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
	Node* GetHead();
	void Display(Node* node);

private:
	Node* mHead;
	Node* mTail;
};

void LinkedList::AddNode(int num)
{
	Node* tmp = new Node();
	tmp->data = num;
	tmp->next = nullptr;

	if (mHead == nullptr)
	{
		mHead = tmp;
		mTail = tmp;
	}
	else
	{
		mTail->next = tmp;
		mTail = mTail->next;
	}
}

Node* LinkedList::GetHead()
{
	return mHead;
}

void LinkedList::Display(Node* node)
{
	if (node == nullptr)
	{
		cout << "End\n";
	}
	else
	{
		cout << node->data << endl;
		Display(node->next);
	}
}

int main()
{
	LinkedList* list = new LinkedList();

	for (int i=0; i<20; i++)
	{
		list->AddNode(0 - i * i);
	}

	list->Display(list->GetHead());
	return 0;
}