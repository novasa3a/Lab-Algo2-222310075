#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Struktur data untuk merepresentasikan grafik
struct Edge {
    int destination;
    int weight;
};

// Fungsi untuk mencari jalur terpendek menggunakan algoritma Dijkstra
void findShortestPath(vector<vector<Edge>>& graph, int source, int destination) {
    int numVertices = graph.size();

    // Inisialisasi vektor jarak dengan nilai tak terhingga dan vektor jalur dengan -1
    vector<int> distance(numVertices, INT_MAX);
    vector<int> parent(numVertices, -1);

    // Menyimpan jarak dari titik awal ke titik awal sebagai 0
    distance[source] = 0;

    // Menyimpan titik awal ke antrian prioritas dengan jarak 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int currentVertex = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        // Jika jarak saat ini lebih besar dari jarak yang sudah disimpan, lewati
        if (currentDistance > distance[currentVertex]) {
            continue;
        }

        // Iterasi melalui semua tetangga dari currentVertex
        for (const Edge& edge : graph[currentVertex]) {
            int neighbor = edge.destination;
            int weight = edge.weight;

            // Mengupdate jarak jika ditemukan jarak yang lebih pendek
            if (currentDistance + weight < distance[neighbor]) {
                distance[neighbor] = currentDistance + weight;
                parent[neighbor] = currentVertex;
                pq.push(make_pair(distance[neighbor], neighbor));
            }
        }
    }

    // Mencetak jalur terpendek dan jarak minimum
    cout << "Jalur terpendek dari " << source << " ke " << destination << " : ";

    int currentVertex = destination;
    vector<int> path;
    while (currentVertex != -1) {
        path.push_back(currentVertex);
        currentVertex = parent[currentVertex];
    }

    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i != 0) {
            cout << " -> ";
        }
    }

    cout << endl;
    cout << "Jarak minimum: " << distance[destination] << endl;
}

int main() {
    int numVertices = 6; // Jumlah total kota dalam grafik
    vector<vector<Edge>> graph(numVertices);

    // Menambahkan edge ke grafik
    // Format: graph[source].push_back({destination, weight});
    graph[1].push_back({2, 7});
    graph[1].push_back({3, 9});
    graph[2].push_back({3, 10});
    graph[2].push_back({4, 15});
    graph[3].push_back({4, 11});
    graph[4].push_back({5, 6});  

    int source = 1;
    int destination = 5;

    // Mencari jalur terpendek menggunakan algoritma Dijkstra
    findShortestPath(graph, source, destination);

    return 0;
}