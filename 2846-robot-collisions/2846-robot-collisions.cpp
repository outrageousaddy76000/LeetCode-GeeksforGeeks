class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, pair<int, int>>> robots;
        map <int,int> m;
        for (int i = 0; i < positions.size(); i++) {
            m[positions[i]]=i;
            robots.push_back({positions[i], {directions[i] == 'R' ? 1 : 0, healths[i]}});
        }
        
        // Sort robots by their positions
        sort(robots.begin(), robots.end());

        stack<pair<int, pair<int, int>>> st;
        for (int i = 0; i < robots.size(); i++) {
            if (st.empty()) {
                st.push(robots[i]);
            } else {
                while (!st.empty() && st.top().second.first == 1 && robots[i].second.first == 0) {
                    if (robots[i].second.second < st.top().second.second) {
                        st.top().second.second--;
                        robots[i].second.second = 0;
                        break;
                    } else if (robots[i].second.second == st.top().second.second) {
                        robots[i].second.second = 0;
                        st.pop();
                        break;
                    } else {
                        robots[i].second.second--;
                        st.pop();
                    }
                }
                if (robots[i].second.second > 0) {
                    st.push(robots[i]);
                }
            }
        }

        vector<pair<int,int>> v;
        while (!st.empty()) {
            v.push_back({st.top().first,st.top().second.second});
            st.pop();
        }
        //now positions wise sorting
        sort(v.begin(),v.end(),[&m](const pair<int,int> a, const pair <int,int> b){
            return m[a.first]<m[b.first];
        });
        vector <int> ans;
        for(auto &val:v) ans.push_back(val.second);
        return ans;
    }
};