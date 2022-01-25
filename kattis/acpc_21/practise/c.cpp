#include <bits/stdc++.h>

using namespace std;

const int maxn = 101;
const int INF = 1e9;

bool uniq[7];
int present[7];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    int a;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(present[a]) uniq[a] = true;
        else present[a] = i + 1;
    }

    for(int i = 6; i >= 1; --i){
        if(present[i] && !uniq[i]) {
            cout << present[i] << '\n';
            return 0;
        }
    }
    cout << "none\n";
    return 0;
}