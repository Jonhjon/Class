#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // 圖中頂點的數量

// 找到當前未處理頂點中距離最小的頂點
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    // 遍歷所有頂點，找到距離最小且尚未被處理的頂點
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// 遞歸函數打印從源到頂點的路徑
void printPath(int parent[], int j) {
    if (parent[j] == -1)  // 如果 j 是源點則返回
        return;

    printPath(parent, parent[j]);  // 遞歸打印其父節點
    printf(" -> %c", j+'A');  // 打印當前頂點
}

// 打印從源到所有頂點的最短距離和路徑
void printSolution(int dist[], int parent[], int src) {
    printf("Vertex \t Distance from Source\tPath\n");
    for (int i = 1; i < V; i++) {
        printf("%d \t %d\t\t", i, dist[i]);
        printf("%c", src+'A');
        printPath(parent, i);  // 打印從源點到 i 的路徑
        printf("\n");
    }
}

// 實現 Dijkstra 算法
void dijkstra(int graph[V][V], int src) {
    int dist[V];  // dist[i] 將保存 src 到 i 的最短距離
    bool sptSet[V];  // sptSet[i] 將為 true 如果頂點 i 在最短路徑樹中
    int parent[V];  // 保存最短路徑樹

    // 初始化所有距離為無窮大，且 sptSet[] 為 false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;  // 設置初始距離為無窮大
        sptSet[i] = false;  // 標記所有頂點為未處理
        parent[i] = -1;  // 初始化父節點為 -1
    }

    // 源頂點到源頂點的距離為 0
    dist[src] = 0;

    // 找到從 src 到所有頂點的最短路徑
    for (int count = 0; count < V - 1; count++) {
        // 選擇未處理頂點中距離最小的頂點
        int u = minDistance(dist, sptSet);

        // 標記該頂點為已處理
        sptSet[u] = true;

        // 更新 u 的鄰接頂點的距離值
        for (int v = 0; v < V; v++) {
            // 如果 dist[u] 不為無窮大，並且 u 和 v 有邊相連，
            // 且通過 u 到 v 的距離小於當前的 dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];  // 更新距離
                parent[v] = u;  // 記錄前驅頂點
            }
        }
    }

    // 打印最終的最短距離和路徑
    printSolution(dist, parent, src);
}

// 主函數
int main() {
    // 定義圖的鄰接矩陣表示
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 1, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    int start_vertex = 0;  // 設置源點
    dijkstra(graph, start_vertex);  // 調用 Dijkstra 算法

    return 0;
}
