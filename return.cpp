#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define MAX_N 50

// 농사지을 땅의 수익의 합이 같다.
// 단위 정사각형의 수익은 음수가 될 수 있다.
// 두 땅은 한 꼭짓점에서 만나야 한다.
#define NEGINF -987654321
int N, profit[MAX_N][MAX_N];
int cache[MAX_N][MAX_N][MAX_N][MAX_N];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int getProfit(pair<int,int> groundA, pair<int, int> groundB){
    int h = abs(groundA.first - groundB.first)+1;
    int w = abs(groundA.second - groundB.second)+1;
    int totalProfit = 0;
    f(i, 0, h)
        f(j, 0, w)
            totalProfit += profit[i][j];
    return totalProfit;
}

// 상근이의 땅이 주어졌을 때 나누어 주는 경우의 수
int count(pair<int,int> groundA, pair<int, int> groundB){
    // 범위 체크
    if(groundA.first < 0 || groundA.second < 0 || groundB.first < 0 || groundB.second < 0 ||
        groundA.first > N-1 || groundA.second > N-1 || groundB.first > N-1 || groundB.second > N-1)
        return 0;

    

    int& ret = cache[groundA.first][groundA.second][groundB.first][groundB.second];
    if(ret != NEGINF) return ret;

    int ret = 0;
    f(i, 0, )
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    f(i, 0, N)
        f(j, 0, N){
            cin >> profit[i][j];
            f(k, 0, N)
                f(l, 0, N)
                    cache[i][j][k][l] = NEGINF;
        }
    return 0;
}