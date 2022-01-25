#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int maxn = 100;
const int maxnum = 1e5+1;
int h[maxn], b[maxn];
int colh[maxnum], colb[maxnum];

bool desc_comp(int a, int b){
    return a > b;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int sumh = 0;
    int H, B;
    cin >> H;
    for(int i = 0; i < H; ++i) {
        cin >> h[i];
        sumh+=h[i];
    }
    sort(h, h + H, desc_comp);
    cin >> B;

    int sumb = 0;
    for(int i = 0; i < B; ++i){
        cin >> b[i];
        sumb+=b[i];
    }
    sort(b, b + B, desc_comp);
    colh[0] = 1;
    for(int i = 0; i < H; ++i){
        for(int j = sumh; j >= h[i]; j--){
            if(colh[j - h[i]]) {
                if (colh[j]) colh[j] = min(colh[j], colh[j - h[i]] + 1);
                else colh[j] = colh[j - h[i]] + 1;
            }
        }
    }
    colb[0] = 1;
    for(int i = 0; i < B; ++i){
        for(int j = sumb; j >= b[i]; j--){
            if(colb[j - b[i]]) {
                if (colb[j]) colb[j] = min(colb[j], colb[j - b[i]] + 1);
                else colb[j] = colb[j - b[i]] + 1;
            }
        }
    }
    int ans = INF;
    for(int i = 1; i <= min(sumh, sumb); ++i){
        if(colh[i] && colb[i]) ans = min(ans, colh[i] + colb[i]);
    }
    if(ans == INF) cout << "Impossible\n";
    else cout << ans - 2 << '\n';

    return 0;
}