class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector <int> ans(2);
        int alicetotal = accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int bobtotal = accumulate(bobSizes.begin(),bobSizes.end(),0);
        if(alicetotal>bobtotal){
            int x = alicetotal-bobtotal;
            unordered_map <int,int> m;
            for(int i=0;i<aliceSizes.size();i++){
                m[aliceSizes[i]]++;
            }
            for(auto val:bobSizes){
                int curr=x+2*val;
                if(curr%2!=0) continue;
                if(m.find(curr/2)!=m.end()){
                    ans[0]=curr/2;
                    ans[1]=val;
                    return ans;
                }
            }
        }
        else{
            int x = bobtotal-alicetotal;
            unordered_map <int,int> m;
            for(int i=0;i<bobSizes.size();i++){
                m[bobSizes[i]]++;
            }
            for(auto val:aliceSizes){
                int curr=x+2*val;
                if(curr%2!=0) continue;
                if(m.find(curr/2)!=m.end()){
                    ans[0]=val;
                    ans[1]=curr/2;
                    return ans;
                }
            }
        }
        return ans;
    }
};