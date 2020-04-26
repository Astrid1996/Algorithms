#include <iostream>
using namespace std;

int ans[91]={1,1,};

int calculate(int x){
    if(x<=1) return ans[x];
    else{
        if(ans[x]>0) return ans[x]; //조건을 삽입하지 않으면 초기화 된 값 '0'을 바로 출력해버림
    }
    return ans[x] = calculate(x-1) + calculate(x-2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int num = 0;
        cin >> num;
        if(num==0) cout << "1 0" << "\n";
        else if(num==1) cout << "0 1" << "\n";
        else{
            calculate(num);
            cout << ans[num-2] << " " << ans[num-1] << "\n";
            }
    }
    
    return 0;
}
