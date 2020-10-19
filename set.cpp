#include<bits/stdc++.h>

using namespace std;

int S;


void add(int x){
    S |= (1 << x);
}

void rm(int x){
    S &= ~(1 << x);
}

void check(int x){
    if((S & (1 << x)))
        cout << 1 << "\n";
    else cout << 0 << "\n";
}

void toggle(int x){
    S ^= (1 << x);
}

void all(){
    int s = -1;
    int x = (s << 21);
    x = ~x;
    x -= 1;
    S = x;
}

void empty(){
    S = 0;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int M;
    cin >> M;
    S = 0;
    string f;
    int x;
    while(M--){    
        cin >> f;
        if(f == "add"){
            cin >> x;
            add(x);
            continue;
        }
        if(f == "remove"){
            cin >> x;
            rm(x);
            continue;
        }
        if(f == "check"){
            cin >> x;
            check(x);
            continue;
        }
        if(f == "toggle"){
            cin >> x;
            toggle(x);
            continue;
        }
        if(f == "all"){
            all();
            continue;
        }
        if(f == "empty"){
            empty();
            continue;
        }
    }

    // add(1);
    // add(2);
    // check(1);
    return 0;
}