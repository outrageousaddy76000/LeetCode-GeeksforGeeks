class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        //even - first and last
        //odd - first
        //0 - last
        set <int> s;
        vector <int> ans;
        int n = digits.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i) continue;
                for(int k=0;k<n;k++){
                    if(k==j || k==i) continue;
                    if(digits[i]==0){
                        if(digits[k]!=0)
                        s.insert(100*digits[k]+10*digits[j]);
                    }
                    else if(digits[i]&1){
                        s.insert(100*digits[i]+10*digits[j]+digits[k]);
                    }
                    else{
                        s.insert(100*digits[i]+10*digits[j]+digits[k]);
                        if(digits[k]!=0)
                        s.insert(100*digits[k]+10*digits[j]+digits[i]);
                    }
                }
            }
        }
        for(auto &val:s){
            if(val%2==0)
            ans.push_back(val);
        }
        return ans;
    }
};