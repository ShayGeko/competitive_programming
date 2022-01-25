#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        int arr[MAXN];
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        deque<int> deq;

        deq.push_back(arr[0]);

        for(int i = 1; i < n; ++i){
            if(arr[i] <= deq.front()) deq.push_front(arr[i]);
            else deq.push_back(arr[i]);
        }

        for(auto q : deq){
            cout << q << " ";
        }
        cout << '\n';
    }
    return 0;
}