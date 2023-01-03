#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}
ostream &operator << (ostream& os, pii &p){
    cout << p.first << " " << p.second;
    return os;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

typedef struct node {
    map<string, node*> folders;
    map<string, int> files;
    int size = 0;
    node* parent;
} node_t;


ll tot = 0;

ll dfs(node_t* v){
    ll sz = 0;
    for(auto f : v->folders){
        sz += dfs(f.second);
    }
    for(auto f : v->files){
        sz += f.second;
    }
    v->size = sz;
    if(sz <= 100000) tot +=sz;

    return sz;
}

int mini = INF;
int goal = 0;
void dfs1(node_t* v){
    if(v->size >= goal){
        mini = min(mini, v->size);
        for(auto f : v->folders){
            dfs1(f.second);
        }
    }
}

void solve(){

    node_t* root = new node_t();

    node_t* cur = root;
    string s;
    while(true){
        getline(cin, s);
        cout << s << '\n';
        if(s == "") break;

        stringstream ss(s);

        string a;
        ss >> a;
        cout << a << '\n';
        if(a == "$"){
            cout << "got a command\n";
            string b;
            ss >> b;
            if(b == "cd"){
                string c;
                ss >> c;
                
                if(c == ".."){
                    if(cur->parent)
                        cur = cur->parent;
                }
                else if(c == "/"){
                    cur = root;
                }
                else cur = cur->folders[c];
            }
            else if(b == "ls"){
                string c, d;
                while(cin.peek() != '$' || cin.peek() == EOF){
                    getline(cin, s);
                    stringstream ss(s);
                    ss >> c >> d;
                    if(c == "dir"){
                        if(cur->folders.find(d) == cur->folders.end()){
                            cur->folders[d] = new node_t();
                            cur->folders[d]->parent = cur;
                        }
                    }
                    else if(cur->files.find(d) == cur->files.end()) {
                        cur->files[d]=stoi(c);
                    }
                }
            }
            else break;
        }
    }

    cout << "done getting\n";
    dfs(root);
    cout << tot << '\n';

    goal = 30000000 - (70000000 - root->size);
    dfs1(root);

    cout << root->size << " " << goal << '\n';
    cout << mini << '\n';

}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    
    return 0;
}