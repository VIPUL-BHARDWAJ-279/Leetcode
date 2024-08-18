class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> seti;
        long long currentUglyNum=1;
        seti.insert(currentUglyNum);
        
        for(int i=0;i<n;i++){
            currentUglyNum=*seti.begin();
            seti.erase(currentUglyNum);
            seti.insert(currentUglyNum*2);
            seti.insert(currentUglyNum*3);
            seti.insert(currentUglyNum*5);
        }

        return currentUglyNum;
    }
};