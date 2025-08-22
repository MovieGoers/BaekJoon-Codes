#include <iostream>
using namespace std;

int main() 
{
    int T;
    
    cin >> T;
    
    int a, b;
    
    int min = 1987654321;
    
    while(--T >= 0){
      cin >> a >> b;
      if(min > a + b){
        min = a + b;
      }
    }
    
    cout << min;
    return 0;
}