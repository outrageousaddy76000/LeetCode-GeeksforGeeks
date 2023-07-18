class Solution {
public:
    bool isLeap(int year){
        if((year%4==0 && year%100!=0) || year%400==0) return true;
        return false;
    }
    int ndays(string date){
        unordered_map <int,int> m;
        m[1]=31;
        m[2]=28;
        m[3]=31;
        m[4]=30;
        m[5]=31;
        m[6]=30;
        m[7]=31;
        m[8]=31;
        m[9]=30;
        m[10]=31;
        m[11]=30;
        m[12]=31;
        int year = stoi(date.substr(0,4),0,10);
        int day = stoi(date.substr(8,2),0,10);
        int month = stoi(date.substr(5,2),0,10);
        int cnt=0;
        m[2]+=isLeap(year);
        for(int i=1971;i<year;i++){
            cnt+=(isLeap(i)?366:365);
        }
        for(int i=1;i<month;i++){
            cnt+=m[i];
        }
        cnt+=day;
        return cnt;
    }
    int daysBetweenDates(string date1, string date2) {
        //calculate from 1 jan 1971 and take abs diff
        return abs(ndays(date1)-ndays(date2));
    }
};