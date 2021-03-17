#include "Node.hh"
#include <algorithm>

/**
 * A graph which can process bidirectional edges and return the
 * shortest path between two points and the minimal spanning tree
 * of the graph.
 * 
 * @author Caleb Shilling
 * @date 3-17-2021
 */
class Graph{
public: 
    /**
     * Constructor for the Graph class.
     * 
     * I decided to have the program initalize with a node to
     * prevent errors when performing Prim's or Dijikstra's
     * algorithms.
     * 
     * @param init_name Name of the root node in the graph
     */
    Graph(int init_name){
        struct Node * new_node = new Node;
        new_node->name = init_name;
        graph.push_back(new_node);       
    }

    /**
     * Add a node to the graph.
     * 
     * The program first checks if the node is already present.
     * If it is, the node is not added. If it does not exist in
     * the graph, the node is added.
     * 
     * @param node_name The name of the node to be added
     * @return          Return a 1 if the node was added, 0 otherwise
     */
    int addNode(int node_name){
        // Check if the node has already been added to the graph
        if(getNode(node_name))
            return 0;

        // Add the node if it doesn't exist in the graph
        struct Node * new_node = new Node;
        new_node->name = node_name;
        graph.push_back(new_node);
        return 1;
    }

    /**
     * Adds an edge to the graph between two nodes.
     * 
     * This is a bidirectional edge. Adding a directional edge
     * is possible with a few modifications to Prim's and Dikijstra's
     * to support it.
     * 
     * This function first ensures both nodes are in the graph and
     * makes note of their positions. Once this is done, the length
     * of each edge and the other node is added to each node, allowing
     * access to one node using the other and vice versa.
     * 
     * @param node_1    A node the edge will connect
     * @param node_2    A node the edge will connect
     * @param len       Length of the edge
     */
    int addEdge(int node_1, int node_2, int len){
        int loc1 = 0;
        int node1found = 0;
        int loc2 = 0;
        int node2found = 0;
        // Check if both nodes exist in the graph
        for(int i = 0; i < graph.size(); i++){
            if(graph.at(i)->name == node_1){
                loc1 = i;
                node1found = 1;
            }        
            if(graph.at(i)->name == node_2){
                loc2 = i;
                node2found = 1;
            }      
        }
        if(!node1found or !node2found)
            return 0;

        // Add both nodes to each other's connections.
        graph.at(loc1)->connections.push_back(graph.at(loc2));
        graph.at(loc1)->connections_len.push_back(len);
        graph.at(loc2)->connections.push_back(graph.at(loc1));
        graph.at(loc2)->connections_len.push_back(len);
        return 1;
    }

    /**
     * Structure for returning both the length of the shortest path
     * and the path followed.
     * 
     * @param len   The length of the path
     * @param path  The path followed described using the names of nodes
     */
    struct PathOut{
        int len;
        std::vector<int> path;
    };

    /**
     * Algorithm for determining the shortest path between nodes.
     * 
     * The program first ensures both nodes are in the graph. Then, the source
     * node is added to the queue. The following runs looped:
     * 
     * The node with the smallest distance is taken from the queue. The node is then
     * scanned for children. If there are children, each child is checked if it is visited
     * or if the child is already in the queue. If the child is visited, it is skipped. If
     * the child is not in the queue, it is added with the distance from the source to that
     * node. If it is in the queue, the node's distance is modified if the distance through
     * the parent node is shorter than what is currently listed.
     * 
     * This is ran until the destination node is encountered or the queue ends. If the
     * destination node is not in the queue, the program returns a nullptr. If it is,
     * that node must be the current node. The distance to that node is saved. In order
     * to get the path, which is an int vector, the current node's name is added to the
     * front of the vector. Then, the parent is accessed and the cycle repeats until there
     * is no parent of the current vector, which must be the source.
     * 
     * @param source        The name of the node to start at
     * @param destination   The name of the node to end at
     * @return              The length of the path and a vector containing the path
     */
    PathOut * djikstra(int source, int destination){

        if(!getNode(source) or !getNode(destination))
            return nullptr;

        std::vector<ShortStruct*> q;
        std::vector<int> visited;
        ShortStruct* current;
        ShortStruct* first = new ShortStruct;
        first->node = getNode(source);
        q.push_back(first);
        int index = 0;
        int found = 0;
        int distance = 0;
        int new_dist;

        while(q.size() != 0){
            // Determine which value in the queue is lowest
            index = 0;
            for(int i = 1; i < q.size(); i++){
                // Change the target index if a lower value is found
                if(q.at(i)->dist < q.at(index)->dist)
                    index = i;
            }
            current = q.at(index);      

            // Pop the current value from the queue and mark it as visited
            q.erase(q.begin()+index);
            visited.push_back(current->node->name);

            if(current->node->name == destination){
                break;
            }

            // Add or update non-visited children
            for(int i = 0; i < current->node->connections.size(); i++){

                Node* child_node = current->node->connections.at(i);

                // Ensure the child being observed isn't visited
                if(std::find(visited.begin(), visited.end(), child_node->name) == visited.end()){
                    
                    // Determine if the child is already in the queue
                    ShortStruct* child = nullptr;
                    
                    for(int j = 0; j < q.size(); j++){
                        if(q.at(j)->node->name == child_node->name)
                            child = q.at(j);
                    }
                    
                    // Calculate the distance to the child from the source node
                    new_dist = current->dist + current->node->connections_len.at(i);

                    if(child){
                        // Update the values in the queue
                        if(child->dist > new_dist){
                            child->dist = new_dist;
                            child->parent = current;
                        }
                    }else{
                        // Create a new queue value and add it
                        child = new ShortStruct;
                        child->dist = new_dist;
                        child->parent = current;
                        child->node = current->node->connections.at(i);
                        q.push_back(child);
                    }
                }
            }
        }

        if(current->node->name != destination){
            return nullptr;
        }
        
        PathOut* output = new PathOut;
        output->len = current->dist;
        
        // Create the output path
        while(current->parent){
            // Construct the path by pushing the current node name to the front of the vector
            output->path.insert(output->path.begin(), current->node->name);
            // Set the current node to the parent of this node (we are working backwards)
            current = current->parent;
        }
        // Add the first node's name to the path
        output->path.insert(output->path.begin(), current->node->name);

        return output;
    }

    /**
     * Struct for storing both the graph of the minimum spanning
     * tree and the sum of all edges of the tree.
     * 
     * @param graph Graph of the MST
     * @param sum   Sum of all edges of the MST
     */
    struct MinSpanTree{
        Graph* graph;
        int sum = 0;
    };

    /**
     * Returns the Minimum Spanning Tree of the graph.
     * 
     * The program first ensures both nodes are in the graph. Then, the source
     * node is added to the queue. The following runs looped:
     * 
     * The node who is the shortest distance from its parent is selected from the queue. This node
     * is then added a new graph with an edge connecting it with its parent. The node is then
     * scanned for children. If there are children, each child is checked if it is visited
     * or if the child is already in the queue. If the child is visited, it is skipped. If
     * the child is not in the queue, it is added with the distance from the current node to that
     * node. If it is in the queue, the node's distance is modified if the distance from
     * the parent node is shorter than what is currently listed.
     * 
     * This is ran until the queue is empty. If not all nodes are visited, null values are returned.
     * If all nodes are visited, the new graph is returned alongside the sum of all edges.
     * 
     * @return  The graph containing the MST of this graph.
     */
    MinSpanTree * prim(){

        ShortStruct* current = nullptr;
        ShortStruct* first = new ShortStruct;
        first->node = graph.at(0);
        Graph* mst = new Graph(first->node->name);
        std::vector<int> visited;
        std::vector<Node*> branches;
        std::vector<ShortStruct*> q;
        q.push_back(first);
        int sum = 0;

        while(q.size() != 0){

            // Determine which value in the queue is lowest
            int index = 0;
            for(int i = 1; i < q.size(); i++){
                // Change the target index if a lower value is found
                if(q.at(i)->dist < q.at(index)->dist)
                    index = i;
            }

            current = q.at(index);
            sum = sum + current->dist;

            if(current->parent){
                mst->addNode(current->node->name);
                mst->addEdge(current->parent->node->name, current->node->name, current->dist);
            }

            // Pop the current value from the queue and mark it as visited
            q.erase(q.begin()+index);
            visited.push_back(current->node->name);

            // Add or update non-visited children
            for(int i = 0; i < current->node->connections.size(); i++){

                Node* child_node = current->node->connections.at(i);

                // Ensure the child being observed isn't visited
                if(std::find(visited.begin(), visited.end(), child_node->name) == visited.end()){
                    
                    // Determine if the child is already in the queue
                    ShortStruct* child = nullptr;
                    
                    for(int j = 0; j < q.size(); j++){
                        if(q.at(j)->node->name == child_node->name)
                            child = q.at(j);
                    }
                    
                    // Calculate the distance to the child from the source node
                    int new_dist = current->node->connections_len.at(i);

                    if(child){
                        // Update the values in the queue
                        if(child->dist > new_dist){
                            child->dist = new_dist;
                            child->parent = current;
                        }
                    }else{
                        // Create a new queue value and add it
                        child = new ShortStruct;
                        child->dist = new_dist;
                        child->parent = current;
                        child->node = current->node->connections.at(i);
                        q.push_back(child);
                    }
                }
            }
        }

        MinSpanTree* tree = new MinSpanTree;
        // Return a nullptr if not all nodes were accessed
        if(visited.size() != graph.size()){
            tree->graph = nullptr;
            tree->sum = INT_MAX;
        }else{
            tree->graph = mst;
            tree->sum = sum;
        }

        return tree;
    }

private:
    // Vector which holds the graph nodes
    std::vector<Node*> graph;

    /**
     * Function used for finding a node based on its name.
     * 
     * @param name  Name of the node to search for
     * @return      The node the name represents
     */
    Node* getNode(int name){
        for(int i = 0; i < graph.size(); i++){
            if(graph.at(i)->name == name)
                return graph.at(i);
        }
        return nullptr;
    }

    /**
     * Structure for storing the distance to a node and the parent of
     * the node. Used to queue for shortest path algorithm.
     * 
     * @param node      The node the structure is defined by
     * @param parent    The parent structure that has the shortest path to the node
     * @param dist      The distance to this node from the source node
     */
    struct ShortStruct{
        Node* node = nullptr;
        ShortStruct* parent = nullptr;
        int dist = 0;   
    };
};