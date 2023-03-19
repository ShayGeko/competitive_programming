#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
int completedBoards;
vector<bool> completed;
int getScore(vector<vector<int>> &board){
    int sum = 0;
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            if(board[i][j] > 0) sum+=board[i][j];

    return sum;
}
bool checkBoard(vector<vector<int>> &board){
    for(int i = 0; i < 5; ++i){
        int j = 0;
        while(j < 5 && board[i][j] == -1) ++j;
        if(j == 5) return true;
        j = 0;
        while(j < 5 && board[j][i] == -1) ++j;
        if(j == 5) return true;
    }
    return false;
}
void mark(vector<vector<int>> &board, int num){
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            if(board[i][j] == num) board[i][j] = -1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<int> numbers = {13,47,64,52,60,69,80,85,57,1,2,6,30,81,86,40,27,26,97,77,70,92,43,94,8,78,3,88,93,17,55,49,32,59,51,28,33,41,83,67,11,91,53,36,96,7,34,79,98,72,39,56,31,75,82,62,99,66,29,58,9,50,54,12,45,68,4,46,38,21,24,18,44,48,16,61,19,0,90,35,65,37,73,20,22,89,42,23,15,87,74,10,71,25,14,76,84,5,63,95};

    vector<vector<vector<int>>> boards;
    int temp;
    vector<vector<int>> tempBoard (5);
    for(int i = 0; i < 5; ++i) tempBoard[i] = vector<int>(5);
    while(cin >> temp){
        tempBoard[0][0] = temp;
        for(int i = 1; i < 5; ++i) cin >> tempBoard[0][i];
        for(int i = 1; i < 5; ++i)
            for(int j = 0; j < 5; ++j) cin >> tempBoard[i][j];
        boards.push_back(tempBoard);
    }
    completed.resize(boards.size(), false);
    for(auto num : numbers){
        for(int i = 0; i < boards.size(); ++i){
            if(completed[i]) continue;
            auto &board = boards[i];
            mark(board, num);
            if(checkBoard(board)){
                completed[i] = true;
                ++completedBoards;
                if(completedBoards == boards.size()) {
                    int score = getScore(board);
                    cout << score * num << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}