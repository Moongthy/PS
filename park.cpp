#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define rep(n) for(int i = 0; i < n ; ++i)
#define ll long long

int N, K;
vector<string> Set;

// 분모 : n!
ll mother(int n){
    if(n == 1) return 1;
    return mother(n-1) * n;
}

ll cache[1<<15][100];
ll child(int used, int total){
    if((used == (1<<N)-1) && (total == 0))
        return 1;

    ll& ret = cache[used][total];
    if(ret != -1) return ret;
    
    ret = 0;
    f(next, 0, N){
        if(used & (1<<next)) continue;
        ret += child(used | (1<<next), (total*100 + Set[next])%K);
    }
    return ret;
}

void print(ll child, ll mother){
    if(child == 0){
        cout << "0/1" << endl;
        return;
    }
    if(child == mother){
        cout << "1/1" << endl;
        return;
    }
    for(ll i = 1; i <= child; ++i)
        if(child % i == 0 && mother % i == 0){
            child /= i;
            mother /= i;
        }
    cout << child << "/" << mother << endl;
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    // 각 수의 길이는 길어야 50
    rep(N){
        string num;
        cin >> num;
        Set.push_back(num);
    }
    rep(N){
        
    }
    cin >> K;

    memset(cache, -1, sizeof(cache));
    print(child(0, 0), mother(N));
    return 0;
}


