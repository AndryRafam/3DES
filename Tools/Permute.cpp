#include <string>
#include "header.h"

std::string DES::permute(std::string key, int *arr, int n){
    std::string per = "";
    for(auto i(0); i < n; i++){
        per += key[arr[i]-1];
    }
    return per;
}
