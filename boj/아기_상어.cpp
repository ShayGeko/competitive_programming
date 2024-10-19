#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


    int n;
    cin >> n;
    vector<vi> nums(n, vi(n));
    
    int si, sj;

    vector<pii> fish;
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> nums[i][j];
            if(nums[i][j] == 9) {si = i; sj = j;}
            else if(nums[i][j]) fish.push_back({i, j});
        }
    }

    vector<bool> eaten(n, false);
    int available = sz(fish);
    int time = 0;

    // at any point want to know what is the best next shark
    // greedy doesnt work I 
    // 
    // <= 400 fish
    // not bitmask, maybe N^3?



    // distance, row, col, idx
    typedef array<int, 4> fish_t;
    int size = 2;
    int cur = 0;
    int cnt = 0;
    while(available) {
        fish_t best = {(int)1e9, (int)1e9, (int)1e9, -1};
        queue<pii> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({si, sj});
        visited[si][sj] = true;
        int length=0;
        q.push({-1, -1});
        while(!q.empty()) {
            auto [fi, fj] = q.front();q.pop();

            if(nums[fi][fj] && nums[fi][fj] != 9) {
                best = min(best, {length, fi, fj});
            }
        }

        if(best[3] != -1) {
            --available;
            eaten[best[3]] = true;

            ++cur;
            if(cur == size) {
                ++size;
                cur = 0;
            }
            cnt += best[0];
            si = best[1];
            sj = best[2];
        } else{
             break;
        }
    }

    cout << cnt << '\n';
	return 0;
}