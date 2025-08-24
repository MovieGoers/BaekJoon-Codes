#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str1, str2;
    
    int N;
    
    cin >> N >> str1 >> str2;
    
    int cnt = 0;
    
    for(int n=0;n<N;n++){
      if(str1[n] != str2[n])
        cnt++;
    }
    
    cout << cnt;
    
    return 0;
}