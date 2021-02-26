template<typename T>
struct Node{
    T value;
    char key[5];
    Node<T> * next_node = nullptr;
};