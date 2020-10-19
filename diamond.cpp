#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define MAX 750
int R, C, mine[MAX][MAX], cache[MAX][MAX];

int dy[2] = {1, 1};
int dx[2] = {-1, 1};
// 가장 위 꼭짓점에서 그릴 수 있는 가장 큰 다이아몬드의 크기를 반환한다.
int countDia(int y, int x){

    if(y < 0 || x < 0 || y > R-1 || x > C-1) return 0;

    int& ret = cache[y][x];
    if(ret != -1) return ret;

    ret = mine[y][x];
    int l = countDia(y+dy[0], x+dx[0]);
    int r = countDia(y+dy[1], x+dx[1]);

    if(l == r){
        if(l == 0) return ret;
        if(y+2*l <= R-1 && mine[y+2*l][x]) return ret += l;
        return ret += l-1;
    }
    return ret += min(l, r);
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    cin >> R >> C;
    f(i, 0, R){
        string s;
        cin >> s;
        f(j, 0, s.size()) 
            mine[i][j] = s[j]-'0';
    }
    int ret = -1;
    f(i, 0, R)
        f(j, 0, C)
            ret = max(ret, countDia(i, j));
    cout << ret << endl;
    return 0;
}