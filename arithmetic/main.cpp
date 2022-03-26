//
//  main.cpp
//  arithmetic
//
//  Created by Денис Ядерцов on 26.03.2022.
//

#include <iostream>
#include "Zip.hpp"
#include "Unzip.hpp"

int main(int argc, const char *argv[]) {
    std::string s = "";
    for (int i = 0; i < 1000000; ++i) {
        s += char(rand() % ('z' - 'a' + 1) + 'a');
    }
    std::cout << "Created" << std::endl;
    Zip z(s);
    std::cout << "Coded" << std::endl;
    Unzip un(z.get_string());
    std::cout << "Encoded" << std::endl;
//    std::cout << s << std::endl;
//    std::cout << un.get_string() << std::endl;
//    std::cout << z.get_string() << std::endl;
    if (s.size() == un.get_string().size()) {
        std::string tmp = un.get_string();
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != tmp[i]) {
                std::cout << "WRONG!" << std::endl;
                break;
            }
        }
    } else {
        std::cout << "WRONG SIZE! " << s.size() << ' ' << un.get_string().size() << std::endl;
    }
    std::cout << (z.get_string().size() + 7) / 8 << ' ' << s.size() << std::endl;
    return 0;
}
