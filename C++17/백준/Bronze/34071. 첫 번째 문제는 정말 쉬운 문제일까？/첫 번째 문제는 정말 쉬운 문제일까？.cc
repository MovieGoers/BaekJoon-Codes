#include <iostream>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    int first = 0;
    int hard = -1, ez = 1987;
    
    for(int i=0;i<N;i++){
      int k;
      cin >> k;
      if(i == 0)
        first = k;
      if(k < ez){
        ez = k;
      }
      
      if(k > hard){
        hard = k;
      }
    }
    
    if(first == ez){
      cout << "ez";
    }else if(first == hard){
      cout << "hard";
    }else {
      cout << '?';
    }
    return 0;
}