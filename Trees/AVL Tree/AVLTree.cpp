#include "AVLTree.h"

template<typename T>
AVLTree<T>::AVLTree() {
	root_ = NULL;
}
template<typename T>
void AVLTree<T>::ExampleDeleteLater() {
	RotateLeft(root_);
}
template<typename T>
void AVLTree<T>::Insert(T element) {
	bool conti = false;
	InsertImpl(root_, element, conti);
}
template<typename T>
void AVLTree<T>::InsertImpl(Node<T>*& root_iterator, T element, bool& conti) {
	if (root_iterator == NULL)
	{
		root_iterator = new Node<T>(element);
		conti = true;
	} else {
		if (element < root_iterator->element()) {
			InsertImpl(root_iterator->left(), element, conti);
			if (conti == true) {
				root_iterator->set_factor(root_iterator->factor() + 1);
				if (root_iterator->factor() == 0) {
					conti = false;
				} else {
					if (root_iterator->factor() == 2) {
						conti = false;
						if (root_iterator->left()->factor() == 1) {
							RotateRight(root_iterator);
						} else {
							RotateRightComposed(root_iterator);
						}
					}
				}
			}
		}

		else //(element > root_iterator->element())
		{
			InsertImpl(root_iterator->right(), element, conti);
			if (conti == true) {
				root_iterator->set_factor(root_iterator->factor() - 1);
				if (root_iterator->factor() == 0) {
					conti = false;
				} else {
					if (root_iterator->factor() == -2) {
						conti = false;
						if (root_iterator->right()->factor() == -1) {
							RotateLeft(root_iterator);
						} else {
							RotateLeftComposed(root_iterator);
						}
					}
				}
			}
		}
	}
}
template<typename T>
void AVLTree<T>::RotateLeft(Node<T>*& root_iterator) {
	Node<T>* new_root = root_iterator->right();
	Node<T>* temporary;
	if (new_root->left() != NULL) {
		temporary = new_root->left();
	}
	else {
		temporary = NULL;
	}
	new_root->left() = root_iterator;
	root_iterator->right() = temporary;
	root_iterator = new_root;
	root_iterator->set_factor(0);
	root_iterator->left()->set_factor(0);
}
template<typename T>
void AVLTree<T>::RotateRight(Node<T>*& root_iterator) {
	Node<T>* new_root = root_iterator->left();
	Node<T>* temporary;
	if (new_root->right() != NULL) {
		temporary = new_root->right();
	} else {
		temporary = NULL;
	}
	new_root->right() = root_iterator;
	root_iterator->left() = temporary;
	root_iterator = new_root;
	root_iterator->set_factor(0);
	root_iterator->right()->set_factor(0);
}
template<typename T>
void AVLTree<T>::RotateLeftComposed(Node<T>*& root_iterator)
{
	Node<T>* newRoot = root_iterator->right()->left();
	Node<T>* temp_l = newRoot->left();
	Node<T>* temp_r = newRoot->right();
	newRoot->right() = root_iterator->right();
	newRoot->left() = root_iterator;
	newRoot->left()->right() = temp_l;
	newRoot->right()->left() = temp_r;
	root_iterator = newRoot;
	if (root_iterator->factor() == 0)
	{
		root_iterator->left()->set_factor(0);
		root_iterator->right()->set_factor(0);
	}
	else
	{
		if (root_iterator->factor() == -1)
		{
			root_iterator->left()->set_factor(1);
			root_iterator->right()->set_factor(0);
			root_iterator->set_factor(0);
		}
		else
		{
			root_iterator->left()->set_factor(0);
			root_iterator->right()->set_factor(-1);
			root_iterator->set_factor(0);
		}
	}
}
template<typename T>
void AVLTree<T>::RotateRightComposed(Node<T>*& root_iterator)
{
	Node<T>* newRoot = root_iterator->left()->right();
	Node<T>* temp_l = newRoot->left();
	Node<T>* temp_r = newRoot->right();
	newRoot->left() = root_iterator->left();
	newRoot->right() = root_iterator;
	newRoot->left()->right() = temp_l;
	newRoot->right()->left() = temp_r;
	root_iterator = newRoot;
	if (root_iterator->factor() == 0)
	{
		root_iterator->left()->set_factor(0);
		root_iterator->right()->set_factor(0);
	}
	else
	{
		if (root_iterator->factor() == 1)
		{
			root_iterator->left()->set_factor(0);
			root_iterator->right()->set_factor(-1);
			root_iterator->set_factor(0);
		}
		else
		{
			root_iterator->left()->set_factor(1);
			root_iterator->right()->set_factor(0);
			root_iterator->set_factor(0);
		}
	}
}
template<typename T>
int AVLTree<T>::Count() {
	return CountImpl(root_);
}
template<typename T>
int AVLTree<T>::CountImpl(Node<T>*& root_iterator) {
	int result;
	if (root_iterator == NULL)
	{
		result = 0;
	}
	else
	{
		int left_count = CountImpl(root_iterator->left());
		int right_count = CountImpl(root_iterator->right());
		result = left_count + right_count + 1;
	}
	return result;
}
template<typename T>
void AVLTree<T>::Show2D() {
	Show2DImpl(root_);
}
template<typename T>
void AVLTree<T>::Show2DImpl(Node<T>* root_iterator) {
	Show2DUtil(root_iterator, 0);
}
template<typename T>
void AVLTree<T>::Show2DUtil(Node<T>* root_iterator, int space) {
	if (root_iterator == NULL) {
		//cout << "null";
		return;
	}
	space += SPACES;
	Show2DUtil(root_iterator->right(), space);
	cout << endl;
	for (int i = SPACES; i < space; i++) {
		cout << " ";
	}
	cout << root_iterator->element() << ":" << root_iterator->factor() << "\n";
	Show2DUtil(root_iterator->left(), space);
}
template<typename T>
void AVLTree<T>::ReadAndInsert()
{
	ifstream file;
	file.open("10000datos.txt");
	T num;
	int iterator = 0;
	while (file >> num && iterator++ < 10000)
	{
		T value = num;
		cout << num << endl;
		//if (num == 7675) {
			//Show2D();
			//return;
		//}
		Insert(value);
	}
	file.close();
}