#include<bits/stdc++.h>

using namespace std;

#define INF 987654321
#define f(a, b, c) for(int a = b; a < c; ++a)
#define rep(a, n) for(int a = 0; a < n; ++a)

vector<vector<int>> board(3, vector<int>(3));
vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
int best = INF;
// 간단한 휴리스틱
int heuristic(const vector<vector<int>>& state){
    int ret = 0;
    rep(i, 3)
        rep(j, 3)
            if(state[i][j] != goal[i][j])
                ret++;
    return ret;
}

// 맨해튼 휴리스틱
int heuristic2(const vector<vector<int>>& state){
    int ret = 0;
    // i가 있을 장소는 [(i-1)/3][i-1]
    rep(i, 3)
        rep(j, 3){
            int num = state[i][j];
            int locY = (num-1)/3;
            int locX = num-1;
            ret += (abs(locY - i) + abs(locX - j));
        }  
    return ret;
}

bool isGoal(const vector<vector<int>>& state){
    rep(i, 3)
        rep(j, 3)
            if(state[i][j] != goal[i][j])
                return false;
    return true;
}
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int cntMove(int y, int x, int path, vector<vector<int>>& board){
    cout << path << endl;
    if(path + heuristic(board) > best) return INF;
    
    if(isGoal(board)) {
        if(best > path) best = path;
        return 0;
    }
    
    int ret = INF;

    rep(i, 4){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || ny == 3 || nx < 0 || nx == 3) continue;

      swap(board[y][x], board[ny][nx]);
      ret = min(ret, 1 + cntMove(ny, nx, path+1, board));
      swap(board[y][x], board[ny][nx]);  
    }
    return ret;
}

int cntMove2(int sy, int sx){

    // f(n), ny, nx
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {sy, sx}});
    int gn = 0;
    while(pq.empty()){
        // 확장할 노드를 선택


        // 노드 생성
        f(i, 0, 4){
            int ny = y+dy[i], nx = x+dx[i];
            if(ny < 0 || nx < 0 || ny == 3 || nx == 3) continue;
            pq.push({-(gn + heuristic())})
        }
        // 현재 거리
        gn++;
    }
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    rep(i, 3)
        rep(j, 3)
            cin >> board[i][j];
    
    rep(i, 3)
        rep(j, 3)
            if(!(board[i][j])){
                cout << cntMove(i, j, 0, board) << endl;
                return 0;
            }
    return 0;
}