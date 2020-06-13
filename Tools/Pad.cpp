#include <string>
#include "header.h"

std::vector<std::string> pad_table = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

std::string DES::Padding(std::string bloc){
	srand(time(0));
	do{
		int x = rand()%16;
		bloc+=pad_table[x];
	}while(bloc.size()!=16);
	return bloc;
}
