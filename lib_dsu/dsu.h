// Copyright 2024 Gleb Zaharov

#pragma once

#include <stdlib.h>
#include <iostream>
#include "../lib_tlist/tlist.h"

typedef typeof(sizeof(0)) size_t;


class DSU {
  TList<size_t> elements;
  TList<size_t> group;

  DSU() {
    elements = TList<size_t>();
    group = TList<size_t>();
  }

  void make_set(size_t el);

  size_t find(size_t el);

  void join(size_t el1, size_t el2);
};
