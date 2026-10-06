#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int grid[51][51];
int temp1[51];
int temp2[51];
struct box{
    int num;
    int c;
    int w;
    int h;
    int live;
};

box boxs[101]; // 택배는 최대 100개까지 가능함.
box boxs2[101];

void out_box(int num){
    boxs2[num].live=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i][j]==num){
                grid[i][j]=0;
            }
        }
    }
}

void drop(){
    //현재 격자에서 중력 적용.
    
    for(int i=n-1; i>=1; i--){
        // i행    temp1[]
        // i+1행  temp2[]
        // 두 행에 대해서 아래에서 위로 진행.
        for(int j=1; j<=n; j++){
            temp1[j]=0;
            temp2[j]=0;
        }
        int idx=1;
        while(idx<=n){
            //1열부터 n열까지 탐색
            if(grid[i][idx]!=0){
                //값이 있다면 중력을 받아 떨어질 수 있음.
                int flag=1;
                int num=grid[i][idx];
                for(int j=idx; j<idx+boxs2[num].w; j++){
                    if(grid[i+1][j]!=0){
                        flag=0;
                        break;
                    }
                }
                if(flag==1){
                    for(int j=idx; j<idx+boxs2[num].w; j++){
                        temp1[j]=0;
                        temp2[j]=grid[i][j];
                    }
                    idx=idx+boxs2[num].w;
                }else if(flag==0){
                    for(int j=idx; j<idx+boxs2[num].w; j++){
                        temp1[j]=grid[i][j];
                        temp2[j]=grid[i+1][j];
                    }
                    idx=idx+boxs2[num].w;
                }
            }else{
                temp1[idx]=grid[i][idx];
                temp2[idx]=grid[i+1][idx];
                idx++;
            }
        }

        for(int j=1; j<=n; j++){
            grid[i][j]=temp1[j];
            grid[i+1][j]=temp2[j];
        }
    }
}

void plus_box(){
    // 일단 boxs[1] ~ boxs[m] 까지 진행 해야함.
    for(int i=1; i<=m; i++){
        for(int a=1; a<=boxs[i].h; a++){
            for(int b=boxs[i].c; b<boxs[i].c+boxs[i].w; b++){
                //모든 박스가 들어갈 수 있음이 보장되기 때문에 모든 박스가 최소 이 위치까지 올 수 있음이 보장됨.
                grid[a][b]=boxs[i].num; // grid 는 빈공간은 0, 각 박스가 있는곳은 그 박스의 번호로 기록
            }
        }

        for(int a=0; a<n; a++){
            drop();//중력 적용.
        }

    }

    /*
    cout << "======================\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "======================\n";
    */
}

int select_left(){
    int num=101;
    int i=1;
    while(i<=n){
        int flag2=0;
        for(int j=1; j<=n; j++){
            if(grid[i][j]!=0){
                int cur_num=grid[i][j];
                if(cur_num>num){
                    break;
                }
                int flag=1;
                for(int a=i; a<i+boxs2[cur_num].h; a++){
                    int sum=0;
                    for(int b=1; b<j; b++){
                        sum+=grid[a][b];
                    }
                    if(sum!=0){
                        flag=0;
                        flag2=1;
                        i=a;
                        break;
                    }
                }
                if(flag==1){
                    if(cur_num<num){
                        num=cur_num;
                        flag2=1;
                        i+=boxs2[cur_num].h;
                    }
                }
                break;
            }
        }
        if(flag2==0){
            i++;
        }
    }
    return num;
}

int select_right(){
    int num=101;
    int i=1;
    while(i<=n){
        int flag2=0;
        for(int j=n; j>=1; j--){
            if(grid[i][j]!=0){
                int cur_num=grid[i][j];
                if(cur_num>num){
                    break;
                }
                int flag=1;
                for(int a=i; a<i+boxs2[cur_num].h; a++){
                    int sum=0;
                    for(int b=n; b>j; b--){
                        sum+=grid[a][b];
                    }
                    if(sum!=0){
                        flag=0;
                        flag2=1;
                        i=a;
                        break;
                    }
                }
                if(flag==1){
                    if(cur_num<num){
                        num=cur_num;
                        flag2=1;
                        i+=boxs2[cur_num].h;
                    }
                }
                break;
            }
        }
        if(flag2==0){
            i++;
        }
    }
    return num;
}

void out_left(){
    int num=select_left();
    cout << num << "\n";
    out_box(num);
    for(int i=0; i<n; i++){
        drop();
    }
}

void out_right(){
    int num=select_right();
    cout << num << "\n";
    out_box(num);
    for(int i=0; i<n; i++){
        drop();
    }
}

int main() {
    // Please write your code here.
    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int k,w,h,c;
        cin >> k >> h >> w >> c;
        boxs[i]={k,c,w,h,1}; //순서 보존
        boxs2[k]={k,c,w,h,1}; //인덱스랑 박스 번호 같음.
    }

    plus_box(); //1.택배 투입

    for(int i=0; i<m; i++){
        //택배 개수만큼 반복될것
        if(i%2==0){
            out_left(); //2.택배 하차 왼쪽
        }else{
            out_right(); //3.택배 하차 오른쪽
        }
        /*
        cout << "======================\n";
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "======================\n";
        */
    }
    return 0;
}