#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    // st.pop();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.top() << endl;
    st.push(5);
    st.push(6);
    cout << st.top() << endl;
    st.pop();
    st.pop();
    cout << st.top() << endl;
    cout << st.empty() << endl; // false

    return 0;
}