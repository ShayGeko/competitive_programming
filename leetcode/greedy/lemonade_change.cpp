#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int tens = 0, fives = 0;
        
        for(auto bill : bills){
            if(bill == 5) ++fives;
            else if(bill == 10){
                if(fives){
                    ++tens;
                    --fives;
                }
                else return false;
            }
            else{
                if(tens && fives){
                    --tens;
                    --fives;
                }
                else if(fives >= 3){
                    fives-=3;
                }
                else return false;
            }
        }
        
        return true;
    }
};