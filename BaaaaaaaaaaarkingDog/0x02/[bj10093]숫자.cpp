#include <iostream>

using namespace std;

int main() {
    long long a,b,temp;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> temp;

    if(temp>a) {
        b = temp;
    } else { // temp < a
        b = a;
        a = temp;
    }

    if ((b-a-1) <=0 ) {
        cout << "0\n";
        return 0;
    } else {
        cout << (b-a-1) << "\n";
        for(long long i = a+1 ; i < b ; i++ ) {
            cout << i << " ";
        }   
    }
}