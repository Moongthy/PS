#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

string str;
int cache[2501];
bool isPelin(string s){
    if(s.size() == 1) return true;
    f(i, 0, s.size()/2)
        if(s[i] != s[s.size()-1-i])
            return false;
    return true;
}

int divcount(int start){
    if(start == str.size()) return 0;
    int& ret = cache[start];
    if(ret != -1) return ret;
    ret = 987654321;
    f(i, start, str.size())
        if(isPelin(str.substr(start,i-start+1)))
            ret = min(ret, 1 + divcount(i+1));
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    cin >> str;
    int ret = 987654321;
    cout << divcount(0) << endl;
    return 0;
}