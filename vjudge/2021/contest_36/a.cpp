#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int x;
    while(n--){
        cin >> x;
        if(x%2) cout << x << " is odd\n";
        else cout << x << "is even\n";
    }
    return 0;
}