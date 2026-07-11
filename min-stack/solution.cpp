class MinStack {
    stack<int>st;
    stack<int>min_st;
public:
     int min_value=INT_MAX;
    MinStack() {
       
    }
    
    void push(int value) {
        st.push(value);
        if(min_value>=value)
        {
            min_value=value;
            min_st.push(min_value);
        }

    }
    
    void pop() {
        if(st.top()==min_st.top() && !min_st.empty())
        {
            min_st.pop();
            if(!min_st.empty())
            {
                min_value=min_st.top();
            }
            else
            {
                min_value=INT_MAX;
            }
            
        }
        st.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */