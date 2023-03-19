#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 2e6 + 1;
const int INF = 1e9;

int arr[MAXN], minStepsToZero[MAXN];
bool used[MAXN];

bool getPaths(vector<int> &paths, int n, int d){
    memset(used, '\0',  n);
    for(int i = 0; i < n; ++i){
        if(!used[i]) {
            int firstZeroIndex = -1;
            int j = i;
            while (!used[j]) {
                used[j] = true;
                if(firstZeroIndex == -1 && !arr[j]) firstZeroIndex = j;
                j = (j + d) % n;
            }

            if(firstZeroIndex == -1) return false;
            else paths.push_back(firstZeroIndex);
        }
    }

    return true;
}
int getMaxPathValue(vector<int> &paths, int n,int d){
    int maxPathValue = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i]) minStepsToZero[i] = INF;
        else minStepsToZero[i] = 0;
    }
    for (auto i: paths) {
        int cur = i;
        int next;
        do {
            next = (cur + d) % n;
            if (minStepsToZero[next] == 0) {
                maxPathValue = max(maxPathValue, minStepsToZero[cur]);
            } else {
                minStepsToZero[next] = minStepsToZero[cur] + 1;
            }

            cur = next;
        } while (cur != i);
    }

    return maxPathValue;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, d;
        cin >> n >> d;
        for(int i = 0; i < n; ++i) cin >> arr[i];

        vector<int> paths;

        bool isFinite = getPaths(paths, n, d);

        if(isFinite){
            int ans = getMaxPathValue(paths, n, d);
            cout << ans << '\n';
        }
        else  cout << "-1\n";
    }
    return 0;
}