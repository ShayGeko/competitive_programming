#include <bits/stdc++.h>

using namespace std;
const int MAXN = 400;

char arr[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    int a, b;
    int atotal, btotal;
    string str;
    while(t--){
        cin >> b >> a;
        cin >> str;

        int insertCount = 0;
        for(auto c: str){
            if(c == '1') a--;
            else if(c == '0') b--;
            else insertCount++;
        }
        if(insertCount != (a + b)) {
            cout << -1 << '\n';
            continue;
        }

        int n = str.length();

        int k;
        bool impossible = false;
        for(int i = 0; i < n / 2 && !impossible; ++i){
            k = n - 1 - i;
            if(str[i]=='1'){
                if(str[k] == '0') impossible = true;
                else if (str[k] == '?'){
                    if(a == 0) impossible = true;
                    else {
                        str[k] = '1';
                        a--;
                    }
                }
            }
            else if(str[i] == '0') {
                if (str[k] == '1') impossible = true;
                else if (str[k] == '?') {
                    if (b == 0) impossible = true;
                    else {
                        str[k] = '0';
                        b--;
                    }
                }
            }
            else{
                if(str[k] == '1'){
                    if(a > 0){
                        str[i] = '1';
                        a--;
                    }
                    else impossible = true;
                }
                else if(str[k] == '0'){
                    if(b > 0){
                        str[i] = '0';
                        b--;
                    }
                    else impossible = true;
                }
            }
        }

        if(impossible){
            cout << "-1\n";
        }
        else{
            for(int i = 0; i < n/2 && !impossible; ++i){
                int k = n - 1 -i;
                if(str[i] == '?'){
                    if(a >= 2){
                        str[k] = str[i] = '1';
                        a-=2;
                    }
                    else if(b >= 2){
                        str[k] = str[i] = '0';
                        b-=2;
                    }
                    else impossible = true;
                }
            }
            if(n % 2){
                if (str[n / 2] == '?'){
                    if(a > 0){ str[n/2] = '1'; a--;}
                    else if (b > 0) {str[n / 2] = '0'; b--;}
                    else impossible = true;
                }
            }
            if(a != 0 || b !=0) impossible = true;
            if(!impossible) cout << str << '\n';
            else cout << "-1\n";
        }
    }

    return 0;
}