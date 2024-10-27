// Copyright 2024 Gleb Zaharov

#pragma once
#include "../lib_tdarray/tdarray.h"

template<typename T>
class TVector {
  TArchive<T> _data;

 public:
  TVector(const T* arr, size_t n): _data(arr, n) {}
  TVector(const TVector<T>& v): _data(v._data) {}

  const T& operator[] (size_t idx) const { _data.get(idx); }
  bool operator== (const TVector& v) const noexcept {
    if (_data.len() != v._data.len()) return false;
    for (int i = 0; i < _data.len(); i++) {
      if (_data.get(i) != v._data.get(i)) return false;
    }
    return true;
  }
  TVector operator+ (const TVector v) {
    if (_data.len() != v._data.len())
      throw std::invalid_argument("Vectors have different size");
    for (int i = 0; i < _data.len(); i++)
      _data.update(i, _data.get(i) + v._date.get(i));
    return *this;
  }
  TVector operator- (const TVector v) {
    if (_data.len() != v._data.len())
      throw std::invalid_argument("Vectors have different size");
    for (int i = 0; i < _data.len(); i++)
      _data.update(i, _data.get(i) - v._date.get(i));
    return *this;
  }
  TVector operator* (const T val) noexcept {
    for (int i = 0; i < _data.len(); i++)
      _data.update(i, _data.get(i) * val);
    return *this;
  }
  TVector operator= (const T val) noexcept {
    for (int i = 0; i < _data.len(); i++)
      _data.update(i, val);
    return *this;
  }

  void append(T val) { _data.puah_back(val); }
};

