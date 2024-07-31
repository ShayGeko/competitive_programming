#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int queens(int fullmask, int row, int ld, int rd, int cnt=0) {
    int freeCell = ~(row|ld|rd) & fullmask;

    while (freeCell) {
        // choose the last set bit
        int pos = -freeCell&freeCell;
        // put a queen there
        freeCell ^= pos; 

        // diagonal masks need to be shifted in the direction of diagonal
        cnt += queens(fullmask, (row | pos), (ld | pos) << 1, (rd | pos) >> 1);
    }

    return cnt += row == fullmask;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    int cnt = queens((1<<n)-1, 0,0,0);

    cout << cnt << '\n';

	return 0;
}