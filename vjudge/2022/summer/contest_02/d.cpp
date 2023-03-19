#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
const int P = 1e9 + 7;

int nums[1001];
string s;
char get(bool a){
    if(a) return 'B';
    else return 'R';
}
void fill(int pos){
    bool l_v, r_v;
    l_v = r_v = s[pos] != 'B';
    int l = pos - 1, r = pos + 1;

    while(l >= 0 && s[l] == '?'){
       s[l] = get(l_v);
       l_v = !l_v;
       l--;
    }
    while(r < s.length() && s[r] == '?'){
        s[r] = get(r_v);
        r_v = !r_v;
        r++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    int n;
    bool painted;
    while(t--){
        cin >> n;
        cin >> s;
        painted = false;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] != '?') {
                painted = true;
                fill(i);
            }
        }
        if(!painted){
            bool k = false;
            for(int i = 0; i < n; ++i){
                s[i] = get(k);
                k = !k;
            }
        }
        cout << s << '\n';
    }
    return 0;
}