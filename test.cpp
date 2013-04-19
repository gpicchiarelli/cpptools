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

#include "include/gbtree.hpp"
#include <iostream>

using namespace std;
using namespace gcpptools;
int main(){
	cout << "test" << endl;
	
	gbtree<double>* t = new gbtree<double>();
	
	for(int i = 0; i< 300 ; i++)
		{t->add(i); t->add(i/2);}
	
	node<double>* nn = t->search(199);
	cout << t->elements << endl;
	node<double>* nnn = nn->left;
	if (nnn != NULL){
		cout << nnn->key << endl;
	}
	
	return 0;
} 
