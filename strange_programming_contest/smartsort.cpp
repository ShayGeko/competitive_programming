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

void printBLock(vi arr, int start, int sz){
    for(int j = 0; j < sz; ++j){
        cout << arr[start + j] + " < " << arr[start + sz - 1 - j] << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    int n, m;

    cin >> n >> m;

    int pows2[] = {1,2,4,8,16,32,64,128,256,512,1024};

    // closest power of n
    int goodN = pows2[(int)ceil(log2(n))];
    cout << goodN << '\n';
    
    vi arr(goodN);

    for(int i = 0; i < goodN; ++i){
        arr[i] = i+1;
    }

    int c = 2;

    while(true){
        cout << "q" << n/2 << '\n';
        for(int i = 0; i < n; i+=c){
            for(int j = 0; j < c; ++j){
                cout << arr[i + j] + " < " << arr[i + c - 1 - j] << endl;
            }
        }
        int response;
        for(int i = 0; i < n/2; ++i)
            for(int j = 0; j < c; ++j){
                cin >> response;
                if(!response)
                    swap(arr[i+j], arr[i+c-1-j]);
            }
    }
    return 0;
}