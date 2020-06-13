#include <string>
#include <unordered_map>
#include "header.h"

std::string DES::BinHex(std::string s){
    std::unordered_map<std::string,std::string> dico; // dictionnary matching between binary and hexadecimal

    dico["0000"] = "0";
    dico["0001"] = "1";
    dico["0010"] = "2";
    dico["0011"] = "3";
    dico["0100"] = "4";
    dico["0101"] = "5";
    dico["0110"] = "6";
    dico["0111"] = "7";
    dico["1000"] = "8";
    dico["1001"] = "9";
    dico["1010"] = "A";
    dico["1011"] = "B";
    dico["1100"] = "C";
    dico["1101"] = "D";
    dico["1110"] = "E";
    dico["1111"] = "F";

    std::string hexadecimal = "";
    for (auto i(0); i < s.length(); i += 4) {
        std::string ch = "";
        ch += s[i];
        ch += s[i + 1];
        ch += s[i + 2];
        ch += s[i + 3];
        hexadecimal += dico[ch];
    }
    return hexadecimal;
}
