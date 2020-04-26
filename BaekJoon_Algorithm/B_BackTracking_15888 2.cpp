#include <iostream>
#include <vector>
#include <limits.h> // INT_MIN과 INT_MAX를 사용하기 위한 헤더파일
using namespace std;

int max_val = INT_MIN;
int min_val = INT_MAX;
int num = 0;
vector <int> v;
int cul[4];

void Input(){
    cin >> num;

    for(int i=0; i<num; i++){
        int x = 0;
        cin >> x;
        v.push_back(x);
    }

    for(int i=0; i<4; i++)
        cin >> cul[i];
}

void BackTracking(int result, int pl, int mi, int mul, int div, int index){
    if(pl < 0 || mi < 0 || mul < 0 || div < 0) return;
    if(index == num){
        if(result > max_val) max_val = result;
        if(result < min_val) min_val = result;
        return;
    }
    BackTracking(result + v[index], pl-1, mi, mul, div, index+1);
    BackTracking(result - v[index], pl, mi-1, mul, div, index+1);
    BackTracking(result * v[index], pl, mi, mul-1, div, index+1);
    BackTracking(result / v[index], pl, mi, mul, div-1, index+1);
}

void Print_vals(){
    cout << max_val << "\n" << min_val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    BackTracking(v[0],cul[0],cul[1],cul[2],cul[3],1);
    Print_vals();
    
    return 0;
}
