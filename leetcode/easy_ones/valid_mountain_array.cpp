class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        if(arr[0] >= arr[1]) return false;
        int i = 1;
        while(i < n && arr[i] > arr[i - 1]){++i;}
        if(i >= n) return false;
        while(i < n && arr[i] < arr[i - 1]){++i;}
        return i == n;
    }
};