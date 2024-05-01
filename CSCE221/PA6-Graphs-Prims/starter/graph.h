#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    private:
        unordered_map<int, unordered_map<int, int>> adjList;

    public:
        Graph() {};

        bool contains_vertex(int u) {
            if(adjList.find(u) == adjList.end()){
                return false;
            }
            return true;
        }

        bool contains_edge(int u, int v) {
            if(contains_vertex(u) && contains_vertex(v)
                && adjList[u].find(v) != adjList[u].end()){
                return true;
            }
            return false;
        }

        void addVertex(int u) {
            if(!contains_vertex(u)){
                adjList[u] = unordered_map<int,int>();
            }
        }

        void addEdge(int u, int v, int w) {
            adjList[u][v] = w;
            adjList[v][u] = w;
        }

        void removeEdge(int u, int v) {
            adjList[u].erase(v);
            adjList[v].erase(u);
        }

        void removeVertex(int id) {
            adjList.erase(id);
        }

        int numVertices() {
            return adjList.size();
        }

        int getEdgeWeight(int u, int v) {
            if(adjList[u].find(v) != adjList[u].end()){
                return adjList[u][v];
            }
            return -1; 
        }

        vector<pair<int, int>> primMST() {
            vector<pair<int, int>> p;
            unordered_map<int, bool> inMST;
            unordered_map<int, int> parent;
            priority_queue<pair<int, int>, 
                vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, adjList.begin()->first});
            pair<int, int> current;
            int u, u_weight;
            while(!pq.empty()){
                current = pq.top();
                pq.pop();
                u = current.second;
                u_weight = current.first;
                inMST[u] = true;
                for(auto it = adjList[u].begin(); it != adjList[u].end(); it++){
                    int neighbor = it->first;
                    int neighbor_weight = it->second;
                    if(!inMST[neighbor] && (parent.find(neighbor) == parent.end() 
                        || getEdgeWeight(parent[neighbor], neighbor) > neighbor_weight)){
                            pq.push({neighbor_weight, neighbor});
                            parent[neighbor] = u;
                    }
                }
                while(!pq.empty() && inMST[pq.top().second]){
                    pq.pop();
                }
                if(!pq.empty()){
                    p.push_back({parent[pq.top().second], pq.top().second});
                }
            }
            return p;
        }
};