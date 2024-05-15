#include <iostream>
#include <fstream>
#include <string>  // Include <string> header for string manipulation
#include <sstream> 
#include <vector>

using namespace std;

vector<vector<int> > adj;
vector<int> sum;
vector<int> cnt;

void dfs(int root,int parent){
    for(int child : adj[root]){
        if(child==parent) continue;
        dfs(child,root);
        cnt[root] += cnt[child];
        sum[root] += sum[child]+cnt[child];
    }
}

void reroot(int root,int parent,int n){
    for(int child:adj[root]){
        if(child==parent) continue;
        sum[child] = sum[root] + n - 2*cnt[child];
        reroot(child,root,n);
    }
}

vector<int> findDistance(vector<vector<int> >& edges,int n){
    adj.resize(n);
    for(int i = 0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cnt.assign(n,1);
    sum.assign(n,0);
    dfs(0,-1);
    reroot(0,-1,n);

    return sum;
}

int main(int argc, char* argv[]) {

    for(int i = 0;i<argc;i++){
        cout<<argv[i]<<endl;
    }

    string inputFileName = argv[1];
    string outputFileName = argv[2];

    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cout << "Failed to open input file: " << inputFileName << endl;
        return 1;
    }
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cout << "Failed to open output file: " << outputFileName << endl;
        return 1;
    }

    int nodes;
    inputFile>>nodes;
    cout<<"nodes: "<<nodes<<endl;
    vector< vector<int> > edges;

    int u,v;

    while(inputFile>>u>>v){
        vector<int> aux;
        aux.push_back(u-1);
        aux.push_back(v-1);
        edges.push_back(aux);
    }

    

    for(int i = 0;i<edges.size();i++){
        for(int j = 0;j<edges[i].size();j++){
            cout<<edges[i][j]<<"\t";
        }
        cout<<endl;
    }

    vector<int> ans = findDistance(edges,nodes);

    for(int i = 0;i<ans.size();i++){
        if(i==ans.size()-1)
        outputFile<<ans[i];
        else
        outputFile<<ans[i]<<" ";
    }

    return 0;
}
