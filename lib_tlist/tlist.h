// Copyright 2024 Gleb Zaharov

using size_t = decltype(sizeof(0));

template<typename T>
class Node {
    T _value;
    Node* _nptr;

  public:
    Node(T value) {
        _value = value;
        _nptr = nullptr;
    }

    void set_next(Node* node) { _nptr = node; }
    Node* get_next() { return _nptr; }
    T get_val() { return _value; }
};

template<typename T>
class TList {
    Node<T>* _head;
    Node<T>* _tail;

  public:
    TList() {
        _head = nullptr;
        _tail = nullptr;
    }

    ~TList() {
        Node<T>* ptr = _head;
        while (ptr != nullptr) {
            Node<T>* nptr = ptr->get_next();
            delete ptr;
            ptr = nptr;
        }
    }

    void add_front(T value) {
        Node<T>* node = new Node(value);
        if (_tail == nullptr)
            _tail = node;
        else
            node->set_next(_head);
        _head = node;
    }

    void add_back(T value) {
        Node<T>* node = new Node(value);
        if (_head == nullptr)
            _head = node;
        else
            _tail->set_next(node);
        _tail = node;
    }

    T get(size_t pos) {
        Node<T>* ptr = _head;
        for (int i = 0; i < pos; i++)
            ptr = ptr->get_next();
        return ptr->get_val();
    }
};
