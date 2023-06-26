class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set <int> s;
        for(int i=0;i<candyType.size();i++){
            s.insert(candyType[i]);
        }
        //can eat max of candyType.size()/2 candies
        //s.size() is less we eat s.size()
        if(s.size()>candyType.size()/2){
            return candyType.size()/2;
        }
        return s.size();
    }
};