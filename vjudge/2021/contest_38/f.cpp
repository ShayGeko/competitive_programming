#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3000;

int lcs[MAXN][MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;
    lcs[0][0] = (s[0] == t[0]);
    for (int i = 1; i < s.length(); ++i) {
        lcs[i][0] = max(lcs[i-1][0], (int)(s[i] == t[0]));
        lcs[0][i] =max(lcs[0][i-1], (int)(s[0] == t[i]));
    }
    for (int i = 1; i < s.length(); ++i){
        for (int j = 1; j < t.length(); ++j) {
            if (s[i] == t[j]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    int n = s.length(), m = t.length();
    stack<char> st;
    for(int i = n - 1, j = m - 1; i >= 0 && j >= 0;){
        if(s[i] == t[j]){
            st.push(s[i]);
            i--;
            j--;
        }
        else if(i > 0 && lcs[i][j] == lcs[i-1][j]) i--;
        else j--;
    }

    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}