#include "List.h"
#include <string>
#include <iostream>
#include <cstring>

int main () {

	std::string abc = "abc";
	char * str = new char [3];
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	size_t i = 0;

	if (! strcmp (str, abc.c_str())) {
		std::cout << "Equal !";
	}

	pr::List list;
	list.push_front(abc);
	list.push_front(abc);

	std::cout << "Liste : " << list << std::endl;
	std::cout << "Taille : " << list.size() << std::endl;

	// Affiche à l'envers
	for (i= list.size() ; i > 0 ; i--) {     //FAUTE : iLes "i" négatifs doivent être évités.
		std::cout << "elt " << i - 1<< ": " << list[i - 1] << std::endl;
	}


	// Libeler els char de la chaine
//	for (char *cp = str ; *cp ; cp++) {   //FAUTE :"cp" est un pointeur temporaire et n'a pas besoin d'être libéré.
//		delete cp;							//		Il nous suffit d'utiliser delete[] str ;
//	}
	// et la chaine elle meme
	delete[] str;
}
