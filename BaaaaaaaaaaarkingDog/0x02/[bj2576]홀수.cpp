#include <iostream>

using namespace std;

int main() {
    // 홀수만 더하고 이중 최소값을 찾는다
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tmp , sum = 0 ; int min = 101;

    for (int i = 0 ; i < 7 ; i++){
        cin >> tmp;
        if (!(tmp %2 ==0 )) {
            min = (tmp < min) ? tmp : min;
            sum += tmp;
        }
    }
    
    if(sum == 0) cout << "-1\n";
    else cout << sum << "\n" << min;
}