class Solution {
public:
    int numTeams(vector<int>& rating) {
        //how many numbers greater than rating[i] are there, how many less are there
        vector <int> dpi(rating.size()),dpd(rating.size());
        int ans=0;
        //popultale the dp
        for(int i=rating.size()-1;i>=0;i--){
            for(int j=i+1;j<rating.size();j++){
                if(rating[j]>rating[i]) dpi[i]++;
                else dpd[i]++;
            }
        }
        for(int i=0;i<rating.size();i++){
            //choose the ith
            for(int j=i+1;j<rating.size();j++){
                //choose the jth
                if(rating[j]>rating[i]) ans+=dpi[j];
                else ans+=dpd[j];
            }
        }
        return ans;
    }
};