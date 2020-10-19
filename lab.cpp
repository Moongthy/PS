#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

const int MAX_N = 15;
int k;
string word[MAX_N];
int cache[MAX_N][1<<MAX_N], overlap[MAX_N][MAX_N];
int restore(int last, int used){
    // 기저사례
    if(used == (1<<k)-1) return 0;
    // 메모이제이션
    int& ret = cache[last][used];
    if(ret != -1) return ret;
    ret = 0;
    f(next, 0, k)
        if((used & (1<<next)) == 0){
            int cand = overlap[last][next] + restore(next, used + (1<<next));
            ret = max(ret, cand);
        }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    return 0;
}