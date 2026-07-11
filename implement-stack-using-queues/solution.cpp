class MyStack {
     queue<int>q;
public:
    MyStack() {
       
    }
    
    void push(int x) {
        q.push(x);
        if(q.size()>1){
        for(int i=0;i<q.size()-1;i++)
        {
            int value=q.front();
            q.pop();
            q.push(value);
        }
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */