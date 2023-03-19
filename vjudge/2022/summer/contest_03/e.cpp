#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
int f(int x);
vector<int> nums;
int k;
bool check(int x){
    int count = 0;
    int sum = 0;
    for(auto num: nums){
        if(num > x) return false;

        sum+=num;
        if(sum > x){
            ++count;
            sum = num;
        }
    }
    return count < k;
}
int bin_search(int l, int r){
    while(r - l >= 1){
        int m = l + ((r - l) >> 1);
        if(check(m)) r = m;
        else l = m + 1;
    }
    return r;
}
int main(){
     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n >> k;
    nums.resize(n);
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }

    cout << bin_search(0, sum) << endl;
    return 0;
}