#include <iostream>
#include <vector>
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

struct LinkedList
{
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data)
    {
        if (head == nullptr)
        {
            insertAtHead(data);
            return;
        }
        Node *newNode = new Node(data);
        Node *temp = head;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void displayNodes()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

// using recursion
void mergingKSortedLLs(vector<LinkedList> &v, LinkedList &ansList, int i = 0)
{
    if (i == v.size())
        return;

    if (!ansList.head)
    {
        ansList.head = v[i].head;
        return mergingKSortedLLs(v, ansList, i + 1);
    }

    Node *temp1 = ansList.head;
    Node *temp2 = v[i].head;
    Node *new_head = nullptr;

    if (temp1->data < temp2->data)
    {
        new_head = temp1;
        temp1 = temp1->next;
    }
    else
    {
        new_head = temp2;
        temp2 = temp2->next;
    }

    Node *ansNode = new_head;
    ansList.head = ansNode;

    while (temp1 && temp2)
    {
        if (temp1->data < temp2->data)
        {
            ansNode->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            ansNode->next = temp2;
            temp2 = temp2->next;
        }
        ansNode = ansNode->next;
    }

    if (temp1)
    {
        ansNode->next = temp1;
    }
    else
    {
        ansNode->next = temp2;
    }

    return mergingKSortedLLs(v, ansList, i + 1);
};

// Youtube Approach
// Node* mergingKSortedLLs(vector<Node*> &lists) {
//     while(lists.size() > 1) {
//         Node *mergeHead = mergeLinkedLists(lists[0], lists[1]);
//         // function for 2 linked lists
//         // uses the function used to merge two sorted linked lists

//         lists.push_back(mergeHead);
//         lists.erase(lists.begin());
//         lists.erase(lists.begin());
//     }
//     return lists[0];
// }

int main()
{
    LinkedList list1 = LinkedList();
    for (int i = 1; i <= 18; i += 3)
    {
        list1.insertAtTail(i);
    }
    list1.displayNodes();

    LinkedList list2 = LinkedList();
    for (int i = 2; i <= 18; i += 3)
    {
        list2.insertAtTail(i);
    }
    list2.displayNodes();

    LinkedList list3 = LinkedList();
    for (int i = 3; i <= 18; i += 3)
    {
        list3.insertAtTail(i);
    }
    list3.displayNodes();

    vector<LinkedList> v = {list1, list2, list3};
    LinkedList mergedLL = LinkedList();
    mergingKSortedLLs(v, mergedLL);
    mergedLL.displayNodes();

    return 0;
}

// recursion approach
// Time Complexity -> O(k*n)
// Space Complexity -> O(k) {k recursive calls}
// k -> Number of sorted linked lists
// n -> length of the shorter linked list in one recursion