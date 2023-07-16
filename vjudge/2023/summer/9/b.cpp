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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define fora(i, n) for(int i = 0; i < n; i++)
#define forb(i, n) for(int i = 1; i <= n; i++)
#define forc(a, b) for(const auto &a : b)
#define ford(i, n) for(int i = n; i >= 0; i--)

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
istream &operator >> (istream& is, pair<T, T> &p){
    is >> p.first >> p.second;
    return is;
}
template <class T>
ostream &operator << (ostream& os, pair<T, T> &p){
    os << p.first << " " << p.second;
    return os;
}
template <class T>
pair<T, T> operator + (pair<T,T> &a, pair<T,T> &b){
    return {a.first + b.first, a.second + b.second};
}

template <class T>
pair<T, T> operator - (pair<T,T> &a, pair<T,T> &b){
    return {a.first - b.first, a.second - b.second};
}

template<class T>
vector<T> operator+(const vector<T> &a, const vector<T> &b){
    assert(sz(a) == sz(b));

    vector<T> res(a);
    fora(i, sz(b)){
        res[i] += b[i];
    }

    return res;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vector<string> nums(n);
    for(auto &x : nums) {
        ll temp; cin >> temp;
        x = to_string(temp);
    }

    bool found = false;

    for(int i = 0; i < n && !found; ++i) {
        // cases:
        // different sizes - skip
        // 234 434 -> (9)34 434
        // 234 934 -> 234 (1)34
        // 134 934 -> skip
        // 143 934 -> 143 (1)34
        // 199 999 -> not possible?
        // 199 998 -> (9)99 998
        // 934 134 (already not sorted) -> 934 (2)34
        // 834 134 -> (9)34 134
        if(i && sz(nums[i]) == sz(nums[i-1])) {
            if(nums[i] < nums[i-1]){
                for(int j = 0;j < sz(nums[i-1]); ++j) {
                    // 834 134 -> 934 134
                    if(nums[i-1][j] < '9') {
                        nums[i-1][j] = '9';
                        break;
                    }
                    else{
                        if(nums[i][j] > '1'){
                            nums[i][j] = '1';break;
                        }
                        else{
                            nums[i][j]++;
                            break;
                        }
                    }
                }
                found = true;
                break;
            }
            if(sz(nums[i]) == 1) {
                if(nums[i-1][0] > '0') nums[i][0] = '0';
                else if(nums[i][0] < '9')nums[i-1][0] = '9';
                else continue;
                found = true;
                break;
            }
            else if(nums[i][0] == '9'){
                if(nums[i-1][0] > '1' || nums[i-1].substr(1) > nums[i].substr(1)){
                    nums[i][0] = '1';
                    found = true;
                    break;
                }
            }
        }
        if(i < n - 1 && sz(nums[i]) == sz(nums[i+1]) && nums[i] <= nums[i+1]){
            if(nums[i+1][0] != '9'){
                found = true;
                nums[i][0] = '9';
                break;
            }
        }
    }

    if(found) {
        for(int i = 0; i < sz(nums); ++i) {
            cout << nums[i] << " ";
        }
    }
    else cout << "impossible";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    
    return 0;
}