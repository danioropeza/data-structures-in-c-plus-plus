#include "Heap.h"

template<typename T, int TAM>
Heap<T, TAM>::Heap() {
	last_leaf_ = -1;
}
template<typename T, int TAM>
void Heap<T, TAM>::Insert(T element) {
	if (last_leaf_ == -1) {
		last_leaf_ = 1;
		heap_[1] = new Node<T>(element);
	} else {
		last_leaf_ += 1;
		heap_[last_leaf_] = new Node<T>(element);
		RecoverUpDown(last_leaf_);
	}
}
template<typename T, int TAM>
void Heap<T, TAM>::RecoverUpDown(int leaf) {
	if (leaf != 1 && heap_[leaf / 2]->exist()) {
		if (heap_[leaf]->element() > heap_[leaf / 2]->element()) {
			T aux = heap_[leaf / 2]->element();
			heap_[leaf / 2]->set_element(heap_[leaf]->element());
			heap_[leaf]->set_element(aux);
			RecoverUpDown(leaf / 2);
		}
	}
}
template<typename T, int TAM>
T Heap<T, TAM>::DeleteFirst() {
	T mayor;
	if (last_leaf_ == -1) {
		return -1;
	} else {
		mayor = heap_[1]->element();
		heap_[1]->set_element(heap_[last_leaf_]->element());
		heap_[last_leaf_]->set_exist(false);
		last_leaf_ -= 1;
		RecoverDownUp(1);
	}
}
template<typename T, int TAM>
void Heap<T, TAM>::RecoverDownUp(int leaf) {
	if (heap_[leaf * 2]->exist()) {
		int theMayor;
		if (!heap_[leaf * 2 + 1]->exist() || heap_[leaf * 2 + 1] == NULL || heap_[leaf * 2]->element() > heap_[leaf * 2 + 1]->element()) {
			theMayor = leaf * 2;
		}
		else
		{
			theMayor = leaf * 2 + 1;
		}
		cout << heap_[leaf]->element() << endl;
		cout << heap_[theMayor]->element() << endl;
		if (heap_[leaf]->element() < heap_[theMayor]->element()) {
			T aux = heap_[theMayor]->element();
			heap_[theMayor]->set_element(heap_[leaf]->element());
			heap_[leaf]->set_element(aux);
			RecoverUpDown(theMayor);
		}
	}
}
template<typename T, int TAM>
void Heap<T, TAM>::Show() {
	if (last_leaf_ == -1) {
		return;
	}
	for (int i = 1; i <= last_leaf_; i++) {
		cout << heap_[i]->element() << endl;
	}
}