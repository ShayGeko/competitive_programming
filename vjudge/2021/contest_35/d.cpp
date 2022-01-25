#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 2e5 + 1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    int n;
    // (soc, index)
    priority_queue<pair<int, int>> people;
    while(t--){
        cin >> n;
        vector<pair<int, int>> talks;
        pair<int,int> temp;
        for(int i = 0; i < n; ++i){
            cin >> temp.first;
            if(temp.first) {
                temp.second = i + 1;
                people.push(temp);
            }
        }
        while(people.size() > 1){
            pair<int,int> a = people.top();
            people.pop();
            pair<int, int> b = people.top();
            people.pop();

            a.first--;
            b.first--;
            if(a.first) people.push(a);
            if(b.first) people.push(b);

            talks.emplace_back(a.second, b.second);
        }
        cout << talks.size() << '\n';
        for(auto talk: talks){
            cout << talk.first << " " << talk.second << '\n';
        }

        if(!people.empty())people.pop();
    }
}