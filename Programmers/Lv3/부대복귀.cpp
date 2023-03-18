// https://school.programmers.co.kr/learn/courses/30/lessons/132266

#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination){

    // Graph
    map<int, vector<int>> graph;
    for(vector<int>& road : roads){
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }

    // BFS
    vector<int> visitied;
    queue<int> q;
    
    visitied.assign(n+1, -1);
    q.push(destination);
    visitied[destination] = 0;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int v : graph[x]){
            if(visitied[v] == -1){
                visitied[v] = visitied[x] + 1;
                q.push(v);
            }
        }
    }
    
    // answer
    vector<int> answer;
    for(int s : sources){
        answer.push_back(visitied[s]);
    }

    return answer;
}