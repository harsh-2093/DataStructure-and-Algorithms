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
        if(helper.empty())
        {
            while(!st.empty())
            {
                helper.push(st.top());
                st.pop();
            }
        }
        if(helper.empty())
        {
            return -1;
        }
        else
        {
            int val=helper.top();
            helper.pop();
            return val;
        }
    }
    
    int peek() {
        if(helper.empty())
        {
            while(!st.empty())
            {
                helper.push(st.top());
                st.pop();
            }
        }
        if(helper.empty())
        {
            return -1;
        }
        else
        {
            return helper.top();
        }
    }

    
    bool empty() {
        if(st.empty()&& helper.empty())
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