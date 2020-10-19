#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

#define MAX 10
int N, K, worth[MAX];

int minCoin(int p){
    int price = p;
    int coinNum = 0;
    int coin = N-1;
    while(true){
        if(!price) return coinNum;
        if(price < worth[coin]){
            --coin;
            continue;
        }
        price -= worth[coin];
        ++coinNum;
    }
    return -1;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    f(i, 0, N)
        cin >> worth[i];
    cout << minCoin(K);
    return 0;
}