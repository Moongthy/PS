#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

int N, board[9][9], hint[9][9][3];
vector<int> domino;

// 각 행, 열, 그리드의 합은 45
int getRowCandidates(int known){
    return ((1<<9)-2) & (~known);
}
int getColCandidates(int known){
    return ((1<<9)-2) & (~known);
}
int getGreedCandidates(int known){
    return ((1<<9)-2) & (~known);
}
int getCandCoordNum(int y, int x){
    return getRowCandidates(hint[y][x][0]) & 
            getColCandidates(hint[y][x][1]) & 
            getGreedCandidates(hint[y][x][2]);
}
bool getCandCoordDom(int CandCoordNum){
    for(int canDom : domino)
        if(canDom == CandCoordNum)
            return true;
}
void generateHint(){
    f(i, 0, 9){
        int rowHint = 0;
        f(j, 0, 9){
            int val = board[i][j];
            if(!val) continue;
            rowHint |= (1<<val);
        }
        f(j, 0, 9) hint[i][j][0] = rowHint;
    }
    f(i, 0, 9){
        int colHint = 0;
        f(j, 0, 9){
            int val = board[j][i];
            if(!val) continue;
            colHint |= (1<<val);
        }
        f(j, 0, 9) hint[i][j][1] = colHint;
    }

    f(i, 0, 3)
        f(j, 0, 3){
            int greedHint = 0;
            f(k, 0, 3)
                f(l, 0, 3){
                    int val =  board[i*3 + k][j*3 + l];
                    if(!val) continue;
                    greedHint |= (1<<val);
                }
            f(k, 0, 3)
                f(l, 0, 3)
                    f(j, 0, 9) hint[i][j][2] = greedHint;
        }

void put(int y1, int x1, int y2, int x2, int num1, int num2){
    board[y1][x1] = num1;
    board[y2][x2] = num2;
    for(int dom : domino)
        if(dom == ((1<<num1)|(1<<num2))){
            dom = 0;
            break;
        }
    
    f(i, 0, 9){
        hint[y1][i][0] & (~(1<<num1));
        hint[i][x1][1] & (~(1<<num1));
        hint[y2][i][0] & (~(1<<num2));
        hint[i][x2][1] & (~(1<<num2));
    }
    f(i, 0, 3)
        f(j, 0, 3)
            hint[y1/3 + i][x1/3 + j][2] &= (~(1<<num1));
            hint[y2/3 + i][x2/3 + j][2] &= (~(1<<num2));
}
void remove(int y1, int x1, int y2, int x2, int num1, int num2){
    board[y1][x1] = 0;
    board[y2][x2] = 0;
    for(int dom : domino)
        if(dom == 0) {
            dom = (1<<num1)|(1<<num2);
            break;
        }
    
    f(i, 0, 9){
        hint[y1][i][0] |= (1<<num1);
        hint[i][x1][1] |= (1<<num1);
        hint[y2][i][0] |= (1<<num2);
        hint[i][x2][1] |= (1<<num2);
    }
    f(i, 0, 3)
        f(j, 0, 3)
            hint[y1/3 + i][x1/3 + j][2] |= (1<<num1);
            hint[y2/3 + i][x2/3 + j][2] |= (1<<num2);
}
vector<int> generateDomino(vector<int>& alreadyDomino){
    vector<int> domino;
    int dom = 0;
    for(int i = 1; i < 9; ++i){
        for(int j = i+1; j < 10; ++j){
            dom += ((1<<i) | (1<<j));
            for(int already : alreadyDomino)
                if((already == dom) break;
            domino.push_back(dom);
        }
    }
    return domino;
}

void solve(){
    vector<int> alreadyDomino;
    cin >> N;
    f(i, 0, N){
        int L, V;
        string LU, LV;
        cin >> U >> LU >> V >> LV;
        board[LU[0]-'A'][LU[1]-'1'] = U;
        board[LV[0]-'A'][LV[1]-'1'] = V;
        alreadyDomino.push_back((1<<U)|(1<<V));
    }
    f(i, 1, 10){
        string L;
        cin >> L;
        board[L[0]-'A'][L[1]-'1'] = i;
    }
    domino = generateDomino(alreadyDomino);
    generateHint();
    f(i, 0, 9)
        f(j, 0, 9){
            int val = board[i][j];
            if(val) continue;
            

        }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}