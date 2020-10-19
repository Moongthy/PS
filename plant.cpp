#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define MAX_N 16

int N, P, cost[MAX_N][MAX_N];
// bitmasking
int plantOn,clicked, cache[1<<MAX_N];


int getMinCost(int plantOn){
    if(__builtin_popcount(plantOn) >= P) return 0;
    
    int& ret = cache[plantOn];
    if(ret >= 0) return ret;

    ret = 987654321;
    f(i, 0, N){
        if(plantOn & (1<<i)){
            int here = i;
            f(next, 0, N){
                if(plantOn & (1<<next)) continue;
                int minCost = cost[here][next] + getMinCost(plantOn|(1<<next));
                ret = min(ret, minCost);
            }
        }
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    f(i, 0, N)
        f(j, 0, N)
            cin >> cost[i][j];
    string isON;
    cin >>isON >> P;
    plantOn = 0;
    f(i, 0, N)
        if(isON[i] == 'Y')
            plantOn |= (1<<i);

    if(plantOn == 0) {
        if(P == 0){
            cout << 0 << endl;
        }
        else cout << -1 << endl;
        return 0;
    }

    cout << getMinCost(plantOn) << endl;
    return 0;
}