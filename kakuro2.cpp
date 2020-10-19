#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

// mask에 속한 원소들의 개수를 반환한다.
int getSize(int mask){
    return __builtin_popcount(mask);
}

// mask에 속한 원소들의 합을 반환한다.
int getSum(int mask){
    int sum = 0;
    f(i, 0, 10)
        if(mask & (1<<i)) sum += i;
    return sum;
}

// len칸의 합이 sum이고, 이 칸들에 이미 쓰인 수의 집합이 known일 때, 
// 나머지 칸에 들어갈 수 있는 숫자들의 집합을 반환한다.
int getCandidates(int len, int sum, int known){
    // 조건에 부합하는 집합들의 교집합
    int allSets = 0;
    // 1~9의 부분집합(즉 모든 짝수)을 모두 생성하고, 그 중
    for(int set = 0; set < 1024; set += 2)
        //known을 포함하고, 크기가 len이며, 합이 sum인 집합을 모두 찾는다.
        if((set & known) == known && getSize(set) == len && getSum(set) == sum)
            allSets |= set;
    //known에 이미 속한 숫자들은 답에서 제외한다.
    return allSets & ~known;
}


// candidates[len][sum][known] = getCandidates(len, sum, known)
int candidates[10][46][1024];

// cacndiataes[][][]를 미리 계산한다.
void generateCandidates(){
    // 우선 전부 0으로 초기화 한다.
    memset(candidates, 0, sizeof(candidates));
    // 1~9의 부분집합을 전부 생성한다.
    for(int set = 0; set < 1024; set += 2){
        // 집합의 크기와 원소의 합을 계산해 둔다.
        int l = getSize(set), s = getSum(set);
        // set의 모든 부분집합에 대해 candidates[][][]를 갱신한다.
        int subset = set;
        while(true){
            // 숫자 하나의 합이 s이고, 이미 subset숫자가 쓰여 있을 때
            // 전체 숫자의 집합이 set이 되도록 나머지 숫자를 채워 넣을 수 있다.
            cacndiataes[l][s][subset] |= (set & ~subset);
            if(subset == 0) break;
            subset = (subset - 1) & set;
        }
    }
}

// 게임판의 정보
// color : 각 칸의 색깔(0 = 검은 칸 혹은 힌트 칸, 1 = 흰 칸)
// value : 각 흰 칸에 쓴 숫자(아직 쓰지 않은 칸은 0)
// hint  : 각 칸에 해당하는 두 힌트의 번호
int n, color[MAXN][MAXN], value[MAXN][MAXN], hint[MAXN][MAXN][2];

// 각 힌트의 정보
// sum : 힌트 칸에 쓰인 숫자
// length : 힌트 칸에 해당하는 흰 칸의 수
// known : 힌트 칸에 해당하는 흰 칸에 쓰인 숫자들의 집합
int q, sum[MAXN*MAXN], length[MAXN*MAXN], known[MAXN*MAXN];
// (y, x)에 val을 쓴다.
void put(int y, int x, int val){
    f(h, 0, 2)
        known[hint[y][x][h]] += (1<<val);
    value[y][x] = val;
}

// (y, x)에 쓴 val을 지운다.
void remove(int y, int x, int val){
    f(h, 0, 2)
        known[hint[y][x][h]] -= (1<<val);
    value[y][x] = 0;
}

// 힌트 번호가 주어질 때 해당 칸에 들어갈 수 있는 후보의 집합을 반환한다.
int getCandCoord(int y, int x){
    return getCandHint(hint[y][x][0]) & getCandHint(hint[y][x][1]);
}

// value[][]에 적힌 값을 출력한다.
void printSolution();
// 답을 찾았으면 true, 아니면 false를 반환한다.
bool search(){
    // 아직 숫자를 쓰지 않은 흰 칸 중 후보의 수가 최소인 칸을 찾는다.
    int y = -1, x = -1, minCands = 1023;
    f(i, 0, n)
        f(j, 0, n)
            if(color[i][j] == WHITE && value[i][j] == 0){
                int cands = getCandCoord(i, j);
                if(getSize(minCands) > getSize(cands)){
                    minCands = cands;
                    y = i; x = j;
                }
            }

    // 이 칸에 들어갈 숫자가 없으면 실패!
    if(minCands == 0) return false;
    // 모든 칸이 채워졌으면 출력하고 종료한다.
    if(y == -1){
        printSolution();
        return true;
    }
    // 숫자를 하나씩 채워보자.
    f(val, 1, 10)
        if(minCands & (1<<val)){
            put(y, x, val);
            if(search()) return true;
            remove(y, x, val);
        }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    return 0;
}