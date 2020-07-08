#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "header.h"

std::string DES::Triple_DES_Encrypt(std::string plaintext){	
	// PC1 table
	int PC1[56] = {57, 49, 41, 33, 25, 17, 9,
				   1, 58, 50, 42, 34, 26, 18,
				   10, 2, 59, 51, 43, 35, 27,
				   19, 11, 3, 60, 52, 44, 36,
				   63, 55, 47, 39, 31, 23, 15,
				   7, 62, 54, 46, 38, 30, 22,
				   14, 6, 61, 53, 45, 37, 29,
				   21, 13, 5, 28, 20, 12, 4};
				   
	// PC2 table
    int PC2[48] =  {14, 17, 11, 24, 1, 5,
                    3, 28, 15, 6, 21, 10,
                    23, 19, 12, 4, 26, 8,
                    16, 7, 27, 20, 13, 2,
                    41, 52, 31, 37, 47, 55,
                    30, 40, 51, 45, 33, 48,
                    44, 49, 39, 56, 34, 53,
                    46, 42, 50, 36, 29, 32};
	
	std::vector<std::string> table = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
	srand(time(0));
	std::string key_1 = "";
	std::string key_2 = "";
	std::string key_3 = "";
	
	// Random hexadecimal keys generator 16 Bytes (64 bits)
	while(key_1.length()!=16 && key_2.length()!=16 && key_3.length()!=16){
		int x = rand()%16;
		int y = rand()%16;
		int z = rand()%16;
		key_1+=table[x];
		key_2+=table[y];
		key_3+=table[z];
	}
	
	// ENCRYPTION WITH KEY_1
	key_1 = HexBin(key_1); // hex to bin

	key_1 = permute(key_1, PC1, 56);

	int shift_table[16] = {1, 1, 2, 2,
                           2, 2, 2, 2,
                           1, 2, 2, 2,
                           2, 2, 2, 1};

   

    std::string left_1 = key_1.std::string::substr(0,28);
    std::string right_1 = key_1.std::string::substr(28,28);
	
    std::vector<std::string> RKB_1; // Round keys binary
    std::vector<std::string> RKH_1; // Round keys hexadecimal

    for(auto i(0); i < 16; i++){
    	left_1 = shift_left(left_1,shift_table[i]);
    	right_1 = shift_left(right_1,shift_table[i]);

    	std::string combined_1 = left_1 + right_1;

    	std::string RoundKey_1 = permute(combined_1, PC2, 48);

    	RKB_1.push_back(RoundKey_1);
    	RKH_1.push_back(BinHex(RoundKey_1));
    }
    std::string cipher = Encrypt_Tool(plaintext,RKB_1,RKH_1);
    
    
    //DECRYPTION WITH KEY_2
    key_2 = HexBin(key_2); // hex to bin
    
    key_2 = permute(key_2, PC1, 56);
    
    std::string left_2 = key_2.std::string::substr(0,28);
    std::string right_2 = key_2.std::string::substr(28,28);
    
    std::vector<std::string> RKB_2;
    std::vector<std::string> RKH_2;
    
    for(auto i(0); i < 16; i++){
    	left_2 = shift_left(left_2,shift_table[i]);
    	right_2 = shift_left(right_2,shift_table[i]);

    	std::string combined_2 = left_2 + right_2;

    	std::string RoundKey_2 = permute(combined_2, PC2, 48);

    	RKB_2.push_back(RoundKey_2);
    	RKH_2.push_back(BinHex(RoundKey_2));
    }
    std::reverse(RKB_2.begin(),RKB_2.end());
    std::reverse(RKH_2.begin(),RKH_2.end());
    std::string cipher_2 = Encrypt_Tool(cipher,RKB_2,RKH_2);
    
    
    //ENCRYPTION WITH KEY 3
    key_3 = HexBin(key_3); // hex to bin
    
    key_3 = permute(key_3, PC1, 56);
    
    std::string left_3 = key_3.std::string::substr(0,28);
    std::string right_3 = key_3.std::string::substr(28,28);
    
    
    std::vector<std::string> RKB_3;
    std::vector<std::string> RKH_3;
    
     for(auto i(0); i < 16; i++){
    	left_3 = shift_left(left_3,shift_table[i]);
    	right_3 = shift_left(right_3,shift_table[i]);

    	std::string combined_3 = left_3 + right_3;

    	std::string RoundKey_3 = permute(combined_3, PC2, 48);

    	RKB_3.push_back(RoundKey_3);
    	RKH_3.push_back(BinHex(RoundKey_3));
    }
    std::string cipher_final = Encrypt_Tool(cipher_2,RKB_3,RKH_3);
    return cipher_final;
}

