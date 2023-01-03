#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;


#pragma once

struct Tree {
	typedef bool T;
	static constexpr T unit = true;
	T f(T a, T b) { return a && b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


void solve(){
    int n, m;
    cin >> n >> m;

    Tree t(n, true);

    while(m--){
        char c;
        cin >> c;

        int a,b;
        if(c == '?'){
            cin >> a >> b;
            
            if(a > b) swap(a,b);
            bool str = t.query(a-1,b);
            bool rev = t.query(0, a) && t.query(b-1, n);

            // cout << "DEBUG| " << str << " " << rev << '\n';
            if(str || rev) cout << "possible\n";
            else cout << "impossible\n";
        }
        else{
            cin >> a;

            t.update(a-1, c == '-'? false:true);

            // for(int i = 0; i < n; ++i){
            //     cout << t.query(i, i + 1) << " ";
            // }
            // cout << '\n';
        }
    }

    
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