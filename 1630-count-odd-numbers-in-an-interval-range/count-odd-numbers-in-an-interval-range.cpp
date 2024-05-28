class Solution {
public:
    int countOdds(int low, int high) {
        return (high+1)/2-low/2; // odd numbers from 1 to n == (n+1)/2
        // Therefore odd numbers between high and low = countOdds(1,high) - countOdds(1,low-1)
        // 'low-1' because we want to include low
    }
};