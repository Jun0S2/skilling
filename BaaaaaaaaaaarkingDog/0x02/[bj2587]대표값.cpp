#include <iostream>
#include <vector>
using namespace std;

void findMin (vector<int>& n1 , vector<int>& n2) {
    int min = 101; int index = 0;

    for (int i = 0 ; i < 5 ; i++ ) {
        if (n1[i] < min) {
            min = n1[i];
            index = i;
        }
    }
    // // add to n2
    n1[index] = 999;
    n2.push_back(min);
}

int main () {
   // 평균과 중앙값 구하기
    int temp , avg = 0;
    vector<int> numbers;
    vector<int> sorted ;
    for(int i = 0 ; i < 5 ; i++ ) {
        cin >> temp;
        avg += temp;
        numbers.emplace_back(temp);
    }
    cout << (avg/5) << "\n" ;
    
    for (int i = 0 ; i< 5; i++) {
        findMin(numbers, sorted);
    }
    
    cout<<sorted[2];
}