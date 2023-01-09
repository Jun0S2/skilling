#include <iostream>
#include <map>

using namespace std;


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int temp = 0;
    map<int , int> numbers;
    
    for(int i = 0 ; i < 3 ; i++) {
        cin >> temp;
        numbers.insert({temp,i});
    }

    for (auto i : numbers) {
        cout << i.first << " ";
    }
}