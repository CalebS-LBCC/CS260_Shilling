#include "Graph.hh"

int main(){

    Graph graph = Graph(1);
    int passed = 1;

    // Test 1: Add a node to a graph
    if(!graph.addNode(2)){
        passed = 0;
    }

    // Test 2: Attempt to add a duplicate node to the graph
    if(graph.addNode(2)){
        passed = 0;
    }

    // Test 3: Add an edge to the graph
    if(!graph.addEdge(1,2,3)){
        passed = 0;
    }

    // Test 4: Add an edge to the graph using a node that doesn't exist
    if(graph.addEdge(1,4,3)){
        passed = 0;
    }

    // Add remaining nodes and edges
    for(int i = 3; i < 9; i++){
        graph.addNode(i);
    }
    graph.addEdge(1,5,1);
    graph.addEdge(2,3,3);
    graph.addEdge(2,4,2);
    graph.addEdge(2,5,2);
    graph.addEdge(2,7,5);
    graph.addEdge(2,8,4);
    graph.addEdge(3,4,2);
    graph.addEdge(4,8,2);
    graph.addEdge(5,6,2);
    graph.addEdge(5,7,3);
    graph.addEdge(6,7,2);
    graph.addEdge(7,8,1);

    // Test 5: Ensure the graph returns the shortest path
    Graph::PathOut* shortest = graph.djikstra(1,8);
    std::vector<int> path1 = {1,5,7,8}; // Path hand-calculated, work in Github
    if(!shortest->len == 5 or !std::equal(shortest->path.begin(), shortest->path.end(), path1.begin())){
        passed = 0;
    }

    // Test 5: Ensure the graph fails to find a path should the target node be isolated
    Graph isolatedGraph = Graph(1);
    isolatedGraph.addNode(2);
    if(isolatedGraph.djikstra(1,2)){
        passed = 0;
    }

    // Test 6: Ensure shortest path fails if a node is entered that doesn't exist
    if(graph.djikstra(9,2)){
        passed = 0;
    }

    if(graph.djikstra(2,9)){
        passed = 0;
    }

    if(graph.djikstra(9,10)){
        passed = 0;
    }

    // Test 7: Ensure the MST has the proper sum of edges
    if(graph.prim()->sum != 12){
        passed = 0;
    }

    // Test 8: Ensure Prim's fails if all nodes cannot be accessed
    if(isolatedGraph.prim()->sum != INT_MAX){
        passed = 0;
    }

    return passed;
}