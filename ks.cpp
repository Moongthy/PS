#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

const int MAX = 2000000000+1;
int N, K;
int cacheLen[501], cacheCnt[501], S[500];

int getLen(int start){

    int& ret = cacheLen[start+1];
    if(ret != -1) return ret;

    ret = 1;
    f(next, start+1, N)
        if(start == -1 || S[next] > S[start])
            ret = max(ret, getLen(next)+1);

    return ret;

}

int count(int start){

    if(getLen(start) == 1) return 1;

    int& ret = cacheCnt[start+1];
    if(ret != -1) return ret;

    ret = 0;
    f(next, start+1, N)
        if((start == -1 || S[next] > S[start]) && (getLen(start) == getLen(next)+1))
            ret = min<long long>(MAX, (long long)ret + count(next));
    
    return ret;

}

void getkth(int start, int skip, vector<int>& ans){

    if(start != -1) ans.push_back(S[start]);
    vector<pair<int, int>> followers;
    f(next, start+1, N)
        if((start == -1 || S[next] > S[start]) && getLen(start) == getLen(next)+1)
            followers.push_back(make_pair(S[next], next));
    sort(followers.begin(), followers.end());
    f(i, 0, followers.size()){
        int idx = followers[i].second;
        int cnt = count(idx);
        if(cnt <= skip)
            skip -= cnt;
        else{
            getkth(idx, skip, ans);
            break;
        }
    } 
}


void solve(){
    getLen(-1);
    vector<int> ans;
    getkth(-1, K-1, ans);
    if(!ans.size()){
        cout << -1 << endl;
        return;
    }
    f(i, 0, ans.size())
        cout << ans[i] << " ";
    cout << endl;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(S, 0, sizeof(S));
    memset(cacheLen, -1, sizeof(cacheLen));
    memset(cacheCnt, -1, sizeof(cacheCnt));
    cin >> N >> K;
    f(i, 0, N) cin >> S[i];
    solve();
    return 0;
}