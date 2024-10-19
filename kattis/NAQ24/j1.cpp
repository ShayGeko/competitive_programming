#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

bool operator<(const pii &a, const pii&b) {
    auto [n1, dn1] = a;
    auto [n2, dn2] = b;
    
    return (ll)n1 * dn2 < (ll)n2 * dn1;
}
pii operator-(const pii &a, const pii&b) {
    auto [n1, dn1] = a;
    auto [n2, dn2] = b;
    
    ll dn = (ll) dn1 * dn2;
    ll nm1 = (ll) n1 * dn2;
    ll nm2 = (ll) n2 * dn1;
    ll nm = nm1 - nm2;
    ll gc = gcd(dn, nm);
    dn /= gc;
    nm /= gc;
    return {nm, dn};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int L;
    cin >> L;

    vector<pii> coord_frac(3);
    rep(i, 0, 3) {
        int a, b;
        cin >> a >> b;
        coord_frac[i] = {a, b};
    }

    pii sz_frac = {1, 3};
    vector<pii> boundaries = {
        {1, 3},
        {2, 3},
        {1, 1}
    };

    set<array<int, 3>> out = {
        {2, 1, 1}, {1, 1, 2}, {1, 2, 1},
        {0, 1, 1}, {1, 1, 0}, {1, 0, 1},
        {1, 1, 1}
    };
    rep(l, 0, L) {
        array<int, 3> cubecoord = {0,0,0};
        
        rep(i, 0, 3) {
            rep(j, 0, 2) {
                if(boundaries[j] <  coord_frac[i]) {
                    ++cubecoord[i];
                }
            }
        }

        
        // now we have (x, y, z) number of the cube we are in.
        // check if out
        if(out.count(cubecoord)) {
            cout << 0 << '\n';
            return 0;
        }

        // otherwise upscale and recur
        // upscaling depends on cube idx
        vector<pii> cube_start(3);
        rep(i, 0, 3) {
            cube_start[i] = {cubecoord[i], 3};
        }
        // cout << "subtracted: ";
        rep(i, 0, 3) {
            coord_frac[i] = coord_frac[i] - cube_start[i];
            auto &[nm, dnm] = coord_frac[i];
            // cout << nm << " " << dnm << " ";
        } 
        // cout << '\n';
        
        // cout << "upscaled: ";
        rep(i, 0, 3) {
            auto &[nm, dnm] = coord_frac[i];

            nm *= 3;

            assert(nm > 0);
            assert(dnm > 0);
            auto gc = gcd(nm, dnm);
            nm /= gc;
            dnm /= gc;


            // cout << nm << " " << dnm  << ' ';
        }
        // cout << '\n';
    }

    cout << 1 << '\n';

    return 0;
}