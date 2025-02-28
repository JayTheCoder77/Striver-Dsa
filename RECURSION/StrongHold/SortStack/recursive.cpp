#include <stack>
using namespace std;

// Helper function to insert an element into the sorted stack
void insertSorted(stack<int>& st, int element) {
    // Base case: If the stack is empty or the top element is smaller than the current element
    if (st.empty() || st.top() <= element) {
        st.push(element);
        return;
    }

    // Otherwise, pop the top element and recursively call insertSorted to find the right place for the element
    int topElement = st.top();
    st.pop();
    insertSorted(st, element);

    // After the recursive call, push the popped element back
    st.push(topElement);
}

// Function to sort the stack using recursion
void sortStack(stack<int>& st) {
    // Base case: If the stack is empty, it's already sorted
    if (st.empty()) {
        return;
    }

    // Pop the top element from the stack
    int topElement = st.top();
    st.pop();

    // Recursively sort the remaining stack
    sortStack(st);

    // Insert the popped element back into the sorted stack
    insertSorted(st, topElement);
}

tc = o(n2)
sc = o(n)