# DSU

## Description
1. Array of unique numbers.
2. Numbers can be joined into subarray.
3. Each subarray has the representer - some number in this array.
4. Initially, each number in DSU is a subarray
5. Subarrays can be joined into one

## Methods
- `void make_set(el: size_t)` - add an `el` into the DSU
- `size_t find(el: size_t)` - find an `el` in the DSU. Returns the representer of a subarray
- `void join(el1: size_t, el2: size_t)` - join subarrays with `el1` and `el2` into one
