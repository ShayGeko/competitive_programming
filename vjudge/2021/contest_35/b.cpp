#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> rotations;
        int arr[MAXN];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        for(int i = 0; i < n; ++i){
            int minim = i;
            bool swapped = false;
            for(int j = i + 1; j < n; ++j){
                if(arr[minim] > arr[j]){
                    minim = j;
                    swapped = true;
                }
            }
            if(swapped){
                // how cool is this
                rotations.emplace_back(i + 1, minim + 1);
                rotate(arr + i, arr + minim, arr + minim + 1);
            }
        }
        cout << rotations.size() << '\n';
        for(auto r: rotations){
            cout << r.first << " " << r.second << " " << r.second - r.first << '\n';
        }
    }
}