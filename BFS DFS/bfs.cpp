#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int> g[N];
int vis[N];
int level[N];
void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        int cur_v=q.front();
        cout<<cur_v<<" ";
        q.pop();
        for(int child: g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_v];
            }
        }
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
}


// 
//13
// 1 2
// 1 3
// 1 13
// 2 5
// 5 6
// 5 7
// 5 8
// 8 12
// 3 4
// 4 9
// 4 10
// 10 11
// 9 11
