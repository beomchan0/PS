#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int grid[30][30]; // -1 : 물건 칸(이동 X), 0 : 먼지 없는 칸, 양수 : 각 칸의 먼지.
int n,k,l; // n : 격자 크기, k : 로봇 수, l 반복 수.
int robot[30][30];
int r[51]; // 각 로봇 행
int c[51]; // 각 로봇 열 
int temp[30][30];
int dx[4]={0,1,0,-1}; //오 아 왼 위
int dy[4]={1,0,-1,0};
int visited[30][30];
int dist[30][30];
queue<pair<int,int>> q;

bool InRange(int x, int y){
    return (x>=0&&x<n&&y>=0&&y<n);
}

void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j]=0;
            dist[i][j]=1000; // 거리의 최대가 900 이므로 초기 거리는 충분히 크게 설정.
        }
    }

    while(!q.empty()){
        q.pop();
    }
}

bool CanGo(int nx, int ny){
    if(InRange(nx,ny)&&visited[nx][ny]==0&&grid[nx][ny]!=-1&&robot[nx][ny]==0){
        return true;
    }

    return false;
}

void Push(int x, int y){
    visited[x][y]=1;
    q.push(make_pair(x,y));
}

void BFS(){
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();

        int x=cur.first;
        int y=cur.second;
        int cur_dist=dist[x][y];

        if(grid[x][y]>0){
            //최소 거리만 의미 있기 때문에 먼지가 발견 되면 탐색 종료해도 됨. 
            break;
        }

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(CanGo(nx,ny)){
                Push(nx,ny);
                dist[nx][ny]=cur_dist+1;
            }
        }

    }
}
void move(){
    for(int i=1; i<=k; i++){
        //현재 i번 청소기가 이동 한다.
        //1.가장 가까운 오염된 격자 찾기.
        init();
        dist[r[i]][c[i]]=0;
        Push(r[i],c[i]);
        BFS();

        int min=1000;

        //2.로봇 이동 시키기.
        for(int j=0; j<n; j++){
            for(int h=0; h<n; h++){
                if(grid[j][h]>0&&dist[j][h]<min){
                    min=dist[j][h];
                    robot[r[i]][c[i]]=0;
                    r[i]=j;
                    c[i]=h;
                    robot[r[i]][c[i]]=1;
                }
            }
        }

    }
}

void clean(){
    for(int i=1; i<=k; i++){
        //i번 로봇 청소.
        int max_sum=0;
        int max_d=0;// 방향.
        int x=r[i];
        int y=c[i];

        for(int j=0; j<4; j++){
            int sum=0;
            if(InRange(x,y)&&grid[x][y]>0){
                sum+=min(grid[x][y],20);
            }
            if(InRange(x+dx[j],y+dy[j])&&grid[x+dx[j]][y+dy[j]]>0){
                sum+=min(grid[x+dx[j]][y+dy[j]],20);
            }
            if(InRange(x+dx[(j+1)%4],y+dy[(j+1)%4])&&grid[x+dx[(j+1)%4]][y+dy[(j+1)%4]]>0){
                sum+=min(grid[x+dx[(j+1)%4]][y+dy[(j+1)%4]],20);
            }
            if(InRange(x+dx[(j+3)%4],y+dy[(j+3)%4])&&grid[x+dx[(j+3)%4]][y+dy[(j+3)%4]]>0){
                sum+=min(grid[x+dx[(j+3)%4]][y+dy[(j+3)%4]],20);
            }
            if(sum>max_sum){
                max_sum=sum;
                max_d=j;
            }
        }
        if(InRange(x,y)&&grid[x][y]>0){
            grid[x][y]=max(0,grid[x][y]-20);
        }
        if(InRange(x+dx[max_d],y+dy[max_d])&&grid[x+dx[max_d]][y+dy[max_d]]>0){
            grid[x+dx[max_d]][y+dy[max_d]]=max(0,grid[x+dx[max_d]][y+dy[max_d]]-20);
        }
        if(InRange(x+dx[(max_d+1)%4],y+dy[(max_d+1)%4])&&grid[x+dx[(max_d+1)%4]][y+dy[(max_d+1)%4]]>0){
            grid[x+dx[(max_d+1)%4]][y+dy[(max_d+1)%4]]=max(0,grid[x+dx[(max_d+1)%4]][y+dy[(max_d+1)%4]]-20);
        }
        if(InRange(x+dx[(max_d+3)%4],y+dy[(max_d+3)%4])&&grid[x+dx[(max_d+3)%4]][y+dy[(max_d+3)%4]]>0){
            grid[x+dx[(max_d+3)%4]][y+dy[(max_d+3)%4]]=max(0,grid[x+dx[(max_d+3)%4]][y+dy[(max_d+3)%4]]-20);
        }

    }
}

void plus_p(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]>0){
                grid[i][j]+=5;
            }
        }
    }
}

void move_p(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==0){
                for(int h=0; h<4; h++){
                    int nx=i+dx[h];
                    int ny=j+dy[h];
                    if(InRange(nx,ny)&&grid[nx][ny]>0){
                        temp[i][j]+=grid[nx][ny];
                    }
                }
                temp[i][j]/=10;
            }else{
                temp[i][j]=grid[i][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            grid[i][j]=temp[i][j];
            temp[i][j]=0;
            //temp 초기화도 동시에 진행.
        }
    }
}

void simulate(){
    move();
    clean();
    plus_p();
    move_p();
}

int count_p(){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]>0){
                cnt+=grid[i][j];
            }
        }
    }
    return cnt;
}

int main() {
    // Please write your code here.
    cin >> n >> k >> l;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }

    for(int i=1; i<=k; i++){
        cin >> r[i] >> c[i]; // 이거 각각 -1 해줘야 함.
        r[i]--;
        c[i]--;
        robot[r[i]][c[i]]=i; //로봇은 각 번호 1~k를 가짐.
    }

    for(int i=0; i<l; i++){
        simulate();
        int ans=count_p();
        cout << ans << "\n";
        if(ans==0) break;
    }

    return 0;
}