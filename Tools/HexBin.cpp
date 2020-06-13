#include <string>
#include <unordered_map>
#include "header.h"

DES::DES(void){}

std::string DES::HexBin(std::string s){
    std::unordered_map<char, std::string> dico; // dictionnary matching between hexadecimal and binary

    dico['0'] = "0000";
    dico['1'] = "0001";
    dico['2'] = "0010";
    dico['3'] = "0011";
    dico['4'] = "0100";
    dico['5'] = "0101";
    dico['6'] = "0110";
    dico['7'] = "0111";
    dico['8'] = "1000";
    dico['9'] = "1001";
    dico['A'] = "1010";
    dico['B'] = "1011";
    dico['C'] = "1100";
    dico['D'] = "1101";
    dico['E'] = "1110";
    dico['F'] = "1111";

    std::string binary = "";
    for (auto i(0); i < s.size(); i++) {
        binary += dico[s[i]];
    }
    return binary;
}
