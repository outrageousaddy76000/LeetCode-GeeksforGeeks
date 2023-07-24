class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int cnt1 = count(students.begin(),students.end(),0);
        int cnt2 = n-cnt1;
        for(int i=0;i<n;i++){
            if(sandwiches[i]==0){
                cnt1--;
            }
            else{
                cnt2--;
            }
            if(cnt1<0 || cnt2<0) return sandwiches.size()-i;
        }
        return 0;
    }
};