#include <string>
#include "header.h"

std::string DES::Xor(std::string a, std::string b){
    std::string res = "";
    for (auto i(0); i < a.size(); i++){
        if (a[i] == b[i]){
            res += "0";
        }
        else{
            res += "1";
        }
    }
    return res;
}
