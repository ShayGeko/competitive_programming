#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
unsigned int to_uint(string binary){
    int pwr = 1;
    unsigned int num = 0;
    for(int i = binary.size() - 1; i >= 0; i--){
        if(binary[i]-'0') num+= pwr;
        pwr <<= 1;
    }
    return num;
}
string getNum(set<string> a, function<bool(unsigned int, unsigned int)> oper) {
    int cnt1;
    char filter;
    unsigned int bitsize = a.begin()->length();
    for(int i = 0; i < bitsize && a.size() > 1; ++i) {
        cnt1 = 0;
        for (auto s: a) {
            cnt1 += s[i] == '1';
        }
        if (oper(cnt1, (a.size()+1) / 2)) filter = '1';
        else filter = '0';
        auto it = a.begin();
        while (it != a.end() && a.size() > 1) {
            if ((*it)[i] != filter) {
                it = a.erase(it);
            } else {
                ++it;
            }
        }
    }

    return *(a.begin());
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<string> bits;
    string temp;
    while(cin >> temp){
        bits.push_back(temp);
    }
    set<string> a, b;
    for(auto s : bits) {
        a.insert(s);
        b.insert(s);
    }
    string astr = getNum(a, greater_equal<>());
    string bstr = getNum(b, less<>());

    unsigned int anum = to_uint(astr);
    unsigned int bnum = to_uint(bstr);

    cout << anum * bnum << '\n';

    return 0;
}