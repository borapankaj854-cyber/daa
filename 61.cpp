/*Given a (directed/undirected) graph, design an algorithm and implement it using a program
to find if a path exists between two given vertices or not. (Hint: use DFS)*/

#include<iostream>
using namespace std;

unordered_map<int,vector<int>> convert_mat_to_list(vector<vector<int>>&adjMat){
    unordered_map<int,vector<int>> adjList;
    for(int i=0;i<adjMat.size();i++){
        for(int j=0;j<adjMat[i].size();j++){
            if(adjMat[i][j]==1)
            adjList[i].push_back(j);
        }
    }
    return adjList;
}

bool path_find(unordered_map<int,vector<int>>&adjList,int src,int dest,unordered_map<int,bool>&visited){
    if(src==dest) return true;
    visited[src] = true;
    for(auto nbr : adjList[src]){
        if(!visited[nbr]){
            if(path_find(adjList,nbr,dest,visited)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int V,src,dest;
    cout << "Enter number of vertices : ";
    cin >> V;
    vector<vector<int>> adjMat(V,vector<int>(V));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin >> adjMat[i][j];
        }
    }
    unordered_map<int,vector<int>> adjList = convert_mat_to_list(adjMat);
    unordered_map<int,bool> visited;

    cout << "Enter source node : ";
    cin >> src;
    cout << "Enter destination node : ";
    cin >> dest;

    if(path_find(adjList,src,dest,visited)){
        cout << "Path found " << endl;
    }
    else{
        cout << "Path not found " << endl;
    }
    return 0;
}