class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans=0;
        int check=0;
        for(int i=0;i<colors.size();){
            //check if k contiguos form group starting from index i
            if(!check){
                int done=0;
                for(int j=i;j<i+k-1;j++){
                   if(colors[j%colors.size()]==colors[(j+1)%colors.size()]){
                       //test has failed, start from j+1
                       i=j+1;
                       done=1;
                       break;
                   }
                }
                if(!done){
                    //i is a good starting point
                    ans++;
                    i++;
                    check=1;
                }
            }
            else{
                if(colors[(i+k-1)%colors.size()]!=colors[(i+k-2)%colors.size()]){
                    ans++;
                    i++;
                }
                else{
                    check=0;
                    i=i+k-1;
                }
            }
        }
        return ans;
    }
};