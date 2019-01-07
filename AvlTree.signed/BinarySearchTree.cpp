

#include "BinarySearchTree.h"

#include <string>
#include "BinarySearchTree.h"

using namespace std;

// Constructor
BinarySearchTree::BinarySearchTree() : root(nullptr) {

}
// Destructor
BinarySearchTree::~BinarySearchTree() {
	clear();
}

BinaryNode *BinarySearchTree::get_root() const {
	return root;
}

int BinarySearchTree::height() const {
	return height(root);
}

int BinarySearchTree::height(const BinaryNode *ptr) const
{
	// if root is null that is tree is empty reurn -1
    if(ptr == nullptr){
    	return -1;
    }

    //check height of left subtree recursively
    int htOfLeftSubTree = height(ptr->left);
    //checl height of right subtree recursively
    int htOfRightSubTree = height(ptr->right);

    // check max height is of left subtree or right subtree add 1 to it and return
    if(htOfLeftSubTree > htOfRightSubTree)
    {
    	return htOfLeftSubTree + 1;
    }
    else
    {
    	 return htOfRightSubTree + 1;
    }

}

int BinarySearchTree::find_min() const throw(string)
{
    if (is_empty()) throw(string("Empty tree"));
    return find_min(root)->data;
}

BinaryNode *BinarySearchTree::find_min(BinaryNode *ptr) const
{
	BinaryNode* root = ptr;

	 while(root->left != nullptr){
		 root = root->left;
	 }

    return root;
}

int BinarySearchTree::find_max() const throw(string)
{
    if (is_empty()) throw(string("Empty tree"));
    return find_max(root)->data;
}

BinaryNode *BinarySearchTree::find_max(BinaryNode *ptr) const
{
	BinaryNode* root = ptr;

	 while(root->right != nullptr){
		 root = root->right;
	 }

    return root;
}

void BinarySearchTree::clear()
{
    clear(root);
}

void BinarySearchTree::clear(BinaryNode* &ptr)
{
	// ptr to root node is null then return
    if(ptr == nullptr){
    		return;
    }

    // clear left subtree
    clear(ptr->left);
    // clear right subtree
    clear(ptr->right);

    // then delete the root node
    ptr = nullptr;
}

bool BinarySearchTree::is_empty() const
{
    return root == nullptr;
}

bool BinarySearchTree::contains(const int data) const
{
    return contains(data, root);
}

bool BinarySearchTree::contains(const int data, BinaryNode *ptr) const
{

	if(ptr == nullptr){
		return false;
	}
	else{

		if(ptr->data == data){
			return true;
		}
		else if (data < ptr->data ){
			return contains(data,ptr->left);
		}
		else{
			return contains(data,ptr->right);
		}
	}


}

void BinarySearchTree::insert(const int data)
{
    insert(data, root);
}

void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{
    if(ptr == nullptr){
    	ptr  =	new BinaryNode(data);
    }

    if( data < ptr->data){
    	 insert( data, ptr->left);
    }
    else if (data >ptr->data ){
    insert( data, ptr->right);
    }
}

void BinarySearchTree::remove(const int data)
{
    remove(data, root);
}
/**
 * Citaion : From class slides
 */
void BinarySearchTree::remove(const int data, BinaryNode* &ptr)
{
   if(ptr == nullptr){
	   return;
   }
   if(data < ptr->data){
	   remove(data,ptr->left);
   }else if(data > ptr->data){
	   remove(data,ptr->right);
   }else if(	(ptr->left != nullptr) && (ptr->right != nullptr)	){
	   ptr->data = find_min(ptr->right)->data;
	   remove(ptr->data, ptr->right);
   }
   else{

	   BinaryNode *oldNode = ptr;
	   ptr = (ptr->left != nullptr) ? ptr->left:ptr->right;
	   delete oldNode;


   }

}