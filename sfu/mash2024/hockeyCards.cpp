#include <bits/stdc++.h>

using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi topoSort(const vector<vi> &gr) {
  vi indeg(sz(gr)), ret;
  for (auto &li : gr) for (int x : li) indeg[x]++;
  queue<int> q; // use priority_queue for lexic. largest ans.
  rep(i, 0, sz(gr)) if (indeg[i] == 0) q.push(i);
  while (!q.empty()) {
    int i = q.front(); // top() for priority queue
    ret.push_back(i);
    q.pop();
    for (int x : gr[i])
      if (--indeg[x] == 0) q.push(x);
  }
  return ret;
}

const int HEIGHTS = 221;
const int SPEEDS = 71;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vector<string> mnames;
  
  // card + in and out for each bucket
  const int totalNodeCnt = n + 2*(26 + SPEEDS + HEIGHTS);
  vector<vi> adj(totalNodeCnt);

  const int IN_OFFSET = n;
  const int OUT_OFFSET = n + 26 + SPEEDS + HEIGHTS;

  rep(i, 0, n) {
    string s;
    int a, b;
    cin >> s >> a >> b;

    // connect in-buckets to cards
    adj[IN_OFFSET + s[0]-'A'].push_back(i);
    adj[IN_OFFSET + 26 + a].push_back(i);
    adj[IN_OFFSET + 26 + SPEEDS + b].push_back(i);

    // connect cards to out-buckets
    adj[i].push_back(OUT_OFFSET + s[0]-'A');
    adj[i].push_back(OUT_OFFSET + 26 + a);
    adj[i].push_back(OUT_OFFSET + 26 + SPEEDS + b);

    mnames.push_back(s);
  }

  rep(i, 0, q){
    string s;
    cin >> s;

    int a1, b1;
	int off1 = 0;
    if(s == "Name"){
      char aa, bb;
      cin >> aa >> bb;
      a1 = aa - 'A';
      b1 = bb - 'A';
    }else if(s == "Speed"){
      cin >> a1 >> b1;
	    off1 = 26;


    }else {
      cin >> a1 >> b1;
	    off1 = 26 + SPEEDS;
    }
    char _;
    cin >> _;

    cin >> s;
    int a2, b2;
	int off2 = 0;
    if(s == "Name"){
      char aa, bb;
      cin >> aa >> bb;
      a2 = aa - 'A';
      b2 = bb - 'A';
    }else if(s == "Speed"){
      cin >> a2 >> b2;
	  off2 = 26;

    }else{
      cin >> a2 >> b2;
	    off2 = 26 + SPEEDS;
    }
	
    rep(xx, a1, b1+1) { // for each left query
        rep(yy, a2, b2+1) { // for each right q
			    adj[OUT_OFFSET + off1 + xx].push_back(IN_OFFSET + off2 + yy); // bucket[type1][xx] > bucket[type2][yy]
        }
	  }   
  }

  auto ts = topoSort(adj);

  vector<bool> visited(n);
  vi ans;
  bool feasible = true;
  for(auto v : ts) {
    if(v < n) {
      ans.push_back(v);
    }
  }

  if(ans.size() < n) {
    cout << "your preferences are wrong\n";
  } else {
    for(auto i : ans) {
      cout << mnames[i] << '\n';
    }
  }
}