#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    // 각각 부모 노드를 설정
    vector<int> Tree(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &Tree[i]);
    }

    // 부모 노드 연결 끊기
    int v;
    scanf("%d", &v);
    Tree[v] = -2;

    // Leaf인지 체크
    vector<int> check(N, 1);
    for(int i = 0; i < N; i++){
        int temp = i;
        while(Tree[temp] >= 0){
            temp = Tree[temp];
            check[temp] = 0;
        }
        if(Tree[temp] == -2){
            check[i] = 0;
        }
    }
  
    int sum = 0;
    for(const auto& v : check) sum += v;
    cout << sum << endl;
  
    return 0;
}
