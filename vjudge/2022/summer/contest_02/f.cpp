#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
const int P = 1e9 + 7;

vector<pair<double, double>> hives;
bool isSour[100];
double distance(pair<double, double> a, pair<double, double> b){
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    double d;
    int n;
    while(true){
        hives.clear();
        cin >> d;
        cin >> n;
        if(d == 0 && n == 0) break;
        for(int i = 0; i < n; ++i){
            isSour[i] = false;
        }
        double x, y;
        int sour = 0, sweet = 0;
        for(int i  = 0; i < n; ++i){
            cin >> x >> y;
            hives.emplace_back(x, y);
        }
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                if(distance(hives[i], hives[j]) < d){
                    isSour[i] = true;
                    isSour[j] = true;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            if(isSour[i]) ++sour;
            else ++sweet;
        }
        cout << sour << " sour, " << sweet << " sweet\n";
    }
    return 0;
}