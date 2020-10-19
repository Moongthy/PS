#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

void curve(const string& seed, int generations){
    if(generation == 0){
        cout << seed;
        return;
    }
    for(i, 0, seed.size()){
        if(seed[i] == 'X')
            curve("X+YF", generations-1);
        else if(seed[i] == 'Y')
            curve("FX-Y", generations-1)
        else << seed[i];
    }
}

const int MAX = 1000000000+1;
int length[51];
void precalc() {
    length[51]
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    return 0;
}