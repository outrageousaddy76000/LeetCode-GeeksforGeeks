class Solution {
public:
    int countOdds(int low, int high) {
        int x = high-low+1;
        return x/2 + (high%2 && low%2);
    }
};