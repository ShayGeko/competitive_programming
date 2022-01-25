#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000;
const int modulo = 998244353;
int arr[maxn];
class Compare
{
public:
    bool operator() (int i, int j)
    {
        return arr[i] > arr[j];
    }
};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k, n;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    priority_queue<int, vector<int>, Compare> pq;

    for(int i = 0; i < k; ++i){
        pq.push(i);
    }
    int prev;
    for(int i = k; i < n; ++i){
        prev = pq.top();
        if(arr[prev] < arr[i]){
            pq.pop();
            pq.push(i);
        }
    }
    long long sum = 0;
    set<int> indices;
    while(!pq.empty()){
        indices.insert(pq.top());
        pq.pop();
    }
    vector<int> indvec;
    for(auto index : indices){
        sum+= arr[index];
        indvec.push_back(index);
    }
    long long partition_num = 1;
    for(int i = 1; i < indvec.size(); ++i){
        partition_num = (partition_num * (indvec[i] - indvec[i-1])) % modulo;
    }
    cout << sum << ' ' << partition_num << '\n';

    return 0;
}