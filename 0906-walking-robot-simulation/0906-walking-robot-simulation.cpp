class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<int,set<int>> obsrow,obscol;
        for(auto &val:obstacles){
            int x = val[0];
            int y = val[1];
            obscol[val[0]].insert(val[1]);
            obsrow[val[1]].insert(val[0]);
        }
        int currx=0,curry=0,dir=0;
        //0 - north,1 - east, 2 - south, 3 - west
        int ans=0;
        for(auto& val : commands) {
            if(val == -1) {
                dir++;
                dir %= 4;
            }
            else if(val == -2) {
                dir += 3;
                dir %= 4;
            }
            else {
                if(dir == 0) {
                    // north
                    if(obscol[currx].empty()) {
                        curry += val;
                    } else {
                        auto it = obscol[currx].upper_bound(curry);
                        if(it == obscol[currx].end() || *it > curry + val) {
                            curry += val;
                        } else {
                            curry = *it - 1;
                        }
                    }
                }   
                else if(dir == 1) {
                    // east
                    if(obsrow[curry].empty()) {
                        currx += val;
                    } else {
                        auto it = obsrow[curry].upper_bound(currx);
                        if(it == obsrow[curry].end() || *it > currx + val) {
                            currx += val;
                        } else {
                            currx = *it - 1;
                        }
                    }
                }
                else if(dir == 2) {
                    // south
                    if(obscol[currx].empty()) {
                        curry -= val;
                    } else {
                        auto it = obscol[currx].lower_bound(curry);
                        if(it == obscol[currx].begin()) {
                            curry -= val;
                        } else {
                            it--;
                            if(*it < curry - val) {
                                curry -= val;
                            } else {
                                curry = *it + 1;
                            }
                        }
                    }
                }
                else {
                    // west
                    if(obsrow[curry].empty()) {
                        currx -= val;
                    } else {
                        auto it = obsrow[curry].lower_bound(currx);
                        if(it == obsrow[curry].begin()) {
                            currx -= val;
                        } else {
                            it--;
                            if(*it < currx - val) {
                                currx -= val;
                            } else {
                                currx = *it + 1;
                            }
                        }
                    }
                }
            }
            ans=max(ans,currx*currx + curry*curry);
        }
        return ans;
    }
};