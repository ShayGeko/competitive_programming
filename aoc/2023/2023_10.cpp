#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef pair<string, int> psi;
typedef pair<string, ll> psll;
typedef vector<psi> vpsi;
typedef vector<psll> vpsll;
typedef map<string, int> msi;
typedef map<string, ll> msll;
typedef map<char, int> mci;
typedef map<char, ll> mcll;
typedef stringstream ss;

template <typename  T>
istream &operator >> (istream& is, pair<T, T> &p){
    cin >> p.first >> p.second;
    return is;
}
template <typename  T>
ostream &operator << (ostream& os, pair<T,T> &p){
    cout << p.first << " " << p.second;

    return os;
}

pii operator* (pii a, int b) {
	return {a.first * b, a.second * b};
};
void operator*= (pii&a, int b) {
	a.first*=b;
	a.second*=b;
}
pii operator+ (pii a, int b) {
	return {a.first + b, a.second + b};
}

void operator+= (pii&a, pii b){
	a.first += b.first;
	a.second += b.second;
}

template <typename T1, typename T2>
pair<T1, T2> operator+ (pair<T1, T2> a, pair<T1, T2> b) {
	return {a.first + b.first, a.second + b.second};
}
template <typename T1, typename T2>
pair<T1, T2> operator- (pair<T1, T2> a, pair<T1, T2> b) {
	return {a.first - b.first, a.second - b.second};
}
string str, word;
ll cnt = 0, a, b, x, num;
vi nums;
vector<string> vstr;
char c, _;

void p1() {
	vector<string> grid;

	while(getline(cin, str)) grid.push_back(str);

	pii start;
	rep(i, 0, sz(grid)) rep(j, 0, sz(grid[0])) if(grid[i][j] == 'S') start = {i,j};

	vector<vector<bool>> visited(sz(grid), vector<bool>(sz(grid[0]), false));

	queue<pair<pii, pii>> q;
	vector<pii> moves = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
	map<pii, string> pipes = {
		{{0,1}, "-#7J"},
		{{0, -1}, "#-FL"},
		{{1, 0}, "LJ|#"},
		{{-1, 0}, "F7#|"}
	};
	visited[start.first][start.second] = true;
	vvi d(sz(grid), vi(sz(grid[0]),0));
	for(auto mv : moves) {
		auto [ni, nj] = start + mv;
		if(ni >=0 && nj >= 0 && ni < sz(grid) && nj < sz(grid[0])) {
			auto cchar = grid[ni][nj];
			rep(t, 0, 4){
				if(pipes[mv][t] == cchar) {
					q.push({start + mv, start});
					d[ni][nj] = 1;
					// visited[ni][nj]=true;
				}
			}
			
		}
	}
	int ans = 0;
	while(!q.empty()) {
		auto [cur, from] = q.front();q.pop();
		auto [ci, cj] = cur;
		auto [fi, fj] = from;

		char cchar = grid[ci][cj];
		ans = max(ans, d[ci][cj]);
		auto mv = cur - from;
		string mp = pipes[mv];
		rep(t, 0, 4){
			if(mp[t] == cchar) {
				auto [ni, nj] = moves[t];
				if(!visited[ci + ni][cj+nj]) {
					q.push({{ci + ni, cj + nj}, cur});
					visited[ci][cj] = true; // only mark as visited if we used it
					d[ci+ni][cj+nj]=d[ci][cj] + 1;
				}
			}
		}
	}
	rep(i, max(0, start.first - 30), min(start.first + 31, sz(grid))) {
		rep(j, max(0, start.second - 30), min(start.second + 31, sz(grid[0]))) {
			cout << d[i][j];
		}
		cout << '\n';
	}
	rep(i, max(0, start.first - 30), min(start.first + 31, sz(grid))) {
		rep(j, max(0, start.second - 30), min(start.second + 31, sz(grid[0]))) {
			cout << grid[i][j];
		}
		cout << '\n';
	}
	cout << ans<< '\n';
}
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};
template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}


void p2() {
	vector<string> grid;

	while(getline(cin, str)) grid.push_back(str);

	pii start;
	rep(i, 0, sz(grid)) rep(j, 0, sz(grid[0])) if(grid[i][j] == 'S') start = {i,j};

	vector<vector<bool>> visited(sz(grid), vector<bool>(sz(grid[0]), false));

	queue<pair<pii, pii>> q;
	vector<pii> moves = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
	map<pii, string> pipes = {
		{{0,1}, "-#7J"},
		{{0, -1}, "#-FL"},
		{{1, 0}, "LJ|#"},
		{{-1, 0}, "F7#|"}
	};
	visited[start.first][start.second] = true;
	vvi d(sz(grid), vi(sz(grid[0]),0));
	for(auto mv : moves) {
		auto [ni, nj] = start + mv;
		if(ni >=0 && nj >= 0 && ni < sz(grid) && nj < sz(grid[0])) {
			auto cchar = grid[ni][nj];
			rep(t, 0, 4){
				if(pipes[mv][t] == cchar) {
					q.push({start + mv, start});
					d[ni][nj] = 1;
					// visited[ni][nj]=true;
				}
			}
			
		}
	}
	int ans = 0;
	map<pii, pii> parent;
	map<pii, pii> child;
	pii node; 
	while(!q.empty()) {
		auto [cur, from] = q.front();q.pop();
		auto [ci, cj] = cur;
		auto [fi, fj] = from;

		char cchar = grid[ci][cj];
		if(d[ci][cj] > ans) {
			ans = max(ans, d[ci][cj]);
			node = cur;
		}
		
		auto mv = cur - from;
		string mp = pipes[mv];
		rep(t, 0, 4){
			if(mp[t] == cchar) {
				auto [ni, nj] = moves[t];
				if(!visited[ci + ni][cj+nj]) {
					q.push({{ci + ni, cj + nj}, cur});
					visited[ci][cj] = true; // only mark as visited if we used it
					d[ci+ni][cj+nj]=d[ci][cj] + 1;
				}
				child[cur]={ci+ni, cj + nj};
				parent[cur] = from;
			}
		}
	}
	rep(i, max(0, start.first - 30), min(start.first + 31, sz(grid))) {
		rep(j, max(0, start.second - 30), min(start.second + 31, sz(grid[0]))) {
			cout << d[i][j];
		}
		cout << '\n';
	}
	rep(i, max(0, start.first - 30), min(start.first + 31, sz(grid))) {
		rep(j, max(0, start.second - 30), min(start.second + 31, sz(grid[0]))) {
			cout << grid[i][j];
		}
		cout << '\n';
	}
	

	vector<vector<bool>> isLoop(sz(grid), vector<bool>(sz(grid[0]), false));
	vector<Point<int>> polygon;
	q.push({node, parent[node]});
	while(!q.empty()) {
		auto [cur, from] = q.front();q.pop();
		auto [ci, cj] = cur;
		auto [fi, fj] = from;

		isLoop[ci][cj]=true;
		char cchar = grid[ci][cj];
		if(d[ci][cj] > ans) {
			ans = max(ans, d[ci][cj]);
			node = cur;
		}
		
		auto mv = cur - from;
		string mp = pipes[mv];
		rep(t, 0, 4){
			if(mp[t] == cchar) {
				auto [ni, nj] = moves[t];
				// if(!visited[ci + ni][cj+nj]) {
				q.push({{ci + ni, cj + nj}, cur});
				visited[ci][cj] = true; // only mark as visited if we used it
				d[ci+ni][cj+nj]=d[ci][cj] + 1;
				// }
			}
		}
	}

	queue<pii> qq;
	vector<vector<bool>> vis(sz(grid), vector<bool>(sz(grid[0]), false));

	int n = sz(grid), m = sz(grid[0]);
	vi temp = {0, n-1, m-1};
	rep(i, 0, n) rep(j, 0, m) for(auto x : temp) if(i == x || j == x) {
		if(!isLoop[i][j]) {
			qq.push({i, j});
			vis[i][j]=true;
		}
	}
	while(!qq.empty()){
		auto [ci, cj] = qq.front();qq.pop();

		rep(di, -1, 2) rep(dj, -1, 2) {
			if(di == 0 && dj == 0) continue;
			auto [ni, nj] = pii(ci+di, cj+dj);

			if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
				if(!vis[ni][nj] && !isLoop[ni][nj]){
					qq.push({ni, nj});
					vis[ni][nj] = true;
				}
			}
		}
	}

	ans = 0;
	rep(i, 0, sz(grid)){
		rep(j, 0, sz(grid[0])) {
			if(isLoop[i][j]) cout << '#';
			else if(vis[i][j]) cout << 0;
			else {
				++ans;	
				cout << 1;
			}
		}
		
		cout << '\n'; 
	}

	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	string part;
	getline(cin, part);

	if(part == "1") p1();
	else if(part == "2") p2();
	else {
		cout << "\033[1;31minvalid input. Make sure first line is \"1\" or \"2\" to specify part\n\033[0m\n";
		while(getline(cin, str)) {};
	}
	return 0;
}