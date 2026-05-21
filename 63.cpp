/*Given a directed graph, design an algorithm and implement it using a program to find
whether cycle exists in the graph or not.*/

#include<iostream>
using namespace std;
unordered_map<int,vector<int>> convert_to_List(vector<vector<int>>&adjMat){
    unordered_map<int,vector<int>> adjList;
    for(int i=0;i<adjMat.size();i++){
        for(int j=0;j<adjMat[i].size();j++){
            if(adjMat[i][j]==1)
            adjList[i].push_back(j);
        }
    }
    return adjList;
}

bool cycle_present(int src,unordered_map<int,vector<int>> &adjList,unordered_map<int,bool>&tracker,unordered_map<int,bool> &visited){
    visited[src]=true;
    tracker[src]=true;
    for(auto nbr : adjList[src]){
        if(!visited[nbr]){
            bool ans = cycle_present(nbr,adjList,tracker,visited);
            if(ans) return true;
        }
        else if(visited[nbr]==true && tracker[nbr]==true){
            return true;
        }
    }
    tracker[src]=false;
    return false;
}
int main(){
    int V;
    cout << "Enter number of vetices :";
    cin >> V;
    vector<vector<int>> adjMat(V,vector<int>(V));
    unordered_map<int,bool> tracker;
    unordered_map<int,bool> visited; 
    cout << "Enter them in matrix : ";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin >> adjMat[i][j];
        }
    }
    unordered_map<int,vector<int>> adjList = convert_to_List(adjMat);
    if(cycle_present(0,adjList,tracker,visited)){
        cout << "cycle present" << endl;
    }
    else{
        cout << "cycle not present" << endl;
    }

    return 0;
}