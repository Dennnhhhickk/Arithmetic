//
//  Unzip.hpp
//  arithmetic
//
//  Created by Денис Ядерцов on 26.03.2022.
//

#ifndef Unzip_hpp
#define Unzip_hpp

#include <string>

class Unzip {
    const int MAX = 1000;
    const int N = 256;
    std::string unzip;
    int a[256];
    int sum;
    
    int search(int);
public:
    Unzip();
    Unzip(std::string);
    std::string add(std::string);
    std::string get_string();
    ~Unzip();
};

#endif /* Unzip_hpp */
