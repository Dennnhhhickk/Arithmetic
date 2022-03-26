//
//  zip.cpp
//  arithmetic
//
//  Created by Денис Ядерцов on 26.03.2022.
//

#include "zip.hpp"
#include <iostream>
Zip::Zip() {
    sum = N;
    for (int i = 0; i < N; ++i) {
        a[i] = i;
    }
    zip = "";
}

Zip::Zip(std::string _s) {
    sum = N;
    for (int i = 0; i < N; ++i) {
        a[i] = i;
    }
    zip = "";
    for (int i = 0; i < _s.size(); ++i) {
//        std::cout << i << ' ' << (i * 100.0) / _s.size() << "%" << std::endl;
        add(_s[i], (i == _s.size() - 1));
    }
}

Zip::~Zip() {
    
}

int Zip::search(int b) {
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

std::string Zip::add(char ch, bool mod) {
    std::string s = "";
    int l = 0, r = a[255];
    while (search(r) - search(l) > 1) {
        int m = (r + l) / 2;
        if (int(ch) < search(m)) {
            s += "0";
            r = m;
        } else {
            s += "1";
            l = m;
        }
        if (mod) {
//            std::cout << l << ' ' << r << '\n' << search(l) << ' ' << search(r) << std::endl;
        }
    }
    for (int i = 0; i < 256; ++i) {
        if (i > ch) {
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
    
    zip += s;
    return s;
}

std::string Zip::get_string() {
    return zip;
}
