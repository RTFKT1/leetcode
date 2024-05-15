#include <iostream>
#include <fstream>
#include <string>  // Include <string> header for string manipulation
#include <sstream> // Include <sstream> header for stringstream

using namespace std;

vector<vector<int> > adj;
vector<int> findDistance(vector<vector<int> >& edges,int n){
    vector<int> ans;
    for(int i = 0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return ans;
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
        aux.push_back(u);
        aux.push_back(v);
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
        outputFile<<ans[i]<<" ";
    }

    return 0;
}
