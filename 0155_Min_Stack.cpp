class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        sOrder.push(x);
        if (sMin.empty() or x <= sMin.top())
            sMin.push(x);
    }

    void pop()
    {
        if (sMin.top() == sOrder.top())
            sMin.pop();
        sOrder.pop();
    }

    int top()
    {
        return sOrder.top();
    }

    int getMin()
    {
        return sMin.top();
    }

private:
    stack<int> sOrder, sMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */