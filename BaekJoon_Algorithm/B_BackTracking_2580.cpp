#include <iostream>
#define MAX 9
using namespace std;

int Map[MAX][MAX];
bool Row[MAX][MAX];
bool Col[MAX][MAX];
bool Square[MAX][MAX];

void Input(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cin >> Map[i][j];
            if(Map[i][j]!=0){
                Row[i][Map[i][j]] = true;
                Col[j][Map[i][j]] = true;
                Square[(i/3)*3 + (j/3)][Map[i][j]] = true;
            }
        }
    }
}

void Print(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cout << Map[i][j] << " ";
        }
        cout << "\n";
    }
}

void DFS(int Cnt){
    int x = Cnt/MAX;
    int y = Cnt%MAX;
    
    if(Cnt==81){
        Print();
        exit(0);
    }
    
    if(Map[x][y]==0){
        for(int i=1; i<=9; i++){
            if(Row[x][i]==false&&Col[y][i]==false&&Square[(x/3)*3+(y/3)][i]==false){
                Row[x][i] = true;
                Col[y][i] = true;
                Square[(x/3)*3 +(y/3)][i] = true;
                Map[x][y] = i;
                DFS(Cnt+1); // 해당 숫자가 아닐 경우 백트래킹 시작
                Map[x][y] = 0;
                Row[x][i] = false;
                Col[y][i] = false;
                Square[(x/3)*3+(y/3)][i] = false;
            }
        }
    }
    else DFS(Cnt+1);
}

void Solution(){
    DFS(0);
}

void Solve(){
    Input();
    Solution();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Solve();
    
    return 0;
}
