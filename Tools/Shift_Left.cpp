#include <string>
#include "header.h"

std::string DES::shift_left(std::string key, int shift){
    std::string s = "";
    for(auto i(0); i < shift; i++){
        for(auto j(1); j < 28;  j++){
            s += key[j];
        }
        s += key[0];
        key = s;
        s = "";
    }
    return key;
}
