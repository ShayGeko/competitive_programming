#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
long long x, y, aim;
void move(string dir, int cnt){
    switch(dir[0]){
        case 'f': {
            x+=cnt;
            y+=aim*cnt;
        }
            break;
        case 'd': aim+=cnt;
            break;
        case 'u': aim-=cnt;
        default:
            break;
    }

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string dir;
    int cnt;
    string input;
    while(getline(cin, input)){
        stringstream ss(input);
        ss >> dir >> cnt;
        move(dir, cnt);
    }
    cout << x * y << '\n';
    return 0;
}