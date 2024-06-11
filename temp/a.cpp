#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct segTree {
    vector<int> tree;
    int n;
    segTree(const vector<int> arr, int n, int height){
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n-1, height);
    }

    void build(const vector<int>& arr, int node, int start, int end, int height){
        cout << node << " " << start << " " << end << " height " << height << endl;
        if(start == end){
            tree[node] = arr[start];
            cout << "node : " << node << "value :" << tree[node] << endl;
        }
        else {
            int mid = start + (end - start) / 2;
            build(arr, node * 2, start, mid, height - 1);
            build(arr, node * 2 + 1, mid + 1, end, height - 1);
            height / 2 == 0 ? (tree[node] = (tree[node * 2] | tree[node * 2 + 1])) : (tree[node] = (tree[node * 2] ^ tree[node * 2 + 1]));
            cout << "node : " << node << "value :" << tree[node] << endl;
        }
    }
//    void update(in)
    void query(vector<int>& arr, int index, int value, int height){
        arr[index - 1] = value;
        cout << arr[index-1] << endl;
        cout << n << endl;
        build(arr, 1, 0, n-1, height);
    }
    int get_val(){
        return tree[1];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr;

    int size = pow(n, 2);
    arr.resize(size);
    int height = log2(size) + 1;
    for(int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }
    segTree seg(arr, n, height);
    cout << seg.get_val() << endl;
    while(m--){
        int index, value;
        cin >> index >> value;
        seg.query(arr, index, value, height);
        int a = seg.get_val();

        cout << a << endl;
    }
}