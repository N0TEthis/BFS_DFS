#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printStack(stack<int>s , const string&label){
     cout << label <<" [";
     vector <int> temp;
        while(!s.empty()){
            temp.push_back(s.top());
            s.pop();
        }//while
        
        for(int i=temp.size();i>=;i--){
            cout <<temp[i];
            if(i>0){
                cout<<" ";
            }
        }//for
        cout << " ]" << endl;
}//printS

class Graph{
    int numVertices;//кол-во вершин
    vector<vector<int>>adj;//вектор со всеми интами
    vector<bool>visited;
    bool verbose;

    public:
    Graph(int V, bool verboseMode = false){
        numVertices = V;
        adj.resize(V);
        visited.resize(V,false);
        verbose = verboseMode;
    }
    void addEdge(int u, int v){
        adj[u].push_back (v);
        adj[v].push_back (u);
    }

    void DFS(int startVertex){
        fill(visited.begin(), visited.end(), false);
        stack<int> stack;
        visited[startVertex]=true;
        stack.push(startVertex);
        if(verbose){
            printStack(stack,"начало вершины мяу");
            cout<<"посещенные вершины";
        }
        int step=1;
        int level = 0;

        while(!stack.empty()){
        if(verbose){ printQueue(stack, "beb"); } //что-то надо хз потом разберу  
        int currentVertex = stack.top();
        stack.pop();
        if(verbose){ printQueue(stack, "chtymr"); }
        cout << currentVertex << " ";
        if(verbose){ printQueue(stack, "chyros"); }
        for(int neighbor : adj[currentVertex]){
            if(!visited[neighbor]){
                visited[neighbor]=true;
                stack.push(neighbor);
                if(verbose){ printQueue(q, "am am"); }
            }
            if(verbose){printQueue(q, "miao");}
        }//while
    }//DFS
}//graph