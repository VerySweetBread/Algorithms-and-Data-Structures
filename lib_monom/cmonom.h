// Copyright 2024 Gleb Zaharov

#pragma once

#include <stdlib.h>
#include <iostream>

typedef typeof(sizeof(0)) size_t;

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
};
