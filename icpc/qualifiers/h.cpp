#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

const int maxnum = 100;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    int first;
    int temp;
    bool start = true;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        if(start) {
            first = temp;
            start = false;
        }
        else{
            if(temp % first == 0) {
                cout << temp << '\n';
                start = true;
            }
        }

    }
    return 0;
}