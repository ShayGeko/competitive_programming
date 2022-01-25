#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

double delta = 1e-7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        if (m % 4 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}