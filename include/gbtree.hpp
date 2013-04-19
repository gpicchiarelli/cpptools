/*
Copyright 2013 Giacomo Picchiarelli <gpicchiarelli@gmail.com>

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either 
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public 
License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

//* A generic binary tree *//

#include <stdio.h>

using namespace std;

namespace gcpptools{
	
	template <typename T> 
	struct node
	{
		T key;
		node *left;
		node *right;
	};
	
	template <typename T>
	class gbtree
	{
    public:
        gbtree();
        ~gbtree();	
        void add(T key);
        node<T> *search(T key);
        void destroy_gbtree();

    private:
        void destroy_tree(node<T> *leaf);
        void add(T key, node<T> *leaf);
        node<T> *search(T key, node<T> *leaf);        
        node<T> *root;
	};
	
	template<typename T>
	node<T> *gbtree<T>::search(T key)
	{
	  return search(key, root);
	}
	
	template<typename T>
	void gbtree<T>::destroy_gbtree()
	{
	  destroy_tree(root);
	}

	template<typename T>
	gbtree<T>::gbtree()
	{
	  root=NULL;
	}
	
	template<typename T>	
	void gbtree<T>::destroy_tree(node<T> *leaf)
	{
	  if(leaf!=NULL)
	  {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	  }
	}		

	template<typename T>
	void gbtree<T>::add(T key, node<T> *leaf)
	{
	  if(key < leaf->key_value)
	  {
		if(leaf->left!=NULL)
		 add(key, leaf->left);
		else
		{
		  leaf->left=new node<T>();
		  leaf->left->key_value=key;
		  leaf->left->left=NULL;   
		  leaf->left->right=NULL;
		}  
	  }
	  else if(key >= leaf->key_value)
	  {
		if(leaf->right!=NULL)
		  add(key, leaf->right);
		else
		{
		  leaf->right=new node<T>();
		  leaf->right->key_value=key;
		  leaf->right->left=NULL;  
		  leaf->right->right=NULL;
		}
	  }
	}

	template <typename T>
	node<T> *gbtree<T>::search(T key, node<T> *leaf)
	{
	  if(leaf!=NULL)
	  {
		if(key==leaf->key_value)
		  return leaf;
		if(key<leaf->key_value)
		  return search(key, leaf->left);
		else
		  return search(key, leaf->right);
	  }
	  else return NULL;
	}

	template<typename T>
	void gbtree<T>::add(T key)
	{
	  if(root!=NULL)
		add(key, root);
	  else
	  {
		root=new node<T>();
		root->key_value=key;
		root->left=NULL;
		root->right=NULL;
	  }
	}
}
