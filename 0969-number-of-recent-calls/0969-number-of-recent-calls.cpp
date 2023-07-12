class RecentCounter {
public:
    priority_queue<int,vector <int>, greater<int>> pq;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pq.push(t);
        while(pq.top()<t-3000){
            pq.pop();
        }
        return pq.size();
        //range of t-3000,t
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */