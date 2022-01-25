#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

double x[maxn];
double y[maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        double book_x, book_y;
        cin >> book_x >> book_y;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        bool works = false;
        for(int i = 0; i < n; ++i){
            if((x[i] - book_x) * (x[i] - book_x) + (y[i] - book_y)*(y[i] - book_y) <= 64.){
                works = true;
            }
        }
        if(works) cout << "light a candle\n";
        else cout << "curse the darkness\n";
    }
    return 0;
}