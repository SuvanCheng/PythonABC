#include<stack>

class MyQueue {
    std::stack<int> inStack;
    std::stack<int> outStack;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        checkOutStack();
        int temp = outStack.top();
        outStack.pop();
        return temp;
    }

    /** Get the front element. */
    int peek() {
        checkOutStack();
        return outStack.top();
    }
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * node;
        
    }
};
    /** Returns whether the queue is empty. */
    bool empty() {
        return inStack.empty() && outStack.empty();
    }

    void checkOutStack() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */