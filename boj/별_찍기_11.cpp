#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vector<vector<char>> grid;
vector<string> lines = {
    "*",
    "* *",
    "*****"
};
int H;
void print(int height, int triangleHeight, int offset) {
    if(triangleHeight == 3) {
        rep(i, 0, 3) {
            rep(j, 0, sz(lines[i])) {
                grid[height + i][offset -i + j] = lines[i][j];
            }
        }
    } else {
        triangleHeight /= 2;
        print(height, triangleHeight, offset);
        print(height + triangleHeight, triangleHeight, offset - triangleHeight);
        print(height + triangleHeight, triangleHeight, offset + triangleHeight);
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    grid = vector<vector<char>> (n, vector<char>(2*n, ' '));


    print(0, n, n-1);

    for(auto &x : grid) {
        for(auto &y : x) cout << y;
        cout << '\n';
    }
	return 0;
}