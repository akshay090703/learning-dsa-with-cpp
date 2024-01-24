#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// All operations will take O(1) time complexity (average)
// Or when all the values will be in one list, only then will the complexity be O(n) (absolute worst case)
// we will have a vector of list
class Hashing
{
    vector<list<int>> hashTable;
    int size; // number of buckets in the table

public:
    Hashing(int size)
    {
        this->size = size;
        hashTable.resize(size);
    }

    int hashValue(int key)
    {
        return key % size; // division method
    }

    void add(int key)
    {
        int idx = hashValue(key);
        hashTable[idx].push_back(key);
    }

    list<int>::iterator search(int key)
    {
        int idx = hashValue(key);
        return find(hashTable[idx].begin(), hashTable[idx].end(), key);
    }

    void deleteKey(int key)
    {
        int idx = hashValue(key);
        if (search(key) != hashTable[idx].end()) // key is present
        {
            hashTable[idx].erase(search(key));
            cout << key << " is deleted." << endl;
        }
        else
        {
            cout << "Key not present in hashtable." << endl;
        }
    }
};

int main()
{
    Hashing *h = new Hashing(10);

    h->add(5);
    h->add(9);
    h->add(3);
    h->add(2);

    h->deleteKey(3);
    h->deleteKey(3);

    return 0;
}