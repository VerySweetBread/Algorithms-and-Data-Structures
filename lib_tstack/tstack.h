// Copyright 2024 Gleb Zaharov

#include "../lib_tdarray/tdarray.h"

template<typename T>
class TStack {
    TArchive<T> _data;
    size_t _size;

 public:
    TStack(size_t size);

    void push(T item);
    T pop();

    bool is_empty();
};

template<typename T>
TStack<T>::TStack(size_t size) {
    TArchive<T> _data;
    _size = size;
}

template<typename T>
void TStack<T>::push(T item) {
    if (_data.len() == _size)
        throw std::logic_error("Max size achived");
    _data.push_back(item);
}

template<typename T>
T TStack<T>::pop() {
    return _data.pop_back();
}

template<typename T>
bool TStack<T>::is_empty() {
    return _data.len() == 0;
}
