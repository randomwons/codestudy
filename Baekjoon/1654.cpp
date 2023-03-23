#include <iostream>
#include <vector>

using namespace std;

int main(){
    int K, N;
    scanf("%d %d", &K, &N);
    
    vector<int> lines(K);
    int max = 0;
    for(int i = 0; i < K; i++){
        scanf("%d", &lines[i]);
        if(max < lines[i]) max = lines[i];
    }

    long long l, r, mid;
    l = 0;
    r = max;
    int count;
    while(r - l > 1){
        count = 0;
        mid = (l + r) / 2;
        for(const auto& v : lines) count += (v / mid);
        if(count >= N) l = mid;
        else r = mid;
    }

    count = 0;
    for(const auto& v : lines) count += (v / r);
    cout << (count >= N ? r : l) << endl;
}