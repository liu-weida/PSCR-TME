#include "list.h"    ////FAUTE :Ne pas introduire "list.h".

namespace pr {

// ******************* Chainon
Chainon::Chainon (const std::string & data, Chainon * next):data(data),next(next) {};

size_t Chainon::length() {
	size_t len = 1;
	if (next != nullptr) {
		len += next->length();
	}
	return len;  //FAUTE :Devrait renvoyer len au lieu de s'appeler lui-même récursivement.
}

void Chainon::print (std::ostream & os) const{  //FAUTE :Manque const
	os << data ;
	if (next != nullptr) {
		os << ", ";
		next->print(os);  //FAUTE :S'il est placé à l'extérieur du "si", il en résultera un pointeur nul.
	}

}

// ******************  List
const std::string & List::operator[] (size_t index) const  {
	Chainon * it = tete;
	for (size_t i=0; i < index ; i++) {
		it = it->next;
	}

    if (it == nullptr) { 	//FAUTE :Évite les pointeurs nuls parce que l'"index" est plus grand que la longueur réelle de la table de chaîne.
        throw std::out_of_range("Index out of bounds!");
    }

	return it->data;
}

void List::push_back (const std::string& val) {
	if (tete == nullptr) {
		tete = new Chainon(val);
	} else {
		Chainon * fin = tete;
		while (fin->next) {
			fin = fin->next;
		}
		fin->next = new Chainon(val);
	}
}

//void List::push_front (const std::string& val) {    //FAUTE :Défini dans list.h,il peut être supprimé ici.
//	tete = new Chainon(val,tete);
//}

bool List::empty() {     //FAUTE :Il manque List::
	return tete == nullptr;
}

size_t List::size() const {
	if (tete == nullptr) {
		return 0;
	} else {
		return tete->length();
	}
}



std::ostream & operator<< (std::ostream & os, const pr::List & vec)
{
	os << "[";
	if (vec.tete != nullptr) {
		vec.tete->print (os) ;
	}
	os << "]";
	return os;
}
} // namespace pr  //FAUTE : Le remaniement doit se faire dans un "espace de noms".
