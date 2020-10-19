#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define MAX 10003
int n, popu[MAX], cache[MAX][2];
bool visited[MAX];
vector<vector<int>> tree;

// here마을과 우수마을 여부가 주어질 떄, 남은 우수마을 주민수의 총합.
int greatTown(int here, int isGreat){
    int& ret = cache[here][isGreat];
    if(ret != -1) return ret;
    ret = 0;
    visited[here] = true;
    f(i, 0, tree[here].size()){
        int there = tree[here][i];
        // 현재 마을이 우수마을이 아니면, 다음 마을은 우수마을 일수도, 아닐수도 있다.
        if(visited[there]) continue;
        if(!isGreat)
            ret += max(greatTown(there, 0), popu[there] + greatTown(there, 1));
        // 현재 마을이 우수마을 이면, 다음 마을은 우수마을이 아니다.
        else
            ret += greatTown(there, 0);
    }
    visited[here] = false;
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    
    cin >> n;
    tree = vector<vector<int>>(n, vector<int>(0, 0));
    f(i, 0, n)
        cin >> popu[i];
    
    f(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        --a; --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int ret = max(greatTown(0, 0), greatTown(0, 1) + popu[0]);
    cout << ret << endl;

    return 0;
}