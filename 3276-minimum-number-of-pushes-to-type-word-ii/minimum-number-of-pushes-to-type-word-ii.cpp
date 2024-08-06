class Solution {
public:
    int minimumPushes(string word) {
        int arr[26] = {0};
        for(char c : word) {
            arr[c - 'a']++;
        }
        sort(arr, arr + 26, greater<int>());
        int count = 0, ans = 0, start = 1;
        for(int i = 0; i < 26; i++) {
            if(arr[i] == 0) {
                break;
            }
            ans += start * arr[i];
            count++;
            if(count == 8) {
                start++;
                count = 0;
            }
        }
        return ans;
    }
};