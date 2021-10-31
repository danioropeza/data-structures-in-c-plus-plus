#include "Hash.h"

template<typename T, int TAM>
Hash<T, TAM>::Hash() {


}
template<typename T, int TAM>
int Hash<T, TAM>::GetHashValue(T element) {
	string word = element;
	transform(word.begin(), word.end(), word.begin(), tolower);
	word[0] = toupper(word[0]);
	int ascii_sum = 0;
	for (int i = 0; i < word.length(); i++) {
		ascii_sum += (int(word[i]) * pow(2, i));
	}
	return ascii_sum % TAM;
}
template<typename T, int TAM>
void Hash<T, TAM>::Insert(T element) {
	int index = GetHashValue(element);
	if (hash[index] == NULL) {
		hash[index] = new List8<T>();
	}
	hash[index]->AddBack(element);
}
template<typename T, int TAM>
void Hash<T, TAM>::Delete(T element) {
	int index = GetHashValue(element);
	if (hash[index] != NULL) {
		hash[index]->Delete(element);
		hash[index] = NULL;
	}
}
template<typename T, int TAM>
Triple<T>* Hash<T, TAM>::Search(T element) {
	int index = GetHashValue(element);
	if (hash[index] != NULL) {
		return hash[index]->Search(element);
	}
	return NULL;
}
template<typename T, int TAM>
void Hash<T, TAM>::Show() {
	for (int index = 0; index < TAM; index++) {
		if (hash[index] != NULL) {
			hash[index]->Show();
		}
	}
	cout << endl;
}
