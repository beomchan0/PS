#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
int sr,sc,er,ec;
int grid[50][50];
int monster_sight[50][50];
int cnt_man[50][50];
struct man{
    int num;
    int r,c;
    int able_move;
    int live;
};
int man_dist, rock_man, attack_man;
int visited[50][50];
int dist1[50][50];//메두사가 경로 찾기 위해 사용
int dist2[50][50];//전사가 메두사 찾기위해 사용.
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
queue<pair<int,int>> q;
man mans[301];
int temp1[50][50];
int temp2[50][50];

void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j]=0;
        }
    }

    while(!q.empty()){
        q.pop();
    }
}

bool InRange(int x, int y){
    return (x>=0&&x<n&&y>=0&&y<n);
}

bool CanGo1(int nx, int ny){
    if(InRange(nx,ny)&&visited[nx][ny]==0&&grid[nx][ny]==0){
        return true;
    }
    return false;
}

bool CanGo3(int nx, int ny){
    if(InRange(nx,ny)&&visited[nx][ny]==0){
        return true;
    }
    return false;
}

void Push(int x, int y){
    visited[x][y]=1;
    q.push(make_pair(x,y));
}

void BFS1(){
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        int x=cur.first;
        int y=cur.second;

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(CanGo1(nx,ny)){
                Push(nx,ny);
            }
        }
    }
}

void BFS2(){
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        int x=cur.first;
        int y=cur.second;
        int cur_dist=dist1[x][y];
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(CanGo1(nx,ny)){
                Push(nx,ny);
                dist1[nx][ny]=cur_dist+1;
            }
        }
    }
}

void BFS3(){
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        int x=cur.first;
        int y=cur.second;
        int cur_dist=dist2[x][y];
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(CanGo3(nx,ny)){
                Push(nx,ny);
                dist2[nx][ny]=cur_dist+1;
            }
        }
    }
}

bool Can_park(){
    init();
    Push(sr,sc);
    BFS1();
    if(visited[er][ec]==1){
        return true;
    }else{
        return false;
    }
}

void find_dist1(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dist1[i][j]=10000;
        }
    }

    init();
    dist1[er][ec]=0;
    Push(er,ec);
    BFS2();
}

void make_cnt_man(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cnt_man[i][j]=0;
        }
    }
    for(int i=1; i<=m; i++){
        if(mans[i].live==1){
            cnt_man[mans[i].r][mans[i].c]+=1;
        }
    }
}

void monster_move(){
    //읻단 우선 순위대로 이동.
    for(int i=0; i<4; i++){
        int nx=sr+dx[i];
        int ny=sc+dy[i];
        if(InRange(nx,ny)&&dist1[sr][sc]-1==dist1[nx][ny]){
            sr=nx;
            sc=ny;
            break;
        }
    }
    //전사 있을시 전사 사라짐.
    for(int i=1; i<=m; i++){
        if(mans[i].r==sr&&mans[i].c==sc){
            mans[i].live=0;
        }
    }
    cnt_man[sr][sc]=0;
}

void turn_right(){
    //temp1을 시계 방향으로 90돌림.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp2[i][j]=temp1[n-1-j][i];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp1[i][j]=temp2[i][j];
        }
    }
}

void turn_sight(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp2[i][j]=monster_sight[n-1-j][i];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            monster_sight[i][j]=temp2[i][j];
        }
    }
}

int cal_sight(int d){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            monster_sight[i][j]=0;
            temp1[i][j]=cnt_man[i][j];
        }
    }


    int turn_num[4]={2,0,3,1};//아래 기준으로 다 돌려 줌.
    int temp1_r=sr;
    int temp1_c=sc;
    int temp2_r,temp2_c;
    for(int i=0; i<turn_num[d]; i++){
        turn_right();
        temp2_r=temp1_c;
        temp2_c=n-1-temp1_r;
        temp1_r=temp2_r;
        temp1_c=temp2_c;
    }

    //이제 temp1, temp1_r, temp1_c기준 아래 방향만 생각 하면됨.
    int ans=0;
    for(int i=temp1_r+1; i<n; i++){
        monster_sight[i][temp1_c]=1;
        if(temp1[i][temp1_c]>0){
            ans+=temp1[i][temp1_c];
            break;
        }
    }

    int no_see[50][50];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            no_see[i][j]=0;
        }
    }

    for(int j=temp1_c-1; j>=0; j--){
        for(int i=temp1_r+(temp1_c-j); i<n; i++){
            monster_sight[i][j]=1;
            if(temp1[i][j]>0&&no_see[i][j]==0){
                ans+=temp1[i][j];
                for(int b=j-1; b>=0; b--){
                    for(int a=i+(j-b); a<n; a++){
                        no_see[a][b]=1;
                    }
                }
                break;
            }
        }
    }
    for(int j=temp1_c+1; j<n; j++){
        for(int i=temp1_r+(j-temp1_c); i<n; i++){
            monster_sight[i][j]=1;
            if(temp1[i][j]>0&&no_see[i][j]==0){
                ans+=temp1[i][j];
                for(int b=j+1; b<n; b++){
                    for(int a=i+(b-j); a<n; a++){
                        no_see[a][b]=1;
                    }
                }
                break;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(no_see[i][j]==1&&monster_sight[i][j]==1){
                monster_sight[i][j]=0;
            }
        }
    }

    for(int i=0; i<4-turn_num[d]; i++){
        turn_sight();
    }

    return ans;

}

void monster_see(){
    int max_d=0;
    int max_num=0;
    for(int i=0; i<4; i++){
        //4방향에 대해서 시선 구함.
        //그냥 아래로 cnt_man을 돌리자 temp로 복사해서 돌리기.
        int cur_num=0;
        cur_num=cal_sight(i);
        if(cur_num>max_num){
            max_num=cur_num;
            max_d=i;
        }
    }
    //cout << max_d << " " << max_num << "\n";
    rock_man=cal_sight(max_d); //monster_sight배열도 현재 완성 완료.

    for(int i=1; i<=m; i++){
        if(mans[i].live==1&&monster_sight[mans[i].r][mans[i].c]==1){
            mans[i].able_move=0;
        }
    }

}

void man_move(){
    //마지막엔 모두 이동가능 상태로 만들어 줘야함.
    /*
    cout << "=====================\n";
    for(int i=0; i<n ; i++){
        for(int j=0; j<n; j++){
            cout << monster_sight[i][j] << " "; 
        }
        cout << "\n";
    }
    cout << "=====================\n";
    */
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dist2[i][j]=10000;
        }
    }
    init();
    dist2[sr][sc]=0;
    Push(sr,sc);
    BFS3();
    for(int i=1; i<=m; i++){
        if(mans[i].live==0||mans[i].able_move==0){
            continue;
        }
        int x=mans[i].r;
        int y=mans[i].c;
        for(int d=0; d<4; d++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(InRange(nx,ny)&&monster_sight[nx][ny]==0&&(dist2[x][y]>dist2[nx][ny])){
                man_dist++;
                cnt_man[x][y]--;
                cnt_man[nx][ny]++;
                x=nx;
                y=ny;
                break;
            }
        }

        int dx2[4]={0,0,-1,1};
        int dy2[4]={-1,1,0,0};
        for(int d=0; d<4; d++){
            int nx=x+dx2[d];
            int ny=y+dy2[d];
            if(InRange(nx,ny)&&monster_sight[nx][ny]==0&&(dist2[x][y]>dist2[nx][ny])){
                man_dist++;
                cnt_man[x][y]--;
                cnt_man[nx][ny]++;
                x=nx;
                y=ny;
                break;
            }
        }
        mans[i].r=x;
        mans[i].c=y;
    }

    
    for(int i=1; i<=m; i++){
        if(mans[i].live==1){
            mans[i].able_move=1;
        }
    }
}

void man_attack(){
    cnt_man[sr][sc]=0;
    for(int i=1; i<=m; i++){
        if(mans[i].live==1){
            if(mans[i].r==sr&&mans[i].c==sc){
                //cout << i << "\n";
                attack_man++;
                mans[i].live=0;
            }
        }
    }
}

void print_info(){
    if(sr==er&&sc==ec){
        cout << 0 << "\n";
    }else{
        cout << man_dist << " " <<  rock_man << " "  << attack_man << "\n";
    }
}

void simulate(){
    man_dist=0, rock_man=0, attack_man=0;
    monster_move();
    //cout<< sr << " " << sc << "\n";
    monster_see();
    man_move();
    man_attack();
    print_info();
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    cin >> sr >> sc >> er >> ec;
    for(int i=1; i<=m; i++){
        int mr,mc;
        cin >> mr >> mc;
        mans[i]={i,mr,mc,1,1};
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    if(Can_park()){
        find_dist1();
        int max_turn=dist1[sr][sc];
        make_cnt_man();
        for(int i=0; i<max_turn; i++){
            simulate();
        }
        
    }else{
        cout << -1 << "\n";
    }
    return 0;
}