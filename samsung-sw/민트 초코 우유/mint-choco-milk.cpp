#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int n,T;
int grid[50][50]; // 신앙심 저장
int t[50][50]; //민트
int c[50][50]; //초코
int m[50][50]; //우유
int visited[50][50];
queue<pair<int,int>> q;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
pair<int,int> leader[2501];
int cnt_g;
int able_move[50][50];

void print_grid(){
    cout << "================================\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "================================\n";
}

void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j]=0;
        }
    }
}

void breakfast(){
    //모두 신앙심이 오름.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            grid[i][j]++;
        }
    }
}

bool InRange(int x, int y){
    return (x>=0&&x<n&&y>=0&&y<n);
}

bool CanGo(int nx, int ny, int cur_t, int cur_c, int cur_m){
    if(InRange(nx,ny)&&visited[nx][ny]==0&&t[nx][ny]==cur_t&&c[nx][ny]==cur_c&&m[nx][ny]==cur_m){
        return true;
    }
    return false;
}

void Push(int x, int y,int group_num){
    visited[x][y]=group_num;
    q.push(make_pair(x,y));
}

void BFS(int group_num){
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        int x=cur.first;
        int y=cur.second;
        int cur_t=t[x][y];
        int cur_c=c[x][y];
        int cur_m=m[x][y];
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(CanGo(nx,ny,cur_t,cur_c,cur_m)){
                Push(nx,ny,group_num);
            }
        }
    }
}

void lunch(){
    //그룹 만들기
    init();
    int group_num=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]==0){
                Push(i,j,group_num);
                BFS(group_num);
                group_num++;
            }
        }
    }
    cnt_g=group_num-1; // 총 그룹 개수 cnt_g;

    //대표자 정하기
    for(int i=1; i<=cnt_g; i++){
        leader[i].first=0;
        leader[i].second=0;
    }
    for(int i=1; i<=cnt_g; i++){
        int max=0;
        
        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                if(visited[a][b]==i&&grid[a][b]>max){
                    max=grid[a][b];
                    leader[i].first=a;
                    leader[i].second=b;
                }
            }
        }

    }

    //대표자에게 그룹원들이 신앙심 전달.
    for(int i=1; i<=cnt_g; i++){
        int cnt_mem=0;
        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                if(visited[a][b]==i){
                    grid[a][b]-=1;
                    cnt_mem++;
                }
            }
        }
        grid[leader[i].first][leader[i].second]+=cnt_mem;
    }
}

bool cmp(pair<int,int> a, pair<int,int> b){
    int sum_a=0;
    int sum_b=0;
    sum_a=t[a.first][a.second]+c[a.first][a.second]+m[a.first][a.second];
    sum_b=t[b.first][b.second]+c[b.first][b.second]+m[b.first][b.second];
    if(sum_a==sum_b){
        if(grid[a.first][a.second]==grid[b.first][b.second]){
            if(a.first==b.first){
                return a.second<b.second;
            }else{
                return a.first<b.first;
            }
        }else{
            return grid[a.first][a.second]>grid[b.first][b.second];
        }
    }else{
        return sum_a < sum_b;
    }
}

void dinner(){
    //전파 가능한지를 알아야함.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            able_move[i][j]=1;//일단 기본적으로 모두 전파 가능한 상태.
        }
    }

    //일단 리더를 정렬.
    sort(leader+1, leader+cnt_g+1, cmp);

    for(int i=1; i<=cnt_g; i++){
        //cout << leader[i].first << " " << leader[i].second << "\n";
        int cur_r=leader[i].first;
        int cur_c=leader[i].second;
        if(able_move[cur_r][cur_c]==0){
            //전파 불가능 상태면 다음 리더로 턴 넘어감.
            continue;
        }
        int d=grid[cur_r][cur_c]%4;
        int want=grid[cur_r][cur_c]-1;
        grid[cur_r][cur_c]=1;
        int x=cur_r;
        int y=cur_c;
        while(true){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(!InRange(nx,ny)||want==0){
                break;
            }
            if(t[cur_r][cur_c]==t[nx][ny]&&c[cur_r][cur_c]==c[nx][ny]&&m[cur_r][cur_c]==m[nx][ny]){
                x=nx;
                y=ny;
            }else{
                if(want>grid[nx][ny]){
                    //강한 전파
                    t[nx][ny]=t[cur_r][cur_c];
                    c[nx][ny]=c[cur_r][cur_c];
                    m[nx][ny]=m[cur_r][cur_c];
                    want-=(grid[nx][ny]+1);
                    grid[nx][ny]+=1;
                    able_move[nx][ny]=0;
                    x=nx;
                    y=ny;
                }else{
                    //약한 전파.
                    t[nx][ny]=max(t[nx][ny],t[cur_r][cur_c]);
                    c[nx][ny]=max(c[nx][ny],c[cur_r][cur_c]);
                    m[nx][ny]=max(m[nx][ny],m[cur_r][cur_c]);
                    grid[nx][ny]+=want;
                    want=0;
                    able_move[nx][ny]=0;
                    break;
                }
            }
        }
    }

}

void print_B(){
    int sum_tcm=0;
    int sum_tc=0;
    int sum_tm=0;
    int sum_cm=0;
    int sum_t=0;
    int sum_c=0;
    int sum_m=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(t[i][j]==1&&c[i][j]==1&&m[i][j]==1){
                sum_tcm+=grid[i][j];
            }else if(t[i][j]==1&&c[i][j]==1&&m[i][j]==0){
                sum_tc+=grid[i][j];
            }else if(t[i][j]==1&&c[i][j]==0&&m[i][j]==1){
                sum_tm+=grid[i][j];
            }else if(t[i][j]==0&&c[i][j]==1&&m[i][j]==1){
                sum_cm+=grid[i][j];
            }else if(t[i][j]==1&&c[i][j]==0&&m[i][j]==0){
                sum_t+=grid[i][j];
            }else if(t[i][j]==0&&c[i][j]==1&&m[i][j]==0){
                sum_c+=grid[i][j];
            }else if(t[i][j]==0&&c[i][j]==0&&m[i][j]==1){
                sum_m+=grid[i][j];
            }
        }
    }
    cout << sum_tcm << " " << sum_tc << " " << sum_tm << " " << sum_cm << " " << sum_m << " " << sum_c << " " << sum_t << "\n";
}

void simulate(){
    breakfast();
    lunch();
    dinner();
    print_B();
    
}

int main() {
    // Please write your code here.
    cin >> n >> T;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<n; j++){
            if(str[j]=='T'){
                t[i][j]=1;
            }else if(str[j]=='C'){
                c[i][j]=1;
            }else if(str[j]=='M'){
                m[i][j]=1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    //print_grid();
    for(int i=0; i<T; i++){
        simulate();
        //print_grid();
    }
    return 0;
}