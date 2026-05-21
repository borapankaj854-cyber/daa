/*Given a graph, design an algorithm and implement it using a program to find if a graph is
bipartite or not. (Hint: use BFS)*/

#include<iostream>
using namespace std;

unordered_map<int,vector<int>> convert_to_List(vector<vector<int>>&adjMat){
    unordered_map<int,vector<int>> adjList;
    for(int i=0;i<adjMat.size();i++){
        for(int j=0;j<adjMat[i].size();j++){
            if(adjMat[i][j]==1){
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}

bool isBipartite(unordered_map<int,vector<int>>& adjList,int V){
    //make color map
    unordered_map<int,int> color;
    //give all color to -1
    for(int i=0;i<V;i++){
        color[i]=-1;
    }
    //logic this loop for disconnected components
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            queue<int> q;
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(auto nbr : adjList[front]){
                    if(color[nbr]==-1){
                        color[nbr] = 1 - color[front];
                        q.push(nbr);
                    }
                    else if(color[nbr]==color[front]){
                        return false;
                    }
                }
            }
        }
    }
    //if any adj edges dont have same color return true
    return true;
}
int main(){
    int V;
    cout << "Enter number of edges : ";
    cin >> V;
    vector<vector<int>> adjMat(V,vector<int>(V));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin >> adjMat[i][j];
        }
    }
    unordered_map<int,vector<int>> adjList = convert_to_List(adjMat);

    if(isBipartite(adjList,V)){
        cout << "Yes Bipartite";
    }
    else{
        cout << "Not Bipartite";
    }
    return 0;
}