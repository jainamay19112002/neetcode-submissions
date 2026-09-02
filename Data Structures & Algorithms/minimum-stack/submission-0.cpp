class MinStack {
public:
    stack<int>st;
    stack<int>minist;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(minist.empty() || minist.top()>=val)
        minist.push(val); 
    }
    
    void pop() {
        if(st.top()==minist.top())
        minist.pop();

        st.pop();
        
    }
    
    int top() {
        return st.top();

    }
    
    int getMin() {
        return minist.top();
        
    }
};
