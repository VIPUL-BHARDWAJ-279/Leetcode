class Solution {
public:
    int numWaterBottles(int x, int a) {
        return (x*a-1)/(a-1);
    }
};