#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <unordered_set>
using namespace std;

class Graph {
    private:
        int n;
        typedef pair<int, int> Edge;
        vector<list<Edge>> v;
        
    public:
        Graph(int size = 2) {
            n = size;
            v.resize(n);
        }

        void addEdge(int x, int y, int w) {
            Edge to_insert1(y,w);
            Edge to_insert2(x,w);
            v[x].push_back(to_insert1);
            v[y].push_back(to_insert2);
        }

        void print() {
            for(int i = 0; i < n; i++) {
                cout << "Node " << i << " is connected to: ";
                for (pair<int,int> j : v[i]) {
                    if(j.first != -1){
                        cout << j.first << " : "<< j.second<<", ";
                    }
                }
                cout << endl;
            }
        }

        vector<pair<int, int>> dijkstra(int startNode) {
            vector<pair<int, int>> p(n);
            priority_queue<pair<int, int>, 
                vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pair<int, int> to_insert;
            to_insert.first = 0; to_insert.second = 0;
            p[startNode] = to_insert;
            to_insert.second = startNode;
            pq.push(to_insert);
            for(int i = 0; i < n; i++){
                if(i != startNode){
                    to_insert.first = -1;
                    to_insert.second = -1;
                    p[i] = to_insert;
                    // pq.push({INT32_MAX, i});
                }
            }
            pair<int, int> current;
            std::list<pair<int, int>>::iterator it;
            while(!pq.empty()){
                current = pq.top();
                pq.pop();
                int u = current.second;
                int u_weight = current.first;
                for(it = v[u].begin(); it != v[u].end(); it++){
                    int neighbor = it->first;
                    int neighbor_weight = it->second;
                    if(p[neighbor].first == -1 ||
                        p[neighbor].first > neighbor_weight + u_weight){
                            p[neighbor].first = neighbor_weight + u_weight;
                            p[neighbor].second = u;
                            to_insert.first = p[neighbor].first;
                            to_insert.second = neighbor;
                            pq.push(to_insert);
                    }
                }
            }
            return p;
        }

        string printShortestPath(int startNode, int endNode) {
            int current = endNode;
            vector<string> store;
            string s;
            vector<pair<int, int>> p = dijkstra(startNode);
            store.push_back(to_string(endNode));
            while(p[current].first != -1){
                store.push_back(to_string(p[current].second));
                if(p[current].second == startNode){
                    break;
                }
                current = p[current].second;
            }
            if(p[current].first == -1){
                return "";
            }
            for(int i = store.size()-1; i > -1; i--){
                s = s + store.at(i) + " ";

            }
            return s;
        }
};



