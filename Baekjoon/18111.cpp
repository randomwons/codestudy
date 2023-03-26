#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M, B;
    scanf("%d %d %d", &N, &M, &B);

    vector<int> count(257);
    int v;
    int min = 256, max = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &v);
            count[v]++;
            if( min > v ) min = v;
            if( max < v ) max = v;
        }
    }
    
    int time, up_block, down_block;
    int time_min = 99999999;
    int answer = 0;
    for(int height = min; height <= max; height++){
        up_block = 0;
        down_block = 0;
        time = 0;
        for(int i = min; i < height; i++){
            down_block += ((height - i) * count[i]);
        }
        for(int j = height + 1; j <= max; j++){
            up_block += ((j - height) * count[j]);
        }
        if (B + up_block < down_block) continue;
        else {
            time += (2 * (up_block) + (down_block));
        }
        if(time <= time_min){
            time_min = time;
            answer = height;
        }
    }    

    cout << time_min << " " << answer << endl;
}