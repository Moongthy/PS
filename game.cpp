#include<bits/stdc++.h>

using namespace std;
#define MAX 50
#define f(a, b, c) for(int a = b; a < c; ++a)

int n, m, cache[MAX][MAX], Map[MAX][MAX];
bool visited[MAX][MAX];
bool isCycle;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool isIn(int y, int x){
    if(y < 0 || x < 0 || y > n-1 || x > m-1)
        return false;
    if(Map[y][x] == -1)
        return false;
    return true;
}
// 현재위치가 Map[y][x]일 때, 남은 최대 이동 횟수
int cntMove(int y, int x){
    if(y < 0 || x < 0 || y > n-1 || x > m-1)
        return 0;
    if(Map[y][x] == -1)
        return 0;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    visited[y][x] = true;
    ret = -987654321;
    f(i, 0, 4){
        int ny = y+dy[i]*Map[y][x];
        int nx = x+dx[i]*Map[y][x];
        if(isIn(ny, nx) && visited[ny][nx]){
            cout << -1 << endl;
            exit(0);
        }
        ret = max(ret, 1 + cntMove(ny, nx));
    }
    visited[y][x] = false;
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    memset(visited, false, sizeof(visited));
    cin >> n >> m;
    f(i, 0, n){
        string s;
        cin >> s;
        f(j, 0, m){
            if(s[j] == 'H')
                Map[i][j] = -1;
            else
                Map[i][j] = s[j]-'0';
        }
    }
    
    cout << cntMove(0, 0) << endl;
    return 0;
}