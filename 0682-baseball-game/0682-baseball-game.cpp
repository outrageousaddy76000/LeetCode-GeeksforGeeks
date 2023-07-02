class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack <int> st;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                b+=a;
                st.push(a);
                st.push(b);
            }
            else if(operations[i]=="D"){
                int a = st.top();
                a*=2;
                st.push(a);
            }
            else if(operations[i]=="C"){
                st.pop();
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        //sum all
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};