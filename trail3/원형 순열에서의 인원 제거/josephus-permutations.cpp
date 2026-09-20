#include <iostream>
#include <queue>

using namespace std;

int N, K;

int main() {
    cin >> N >> K;

    queue<int> q;
    int arr[5000];

    for(int i=0; i<N; i++){
        q.push(i);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<K-1; j++){
            q.push(q.front());
            q.pop();
        }
        arr[i]=q.front();
        q.pop();
    }

    for(int i=0; i<N; i++){
        cout << arr[i]+1 <<" ";
    }

    // Please write your code here.

    return 0;
}
