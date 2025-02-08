// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// agminton

#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() : BinarySearchTree() //Constructor, RBT is a type of BST
{
	
	
}

RedBlackTree::~RedBlackTree() //Destructor
{
	
	
}

void RedBlackTree::insert(int data) //inserts a node into RBT
{
	TreeNode * newNode = new TreeNode(data); //Creates new TreeNode
	
	newNode->setColor(RED); //Initializes color of newNode to red per RBT rules
	
	BinarySearchTree::setRoot(BinarySearchTree::insertNode(BinarySearchTree::getRoot(), newNode)); //Calls helper function with root and newNode to insert into tree
	
	TreeNode * rootNode = BinarySearchTree::getRoot(); //Sets the root of RBT to root provided by BST
	
	//rootNode->setColor(BLACK); //Phase III Testing, comment out for next phase
	
	balanceColor(rootNode, newNode); //Balances the color of the RBT
}

void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode) //Performs a left rotation on RBT
{
	TreeNode * rightChild = newNode->getRightChild(); //Sets rightChild pointer to newNodes right child
	
	newNode->setRightChild(rightChild->getLeftChild()); //Sets newNodes right child to the left child of newnodes right child
	
	if(newNode->getRightChild() != nullptr) //if newNode has right child
	{
		newNode->getRightChild()->setParent(newNode); //Sets the parent of newNodes right child to newNode
	}
	
	rightChild->setParent(newNode->getParent()); //Right childs parent becomes newNodes parent
	
	if(newNode->getParent() == nullptr) //If newNode has no parent
	{
		root = rightChild; //set parameter root to right Child
		BinarySearchTree::setRoot(rightChild); //set root to right Child
	}
	else if(newNode == newNode->getParent()->getLeftChild()) //If newNode is the leftChild of its parent
	{
		newNode->getParent()->setLeftChild(rightChild); //Set the newNodes parents left Child to rightChild
	}
	else
	{
		newNode->getParent()->setRightChild(rightChild); //Set the newNodes parents right Child to rightChild
	}
	
	rightChild->setLeftChild(newNode); //set the rightChilds leftchild to newNode
	newNode->setParent(rightChild); //set newNodes parent to rightChild
}

void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode) //Performs a right rotation on RBT
{
	TreeNode * leftChild = newNode->getLeftChild(); //Sets leftChild pointer to newNodes left child
	
	newNode->setLeftChild(leftChild->getRightChild()); //Sets newNodes left child to the right child of newnodes left child
	
	if(newNode->getLeftChild() != nullptr) //if newNode has left child
	{
		newNode->getLeftChild()->setParent(newNode); //Sets the parent of newNodes left child to newNode
	}
	
	leftChild->setParent(newNode->getParent()); //Left childs parent becomes newNodes parent
	
	if(newNode->getParent() == nullptr) //If newNode has no parent
	{
		BinarySearchTree::setRoot(leftChild); //set root to left child
		root = leftChild; //set parameter root to left child
	}
	else if(newNode == newNode->getParent()->getLeftChild()) //If newNode is the leftChild of its parent
	{
		newNode->getParent()->setLeftChild(leftChild); //Set the newNodes parents left Child to leftChild
	}
	else
	{
		newNode->getParent()->setRightChild(leftChild); //Set the newNodes parents right Child to leftChild
	}
	
	leftChild->setRightChild(newNode); //set the leftChilds rightchild to newNode
	newNode->setParent(leftChild); //set newNodes parent to leftChild
	
}

void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode) //Balances the color of RBT
{
	TreeNode * parent = nullptr; //pointer to parent of newNode
	TreeNode * grandParent = nullptr; //pointer to grandParent of newNode

	root->setColor(BLACK); //Sets root to black per RBT rules
	
	while(newNode != root && newNode->getColor() != BLACK && newNode->getParent()->getColor() == RED) //While RBT not color balanced per RBT rules
	{
		parent = newNode->getParent(); //assigns pointer to newnodes parent
		grandParent = newNode->getParent()->getParent(); //assigns pointer to newnodes grandparent
		
		if(parent == grandParent->getLeftChild()) //parent is the grandparents left child
		{
			TreeNode * uncle = grandParent->getRightChild(); //We create uncle to be the uncle of newnode and sibling of parent
			
			if(uncle != nullptr && uncle->getColor() == RED) //If uncle exists and is red
			{
				//Pushes down blackness from grandParent
				grandParent->setColor(RED); //Set grandParents color to red
				parent->setColor(BLACK); //Set parents color to black
				uncle->setColor(BLACK); //Set uncles color to black
				newNode = grandParent; //Set newNode to grandparent
			}
			else
			{
				if(newNode == parent->getRightChild()) //If newNode is equal to parents right child
				{
					rotateLeft(root,parent); //Perform left rotation
					
					//Resets Relationships between nodes
					newNode = parent;
					parent = newNode->getParent();
				}
				else
				{
					rotateRight(root,grandParent); //Perform right rotation
					
					//Creates temporary color to swap colors 
					Color swap = parent->getColor();
					parent->setColor(grandParent->getColor());
					grandParent->setColor(swap);
					
					//Reset Relationship
					newNode = parent;
					
				}				
			}
		}
		else //Same thing but switched to left child
		{
			TreeNode * uncle = grandParent->getLeftChild(); //We create uncle to be the uncle of newnode and sibling of parent
			
			if(uncle != nullptr && uncle->getColor() == RED) //If uncle exists and is red
			{
				//Pushes down blackness from grandParent
				grandParent->setColor(RED); //Set grandParents color to red
				parent->setColor(BLACK); //Set parents color to black
				uncle->setColor(BLACK); //Sets uncles color to black
				newNode = grandParent; //Set newNode to grandparent
			}
			else
			{
				if(newNode == parent->getLeftChild()) //If newNode is equal to parents left child
				{
					rotateRight(root,parent); //Perform right rotation
					
					//Resets Relationships between nodes
					newNode = parent;
					parent = newNode->getParent();
				}
				else
				{
					rotateLeft(root,grandParent); //Performs left rotation
					
					//Creates temporary color to swap colors
					Color swap = parent->getColor();
					parent->setColor(grandParent->getColor());
					grandParent->setColor(swap);
					
					//Reset Relationship
					newNode = parent;
					
				}				
			}
		}
	}
	
	root->setColor(BLACK); //Makes certain root is black per RBT rules
}

void RedBlackTree::printRedNodes(TreeNode * root) //Prints red nodes of a RBT (INORDER TRAVERSAL)
{
	if(root != nullptr) //If tree exists
	{
		printRedNodes(root->getLeftChild()); //Recursively calls here per inorder traversal
		if(root->getColor() == RED) //If node is red
		{
			std::cout << root->getValue() << " "; //Print the value of the node
		}
		printRedNodes(root->getRightChild()); //Recursively calls here per inorder traversal
	}
}
		
void RedBlackTree::printBlackNodes(TreeNode * root) //Print black nodes of a RBT (PREORDER TRAVERSAL)
{
	if(root != nullptr) //if tree exists
	{
		if(root->getColor() == BLACK) //If node is black
		{
			std::cout << root->getValue() << " "; //Print the value of the node
		}
		printBlackNodes(root->getLeftChild()); //Recursively calls here per preorder traversal
		printBlackNodes(root->getRightChild()); //Recursively calls here per preorder traversal
	}
}
