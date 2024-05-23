#include<bits/stdc++.h>
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        for(int i=0;i<operations.size();i++){         
            if(operations[i]=="+"){
                int last=record.back();
                record.pop_back();
                int secondLast=record.back();
                record.push_back(last);
                int num=last+secondLast;
                record.push_back(num);
            }
            else if(operations[i]=="D")record.push_back(2*record.back());
            else if(operations[i]=="C")record.pop_back();
            else record.push_back(stoi(operations[i]));
        }
        int sum=0;
        for(int i=0;i<record.size();i++)sum+=record[i];
        return sum;
    }
};