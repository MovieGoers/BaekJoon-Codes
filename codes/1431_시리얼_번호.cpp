#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string str1, string str2){
    int str1Size = str1.size();
    int str2Size = str2.size();

    if(str1Size != str2Size)
        return str1Size < str2Size;
    else{
        int str1Sum = 0, str2Sum = 0;

        for(int i=0;i<str1Size;i++){
            if(str1[i] >= '0' && str1[i] <= '9'){
                str1Sum += str1[i] - '0';
            }
        }

        for(int i=0;i<str2Size;i++){
            if(str2[i] >= '0' && str2[i] <= '9'){
                str2Sum += str2[i] - '0';
            }
        }

        if(str1Sum != str2Sum)
            return str1Sum < str2Sum;
        
        return str1 < str2;
    }
};

int main(){
    string strings[50];
    int N;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> strings[i];
    }

    sort(strings, strings + N, cmp);

    for(int i=0;i<N;i++){
        cout << strings[i] << '\n';
    }

    return 0;
}
