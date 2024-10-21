class Solution {
private:
    int max(int a,int b){
        if(a>b) return a;
        return b;
    }
    int ans;
    void helper(string s, int index, set <string> taken){
        if(index==s.size()) ans=max(ans,taken.size());
        for(int len=1;index+len<=s.size();len++){
            string curr = s.substr(index,len);
            if(taken.find(curr)==taken.end()){
                //try taking it and move forward
                taken.insert(curr);
                helper(s,index+len,taken);
                taken.erase(curr);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        ans=0;
        set <string> taken;
        helper(s,0,taken);
        return ans;
    }
};