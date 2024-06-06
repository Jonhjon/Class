#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // �Ϥ����I���ƶq

// ����e���B�z���I���Z���̤p�����I
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    // �M���Ҧ����I�A���Z���̤p�B�|���Q�B�z�����I
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// ���k��ƥ��L�q���쳻�I�����|
void printPath(int parent[], int j) {
    if (parent[j] == -1)  // �p�G j �O���I�h��^
        return;

    printPath(parent, parent[j]);  // ���k���L����`�I
    printf(" -> %c", j+'A');  // ���L��e���I
}

// ���L�q����Ҧ����I���̵u�Z���M���|
void printSolution(int dist[], int parent[], int src) {
    printf("Vertex \t Distance from Source\tPath\n");
    for (int i = 1; i < V; i++) {
        printf("%d \t %d\t\t", i, dist[i]);
        printf("%c", src+'A');
        printPath(parent, i);  // ���L�q���I�� i �����|
        printf("\n");
    }
}

// ��{ Dijkstra ��k
void dijkstra(int graph[V][V], int src) {
    int dist[V];  // dist[i] �N�O�s src �� i ���̵u�Z��
    bool sptSet[V];  // sptSet[i] �N�� true �p�G���I i �b�̵u���|��
    int parent[V];  // �O�s�̵u���|��

    // ��l�ƩҦ��Z�����L�a�j�A�B sptSet[] �� false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;  // �]�m��l�Z�����L�a�j
        sptSet[i] = false;  // �аO�Ҧ����I�����B�z
        parent[i] = -1;  // ��l�Ƥ��`�I�� -1
    }

    // �����I�췽���I���Z���� 0
    dist[src] = 0;

    // ���q src ��Ҧ����I���̵u���|
    for (int count = 0; count < V - 1; count++) {
        // ��ܥ��B�z���I���Z���̤p�����I
        int u = minDistance(dist, sptSet);

        // �аO�ӳ��I���w�B�z
        sptSet[u] = true;

        // ��s u ���F�����I���Z����
        for (int v = 0; v < V; v++) {
            // �p�G dist[u] �����L�a�j�A�åB u �M v ����۳s�A
            // �B�q�L u �� v ���Z���p���e�� dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];  // ��s�Z��
                parent[v] = u;  // �O���e�X���I
            }
        }
    }

    // ���L�̲ת��̵u�Z���M���|
    printSolution(dist, parent, src);
}

// �D���
int main() {
    // �w�q�Ϫ��F���x�}���
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 1, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    int start_vertex = 0;  // �]�m���I
    dijkstra(graph, start_vertex);  // �ե� Dijkstra ��k

    return 0;
}
