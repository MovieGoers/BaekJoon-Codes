#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int size;
        vector<int> vec;
        vec.push_back(-1);

        cin >> size;
        for(int j=0;j<size;j++){
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }

        bool checked[1001] = {false, };
        int cnt = 0;

        for(int j = 1;j<=size;j++){
            if(checked[j])
                continue;

            int initialIndex = j;
            checked[initialIndex] = true;

            int nextIndex = vec[initialIndex];
            
            while(nextIndex != initialIndex){
                checked[nextIndex] = true;
                nextIndex = vec[nextIndex];
            }

            cnt++;
        }

        cout << cnt << '\n';
    }
    return 0;
}
