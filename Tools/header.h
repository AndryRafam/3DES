#ifndef _header_h
#define _header_h

#include <string>
#include <vector>

class DES{
private:
    std::string Xor(std::string a, std::string b); // xor between two string

public:
    DES(void); // constructor
    ~DES(void); // destructor
    std::string HexBin(std::string s); // hexadecimal to binary
    std::string BinHex(std::string s); // binary to hexadecimal
    std::string permute(std::string key, int *arr, int n);
    std::string shift_left(std::string key, int shift);
    //RKB stand for round keys binary, RK stand for round keys hexadecimal
    std::string Encrypt_Tool(std::string plaintext, std::vector<std::string> RKB, std::vector<std::string> RKH);
    std::string Triple_DES_Encrypt(std::string plaintext); // 3 DES encryption algorithm
    std::string Padding(std::string bloc); // Padding function
};

#endif
