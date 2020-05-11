#include <iostream>
#include <stack>
using std::stack;

const int size = 5;

int longestDistSubPath(int graph[][size]){
    int visited[size][size] = {};
    stack<int> open_set;
    for(int i = 0; i < size; ++i){
        for (size_t j = 0; j < size; j++)
        {
            if(graph[])


        }

    }
}

int count_walkable_path(int graph[][size]){
    
    return 0;
}

int main(){
    int graph[size][size] = {};
    graph[0][2] = graph[0][3] = graph[0][4] = 1;
    graph[1][0] = graph[2][0] = graph[3][0] = graph[4][0] = 1;
    graph[3][1] = graph[3][3] = graph[3][4] = graph[2][4] = 1; 
    for(int i = 0; i < size; ++i){
        for (size_t j = 0; j < size; j++)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}