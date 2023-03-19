#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
const int P = 1e9 + 7;

int cnt = 0;
double avg_len = 0;
vector<int> merge(vector<int> &a, vector<int> &b){
    vector<int> res;
    avg_len*= cnt;
    avg_len += a.size() + b.size();
    avg_len /= ++cnt;
    res.clear();
    int pos = 0;
    int l = 0, r = 0;
    while(l < a.size() && r < b.size()){
        if(a[l] <= b[r]) res.push_back(a[l++]);
        else res.push_back(b[r++]);
    }
    while(l < a.size()){
        res.push_back(a[l++]);
    }
    while(r < b.size()){
        res.push_back(b[r++]);
    }
    return res;
}
int getNum(vector<int> &sorted, int z){
    auto t = upper_bound(sorted.begin(), sorted.end(), z);
    return sorted.end() - t;
}
typedef struct seg_tree { ;
    int N;
    vector<vector<int>> tree;
    vector<int> a;

    seg_tree(int n, vector<int> &arr){
        N = n;
        tree.resize(5*N);
        a = arr;
    }
    void build_tree(int cur, int l, int r) {
        if (l == r) {
            tree[cur].push_back(a[l]);
            return;
        }
        int mid = l + (r - l) / 2;
        build_tree(2 * cur, l, mid); // Build left tree
        build_tree(2 * cur + 1, mid + 1, r); // Build right tree
        tree[cur] = merge(tree[2 * cur], tree[2 * cur + 1]); //Merging the two sorted arrays
    }

    int query(int cur, int l, int r, int x, int y, int k) {
        if (r < x || l > y) {
            return 0; //out of range
        }
        if (x <= l && r <= y) {
            //Binary search over the current sorted vector to find elements smaller than K

            return tree[cur].end() - upper_bound(tree[cur].begin(), tree[cur].end(), k);
        }
        int mid = l + (r - l) / 2;
        return query(2 * cur, l, mid, x, y, k) + query(2 * cur + 1, mid + 1, r, x, y, k);
    }
} seg_tree_t;
seg_tree_t* root;
vector<int> numbers;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    int k;
    int l, r, z;
    cin >> n;
    numbers.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> numbers[i];
    }
    root = new seg_tree_t (n, numbers);
    root->build_tree(1, 0, n - 1);

    cin >> k;
    while(k--) {
        cin >> l >> r >> z;
        cout << root->query(1, 0, n-1, l-1 , r-1, z) << '\n';
    }
    return 0;
}