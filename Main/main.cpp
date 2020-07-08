/* Andry RAFAM ANDRIANJAFY - TDES (Triple Data Encryption Standard) program.
 * 
 * Compiler version: gcc/g++ 9.3.0 */
 
 
#include <iostream>
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
	
	des.Func(plaintext);
	
	return 0;
}
