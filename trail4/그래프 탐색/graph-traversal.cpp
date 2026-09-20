#include <iostream>

using namespace std;

int n, m;
int from[10000], to[10000];
int graph[1001][1001];
int visited[1001];

int cnt=0;

void DFS(int vertex){
    visited[vertex]=1;

    for(int i=1; i<=n; i++){
        if(visited[i]!=1 && graph[vertex][i]==1){
            //방문이 아니고 현재 정점과 연결되었을 경우에 탐색
            visited[i]=1;
            cnt++;
            DFS(i);
        }
    }
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
        graph[from[i]][to[i]]=1;
        graph[to[i]][from[i]]=1;
    }

    DFS(1);

    cout << cnt;
    // Please write your code here.

    return 0;
}
