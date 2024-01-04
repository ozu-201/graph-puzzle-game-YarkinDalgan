#include <iostream>
#include "src/List/Graph/Graph.h"
#include <fstream>
#include <vector>

using namespace std;
using namespace list;

bool isOneLetterDifference(const string &k1, const string &k2){
    if(k1.length() != k1.length()){
        return false;
    }
    int diffCount = 0;
    for(int i = 0;i<k1.length();i++){
        if(k1[i] != k2[i])
            diffCount++;
    }
    return diffCount == 1;
}

Graph graphConstruction(const vector<string> &vector){
    size_t size = vector.size();
    Graph graph = Graph((long)size);
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size;j++){
            if(isOneLetterDifference(vector[i], vector[j]))
                graph.addEdge(i,j,1);
        }
    }
    return graph;
}

int searchIndex (const string& w, const vector<string>&v){
    int index = 0;
    for(const string& item : v){
        if(item == w)
            return index;
        index++;
    }
    return -1;
}

vector<string> readFile(const string& directory, int size) {
    ifstream in(directory);
    vector<string> words{};
    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            if(line.length() == size) {
                words.push_back(line);
            }
        }
        in.close();
    } else {
        cout << "File cannot open." << endl;
    }
    return words;
}

int main(){
    int letterCount;
    string from;
    string to;
    cout<<"Please enter a letter count"<<endl;
    cin>>letterCount;
    cout<<"Please choose the starting word"<<endl;
    cin>>from;
    cout<<"Please choose the target word"<<endl;
    cin>>to;

    vector<string> words = readFile(R"(C:\Users\TEMP.OZUN.000\CLionProjects\graph-puzzle-game-YarkinDalgan\english-dictionary.txt)",letterCount);

    Graph graph = graphConstruction(words);

    int start = searchIndex(from,words);
    int finish = searchIndex(to,words);

    graph.wordLadderBFS(words,start,finish);
}