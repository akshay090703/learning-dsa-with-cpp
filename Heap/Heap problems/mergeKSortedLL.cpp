#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

// Time Complexity -> O(1)
void insertAtHead(Node *&head, int data)
{
    if (!head)
    {
        head = new Node(data);
        return;
    }
    Node *new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

// Time Complexity -> O(n)
void insertAtTail(Node *&head, int data)
{
    if (!head)
    {
        insertAtHead(head, data);
        return;
    }
    Node *new_node = new Node(data);
    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtTail(Node *&head)
{
    Node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    Node *dummy = temp->next;
    free(dummy);

    temp->next = nullptr;
}

void displayLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

// Lets assume total nodes are i*j
// we can assume i*j as n total number of nodes
// Time Complexity -> O(klogk) + O(i*j*logk) ~ O((i*j)*log(k)) ~ O(nlogk)
// Space Complexity -> O(k) {only for minHeap}
Node *mergeKLists(vector<Node *> &listArray)
{
    if (listArray.empty())
        return nullptr;

    int k = listArray.size();
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // inserting head of all the LLs
    for (int i = 0; i < k; i++)
    {
        if (listArray[i])
            minHeap.push(listArray[i]);
    }

    Node *new_head = nullptr;
    Node *tail = nullptr;

    while (!minHeap.empty())
    {
        Node *front = minHeap.top();
        minHeap.pop();

        if (front->next)
        {
            minHeap.push(front->next);
        }

        if (!new_head)
        {
            new_head = front;
            tail = front;
        }
        else
        {
            tail->next = front;
            tail = front;
        }
    }

    return new_head;
}

int main()
{
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    Node *head3 = nullptr;

    insertAtTail(head1, 4);
    insertAtTail(head1, 6);
    insertAtTail(head1, 8);

    insertAtTail(head2, 2);
    insertAtTail(head2, 5);
    insertAtTail(head2, 7);

    insertAtTail(head3, 1);
    insertAtTail(head3, 9);

    vector<Node *> listArray = {head1, head2, head3};

    Node *mergedHead = mergeKLists(listArray);
    displayLL(mergedHead);

    return 0;
}