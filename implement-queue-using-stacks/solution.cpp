class MyQueue {
    stack<int>in;
    stack<int>out;
   
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(out.empty())
        {
            while(!in.empty())
            {
                int value=in.top();
                in.pop();
                out.push(value);
            }
        }
        int value=out.top();
        out.pop();
        return value;
    }
    
    int peek() {
        if(out.empty())
        {
            while(!in.empty())
            {
                int value=in.top();
                in.pop();
                out.push(value);
            }
        }
        int value=out.top();
        return value;
    }
    
    bool empty() {
        if(out.empty())
        {
            while(!in.empty())
            {
                int value=in.top();
                in.pop();
                out.push(value);
            }
        }
        return out.empty();
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