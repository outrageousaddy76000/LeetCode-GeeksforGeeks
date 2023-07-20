class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector <int> ans;
        for(int i=0;i<asteroids.size();i++){
            if(ans.size()==0){
                ans.push_back(asteroids[i]);
            }
            else{
                while(1){
                    if(ans.size()==0){
                        ans.push_back(asteroids[i]);
                        break;
                    }
                    else if(asteroids[i]*ans[ans.size()-1]>0 || asteroids[i]>0){
                        ans.push_back(asteroids[i]);
                        break;
                    }
                    else if(asteroids[i]<0){
                        if(abs(asteroids[i])==abs(ans[ans.size()-1])){
                            ans.pop_back();
                            break;
                        }
                        else if(abs(asteroids[i])<abs(ans[ans.size()-1])){
                            break;
                        }
                        else{
                            ans.pop_back();
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};