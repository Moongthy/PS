#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define MAX 100
#define ll long long
const ll mod = 1000000000;
int N;
ll cache[MAX][10][1<<10]; 
// stage : 현재 자릿수
// currNum : 전 자릿수에 해당하는 숫자
ll countStageNum(int stage, int currNum, int used){
    
    if(stage == N){
        if(used == (1<<10)-1) return 1;
        else return 0;
    } 
    ll& ret = cache[stage][currNum][used];
    if(ret != -1) return ret;
    ret = 0;
    if(currNum != 0)
      ret = (ret + countStageNum(stage+1, currNum-1, used|(1<<currNum-1)))%mod;  
    if(currNum != 9)
      ret = (ret + countStageNum(stage+1, currNum+1, used|(1<<currNum+1)))%mod;
    return ret;
}

ll solve(){
    memset(cache, -1, sizeof(cache));
    cin >> N;
    
    ll ret = 0;
    f(i, 1, 10)
        ret = (ret + countStageNum(1, i, 1<<i))%mod;
    
    return ret;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cout << solve();
    

    return 0;
}