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
bool isBFS = false;

vector<bool> visited (1001); 
queue<int> q_bfs ; //bfs용 queue
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
 * visited 배열 초기화
*/
void init() {
    for(auto i : visited) i=false;
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

/**
 * visit
 * parameter가 1개면 dfs
 * parameter가 1개면 bfs
*/
void visit(int node) {
    visited[node] = true;
    LOGI(node);
    if(isBFS) q_bfs.push(node);
}

/**
 * DFS uses vistied vector and list/vector
 * visited - size : N + 1 ,  정점을 visit 했는지 알아본다
*/
void DFS(int a) {
    visit(a);
    for(int i = 1 ; i <=N ; i++ ){
        if(!visited[i] && map[a][i]) DFS(i); // 아직 방문 안하고 연결된 노드
    }
}
/**
 * BFS Uses Queue and visited vector
 * visited - size : N + 1 ,  정점을 visit 했는지 알아본다.
*/
void BFS() {
    isBFS = true;
    visit(V);

    while(!q_bfs.empty()){ // when q is empty, it means its done with traverse
        int current_node = q_bfs.front(); // current node
        q_bfs.pop();
        
        for(int i = 1 ; i<= N ; i++ ){
            if (!visited[i] && map[current_node][i]) visit(i); // 접해있고 방문안직안한노드                    // 서로 접해있음 -> 마크로처리 ㄱㄱ
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();    // get input
    DFS(V);     // print dfs
    init();     // reset visit
    cout<<endl; // return key
    BFS();      // print bfs
}