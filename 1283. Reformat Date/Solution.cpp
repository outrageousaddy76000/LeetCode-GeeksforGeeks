class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> dayMap;
        unordered_map<string, string> monthMap;

        // Days unordered map
        string days[] = {"1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th",
                        "11th", "12th", "13th", "14th", "15th", "16th", "17th", "18th", "19th", "20th",
                        "21st", "22nd", "23rd", "24th", "25th", "26th", "27th", "28th", "29th", "30th", "31st"};

        for (int i = 1; i <= 31; ++i) {
            string key = days[i - 1];
            string value = (i < 10) ? "0" + to_string(i) : to_string(i);
            dayMap[key] = value;
        }

        // Months unordered map
        string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        for (int i = 1; i <= 12; ++i) {
            string key = months[i - 1];
            string value = (i < 10) ? "0" + to_string(i) : to_string(i);
            monthMap[key] = value;
        }
        stringstream ss(date);
        string word;
        string ans="";
        ss>>word;
        ans+=dayMap[word];
        ss>>word;
        ans='-'+ans;
        ans=monthMap[word]+ans;
        ss>>word;
        ans='-'+ans;
        ans=word+ans;
        return ans;
    }
};