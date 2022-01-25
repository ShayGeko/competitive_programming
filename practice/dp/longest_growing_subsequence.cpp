#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    vector<int> lgs (n);
    int length = 1;
    lgs[0] = nums[0];

    for(int i = 1; i < n; ++i){
        auto it = lower_bound(lgs.begin(), lgs.begin() + length, nums[i]);
        *it = nums[i];
        if(length < it - lgs.begin() + 1) ++length;
    }

    cout << length << '\n';
    return 0;
}