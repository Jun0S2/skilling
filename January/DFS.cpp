#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/**
 * static variables
*/
int N; //  1~1000 정점의 개수
int M; //  1~10000 간선의 개수
int V; // 탐색을 시작할 정점의 번호
vector<bool> visited (1001);
vector<vector<bool>> map (1001, vector<bool> (10001)); // init vector with maximum size

/**
 * 디버그용 로그
 * Print Map
*/
void LOGD() {
    for (int row = 1 ; row <= N ; row ++ ) {
        for (int col = 1 ; col <=M ; col++ ) {
            cout<<map[row][col]<<" ";
        }
        cout<<endl;
    }
}

/**
 * Get Input from user
*/
void Input() {
    cin>>N>>M>>V;
    int temp1{0}, temp2{0}; 
    for(auto i  = 0 ; i < M ; i++) {
        cin>>temp1>>temp2;
        map[temp1][temp2] = map[temp2][temp1] = true;
    }
}

/**
 * Prints which node its visiting
 * a : visiting node
*/
void LOGI (int a ){
    cout<<a<<" ";
}

// 복사하지 말고, 포인터를 이용해서 vector 조정하기

/**
 * DFS uses vistied vector and list/vector
 * visited - size : N + 1 ,  정점을 visit 했는지 알아본다.
 * BFS에서는 visited 처리를 lamda로 빼서 했는데, dfs에서도 사용되기 때문에
 * 밖으로 뺴는 게 더 나아 보인다.
*/
void DFS(int a) {
    visited[a] = true; // 방문처리
    LOGI(a);           // 출력

    for(int i = 1 ; i <=N ; i++ ){
        if(visited[i]) continue;
        else if (!map[a][i])continue;
        else DFS(i);
    }
}

void Simulation() {
    Input();
    DFS(V);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Simulation();
}