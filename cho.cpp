#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define MAX 50
#define INF 987654321

// 격자에는 최소 1개의 건포도가 들어있음.
// 경계선의 건포도는 없다.
// 초콜릿을 한번 자를 때마다 비용발생
// 한번 자를 때 마다 자르기 전 격자의 건포도 갯수가 비용임.

// 각 조각의 건포도 수를 암.
// 건포도의 조각이나 위치 모두 bonny가 결정할 수 있음. 
// n * n 격자가 있을 때 자를 수 있는 경우는 (n-1) * (n-1)
int n, m, podo[MAX][MAX];
int cache[MAX][MAX][MAX][MAX];

int getCost(pair<int,int> leftup, pair<int,int> rightdown){

    if(leftup.first == rightdown.first && leftup.second == rightdown.second) return 0;

    int& ret = cache[leftup.first][leftup.second][rightdown.first][rightdown.second];
    if(ret != -1) return ret;
    
    int row = rightdown.first -leftup.first;
    int col = rightdown.second - leftup.second;

    int currCost = 0;
    f(i, 0, row+1)
        f(j, 0, col+1)
            currCost += podo[leftup.first+i][leftup.second+j];

    ret = INF;
    f(i, 0, row){
        int cost = currCost + 
                    getCost(leftup, make_pair(leftup.first+i, rightdown.second)) + 
                    getCost(make_pair(leftup.first+i+1, leftup.second), rightdown);
        ret = min(ret, cost);
    }
    f(i, 0, col){
        int cost = currCost + 
                    getCost(leftup, make_pair(rightdown.first, leftup.second+i)) + 
                    getCost(make_pair(leftup.first, leftup.second+i+1), rightdown);
        ret = min(ret, cost);
    }        
    return ret;

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    f(i, 0, n)
        f(j, 0, m){
            cin >> podo[i][j];
        }

    cout << getCost(make_pair(0, 0), make_pair(n-1, m-1)) << endl;
    return 0;
}