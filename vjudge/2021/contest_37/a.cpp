#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    int n;
    int a, b, c;
    int match;
    int extra, i;
    while(t--){
        cin >> n;
        cin >> a >> b >> c;
        n -= 3;
        i = 3;
        if(a == b) {
            match = a;
            if(a != c) extra = 3;
        }
        else if(a == c) {
            match = a;
            extra = 2;
        }
        else if(b == c) {
            match = b;
            extra = 1;
        }

        while(n--){
            cin >> c;
            ++i;
            if(c != match) extra = i;
        }
        cout << extra << '\n';
    }

    return 0;
}