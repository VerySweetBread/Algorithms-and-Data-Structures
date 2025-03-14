// Copyright 2024 Gleb Zaharov

#pragma once

#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include "../lib_tlist/tlist.h"

typedef typeof(sizeof(0)) size_t;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))


class DSU {
  TList<size_t> _elements;
  TList<size_t> _group;

 public:
  DSU() {
    _elements = TList<size_t>();
    _group = TList<size_t>();
  }

  explicit DSU(size_t n) {
    _elements = TList<size_t>();
    _group = TList<size_t>();

    for (size_t i = 1; i <= n; i++)
      make_set(i);
  }

  void make_set(size_t el) {
    try {
      find(el);
    } catch (...) {
      _elements.add_back(el);
      _group.add_back(el);
      return;
    }

    throw std::invalid_argument("This element already in DSU");
  }

  size_t find(size_t el) {
    for (size_t i = 0; i < _elements.get_len(); i++) {
      if (_elements.get(i) == el) return _group.get(i);
    }

    throw std::invalid_argument("This element was not found");
  }

  void join(size_t el1, size_t el2) {
    size_t i = find(el1);
    size_t j = find(el2);

    size_t from = MAX(i, j);
    size_t to = MIN(i, j);

    for (size_t i = 0; i < _group.get_len(); i++) {
      if (_group.get(i) == from) _group.set(i, to);
    }
  }
};
