#include <iostream>
using namespace std;

// using template class
template <typename T>
struct Node
{
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};

struct CircularLinkedList
{
    Node<int> *head;

    CircularLinkedList()
    {
        head = nullptr;
    }

    // Time Complexity -> O(n)
    void insertAtHead(int data)
    {
        Node<int> *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            newNode->next = newNode;
            return;
        }

        Node<int> *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        // now tail is pointing to the last node

        tail->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Time Complexity -> O(n)
    void insertAtTail(int data)
    {
        if (!head)
        {
            insertAtHead(data);
            return;
        }
        Node<int> *newNode = new Node(data);
        Node<int> *tail = head;

        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = newNode;
        newNode->next = head;
    }

    // Time Complexity -> O(n)
    // uses 0 based indexing
    void insertAtKthPos(int data, int k)
    {
        if (!head)
        {
            insertAtHead(data);
            return;
        }

        int count = 0;
        Node<int> *temp = head;
        while (count < k - 1)
        {
            temp = temp->next;
            count++;
        }
        Node<int> *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtHead()
    {
        if (!head)
        {
            return;
        }

        Node<int> *temp = head;
        Node<int> *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }

        head = head->next;
        tail->next = head;
        free(temp);
    }

    // Time Complexity -> O(n)
    void deleteAtTail()
    {
        if (!head)
        {
            return;
        }

        Node<int> *tail = head;
        while (tail->next->next != head)
        {
            tail = tail->next;
        }
        // now tail is pointing to second last pointer

        Node<int> *temp = tail->next;
        tail->next = tail->next->next;
        free(temp);
    }

    // follows 0 based indexing
    // Time Complexity -> O(n)
    void deleteAtKthPos(int k)
    {
        if (!head)
            return;

        int count = 0;
        Node<int> *temp = head;
        while (count < k - 1)
        {
            temp = temp->next;
            count++;
        }
        // now temp is pointing to the (k-1)th node

        Node<int> *dummy = temp->next;
        temp->next = temp->next->next;
        free(dummy);
    }

    void display()
    {
        Node<int> *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "null" << endl;
    }

    void printCircular()
    {
        Node<int> *temp = head;
        for (int i = 0; i < 10; i++)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    CircularLinkedList cll;
    cll.insertAtHead(3);
    cll.insertAtHead(2);
    cll.insertAtHead(1);
    cll.insertAtTail(4);
    cll.insertAtTail(5);
    cll.insertAtKthPos(4, 5); // 0 based indexing
    cll.display();

    // cll.deleteAtHead();
    // cll.deleteAtTail();
    cll.deleteAtKthPos(5);
    cll.display();
    // cll.printCircular();

    // Node<char> *node = new Node<char>('a');
    // cout << node->data << endl;

    return 0;
}