#include <vector>
#include <bits/stdc++.h>
struct Node{
    int name;
    std::vector<Node*> connections;
    std::vector<int> connections_len;
};