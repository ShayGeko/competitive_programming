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
        5 4 3 4 2 

        2
        5 <- 4 <- 3 <- 2 | 2
        5 <- 4 <- 3 | 4 <- 2
        5 <- 4 | 4 <- 3 <- 2

        5 4 4 3 3 3 2 2 1 1

        {
            4 : 2
        }
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