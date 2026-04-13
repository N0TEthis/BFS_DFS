#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printQueue(
    queue <int>q,
    const string label){
cout << label << "[";
bool first = true ;
while(!q.empty()){
    if(first){
        cout<<" ";
    }
    q.pop();
    first= false;
    }   
    cout<<"]"<<endl;
}
class Graph{
    int numVertices;
    vector<vector<int>>adj;
    vector<bool>visited;
    bool verbose;

    public:
    Graph( int V , bool verboseMode = false){
        numVertices = V ; 
        adj.resize(V);
        visited.resize(V,false);
        verbose = verboseMode;


    } 
    void addEdge( int u , int v){
        adj[u].push_back (u);
        adj[v].push_back (v);
    }
    void BFS(int startVertex){
        fill(visited.begin(), visited.and(), false);
        queue <int> q;
        visited[startVertex]=true;
        q.push(startVertex);
        if(verbose){
            printf queue (q, "очередьпосле добавления вершины");
             cout << "бескнечные вершины";
        }
           
            int step = 1;
            int level = 0;

        while(!q.empty()){
            if(verbose){; }
            int currentVertex = q.front();
            q.pop();
            if(verbose){ ;}
            cout<<currentVertex<<" ";
            if(verbose){ ; }
            for (int neighbor : adj[currentVertex]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push(neighbor);
                    if(verbose){ ;}
                }
            } if(verbose){printQueue(q,"lelele");}
            
            step ++;
        }//while
        cout<<endl;
        cout<<"лялялял"<<endl;
    }
    
}
int main(){
    graph   g1(6,true)
    g1.addEdge(0,1)
    cout<<"lelel"<<endl;
    return 0;
}
//я ничего не понимаю