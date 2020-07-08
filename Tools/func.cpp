#include <iostream>
#include <sstream>
#include "../Tools/header.h"

void DES::Func(std::string plaintext){
	std::string bloc;
	std::string hexa = "";
	for(auto i(0); i < plaintext.size(); i++){
		std::stringstream my_ps;
		my_ps << std::uppercase << std::hex << int(plaintext[i]);
		hexa+=my_ps.str();
	}
	if(hexa.size() < 16){ // If size of the hexa text is less than 16 (64 bits); pad with random hexadecimal character
		std::cout << std::endl << "[ Encrypted Text ] -> ";
		hexa = Padding(hexa);
		std::cout << Triple_DES_Encrypt(hexa);
		std::cout << std::endl << std::endl;
	}
	else if(hexa.size() > 16){ // ECB mode (Crack the message in 64 bits each - 16 hexadecimal numbers)
		std::cout << std::endl << "[ Encrypted Text ] -> ";
		for(auto i(0); i < hexa.size(); i+=16){
			bloc = hexa.substr(i,16);
			if(bloc.size() < 16){ // If size of the final bloc is less than 16 (64 bits); pad the bloc with random hexadecimal character
				bloc = Padding(bloc);
			}
			std::cout << Triple_DES_Encrypt(bloc) << "  ";
		}
		std::cout << std::endl << std::endl;
	}
	else{ // If hexa size == 16 (64 bits)
		std::cout << std::endl << "[ Encrypted Text ] -> " << Triple_DES_Encrypt(hexa) << std::endl << std::endl;
    }
    return;
}
DES::~DES(void){}
