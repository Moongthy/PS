#include<bits/stdc++.h>

using namespace std;

#define NEGINF -99999999
#define MAX 1000
#define f(a, b, c) for(int a = b; a < c; ++a)
#define ll long long


int N, M, price[MAX][MAX];
ll cache[MAX][MAX][3];

int dy[3] = {0, 0, 1};
int dx[3] = {-1, 1, 0};

// here에서 출발 했을 때, 도착지 까지 가는 최대 가치
ll getMaxPrice(int hereY, int hereX, int dir){
    

    if(hereY < 0 || hereX < 0 || hereY > N-1 || hereX > M-1)
        return NEGINF;

    if(hereY == N-1 && hereX == M-1) 
        return (ll)price[hereY][hereX];

    ll& ret = cache[hereY][hereX][dir];
    if(ret != -1) return ret;

    ret = NEGINF;
    f(i, 0, 3){
        if(dir == 1 && i == 0) continue;
        if(dir == 0 && i == 1) continue;
        ll cand = (ll)(price[hereY][hereX] + getMaxPrice(hereY+dy[i], hereX+dx[i], i));
        ret = max(ret, cand);
    } 
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    f(i, 0, N)
        f(j, 0, M)
            cin >> price[i][j];

    ll ret = NEGINF;
    f(i, 0, 3)
        ret = max(ret, getMaxPrice(0, 0, i));
    cout << ret << endl;

    return 0;
}