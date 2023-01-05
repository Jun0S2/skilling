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
vector<vector<bool>> map (1001, vector<bool> (10001)); // init vector with maximum size

/**
 * 디버그용 로그
 * Print Map
*/
void LOGD() {
    // for (const auto &row : map) {
    //     for (const auto &s : row ) {
    //         cout << s << ' ';
    //     }
    //     cout<<endl;
    // }
    for (int row = 1 ; row <= N ; row ++ ) {
        for (int col = 1 ; col <=M ; col++ ) {
            cout<<map[row][col]<<" ";
        }
        cout<<endl;
    }
}

/**
 * Get Input from user
 * Add try-catch to avoid vector[outofarraybound]
*/
void Input() {
    cin>>N>>M>>V;
    int temp1{0}, temp2{0}; 
    for(auto i  = 0 ; i < M ; i++) {
        cin>>temp1>>temp2;
        try {
            map[temp1][temp2] = map[temp2][temp1] = true;
        } catch(const std::exception& e) {
            cerr << "Input number is out of range" << e.what() << '\n';
        }
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
 * BFS Uses Queue and visited vector
 * visited - size : N + 1 ,  정점을 visit 했는지 알아본다.
 * visited = true, q.push, logI가 반복적으로 사용되서 람다 function으로
 * 뺄 수 있겠다고 생각함.
*/
void BFS() {
    queue<int> q ;
    vector<bool> visited (N+1); 

    // Use Macro
    auto macro = [&visited, &q](int node){
        visited[node] = true; // 방문처리
        q.push(node);         // 다음 방문할 정점 리스트에 추가
        LOGI(node);           // 출력
    };

    macro(V); // first visited node(given via input)

    while(!q.empty()){ // when q is empty, it means its done with traverse
        int current_node = q.front(); // current node
        q.pop();
        

        for(int i = 1 ; i<= N ; i++ ){
            if (visited[i]) continue;                 //이미 방문함
            else if (!map[current_node][i]) continue; // 연결 X
            else macro(i);                            // 서로 접해있음 -> 마크로처리 ㄱㄱ
        }
    }
}

void Simulation() {
    Input();
    // LOGD();
    BFS();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Simulation();
}