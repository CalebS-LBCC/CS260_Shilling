template<typename T>
struct Node{
    T value;
    Node<T> * next_node = nullptr;
};