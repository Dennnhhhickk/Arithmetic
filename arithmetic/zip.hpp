//
//  zip.hpp
//  arithmetic
//
//  Created by Денис Ядерцов on 26.03.2022.
//

#ifndef zip_hpp
#define zip_hpp
#include <string>

class Zip {
    const int MAX = 1000;
    const int N = 256;
    std::string zip;
    int a[256];
    int sum;
    
    int search(int);
public:
    Zip();
    Zip(std::string);
    std::string add(char, bool);
    std::string get_string();
    ~Zip();
};

#endif /* zip_hpp */
