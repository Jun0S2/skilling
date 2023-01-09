#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
/**
 * Static Variables
*/
  int N,M; // 가로, 세로 크기
  vector<vector<bool>> visited(100,vector<bool>(100)); //w : true, b : false
  vector<vector<bool>> map(100,vector<bool>(100)); //w : true, b : false
  int resW{0};
  int resB{0};

  vector<int>dx = {-1,1,0,0};//상하좌우
  vector<int>dy = {0,0,-1,1};


/**
 * get N,M,map
*/
void input() {
    cin>>N>>M;
    char temp{'a'};
    for(int i = 0 ; i<N ; i ++){
        for(int j = 0 ; j<M ; j++ ){
            cin>>temp;
            map[i][j] = temp == 'W' ? true : false;
        }
    }
}

/**
 * print map
*/
void LOGD() {
    for(int i = 0 ; i<N ; i ++) {
        for (int j = 0 ; j < M ;j++ ) {
            cout<<map[i][j];
        }
        cout<<endl;
    }
}

void dfs( int i, int j, int *cnt){
    (*cnt)++; //연속된 수 증간 . cnt++했다가 0나옴
    visited[i][j] = true; //방문 처리

    // 사방탐색
    for(int d = 0 ; d<4 ; d++){
        int nx = i + dx[d];
        int ny = j + dy[d];
        if(nx<0||ny<0||nx>=N||ny>=M) continue; //범위 out
        if (visited[nx][ny]) continue; // 이미 방문한 경우
        if (map[nx][ny] != map[i][j]) continue; //같은 색이 아님
        //else
        dfs(nx,ny,cnt);
    }
}

void simulation(){
    for(int i = 0 ; i<N ; i++ ){
        for(int j  = 0 ; j<M ;j ++) {
            int cnt = 0; // 계속 초기화해야함으로 변수로 사용
            if(!visited[i][j]){// 방문 x
                dfs(i,j,&cnt);
                // cout<<cnt<<endl;
                if(map[i][j]) resW += (cnt*cnt);
                else resB += (cnt*cnt);
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // N명이 뭉쳐있으면, N2의 힘을 낼 수 있음
    // 대각선으로만 인접한 경우는 뭉쳐있지 않다.

    input();
   // LOGD();    
    simulation();
    cout<<resW<<" "<<resB<<endl;

    return 0;
}