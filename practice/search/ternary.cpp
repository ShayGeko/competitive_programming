#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
int f(int x);
int ternary_search(int lo, int hi){
    while(hi - lo > 1){
        int mid = (hi + lo) >> 1;
        if(f(mid) > f(mid + 1))
            hi = mid;
        else lo = mid;
    }

    return f(lo + 1);
}
vector<int> nums;

int f(int x){
    return nums[x];
}
int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    nums.resize(n);
    // nums is guaranteed to be unimodal
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    // returns the max element of nums
    cout << ternary_search(-1, n);
    return 0;
}