// Copyright 2024 Gleb Zaharov

#pragma once

#include <stdlib.h>
#include <iostream>
#include "../lib_tlist/tlist.h"

typedef typeof(sizeof(0)) size_t;

size_t pow(size_t n, size_t k) {
    if (k == 0) return 1;

    size_t res = n;
    for (size_t i = 0; i < k-1; i++)
        res *= n;
    return res;
}

class CMonom {
    size_t _coef;
    size_t _p1, _p2, _p3;

 public:
    CMonom(size_t coef, size_t p1, size_t p2, size_t p3) {
        _coef = coef;
        _p1 = p1;
        _p2 = p2;
        _p3 = p3;
    }

    size_t get_coef() { return _coef; }
    size_t get_p1() { return _p1; }
    size_t get_p2() { return _p2; }
    size_t get_p3() { return _p3; }

    CMonom operator= (CMonom const& m) {
        _coef = m._coef;
        _p1 = m._p1;
        _p2 = m._p2;
        _p3 = m._p3;

        return *this;
    }

    bool operator== (CMonom const& m) {
        if (_p1 == m._p1 && _p2 == m._p2 && _p3 == m._p3)
            return true;
        return false;
    }
    bool operator!= (CMonom const& m) {
        return !(*this == m);
    }

    bool operator> (CMonom const& m) {
        if (_p1 < m._p1) return false;
        else if (_p1 > m._p1) return true;

        if (_p2 < m._p2) return false;
        else if (_p1 > m._p2) return true;

        if (_p3 <= m._p3) return false;
        return true;
    }

    bool operator< (CMonom const& m) {
        if (_p1 > m._p1) return false;
        else if (_p1 < m._p1) return true;

        if (_p2 > m._p2) return false;
        else if (_p1 < m._p2) return true;

        if (_p3 >= m._p3) return false;
        return true;
    }

    CMonom operator+ (CMonom const& m) {
        if (*this != m) throw std::logic_error("Monoms are not similar");
        return CMonom(_coef+m._coef, _p1, _p2, _p3);
    }
    CMonom operator- (CMonom const& m) {
        if (*this != m) throw std::logic_error("Monoms are not similar");
        return CMonom(_coef-m._coef, _p1, _p2, _p3);
    }
    CMonom operator* (CMonom const& m) {
        return CMonom(_coef*m._coef, _p1+m._p1, _p2+m._p2, _p3+m._p3);
    }
    CMonom operator/ (CMonom const& m) {
        return CMonom(_coef/m._coef, _p1-m._p1, _p2-m._p2, _p3-m._p3);
    }

    CMonom operator-() const {
        return CMonom(-_coef, _p1, _p2, _p3);
    }

    CMonom operator*(size_t n) {
        return CMonom(_coef*n, _p1, _p2, _p3);
    }
    CMonom operator/(size_t n) {
        return CMonom(_coef/n, _p1, _p2, _p3);
    }

    CMonom operator+= (CMonom const& m) {
        if (*this != m) throw std::logic_error("Monoms are not similar");
        _coef += m._coef;
        return *this;
    }
    CMonom operator-= (CMonom const& m) {
        if (*this != m) throw std::logic_error("Monoms are not similar");
        _coef -= m._coef;
        return *this;
    }
    CMonom operator*= (CMonom const& m) {
        _coef *= m._coef;
        _p1 += m._p1;
        _p2 += m._p2;
        _p3 += m._p3;
        return *this;
    }
    CMonom operator/= (CMonom const& m) {
        _coef /= m._coef;
        _p1 -= m._p1;
        _p2 -= m._p2;
        _p3 -= m._p3;
        return *this;
    }

    size_t calc(size_t x, size_t y, size_t z) {
        return _coef * pow(x, _p1) * pow(y, _p2) * pow(z, _p3);
    }
};

class CPolinom {
    TList<CMonom> monoms;

    CPolinom() {
        monoms = TList<CMonom>();
    }
};
