class MyStack {
public:
    queue <int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int ret = q1.front();
        q1.pop();
        queue <int> temp = q1;
        q1=q2;
        q2=temp;
        return ret;
    }
    
    int top() {
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int ret = q1.front();
        q2.push(q1.front());
        q1.pop();
        queue <int> temp = q1;
        q1=q2;
        q2=temp;
        return ret;
    }
    
    bool empty() {
        if(q1.size()) return false;
        return true;
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