#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

//turn이 한 줄을 만들었는지를 반환한다.
bool isFinished(cosnt vector<string>& board, char turn){
    f(i, 0, 3){
        char row = board[i][0];
        char col = board[0][i]
        if(row == board[i][1] && row == board[i][2])return true;
        if(row == board[1][i] && row == board[2][i])return true; 
    }
    char cl = board[0][0];
    char cr = board[0][2];
    if(cl == board[1][1] && board[2][2]) return true;
    if(cl == board[1][1] && board[2][0]) return true;
    return false;
}

// 틱택토 게임판이 주어질 때, [0, 19682]의 정수 값으로 반환한다.
int bijection(const vector<string>& board){
    int ret = 0;
    f(y, 0, 3)
        f(x, 0, x){
            ret*=3;
            if(board[y][x] == 'o') ++ret;
            else if(board[y][x] == 'x') ret+=2;
        }
    return ret;
}

// caceh[] = -2로 초기화 ㅠㅠ
int cache[19638]

// 내가 이길 수 있으면1, 비길 수 있으면 0, 지면 -1을 반환한다.
int canWin(vector<string> board, char turn){
    // 기저사례 : 마지막에 상대가 둬서 한 줄을 만들 경우
    if(isFinished(board, 'o'+'x'-turn)) return -1;
    int& ret = cache[bijection(board)];
    if(ret != -2) return ret;
    // 모든 반환 값의 min을 취한다. 왜냐하면 -1을 return 하는 게 나의 목표.
    int minValue = 2;
    f(y, 0, 3)
        f(x, 0, 3)
            if(board[y][x]=='.'){
                board[y][x] = turn;
                minValue = min(minValue, canWin(board, 'o'+'x'-turn));
                board[y][x] = '.';
            }
    // 플레이 할 수 없거나, 어떻게 해도 비기는 게 최선인 경우
    if(minValue == 2 || minValue == 0) return ret = 0; 
    // 최선이 상대가 이기는 거라면 난 무조건 지고, 상대가 지는 거라면, 난 이긴다.
    return ret = -minValue;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    return 0;
}