#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

int N;
vector<vector<int>> board;
vector<vector<int>> horiHints;
vector<vector<int>> vertHints;

void printBoard(){
    for(vector<int> line : board){
        for(int yx : line)
            if(yx) cout << 1 << " ";
            else cout << 0 << " ";
        cout << "\n";
    }
}

int printHint(){
    int HintCount = 0;
// 가로 힌트부터.
    f(i, 0, N){
        int sum = 0;
        for(int j = N-1; j >= 0; --j){
            if(board[i][j] == 0 && sum == 0) continue;
            // horizontal hint
            if(board[i][j] == 0){
                vector<int> hint;
                hint.push_back(i+1);
                hint.push_back(j+1);
                hint.push_back(0);
                hint.push_back(sum);
                sum = 0;
            }
            horiHints.push_back(hint);
        }
    }
    
// 세로 힌트
    f(i, 0, N){
        int sum = 0;
        for(int j = N-1; j >= 0; --j){
            if(board[j][i] == 0 && sum == 0) continue;
            // horizontal hint
            if(board[j][i] == 0){
                
                sum = 0;
            }
        }
    }

    return HintCount;
}

void solve(){
    cin >> N;
    f(i, 0, N){
        vector<int> line;
        f(j, 0, N){
            int x;
            cin >> x;
            line.push_back(x);
        }
        board.push_back(line);
    }
    printBoard();
    int hintN = printHint();
    cout << hintN << "\n";
    f(i, 0, hintN)
        cout << hints[i] << "\n";

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}