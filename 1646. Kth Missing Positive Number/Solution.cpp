class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
            int n = arr.size();
            int low = 0;
            int high = n - 1;
            while (low <= high)
            {
                int midIndex = (low + high) / 2;
                //The index for which we will check missing  no
                int missingNoTillMid = arr[midIndex] - (midIndex + 1);
                //Finding Missing No till that index
                if (missingNoTillMid < k)
                {
                    //If the missing no is has not reached around k
                    low = midIndex + 1;
                }
                else
                //If it has exceede k
                    high = midIndex - 1;
            }
            return high + k + 1;
    }
};