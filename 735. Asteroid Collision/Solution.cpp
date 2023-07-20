class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        for(int i=0;i<asteroids.size();i++){
            if(i){
                while(1){
                    if(st.size() && asteroids[i]*st.top()<0 && asteroids[i]<0){
                        //both diff sign
                        if(abs(asteroids[i])==abs(st.top())){
                            st.pop();
                            break;
                        }
                        else if(abs(asteroids[i])>abs(st.top())){
                            st.pop();
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        st.push(asteroids[i]);
                        break;
                    }
                }
            }
            else st.push(asteroids[i]);
        }
        vector <int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};