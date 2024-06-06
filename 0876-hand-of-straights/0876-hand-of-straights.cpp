class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //first group will have the smallest and +1 ...
        //second group will have the smallest remaining ans +1...
        multiset <int> st(hand.begin(),hand.end());
        if(hand.size()%groupSize!=0) return false;
        int n = hand.size()/groupSize;
        while(n--){
            //must make n groups
            //take beginning of multiset then find +1 and remove and so on...
            int first = *st.begin();
            st.erase(st.begin());
            first++;
            for(int i=1;i<groupSize;i++){
                auto it = st.find(first);
                if(it==st.end()) return false;
                else st.erase(it);
                first++;
            }
        }
        return true;
    }
};