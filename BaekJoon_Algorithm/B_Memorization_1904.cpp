#include <iostream>
#define MODULE 15746
using namespace std;

int arr[1000001];

int num = 0;

int Find(int x){
    if(x<=2) return x;
    else if(arr[x]) return arr[x];
    return arr[x]= (Find(x-2) + Find(x-1)) % MODULE;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<2; i++) arr[i] = i;

    cin >> num;
    cout << Find(num)%15746;

    return 0;
}
