#include <bits/stdc++.h>

using namespace std;
const int MAXN = 400;

char arr[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    int n;
    while(t--){
        cin >> n;

        int x1,y1, x2,y2;
        bool found = false;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> arr[i][j];
                if(arr[i][j] == '*'){
                    if(!found){
                        x1 = j; y1 = i;
                        found = true;
                    }
                    else {x2 = j; y2 = i;}
                }
            }
        }
        if(y1 == y2){
            if(y1 > 0){
                y1 = y2 = 0;
            }
            else y1 = y2 = n-1;
        }
        else if(x1 == x2){
            if(x1 > 0){
                x1 = x2 = 0;
            }
            else x1 = x2 = n-1;

        }
        arr[y1][x2] = '*';
        arr[y2][x1] = '*';


        for(int i = 0; i < n; ++i){
            for(int j = 0;j < n; ++j){
                cout << arr[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}