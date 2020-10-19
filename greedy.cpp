#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define MAX 100000

int Begin[MAX], End[MAX], N;
vector<pair<int, int>> meetings;
int maxMeeting(){
    f(i, 0, N){
        pair<int, int> meeting = {End[i], Begin[i]};
        meetings.push_back(meeting);
    }
    sort(meetings.begin(), meetings.end());
    int earlist = 0, count = 1;
    f(i, 1, N){
        // 가장 빨리 종료하는 회의의 시간과 겹치는 시간이 있다?
        if(meetings[earlist].first > meetings[i].second) continue;
        earlist = i;
        ++count;
    }
    return count;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    f(i, 0, N)
        cin >> Begin[i] >> End[i];
    cout << maxMeeting();
    return 0;
}