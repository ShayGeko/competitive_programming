class Solution {
public:
    const static int maxn = 38;
    bool computed[maxn];
    int Trib[maxn];
    int tribonacci(int n) {
        return getTribonacci(n);
    }
    int getTribonacci(int n){
        if(computed[n]) return Trib[n];
        if(n < 3) return (n + 1) / 2;
        computed[n] = true;
        return Trib[n] = getTribonacci(n-3) +getTribonacci(n-2) + getTribonacci(n-1);
    }
};