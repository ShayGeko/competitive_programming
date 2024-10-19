#include <iostream>
#include <algorithm>
#include <vector>
#include<set>


using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> vec(n);

    for(int i = 0; i < n; ++i) cin >> vec[i];

    //  "AA" < "BA"
    set<string> cpy(vec.begin(), vec.end());

    if(cpy.size() != vec.size()) {

        cout << "NEITHER\n";
        return 0;
    }


    bool printed = false;

    bool increasing = true;
    for(int i = 0; i < n; ++i) {
        if(vec[i] != cpy[i]) {
            increasing = false;
            break;
        }
    }

    if(increasing) {
        cout << "INCREASING\n";
        return 0;
    }

    reverse(cpy.begin(), cpy.end());


    

    return 0;
}