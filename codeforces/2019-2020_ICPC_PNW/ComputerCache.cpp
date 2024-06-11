#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// two lazy segment trees
// 1) lazy persistent st for data
// 2) lazy st for cache, store (data id, version, l, r)

typedef struct node1 {
	node1 *l=NULL, *r=NULL;
	int Tl, Tr;
	int val = 0;
	int add = 0;

	node1 (int Tl, int Tr): Tl(Tl), Tr(Tr) {}
	node1 (node1* a){
		l = a->l;
		r = a->r;
		Tl = a->Tl;
		Tr = a->Tr;
		val = a->val;
		add = a->add;
	}

	void push() {
		int m = Tl + (Tr - Tl) / 2;

		if(!l) l = new node1(Tl, m);
		else l = new node1(l);
		if(!r) r = new node1(m+1, Tr);
		else r = new node1(r);

		l->add += add;
		r->add += add;
		add = 0;
	}
	void increment(int ql, int qr, int x) {
		if(ql > qr) return;
		if(Tl == Tr) { // leaf
			val += x + add;
			add = 0;
			return;
		}
		if(ql == Tl && qr == Tr) {
			add += x;
		} else {
			int m = Tl + (Tr - Tl) / 2;
			// if add > 0 -> create copies of both children
			bool copied = false;
			if(add) {
				push();
				copied = true;
			}
			if(ql <= m) {
				if(!l) l = new node1(Tl, m);
				else if(!copied) l = new node1(l);
				l->increment(ql, min(m, qr), x);
			}
			if(qr > m) {
				if(!r) r = new node1(m+1, Tr);
				else if(!copied) r = new node1(r);
				r-> increment(max(m+1, ql), qr, x);
			}
		}
	}

	int query (int ind) {
		if(Tl == Tr) return val + add;

		int m = Tl + (Tr - Tl) / 2;
		push();
		if(ind <= m) {
			return l->query(ind);
		} else {
			return r->query(ind);
		}
	}
} Data;

typedef struct node2 {
	node2 *l = NULL, *r=NULL;
	int Tl, Tr;
	// dataID, version, L, R
	vi info = {-1,-1,-1,-1};

	node2 (int Tl, int Tr): Tl(Tl), Tr(Tr) {}

	void push() {
		int m = Tl + (Tr- Tl) / 2;
		if(!l) l = new node2(Tl, m);
		if(!r) r = new node2(m+1, Tr);

		if(info[0] != -1) { // node's segment is a contiguous piece of data
			int oid = info[0], over = info[1];
			int odl = info[2], odr = info[3];
			assert(odr - odl == Tr - Tl);
			// push assignment down
			int datasplit = odl + (odr - odl) / 2;
			// do I need to push down stuff from children? no coz it should be overwritten
			l->info = {oid, over, odl, datasplit};
			r->info = {oid, over, datasplit+1, odr};

			rep(i, 0, 4) info[i] = -1;
		}
	}
	void update(int ql, int qr, int id, int ver, int dl, int dr) {
		if(dl > dr || ql > qr) return;
		if(ql == Tl && qr == Tr) {
			info = {id, ver, dl, dr};
			return;
		}

		push();
		int m = Tl + (Tr- Tl) / 2;
		if(qr <= m) 
			l->update(ql, qr, id, ver, dl, dr);
		else if(ql > m) {
			r->update(max(m+1, ql), qr, id, ver, dl, dr);
		}
		else {
			int datasplit = dl + m - ql;
			
			l->update(ql, m, id, ver, dl, datasplit);
			r->update(m+1, qr, id, ver, datasplit+1, dr);
		}
	}

	vi query(int ind) {
		if(Tl == Tr) return info;

		push();
		int m = Tl + (Tr- Tl) / 2;
		if(ind <= m) {
			return l->query(ind);
		}
		else {
			return r->query(ind);
		}
	}
} Cache;

void printData(Data* v, string tab = "") {
	cout << tab << v->Tl << " " << v->Tr << " " << v->val << " " << v->add << '\n';

	if(v -> l) printData(v->l, tab + '\t');
	if(v -> r) printData(v->r, tab + '\t');
}
void printCache(Cache* v, string tab = "") {
	cout << tab << v->Tl << " " << v->Tr << " | ";
	for(auto x : v->info) cout << x << " ";
	cout << '\n';

	if(v -> l) printCache(v->l, tab + '\t');
	if(v -> r) printCache(v->r, tab + '\t');
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m, q;
	cin >> n >> m >> q;

	vector<vi> data(m);
	vi version(m, 0);
	Cache* cache = new Cache(0, n-1);
	vector<vector<Data*>> dataIncr(m);
	rep(i, 0, m) {
		int k;
		cin >> k;
		data[i] = vi(k);
		dataIncr[i].push_back(new Data(0, k-1));
		for(auto &x : data[i]) cin >> x;
	}
	
	rep(z, 0, q) {
		int t;
		cin >> t;
		if(t == 1) {
			int id, start;
			cin >> id >> start;
			id--;
			start--;
			cache->update(start, start + sz(data[id]) - 1, id, version[id], 0, sz(data[id])-1);

			// cout << "***************************************************\n";
			// printCache(cache);
			// cout << "***************************************************\n";
		} else if(t == 2) {
			int pos;
			cin >> pos;
			pos--;
			vi ans = cache->query(pos);
			// cout << id << " " << version << " " <<  ind << " ";
			if(ans[0] < 0) cout << 0 << '\n'; // cache is empty
			else {
				int id = ans[0], version = ans[1], l = ans[2], r = ans[3];
				assert(l == r);
				int inc = dataIncr[id][version]->query(l);
				cout << (data[id][l] + inc) % 256 << '\n';
			}
		} else {
			int id, l, r;
			cin >> id >> l >> r;
			--id; --l;--r;
			auto newRoot = new Data(dataIncr[id].back());
			newRoot->increment(l, r, 1);
			dataIncr[id].push_back(newRoot);
			++version[id];

			// printData(dataIncr[id].back());
		}
	}
	return 0;
}