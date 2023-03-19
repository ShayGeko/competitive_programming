#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int maxn = 500;
const int INF = 1e9;


vi age;
vi location_of_person;
vi person_in_node;
vector<vector<int>> graph;
bool used[maxn];
int bfs(int v, int n){

    int mini = INF;
    for(int i = 0; i < n; ++i){
        used[i] = false;
    }
    queue<int> q;
    for(auto to : graph[v]){
        q.push(to);
    }
    while(!q.empty()){
        int cur = q.front();
        used[cur] = true;
        q.pop();

        mini = min(age[person_in_node[cur]], mini);
        for(auto to : graph[cur]){
            if(!used[to]) q.push(to);
        }
    }

    return mini;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n,m ,k;
    cin >> n >> m >> k;

    age.resize(n);
    location_of_person.resize(n);
    person_in_node.resize(n);
    graph.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> age[i];
        location_of_person[i] = i;
        person_in_node[i] = i;
    }

    int a, b;

    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        graph[b-1].push_back(a - 1);
    }
    char q;
    for(int i = 0; i < k; ++i){
        cin >> q;
        if(q == 'P'){
            cin >> a;
            int ans = bfs(location_of_person[a - 1], n);
            if(ans == INF) cout << "*\n";
            else cout << ans << '\n';
        }
        else{
            cin >> a >> b;
            int node_a = location_of_person[a - 1];
            int node_b = location_of_person[b - 1];

            person_in_node[node_a] = b - 1;
            person_in_node[node_b] = a - 1;
            location_of_person[a - 1] = node_b;
            location_of_person[b - 1] = node_a;

        }
    }

    return 0;
}