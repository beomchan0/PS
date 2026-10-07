#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,Q;
int grid[15][15];
int temp[15][15];
int visited[15][15];
int cnt_group_mi[51]; // 각 미생물별 그룹 수 기록.
int shape_mi[15][15]; // 미생물 모양.
queue<pair<int,int>> q;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cnt_mi[51]; // 각 미생물 개수.

void print_grid(){
    cout <<"================================\n";
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "================================\n";
}

bool InRange(int x, int y){
    return (x>=0&&x<n&&y>=0&&y<n);
}

bool CanGo(int nx, int ny, int mi_num){
    if(InRange(nx,ny)&&visited[nx][ny]==0&&grid[nx][ny]==mi_num){
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
        int mi_num=grid[x][y];

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(CanGo(nx,ny,mi_num)){
                Push(nx,ny);
            }
        }
    }
}

void remove_mi(int mi_num){
    // 영역이 나눠진 미생물 삭제하기.
    for(int i=1; i<=mi_num; i++){
        //그룹수 초기화.
        cnt_group_mi[i]=0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //각 미생물 별 그룹개수 파악.
            if(grid[i][j]!=0&&visited[i][j]==0){
                cnt_group_mi[grid[i][j]]++;
                Push(i,j);
                BFS();
            }
        }
    }

    for(int i=1; i<=mi_num; i++){
        if(cnt_group_mi[i]>1){
            //그룹이 두개로 나눠진 미생물 삭제.
            for(int a=0; a<n; a++){
                for(int b=0; b<n; b++){
                    if(grid[a][b]==i){
                        grid[a][b]=0;
                    }
                }
            }
        }
    }
    
}

void into_grid(int mi_num){
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    for(int i=c1; i<c2; i++){
        for(int j=r1; j<r2; j++){
            grid[i][j]=mi_num;
        }
    }

    remove_mi(mi_num);
    
}

void move_grid(int mi_num){
    //이 상태에서 grid는 각 미생물이 한개의 영역만 가지는게 보장이 됨.
    for(int i=1; i<=mi_num; i++){
        cnt_mi[i]=0; // 각 미생물 별 개수.
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]>0){
                cnt_mi[grid[i][j]]++;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j]=0;
            //temp 초기화.
        }
    }

    for(int i=0; i<mi_num; i++){
        //미생물 최대 개수만큼 이동 반복.
        int max_mi_num=1;
        for(int j=2; j<=mi_num; j++){
            if(cnt_mi[j]>cnt_mi[max_mi_num]){
                max_mi_num=j;
            }
        }

        if(cnt_mi[max_mi_num]==0){
            break;
        }
        // max_mi_num 미생물을 temp로 이동시켜야함.
        cnt_mi[max_mi_num]=0; // 일단 cnt 배열 뭐가 됐든 0으로 변경.
        int min_r,min_c,max_r,max_c; // 대상 미생물의 정보.
        for(int b=0; b<n; b++){
            int find=0;
            for(int a=0; a<n; a++){
                if(grid[a][b]==max_mi_num){
                    min_c=b;
                    find=1;
                    break;
                }
            }
            if(find==1) break;
        }
        for(int b=n-1; b>=0; b--){
            int find=0;
            for(int a=0; a<n; a++){
                if(grid[a][b]==max_mi_num){
                    max_c=b;
                    find=1;
                    break;
                }
            }
            if(find==1) break;
        }
        for(int a=0; a<n; a++){
            int find=0;
            for(int b=0; b<n; b++){
                if(grid[a][b]==max_mi_num){
                    min_r=a;
                    find=1;
                    break;
                }
            }
            if(find==1) break;
        }
        for(int a=n-1; a>=0; a--){
            int find=0;
            for(int b=0; b<n; b++){
                if(grid[a][b]==max_mi_num){
                    max_r=a;
                    find=1;
                    break;
                }
            }
            if(find==1) break;
        }
        int gap_r=max_r-min_r+1;
        int gap_c=max_c-min_c+1;

        int flag1=0;//이건 최종적으로 옮겨 지는지 여부.
        for(int s_c=0; s_c<n-gap_c+1; s_c++){
            for(int s_r=0; s_r<n-gap_r+1; s_r++){
                for(int a=0; a<n; a++){
                    for(int b=0; b<n; b++){
                        shape_mi[a][b]=0;//쉐입미 초기화
                    }
                }
                for(int a=0; a<gap_r; a++){
                    for(int b=0; b<gap_c; b++){
                        if(grid[min_r+a][min_c+b]==max_mi_num){
                            shape_mi[s_r+a][s_c+b]=max_mi_num; // 일단 쉐입 기준으로 옮겨 두기.
                        }
                    }
                }

                // 이제 이게 temp로 겹쳐지는지 확인 해주면 됨.
                int flag2=1;//이건 각 턴에서 겹쳐질 수 있는 지 확인
                for(int a=0; a<n; a++){
                    for(int b=0; b<n; b++){
                        if(shape_mi[a][b]!=0&&temp[a][b]!=0){
                            flag2=0; // 한곳이라도 안겹쳐 지면 불가능.
                        }
                    }
                }

                if(flag2==1){
                    for(int a=0; a<n; a++){
                        for(int b=0; b<n; b++){
                            if(shape_mi[a][b]!=0){
                                temp[a][b]=shape_mi[a][b];
                            }
                        }
                    }
                    flag1=1;
                    break;
                }

            }
            if(flag1==1) break;
        }

        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                if(grid[a][b]==max_mi_num){
                    grid[a][b]=0;
                }
            }
        }

    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            grid[i][j]=temp[i][j];
        }
    }

}

void cal_score(int mi_num){
    for(int i=1; i<=mi_num; i++){
        cnt_mi[i]=0; // 각 미생물 별 개수.
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]>0){
                cnt_mi[grid[i][j]]++;
            }
        }
    }

    int score=0;

    for(int i=1; i<mi_num; i++){
        for(int j=i+1; j<=mi_num; j++){
            // i미생물과 j미생물이 겹치는지 판단.
            int flag=0;
            for(int a=0; a<n; a++){
                for(int b=0; b<n; b++){
                    for(int d=0; d<2; d++){
                        int na=a+dx[d];
                        int nb=b+dy[d];
                        if(InRange(na,nb)&&((grid[a][b]==i&&grid[na][nb]==j)||(grid[a][b]==j&&grid[na][nb]==i))){
                            flag=1;
                        }
                    }
                }
            }
            if(flag==1){
                score+=cnt_mi[i]*cnt_mi[j];
            }
        }
    }
    cout << score << "\n";
}

void simulate(int mi_num){
    //mi_num : 미생물 최대 개수.
    into_grid(mi_num);
    move_grid(mi_num);
    cal_score(mi_num);
}

int main() {
    // Please write your code here.
    cin >> n >> Q;

    for(int i=1; i<=Q; i++){
        //i번째 실험이다. 즉 미생물 개수는 최대 i개.
        simulate(i);
        //print_grid();
    }
    return 0;
}