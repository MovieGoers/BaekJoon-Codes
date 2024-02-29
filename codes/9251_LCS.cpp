#include <iostream>
#include <string>

using namespace std;

int arr[1001][1001];
string str1, str2;
int str1Size, str2Size;

int max(int a, int b){
    if(a > b)
        return a;
    
    return b;
}

void ResetArr(){
    for(int i=0;i<=str1Size;i++){
        arr[0][i] = 0;
    }

    for(int i=1;i<=str1Size;i++){
        arr[i][0] = 0;
    } 
};

int main(){
    cin >> str1 >> str2;
    str1Size = str1.size();
    str2Size = str2.size();

    ResetArr();

    for(int i=1;i<=str2Size;i++){
        for(int j=1;j<=str1Size;j++){
            if(str1[j-1] == str2[i-1])
                arr[i][j] = arr[i-1][j-1] + 1;
            else
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }

    cout << arr[str2Size][str1Size];

    return 0;
}
