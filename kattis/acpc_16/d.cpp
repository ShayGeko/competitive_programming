#include <bits/stdc++.h>

using namespace std;

const int maxn = 20002;
pair <int, int> flowers[maxn];
set<int> primes;
bool used[maxn];
pair <int, double> dp[maxn];

double distance(int i, int j){
    int a = flowers[i].first - flowers[j].first;
    int b = flowers[i].second - flowers[j].second;

    return sqrt(a*a + b*b);
}
void erat(){
    primes.insert(0); // dont get mad lmao
    for(int i = 2; i < maxn; ++i){
        if(!used[i]) {
            primes.insert(i);
            for(int j = i; j < maxn; j+=i)
                used[j] = true;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    int n;
    double d;

    erat();
    while(t--){
        cin >> n >> d;

        for(int i = 1; i <= n; ++i) {
            cin >> flowers[i].first >> flowers[i].second;
        }

        dp[0] = {0,0};

        for(int i = 0; i <= n; ++i){
            for(int j = i + 1; j <= n; ++j){
                if(dp[j].first < dp[i].first + 1 && dp[i].second + distance(i, j) < d){
                    dp[j].first = dp[i].first + 1;
                    dp[j].second = dp[i].second + distance(i, j);
                }
                else if(dp[j].first == dp[i].first + 1 && dp[i].second + distance(i, j) < dp[j].second){
                    dp[j].second = dp[i].second + distance(i, j);
                }
            }
        }

        int max = 0;
        for(int i = 0; i <= n; ++i){
            if(dp[i].first > max) max = dp[i].first;
        }
        cout << *(--primes.upper_bound(max)) << '\n';
    }
    return 0;
}