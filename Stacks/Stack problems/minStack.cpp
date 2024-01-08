#include <iostream>
#include <stack>
using namespace std;
#define ll long long int

// all the operations have O(1) space and time complexity
struct MinStack
{
    stack<int> s;
    ll min;

    MinStack()
    {
        this->min = INT_MAX;
    }

    void push(int data)
    {
        if (this->s.empty())
        {
            this->min = data;
            this->s.push(data);
        }
        else
        {
            this->s.push(data - this->min);
            if (this->min > data)
            {
                this->min = data;
            }
        }
    }

    void pop()
    {
        if (!this->s.empty())
        {
            if (this->s.top() >= 0)
            {
                this->s.pop();
            }
            else
            {
                this->min = this->min - this->s.top();
                this->s.pop();
            }
        }
    }

    int top()
    {
        if (this->s.size() == 1)
        {
            return this->s.top();
        }
        else if (this->s.top() < 0)
        {
            return this->min;
        }
        else
        {
            return s.top() + this->min;
        }
    }

    int getMin()
    {
        return this->min;
    }
};

int main()
{

    return 0;
}