#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
string build(int n, int &k){
    if(n == 0) return "";
    if(n == 1) return "1";
    string half = build(n / 2, k);
    string built = half + "d+";
    ++k;
    if(n % 2){
        built += "1+";
        ++k;
    }
    return built;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int current_inc;
    int total_inc = 0;
    vector<int> numbers(n);

    for(int i = 0; i < n; ++i) cin >> numbers[i];

    vector<string> build_strings(n);

    for(int i = n - 1; i >= 0; i--){
        current_inc = 0;
        if(total_inc > 0) {
            string base = build(numbers[i] + total_inc, current_inc);
            build_strings[i] = base;
        }
        else {
            build_strings[i] = build(numbers[i], current_inc);
        }

        total_inc += current_inc;
    }
    string answer = "";
    for(auto s : build_strings) answer += s;
    cout << answer << '\n';
    return 0;
}