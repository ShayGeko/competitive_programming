#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;
void solve(){
    int n;
    cin >> n;
    vi nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    int maxi = -1, maxj = -1, maxprod = 0;

    int cur = 0;
    bool neg = false;
    bool nonzero = false;
    int curmaxi = 0, curmaxj = -1, curmax = 0;
    if(nums[0] > 0) curmaxi = 0;
    for(int i = 0; i < n; ++i){
        if(nums[i] == 0){
            if(neg){
                int l = curmaxi, prodl = 0;
                bool found = false;
                // get product up to first neg from the left;
                for(int j = curmaxi; j <= curmaxj; ++j){
                    if(nums[j] == 2 || nums[j] == -2) ++prodl;
                    if(nums[j] < 0) {
                        l = j;
                        found = true;
                        break;
                    }
                }
                int r = curmaxj, prodr = 0;

                // get sequence up to first neg from the right
                for(int j = curmaxj; j >= curmaxi; --j){
                    if(nums[j] == 2 || nums[j] == -2) ++prodr;
                    if(nums[j] < 0) {
                        r = j;
                        found = true;
                        break;
                    }
                }
                if(!found) {}
                else{
                    // subtract from curmax
                    // update curmaxi curmaxj
                    if(prodl < prodr){
                        curmaxi = l+1;
                        curmax = curmax - prodl;
                    }
                    else{
                        curmaxj = r - 1;
                        curmax = curmax - prodr;
                    }
                }
            }
            if(curmax > maxprod){
                maxprod = curmax;
                maxi = curmaxi;
                maxj = curmaxj;
            }

            curmax = 0;
            curmaxi = i + 1;
            curmaxj = i + 1;
            neg = false;
            nonzero = false;
        }
        else{
            if(nums[i] < 0){
                neg = !neg;
            }
            nonzero = true;
            if(nums[i] == 2 || nums[i]==-2){
                ++curmax;
            }

            curmaxj = i;
        }
    }

    if(neg){
        int l = curmaxi, prodl = 0;
        bool found = false;
        // get product up to first neg from the left;
        for(int j = curmaxi; j <= curmaxj; ++j){
            if(nums[j] == 2 || nums[j] == -2) ++prodl;
            if(nums[j] < 0) {
                l = j;
                found = true;
                break;
            }
        }
        int r = curmaxj, prodr = 0;
        
        // get sequence up to first neg from the right
        for(int j = curmaxj; j >= curmaxi; --j){
            if(nums[j] == 2 || nums[j] == -2) ++prodr;
            if(nums[j] < 0) {
                r = j;
                found = true;
                break;
            }
        }
        if(!found) {}
        else{
        
            // subtract from curmax
            // update curmaxi curmaxj
            if(prodl < prodr){
                curmaxi = l+1;
                curmax = curmax - prodl;
            }
            else{
                curmaxj = r - 1;
                curmax = curmax - prodr;
            }
            
        }
    }
    
    if(curmax > maxprod){
        maxprod = curmax;
        maxi = curmaxi;
        maxj = curmaxj;
    }



    if(maxi == -1 && maxj == -1){
        cout << nums.size() << " " << 0 << '\n'; 
    }
    else cout << maxi << " " << nums.size() - 1 - maxj << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}