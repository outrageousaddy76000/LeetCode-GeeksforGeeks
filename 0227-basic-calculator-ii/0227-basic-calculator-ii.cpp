class Solution {
private:
    bool isOperator(string c){
        return c=="*" || c=="/" || c=="+" || c=="-";
    }
    string applyOp(string op, int a, int b){
        // cout<<a<<" "<<b<<endl;
        if(op=="*") return to_string(a*b);
        if(op=="/") return to_string(a/b);
        if(op=="-") return to_string(a-b);
        else return to_string(a+b);
    }
public:
    int calculate(string s) {
        //first perform multiplication and division
        string curr="";
        queue <string> q; 
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') continue;
            if(isOperator(string(1,s[i]))){
                q.push(curr);
                q.push(string (1, s[i]));
                curr="";
            }
            else curr+=s[i];
        }
        q.push(curr);
        vector <string> v;
        while(!q.empty()){
            if(q.front()=="*" || q.front()=="/"){
                string op = q.front();
                int current = stoi(v[v.size()-1]);
                q.pop();
                int next = stoi(q.front());
                v.pop_back();
                v.push_back(applyOp(op,current,next));
            }
            else v.push_back(q.front());
            // cout<<q.front()<<" ";
            q.pop();
        }
        int ans=stoi(v[0]);
        for(int i=1;i<v.size();i+=2){
            string curr=applyOp(v[i],ans,stoi(v[i+1]));
            ans=stoi(curr);
        }
        return ans;
    }
};