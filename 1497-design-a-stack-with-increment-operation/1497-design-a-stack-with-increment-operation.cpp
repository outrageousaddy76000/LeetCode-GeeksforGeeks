class CustomStack {
public:
    vector <int> v;
    int index=-1;
    CustomStack(int maxSize) {
        v.resize(maxSize);
    }
    
    void push(int x) {
        if(index!=v.size()-1){
            index++;
            v[index]=x;
        } 
    }
    
    int pop() {
        if(index==-1) return -1;
        return v[index--];
    }
    
    void increment(int k, int val) {
        for(int i=0;i<=min(k-1,index);i++){
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */