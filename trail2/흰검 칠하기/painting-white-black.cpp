#include <iostream>

using namespace std;

#define offset 100000

int n;
int x[1000];
char dir[1000];

char arr[200001];
int whiteCnt[200001];
int blackCnt[200001];

int main() {
    cin >> n;

    int cur = 0;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];

        int next;

        if(dir[i] == 'L') {
            next = cur - (x[i] - 1);

            for(int j = next; j <= cur; j++) {
                arr[j + offset] = 'W';
                whiteCnt[j + offset]++;
            }
        }
        else {
            next = cur + (x[i] - 1);

            for(int j = cur; j <= next; j++) {
                arr[j + offset] = 'B';
                blackCnt[j + offset]++;
            }
        }

        cur = next;
    }

    int w = 0;
    int b = 0;
    int g = 0;

    for(int i = 0; i < 200001; i++) {

        if(whiteCnt[i] >= 2 && blackCnt[i] >= 2) {
            g++;
        }
        else if(arr[i] == 'W') {
            w++;
        }
        else if(arr[i] == 'B') {
            b++;
        }
    }

    cout << w << " " << b << " " << g;

    return 0;
}