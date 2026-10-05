#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m,k;

int grid[20][20]; // 산호 : 11, 거북이(1번~m번) : 각 번호
int hot[20][20];
int erupt_vol[10];
int visited[20][20];
int dist[20][20];
queue<pair<int,int>> q;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

class volcano{
    public:
        int max_p;
        int cur_p;
        int r,c;
        
        volcano(int max_p, int r, int c, int cur_p){
            this->max_p=max_p;
            this->r=r;
            this->c=c;
            this->cur_p=cur_p;
        }

        volcano(){}
};

class turtle{
    public:
        int num;
        int r;
        int c;
        int live; //  -1: 도착 못함(기본값), 도착하게 되면 현재 턴의 값을 가짐., 화석이 되면 -2라고 하자.

        turtle(int num, int r, int c, int live){
            this->num=num;
            this->r=r;
            this->c=c;
            this->live=live;
        }

        turtle(){}
};

volcano volcanos[10];
turtle turtles[11];

void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j]=0;
            dist[i][j]=1000; //400이 최대니까 초기화는 모두 무한대로 초기화
        }
    }
}

bool InRange(int x, int y){
    return (x>=0&&x<n&&y>=0&&y<n);
}

bool CanGo(int nx, int ny, int turtle_num){
    if(InRange(nx,ny)&&visited[nx][ny]==0&&(grid[nx][ny]==0||grid[nx][ny]==turtle_num)){
        return true;
    }

    return false;
}

void Push(int nx, int ny){
    visited[nx][ny]=1;
    q.push(make_pair(nx,ny));
}

void BFS(int turtle_num){
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();

        int x=cur.first;
        int y=cur.second;
        int cur_dist=dist[x][y];

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(CanGo(nx,ny,turtle_num)){
                dist[nx][ny]=cur_dist+1;
                Push(nx,ny);
            }
        }

    }
}

void move(int t){
    //t 턴째의 이동.
    //거북이 번호 1~m번까지 모두 이동 하셔야함.
    //이동은 번호 순으로 순차적으로 일어남.

    for(int i=1; i<=m; i++){
        if(turtles[i].live!=-1){
            continue; // 화석이 되거나 도착하면 이동 X, 다음 거북이로 넘기기
        }
        init();
        dist[n-1][n-1]=0;
        Push(n-1,n-1);
        BFS(i);

        for(int j=0; j<4; j++){
            int nx=turtles[i].r+dx[j];
            int ny=turtles[i].c+dy[j];

            if(InRange(nx,ny)&&dist[nx][ny]==dist[turtles[i].r][turtles[i].c]-1){
                grid[turtles[i].r][turtles[i].c]=0;

                turtles[i].r=nx;
                turtles[i].c=ny;
                //cout << nx << " " << ny << "\n";
                grid[turtles[i].r][turtles[i].c]=i;
                break;
            }
        }
        if(turtles[i].r==n-1&&turtles[i].c==n-1){
            grid[n-1][n-1]=0;
            turtles[i].live=t;
        }
    }
}

void charge(){
    for(int i=0; i<k; i++){
        volcanos[i].cur_p+=10;
    }
}

int cnt_erupt(){
    int ans=0;
    for(int i=0; i<k; i++){
        if(erupt_vol[i]==1) ans++;
    }

    return ans;
}

void eruption(){

    int cnt=0;
    //일단 처음엔 화산 조건만.
    for(int i=0; i<k; i++){
        if(volcanos[i].cur_p >= volcanos[i].max_p){
            erupt_vol[i]=1;
            int h=volcanos[i].max_p;
            int x=volcanos[i].r;
            int y=volcanos[i].c; 
            hot[x][y]+=h;      
            for(int j=0; j<4; j++){
                int nx=x+dx[j];
                int ny=y+dy[j];
                int uh=h/2;//전달 되는 열기.
                while(uh>0&&InRange(nx,ny)&&grid[nx][ny]!=11){
                    hot[nx][ny]+=uh;
                    uh/=2;
                    nx+=dx[j];
                    ny+=dy[j];
                }
            }
        }
    }


    while(cnt!=cnt_erupt()){
        cnt=cnt_erupt();
        for(int i=0; i<k; i++){
            if(erupt_vol[i]==0&&hot[volcanos[i].r][volcanos[i].c]+volcanos[i].cur_p >= volcanos[i].max_p){
                //아직 터지지 않았다면 분출;
                erupt_vol[i]=1;
                int h=volcanos[i].max_p;
                int x=volcanos[i].r;
                int y=volcanos[i].c; 
                hot[x][y]+=h;      
                for(int j=0; j<4; j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    int uh=h/2;//전달 되는 열기.
                    while(uh>0&&InRange(nx,ny)&&grid[nx][ny]!=11){
                        hot[nx][ny]+=uh;
                        uh/=2;
                        nx+=dx[j];
                        ny+=dy[j];
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]!=0&&hot[i][j]>=20){
                int num=grid[i][j];
                turtles[num].live=-2;
            }
        }
    }
}

void reset(){
    //열기 정보 없애기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            hot[i][j]=0;
        }
    }

    // 분출 여부 조사해서 분출 했던 화산은 현재 압력 0으로 초기화.
    for(int i=0; i<k; i++){
        if(erupt_vol[i]==1){
            volcanos[i].cur_p=0;
            erupt_vol[i]=0;
        }
    }
}

void simulate(int t){
    move(t);
    charge();
    eruption();
    reset();
}

int main() {
    // Please write your code here.

    cin >> n >> m >> k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a;
            cin >> a;
            grid[i][j]=a*11;
        }
    }

    for(int i=1; i<=m; i++){
        int r,c;
        cin >> r >> c;
        turtles[i]=turtle(i,r,c,-1);
        grid[r][c]=i;
    }

    for(int i=0; i<k; i++){
        int r,c,p;
        cin >> r >> c >> p;
        volcanos[i]=volcano(p,r,c,0);
    }

    for(int i=1; i<=100; i++){
        simulate(i);
    }

    for(int i=1; i<=m; i++){
        if(turtles[i].live==-2){
            cout << -1 << "\n";
        }else{
            cout << turtles[i].live << "\n";
        }
    }


    return 0;
}