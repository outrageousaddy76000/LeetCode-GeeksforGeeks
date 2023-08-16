class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int ind1=-1,ind2=-1,cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                cnt++;
                if(ind1!=-1){
                    ind2=i;
                }
                else{
                    ind1=i;
                }
                if(cnt>2) return false;
            }
        }
        if(ind2==-1) return false;
        swap(s1[ind1],s1[ind2]);
        return s1==s2;
    }
};