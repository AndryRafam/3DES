/* Andry RAFAM ANDRIANJAFY - TDES (Triple Data Encryption Standard) program.
 * 
 * OS: Linux Xubuntu 20.04 LTS (focal fossa)
 * 
 * Compiler version: gcc/g++ 9.3.0 */
 
 
#include <iostream>
#include <algorithm>
#include <ctime>
#include "../Tools/header.h"

int main(){
	
	DES des;
	system("clear");
	
	std::cout << "    ========================================    " << std::endl << std::endl;
	std::cout << "         Andry RAFAM ANDRIANJAFY - TDES         " << std::endl << std::endl;
	std::cout << "    ========================================    " << std::endl;
					   
	std::string plaintext;
	std::cout << std::endl << "[ Clear Text ] -> ";
	std::getline(std::cin,plaintext); 

	srand(time(0));
	
	// Fisher-Yates shuffle algorithm
	for(auto i = plaintext.length()-1; i > 0; i--){
		int j = rand()%(i+1);
		std::swap(plaintext[i],plaintext[j]);
	}
	
	des.Func(plaintext);
	
	return 0;
}
