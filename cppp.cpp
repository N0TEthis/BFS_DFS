//stack
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printStack(stack <int>s , const string & label){
    cout << label <<" [ ";
    vector <int> temp;
    while(!s.empty()){
        temp.push_back(s.top());
        s.pop();
    }//end while
    for(int i = temp.size()-1; i >= 0; i--){
        cout<<temp[i];
        if(i<0){cout<<" ";}
    }
    cout<<" ] "<<endl;
}//end printStack

class Graph{
    int numVertices;//кол-во вершин
    vector<vector<int>>adj;//список смежности
    vector<bool>visited;
    bool verbose;

    public:
    Graph(int V, bool verboseMode = false){
        numVertices = V;
        adj.resize(V);
        visited.resize(V,false);
        verbose = verboseMode;
        
    }//end graph initialization
    void addEdge(int u, int v){
        adj[u].push_back (v);
        adj[v].push_back (u);
    }//end addEdge
    void DFS(int startVertex){
        fill(visited.begin(), visited.end(), false);
        stack <int> stack;
        visited[startVertex]=true;
        stack.push(startVertex);
        if(verbose){
            printStack(stack, "start");
        }

    int step=1;
    while(!stack.empty()){
        if(verbose){ printStack(stack, "first step");  }//дорисовать вербоусы начиная с этого
        int currentVertex = stack.top();
        stack.pop();
        if(verbose){ ; }
        cout << currentVertex << " ";
        if(verbose){ 
            cout<<"\n ищем соседние относительно"<<currentVertex<<": ";
            bool hasUnvisited=false;
            for (int neighbor:adj[currentVertex]){
                cout<<neighbor;
                if(visited [neighbor]){
                    cout<<" посещает ";}
                else {
                    cout<<" новая ";
                    hasUnvisited = true;
                }
                
            }
            cout<<endl;
        }
        vector<int> neighbors;
        for(int neighbor : adj[currentVertex]){
            neighbors.push_back(neighbor);
        }
        for(int i = neighbors.size()-1; i>=0; i--){
            int neighbor = neighbors[i];
            if(!visited [neighbor]){
                visited[neighbor]=true;
                stack.push(neighbor);
                if(verbose){ ; }
            }
        }step++;
    }
    cout<<endl;
    cout<<" обход завершен ";
    }//end dfs c иттерационный подход
    void DFSRecursive(int vertex){
        visited[vertex]=true;
        cout<< vertex <<" ";
        for(int neighbor:adj[vertex]){
            if(!visited[neighbor]){
                DFSRecursive(neighbor);
            }
        }
    }
    
    /**
    @brief dfs с рекурсией
    @param startVertex -- start vertex
     */
    void DFSRecursiveWrapper(int startVertex){
        fill(visited.begin(), visited.end(), false);
        cout<<" DFSRecursive ";
        DFSRecursive(startVertex);
        cout<<endl;
    }
};//end graph

int main() {
    Graph g5(12, true);
    g5.addEdge(0,1);//0,1
    g5.addEdge(0,6);//1,3
    g5.addEdge(1,2);//3,4
    g5.addEdge(1,4);
    g5.addEdge(1,5);
    g5.addEdge(4,5);
    g5.addEdge(4,7);
    g5.addEdge(4,8);
    g5.addEdge(2,3);//0,1
    g5.addEdge(2,4);//1,3
    g5.addEdge(3,10);//3,4
    g5.addEdge(3,8);
    g5.addEdge(5,6);
    g5.addEdge(5,7);
    g5.addEdge(6,11);
    g5.addEdge(6,7);
    g5.addEdge(7,11);//0,1
    g5.addEdge(7,9);//1,3
    g5.addEdge(8,9);//3,4
    g5.addEdge(9,10);
    g5.addEdge(9,11);
    g5.addEdge(10,11);
    g5.DFS(0);
    g5.DFSRecursiveWrapper(0);
    cout <<" end big main graph omg swag " << endl;
    return 0;
}

/*ДЗДЗДЗДДЗЗДЗД ДОДЕЛАТЬ ВЕРБОУЗЫ И КАК ЭТО ЧО РАБОТАТЕТ ,
 рекурсия как выглядит и как мы вершины все обошли э<<--*/
