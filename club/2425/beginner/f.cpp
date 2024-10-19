#include <iostream>
#include <algorithm>
#include <vector>
#include<set>
#include <map>


using namespace std;

int main() {
    int n;
    cin >> n;

    /*
        1 2 3 4 5
        (1 + 5) * 5 / 2 = 15

        1 .. 7
        (1 + 7) * 7 / 2 = 28

        out of 1 2 3 4 5 6 7
        take some
        to get 14

        1
        13
        2
        11
        3
        8

        1 2 3 -> 8

        
        1 2 3 4 5 6 7

        1 3 5 7
        2 4 6 8


        1 4 5 8
        2 3 6 7

        14
        7 : 7
        6 : 1
        1

        
    */
    

    vector<int> nums(n);
    for(int i = 0; i < n; ++i) nums[i] = i + 1; // 1.. n

    reverse(nums.begin(), nums.end());

    long long sum = (1LL + n) * n / 2;

    if(sum % 2) {
        cout << "NO\n";
        return 0;
    }
    long long half = sum / 2;

    vector<int> L, R;
    long long sum_l = 0;

    for(auto x : nums) {
        if(sum_l + x <= half) {
            sum_l += x;
            L.push_back(x);
        } else {
            R.push_back(x);
        }
    }

    cout << L.size()<< '\n';
    for(auto x : L) cout << x << " ";
    cout << '\n';

    
    cout << R.size() << '\n';
    for(auto x : R) cout << x << " ";
    cout << '\n';


    return 0;
}