#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*

expr :=
    ( expr )
    expr op expr
    var

op :=
    *
    /
    +
    -

var := [A-Z]
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    string expr;
    cin >> expr;

    map<char, int> precendence = {
        {'+', 0},
        {'-', 0},
        {'*', 1},
        {'/', 1},
        {'(', 2}
    };

    stack<char> st;

    int i = 0;
    queue<char> out;
    stack<char> op;
    char o;
    while(i < sz(expr)) {
        if(isalpha(expr[i])) out.push(expr[i]);
        else{
            if(expr[i] == '(') {
                op.push('(');
            } else if(expr[i] == ')') {
                while((o = op.top()) != '(') {
                    out.push(o);
                    op.pop();
                }
                op.pop();
            } else {
                while(op.size() > 0 &&  ((o = op.top()) != '(') 
                    && precendence[o] >= precendence[expr[i]]) {
                    op.pop();
                    out.push(o);
                }
                op.push(expr[i]);
            }
        }
        ++i;
    }
    while(!op.empty()) {
        out.push(op.top());op.pop();
    }

    while(!out.empty()) {
        char c = out.front();out.pop();
        cout << c;
    }
    cout << '\n';
	return 0;
}