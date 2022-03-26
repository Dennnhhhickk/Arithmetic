//
//  Unzip.cpp
//  arithmetic
//
//  Created by Денис Ядерцов on 26.03.2022.
//

#include "Unzip.hpp"

Unzip::Unzip() {
    sum = N;
    for (int i = 0; i < N; ++i) {
        a[i] = i;
    }
    unzip = "";
}

Unzip::Unzip(std::string _s) {
    sum = N;
    for (int i = 0; i < N; ++i) {
        a[i] = i;
    }
    unzip = "";
    add(_s);
}


Unzip::~Unzip() {
    
}

int Unzip::search(int b) {
    int l = 0, r = 256;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (a[m] > b) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

std::string Unzip::add(std::string _s) {
    std::string s = "";
    int k = 0;
    while (k < _s.size()) {
        int l = 0, r = a[255];
        while (search(r) - search(l) > 1) {
            int m = (l + r) / 2;
            if (_s[k] == '0') {
                r = m;
            } else {
                l = m;
            }
            ++k;
        }
        int tmp = search(l);
        s += char(tmp);
        for (int i = 0; i < 256; ++i) {
            if (i > tmp) {
                ++a[i];
            }
        }
        if (sum + 1 == MAX) {
            sum = 0;
            for (int i = 1; i < 256; ++i) {
                a[i] = (a[i] + a[i - 1] + 1) / 2;
                sum += a[i];
            }
        } else {
            ++sum;
        }
    }
    unzip += s;
    return s;
}

std::string Unzip::get_string() {
    return unzip;
}
