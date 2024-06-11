#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node {
	Node *l = nullptr, *r = nullptr;
	int tL, tR;

	ll sum = 0, pushL = 0, pushR = 0;

	Node (int tL, int tR): tL(tL), tR(tR) {}

	void add(int qL, int qR, ll addL, ll addR) {
		if(qL > qR) return;
		if(tL == tR) {
			sum += addL; 
			return;
		}

		if(qL == tL && qR == tR) {
			pushL += addL;
			pushR += addR;
			sum+= (addL + addR) * (tR - tL+1) / 2; // (a_0 + a_n-1) * n / 2
			return;
		}

		push();

		ll step = qR == qL? 0 : ((addR - addL) / (qR - qL));
		int m = tL + (tR - tL) / 2;
		int split = min(m, qR);
		if(m >= qR) {
			l->add(qL, qR, addL, addR);
		}
		else if(m < qL)  {
			r->add(qL, qR, addL, addR);
		}
		else {
			ll splitVal = addL + (split - qL) * step;  // a_k = a_0 + k * step
			l->add(qL, min(m, qR), addL, splitVal);
			r->add(max(m+1, qL), qR, splitVal + step, addR);
		}

		sum = l->sum + r->sum;
	}

	void push() {
		int m = tL + (tR - tL) / 2;
		if(!l) l = new Node(tL, m);
		if(!r) r = new Node(m+1, tR);

		
		ll step = (pushR-pushL) / (tR - tL);
		ll addM = pushL + (m - tL) * step; // a_k = a_0 + step * (k)
		if(pushL > 0) {
			l->add(tL, m, pushL, addM);
			r->add(m+1, tR, addM + step, pushR);
			pushL = 0;
			pushR = 0;
		}
		sum = l->sum + r->sum;
	}

	ll query(int qL, int qR) {
		if(qL > qR) return 0; 
		if(qL == tL && qR == tR) return sum;

		push();
		int m = tL + (tR - tL) / 2;

		return l->query(qL, min(qR, m)) + r->query(max(qL, m+1), qR);
	}

	void print(string tab = "") {
		cout << tab << tL << " " << tR << " " << pushL << " " << pushR << ": " << sum << '\n';
		tab += "  ";
		if(l) {
			l->print(tab);
			r->print(tab);
		}

	}
};

void print(Node* node) {
	cout << "--------------------------------------------\n";
	node->print();
	cout << "--------------------------------------------\n";
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	
	vi nums(n);
	for(auto &x : nums) cin >> x;

	Node* node = new Node(0, n-1);
	rep(i, 0, n) {
		node->add(i, i, nums[i], nums[i]);
	}

	// print(node);
	rep(i, 0, m) {
		int a, b, c;
		cin >> a >> b >> c;

		// cout << "Req: " << a << " " << b << " " << c << '\n';
		--b;
		--c;
		if(a == 1) {
			node->add(b, c, 1, c - b + 1);
		} else {
			ll ans = node->query(b, c);

			cout << ans << '\n';
		}

		// print(node);
	}
	return 0;
}