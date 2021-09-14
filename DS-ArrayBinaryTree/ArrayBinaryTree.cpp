#include "ArrayBinaryTree.h"

template<typename T, int TAM>
ArrayBinaryTree<T, TAM>::ArrayBinaryTree() {
	array_[0] = NULL;
	for (int index = 1; index < TAM; index++) {
		array_[index] = new Value<int>();
	}
}

template<typename T, int TAM>
bool ArrayBinaryTree<T, TAM>::Insert(T element, T father, int rootIndex) {
	bool res = false;
	if (!array_[1]->exist()) {
		array_[1]->set_element(element);
		array_[1]->set_exist(true);
		return true;
	}
	if (!array_[rootIndex]->exist()) {
		return false;
	}
	if (array_[rootIndex]->element() == father) {
		if (!array_[rootIndex * 2]->exist()) {
			array_[rootIndex * 2]->set_element(element);
			array_[rootIndex * 2]->set_exist(true);
			return true;
		}
		else {
			array_[rootIndex * 2 + 1]->set_element(element);
			array_[rootIndex * 2 + 1]->set_exist(true);
			return true;
		}
	} else {
		res = Insert(element, father, rootIndex * 2);
		if (!res) {
			res = Insert(element, father, rootIndex * 2 + 1);
		}
	}
	return res;
}
template<typename T, int TAM>
int ArrayBinaryTree<T, TAM>::Count(int index) {
	if (!array_[index]->exist()) {
		return 0;
	}
	return Count(index * 2) + Count(index * 2 + 1) + 1;
}
template<typename T, int TAM>
int ArrayBinaryTree<T, TAM>::CalculateHeight(int index) {
	if (!array_[index]->exist()) {
		return 0;
	}
	int leftSideHeight = CalculateHeight(index * 2);
	int rightSideHeight = CalculateHeight(index * 2);
	if (leftSideHeight > rightSideHeight) {
		return leftSideHeight + 1;
	} else {
		return rightSideHeight + 1;
	}
}
template<typename T, int TAM>
void ArrayBinaryTree<T, TAM>::ShowInOrder(int root) {
	if (array_[root]->exist() == false) {
		return;
	} else {
		ShowInOrder(root * 2);
		cout << array_[root]->element() << " ";
		ShowInOrder(root * 2 + 1);
	}
}
template<typename T, int TAM>
void ArrayBinaryTree<T, TAM>::ShowPreOrder(int root) {
	if (!array_[root]->exist()) {
		return;
	}
	cout << array_[root]->element() << " ";
	ShowPreOrder(root * 2);
	ShowPreOrder(root * 2 + 1);
}
template<typename T, int TAM>
void ArrayBinaryTree<T, TAM>::ShowPostOrder(int root) {
	if (!array_[root]->exist()) {
		return;
	}
	ShowPostOrder(root * 2);
	ShowPostOrder(root * 2 + 1);
	cout << array_[root]->element() << " ";
}