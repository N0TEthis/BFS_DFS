#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//сначала делаем функцию котораря возвращает очередь
//
//
//
void printQueue ( queue <int>q, const string label){
        cout << label <<" [";
        bool first = true;
        while(!q.empty()){
            if(first){ cout << " ";}
            q.pop();
            first = false;
        }
        cout << " ]" << endl;
    }
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
    void BFS(int startVertex){
        fill(visited.begin(), visited.end(), false);
        queue<int> q;
        visited[startVertex]=true;
        q.push(startVertex);
        if(verbose){
            printQueue(q," очередь вершины хз наверное");
            cout<<"посещенные вершины";
        }
    
    int step=1;
    int level = 0;
    
    while(!q.empty()){
        if(verbose){ printQueue(q, "beb"); } //что-то надо хз потом разберу  
        int currentVertex = q.front();
        q.pop();
        if(verbose){ printQueue(q, "chtymr"); }
        cout << currentVertex << " ";
        if(verbose){ printQueue(q, "chyros"); }
        for(int neighbor : adj[currentVertex]){
            if(!visited[neighbor]){
                visited[neighbor]=true;
                q.push(neighbor);
                if(verbose){ printQueue(q, "am am"); }
            }
            if(verbose){printQueue(q, "miao");}
        }
        step++;
    } //while
    cout << endl;
    cout <<"end" << endl;
    }//BFS
}; //class

int main(){
    // Graph g1(6, true);
    // g1.addEdge(0,1);
    // g1.addEdge(1,2);
    // g1.addEdge(1,3);
    // g1.addEdge(0,4);
    // g1.addEdge(4,5);
    // g1.BFS(0);
    // cout <<"omg it's a phone oppo 225 800 3" << endl;
    // return 0;

    // Graph g2(7, true);
    // g2.addEdge(0,1);
    // g2.addEdge(1,3);
    // g2.addEdge(1,4);
    // g2.addEdge(0,2);
    // g2.addEdge(2,5);
    // g2.addEdge(2,6);
    // g2.BFS(0);
    // cout <<"omg it's a phone oppo 226 801 4" << endl;
    // return 0;

    // Graph g4(4, true);
    // g4.addEdge(0,1);
    // g4.addEdge(1,2);
    // g4.addEdge(2,3);
    // g4.BFS(0);
    // cout <<"omg it's a phone oppo 227 802 5" << endl;
    // return 0;

    // Graph g5(5, true);
    // g5.addEdge(0,1);
    // g5.addEdge(0,2);
    // g5.addEdge(0,3);
    // g5.addEdge(0,4);
    // g5.BFS(0);
    // cout <<"omg it's a phone oppo 228 803 6" << endl;
    // return 0;

    // Graph g3(11, true);
    // g3.addEdge(0,1);
    // g3.addEdge(1,2);
    // g3.addEdge(1,3);
    // g3.addEdge(2,4);
    // g3.addEdge(4,3);
    // g3.addEdge(0,2);
    // g3.addEdge(2,1);
    // g3.addEdge(2,4);
    // g3.addEdge(4,3);
    // g3.addEdge(3,1);
    // g3.BFS(0);
    // cout <<"omg it's a phone oppo 228 803 6" << endl;
    // return 0;

    Graph g6(22, true);
    g6.addEdge(0,1);
    g6.addEdge(0,6);
    g6.addEdge(1,2);
    g6.addEdge(1,4);
    g6.addEdge(1,5);
    g6.addEdge(2,3);
    g6.addEdge(2,4);
    g6.addEdge(3,10);
    g6.addEdge(3,8);
    g6.addEdge(4,5);
    g6.addEdge(4,7);
    g6.addEdge(5,6);
    g6.addEdge(5,7);
    g6.addEdge(6,11);
    g6.addEdge(6,7);
    g6.addEdge(7,11);
    g6.addEdge(7,9);
    g6.addEdge(8,9);
    g6.addEdge(9,10);
    g6.addEdge(9,11);
    g6.addEdge(10,11);
    g6.BFS(0);
    cout <<"omg it's a phone oppo 228 803 6" << endl;
    return 0;
}
//мы будем сравнивать одлинаковые деревья с разными обходами
//я ничего не понимаю