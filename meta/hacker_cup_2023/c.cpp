#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define has(a, b) (a.find(b) != a.end())
#define imin(a, b) a = min(a, b)
#define imax(a, b) a = max(a, b)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define fora(i, n) for (int i = 0; i < n; i++)
#define forb(i, n) for (int i = 1; i <= n; i++)
#define forc(a, b) for (const auto &a : b)
#define ford(i, n) for (int i = n; i >= 0; i--)

typedef pair<int, int> pii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

template <class T>
istream &operator>>(istream &is, pair<T, T> &p) {
    is >> p.first >> p.second;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, pair<T, T> &p) {
    os << p.first << " " << p.second;
    return os;
}
template <class T>
pair<T, T> operator+(pair<T, T> &a, pair<T, T> &b) {
    return {a.first + b.first, a.second + b.second};
}

template <class T>
pair<T, T> operator-(pair<T, T> &a, pair<T, T> &b) {
    return {a.first - b.first, a.second - b.second};
}

template <class T>
vector<T> operator+(const vector<T> &a, const vector<T> &b) {
    assert(sz(a) == sz(b));

    vector<T> res(a);
    fora(i, sz(b)) { res[i] += b[i]; }

    return res;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int N = 2 * n - 1;
    vll nums(N);

    for (auto &x : nums) {
        cin >> x;
    }

    if (N == 1) {
        cout << nums[0] << '\n';
        return;
    }
    sort(all(nums));

    auto check = [&](int l, int r, ll sum = -1) {
        if (sum < 0) sum = nums[l++] + nums[r--];
        bool isSumValid = true;
        while (isSumValid && l < r) {
            if (nums[l] + nums[r] != sum)
                isSumValid = false;
            else
                l++, r--;
        }
        return tuple<int, int, bool>{l, r, isSumValid};
    };

    ll sum = nums[0] + nums[N - 2];
    set<ll> ans;
    if (get<2>(check(0, N - 2)) && sum - nums.back() > 0) {
        ans.insert(sum - nums.back());
    }

    sum = nums[1] + nums[N - 1];
    if (get<2>(check(1, nums.size() - 1)) && sum - nums[0] > 0) {
        ans.insert(sum - nums[0]);
    }

    auto [l, r, isSumValid] = check(0, nums.size() - 1);
    sum = nums[0] + nums.back();
    if (isSumValid && sum - nums[l] > 0) {
        ans.insert(sum - nums[l]);
    }

    if (!isSumValid) {
        if (get<2>(check(l + 1, r, sum)) && sum - nums[l] > 0) {
            ans.insert(sum - nums[l]);
        }
        if (get<2>(check(l, r - 1, sum)) && sum - nums[r] > 0) {
            ans.insert(sum - nums[r]);
        }
    }

    if (ans.size()) {
        cout << *ans.begin() << '\n';
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;

    cin >> t;

    rep(i, 1, t + 1) {
        cout << "Case #" << i << ": ";
        solve();
    }
    cout.flush();

    return 0;
}