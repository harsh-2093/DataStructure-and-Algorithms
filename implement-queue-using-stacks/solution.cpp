class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>st;
    stack<int>helper;


    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {

        if(st.empty())
        {
            return -1;
        }
        while(!st.empty())
        {
            helper.push(st.top());
            st.pop();
        }
        int Val=helper.top();
        helper.pop();
        while(!helper.empty())
        {
            st.push(helper.top());
            helper.pop();
        }
        return Val;
    }
    
    int peek() {
        if(st.empty())
        {
            return -1;
        }
        while(!st.empty())
        {
            helper.push(st.top());
            st.pop();
        }
        int Val=helper.top();
        while(!helper.empty())
        {
            st.push(helper.top());
            helper.pop();
        }
        return Val;
    }

    
    bool empty() {
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
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