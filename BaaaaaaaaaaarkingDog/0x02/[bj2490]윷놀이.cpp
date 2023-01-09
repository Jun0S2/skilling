#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt = 0;
    int input = 0;   
    string result = "EABCD";// 0 (1) : 도, 0(2) : 개, 0(3) : 걸 0 (4):윷...모?  0(0):모?

    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    for(int i = 0 ; i < 3 ; i ++ ){
        for (int j = 0 ; j<4 ; j++) {
            cin>>input;
            cnt += (input == 0);
        }
        cout << result[cnt] << "\n";
        input = cnt = 0;
    }
}