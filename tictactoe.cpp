#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

int cache[19684];
bool cache2[19684];

bool isFinished(const string& board, char turn){
    f(i, 0, 3)
        if(board[i*3] == turn && board[i*3+1] == turn && board[i*3+2] == turn) return true;
    f(i, 0, 3)
        if(board[i] == turn && board[3+i] == turn && board[6+i] == turn) return true;
    if(board[0] == turn && board[4] == turn && board[8] == turn) return true;
    if(board[3] == turn && board[4] == turn && board[6] == turn) return true;
    return false;
}

// 틱택토 게임판이 주어질 때, [0, 19682]범위의 정수로 변환한다.
int bijection(const string& board){
    int ret = 0;
    f(y, 0, 3)
        f(x, 0, 3){
            ret *= 3;
            if(board[y*3+x] == 'O') ++ret;
            if(board[y*3+x] == 'X') ret+=2;
        }
    return ret;
}

// turn이 이길 수 있으면 1, 비길 수 있으면 0, 지면 -1을 반환한다.
int canWin(string& board, char turn){
    // 기저 사례 : 마지막에 상대가 둬서 한 줄이 만들어진 경우
    int& ret = cache[bijection(board)];
    if(ret != -2) return ret;
    if(isFinished(board, 'O'+'X'-turn)) {
        cache2[bijection(board)] = true;
        return ret = -1;
    }
    // 모든 반환 값의 min을 취한다.
    int minValue = 2;
    f(y, 0, 3)
        f(x, 0, 3)
            if(board[y*3+x] == '.'){
                board[y*3+x] = turn;
                minValue = min(minValue, canWin(board, 'O'+'X'-turn));
                board[y*3+x] = '.';
            }
    // 플레이 할 수 없거나, 어떻게 해도 비기는 것이 최선일 경우
    if(minValue == 2) cache2[bijection(board)] = true;
    if(minValue == 2 || minValue == 0) return ret = 0;
    // 최선이 상대가 이기는 거라면 나는 무조건 지고, 상대가 지는 거라면 난 이긴다.
    return ret = -minValue;

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 19684; ++i){
        cache[i] = -2;
        cache2[i] = false;
    }
    string b = ".........";
    char turn = 'X';
    
    canWin(b, turn);

    while(true){
        string board;
        cin >> board;
        if(board == "end") return 0;
        if(cache[bijection(board)] == -2)
            cout << "invalid" << endl;
        else if(cache[bijection(board)] == 0)
            cout << "valid" << endl;
        else if(!cache2[bijection(board)])cout << "invalid" << "\n";
        else cout << "valid" << endl;
    }
    return 0;
}