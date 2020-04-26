#include <iostream>
#include <climits>
#define MAX 21
using namespace std;

int num = 0;
int minval = INT_MAX;
int arr[MAX][MAX];
int list1[10], list2[10];
bool check[MAX] = {false,};

int min(int a, int b) {return a<b? a:b;}

void Stalink(int start, int count){
    int x = 0;
    int temp1 = 0; int temp2 = 0; //임시 비교값
    if(count==num/2){
        for(int i=0; i<num; i++){
            if(!check[i]){list2[x] = i; x++;}
        }

        for(int j=0; j<num/2; j++){
            for(int k=0; k<num; k++){
                if(list1[j]!=k&&check[k]) temp1+=arr[list1[j]][k];
                if(list2[j]!=k&&!check[k]) temp2+=arr[list2[j]][k];
            }
        }
        minval = min(abs(temp1-temp2), minval);
        return;
    }
    for(int i=start+1; i<num; i++){
        if(!check[i]){
            check[i] = true;
            list1[count] = i;
            Stalink(i, count+1);
            check[i] = false;
        }
    }
}

void Input(){
    cin >> num;
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            cin >> arr[i][j];
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Stalink(0, 0);
    /*
    첫 번째 0 = 배열의 0부터 시작
    두 번째 0 = count (사람이 몇 명들어왔는지)
    */
    cout << minval;

    return 0;
}
