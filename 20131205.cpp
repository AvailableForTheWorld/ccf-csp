#include<iostream>
#include<cstring>
using namespace std;
char MP[52][52];
int visited[51][51],n,m,vis[51][51];
struct pos{
    int x, y;
} start, target;
int trail[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}},cnt=0;
pos operator+(pos z,int a[]){
    return {z.x + a[0], z.y + a[1]};
}
int islegal(pos z){
    if (z.x <= n && z.x > 0 && z.y <= m && z.y > 0&&!visited[z.x][z.y]&&MP[z.x][z.y]!='#')
        return 1;
    else
        return 0;
}
void dfs(pos cur){
    visited[cur.x][cur.y] = 1;
    pos t;
    if(MP[cur.x][cur.y]=='+'||MP[cur.x][cur.y]=='S'||MP[cur.x][cur.y]=='T'){
        for (int i = 0; i < 4; ++i){
            t = cur + trail[i];
            if(islegal(t)){
                dfs(t);
            }
        }    
    }
    else if(MP[cur.x][cur.y]=='-'){
        for (int i = 1; i < 4;i+=2){
            t = cur + trail[i];
            if(islegal(t)){
                dfs(t);
            }
        }
    }
    else if(MP[cur.x][cur.y]=='|'){
        for (int i = 0; i < 4;i+=2){
            t = cur + trail[i];
            if(islegal(t)){
                dfs(t);
            }
        }
    }
    else if(MP[cur.x][cur.y]=='.'){
        t = cur + trail[0];
            if(islegal(t)){
                dfs(t);
            }
    }
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        getchar();
        for (int j = 1; j <= m; ++j){
            scanf("%c",&MP[i][j]);
            if(MP[i][j]=='S')
                start = {i, j};
            else if(MP[i][j]=='T')
                target = {i, j};
        }
    }
    pos cur = start;
    memset(visited, 0, sizeof(visited));
    dfs(cur);
    // printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    // for (int i = 1; i <= n; ++i){
    //     for (int j = 1; j <= m;++j){
    //         printf(" %d", visited[i][j]);
    //     }
    //     cout << endl;
    // }
    // printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    memcpy(vis, visited, sizeof(visited));
    if(vis[target.x][target.y]){
        for (int i = 1; i <= n;++i){
            for (int j = 1; j <= m;++j){
                if(vis[i][j]){
                    memset(visited, 0, sizeof(visited));
                    cur = {i, j};
                    dfs(cur);
                    if(!visited[target.x][target.y])
                    {
                        ++cnt;
                        // cout << i<<" "<<j << endl;
                    }
                }
            }
        }
        cout << cnt;
    }
    else
        cout << "I'm stuck!";
    return 0;
}
