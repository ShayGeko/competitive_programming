#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 2;
const int INF = 1e9;
set<int> s;
vector<int> divisors;
bool check(int x){
    for(auto t : s){
        if(t % x) return false;
    }
    return true;
}
int bin_search(int l, int r){
    if(l >= r - 1){
        if(check(divisors[r])){
            return divisors[r];
        }
        else return divisors[l];
    }
    int m = (r + l) / 2;
    if(check(divisors[m])){
        return bin_search(m, r);
    }
    else return bin_search(l, m - 1);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, x;
    cin >> n >> x;
    int temp;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        s.insert((temp - x < 0) ? (x - temp): (temp - x));
    }
    int first =*(s.begin());

    for(int i = 1; i <= sqrt(first) + 1; ++i){
        if(!(first % i)) {
            divisors.push_back(i);
            divisors.push_back(first / i);
        }
    }
    std::sort(divisors.begin(), divisors.end());

    for(int i = divisors.size() - 1; i >= 0; i--){
        if(check(divisors[i])) {
            cout << divisors[i] << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';

    return 0;
}