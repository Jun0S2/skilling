#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int i , time =0;
    int priceA,priceB = 0;
    cin >> i;

    /**
     * 영식 요금 - 30초마다 10원씩 청구. 
     * 0~ 29초 - 10원 
     * 30 ~ 59 초  - 20원
     * 공식 : X초 % 60 = N.N == 0 이면 X/60 + 0  else +1
    */
    auto plan = [](int t, int price, int actualtime) {
        // cout << ((actualtime/t) * price) << " + "  <<(((actualtime % t) == 0) ? 0 : price);
        // return (((actualtime/t) * price)+ (((actualtime % t) == 0) ? 0 : price)); 
        if (actualtime < t) return price;
        return price + (actualtime/t*price) ;
    };
    
    for (int j = 0 ; j <i ; j++) {
        cin >> time;
        cout <<"A : " << plan(30,10, time) << " B: " << plan(60,15,time) <<endl;
        priceA += plan(30,10, time);  // 영식 :30초 마다 10원씩 time분
        priceB +=  plan(60,15,time);
    }

    if(priceA == priceB) {
        cout << "Y M " << priceA;
    } else if (priceA < priceB) {
        cout << "Y "<<priceA; 
    } else {
        cout <<"M " <<priceB;
    }
}
