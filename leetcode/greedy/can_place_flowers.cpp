class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int maxi = 0;
        int l = 0, r = 0;
        
        while(r < flowerbed.size() && l < flowerbed.size()){
            while(r < flowerbed.size() && !flowerbed[r]) ++r;
            maxi += (r - l - 1 + (l == 0) + (r == flowerbed.size())) / 2;
        
            l = ++r;
        }
        
        return maxi >= n;
    }
};