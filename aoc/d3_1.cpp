#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
unsigned int to_uint(vector<bool> binary){
    int pwr = 1;
    unsigned int num = 0;
    for(int i = binary.size() - 1; i >= 0; i--){
        if(binary[i]) num+= pwr;
        pwr <<= 1;
    }
    return num;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<string> bits;
    string temp;
    while(cin >> temp){
        bits.push_back(temp);
    }
    vector<bool> gamma(bits[0].length());
    vector<bool> epsilon(gamma.size());
    for(int i = 0; i < bits[0].length(); ++i){
        int cnt1 = 0;
        for(auto bstr : bits){
            cnt1+=bstr[i] - '0';
        }
        gamma[i] = cnt1 > bits.size() / 2;
        epsilon[i] = !gamma[i];
    }
    unsigned int gammaNum = to_uint(gamma);
    unsigned int epsilonNum = to_uint(epsilon);
    cout << gammaNum * epsilonNum;
    return 0;
}