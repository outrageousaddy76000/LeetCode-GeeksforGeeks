class Solution {
public:
    double calculateArea(double x1, double y1, double x2, double y2, double x3, double y3) {
        double area = 0.5 * std::abs((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)));
        return area;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans=INT_MIN;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                for(int k=j+1;k<points.size();k++){
                    ans=max(ans,calculateArea(points[i][0],points[i][1],points[j][0],points[j][1],points[k][0],points[k][1]));
                }
            }
        }
        return ans;
    }
};