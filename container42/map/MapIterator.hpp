#pragma once

#include <cstddef>

#include "../IteratorTraits.hpp"



namespace ft {

	template <class Key, class T, class Compare, typename Node, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
		class MapIterator{
			public:
    			typedef Key  			iterator_category;
    			typedef T         		value_type;
    			typedef Distance  		difference_type;
    			typedef Pointer   		pointer;
    			typedef Reference 		reference;
				typedef Compare			key_comp;
				typedef Node*			nodePtr;

			private:
					nodePtr		_nodePtr;
					key_comp	_comp;

			public:

			MapIterator(nodePtr node = 0, const key_comp& comp = key_comp()): _nodePtr(node), _comp(comp){};

			MapIterator(pointer node, const key_comp& comp = key_comp()): _comp(comp), _nodePtr(node){};

			MapIterator(const MapIterator<const Key, T, Compare, Node> &copy){
				_nodePtr = copy.getNodePtr();
				_comp = copy.getComp();
			};

			~MapIterator(){};


			
			nodePtr getNodePtr() const {
				return _nodePtr;
			};

			key_comp getComp() const {
				return _comp;
			};


			MapIterator& operator=(const MapIterator& rhs){
				if (this != rhs){
					_nodePtr = rhs.getNodePtr();
					_comp = rhs.getComp();
				}
			}

			bool operator==(const MapIterator& it) const {
				return (it._nodePtr == _nodePtr);
			}

            bool operator!=(const MapIterator& it) const {
				return (it._nodePtr != _nodePtr);
			}

			reference operator*() const {
				return _nodePtr->content;
			}
			
			pointer operator->() const {
				return (&_nodePtr->content);
			}

			MapIterator& operator++(){
				std::cout << "haha\n";
				if (_nodePtr == NULL)
					return NULL;
				nodePtr origin = _nodePtr;

				if (_nodePtr->right){
					_nodePtr = _nodePtr->right;
					return (*this);
				}
				if (_nodePtr->parent)
					_nodePtr = _nodePtr->parent;
				else
					return NULL;
				while (!_comp(origin->content.first, _nodePtr->content.first)){
					if (_comp(origin->content.first, _nodePtr->right->content.first && _nodePtr->right != origin)){
						_nodePtr = _nodePtr->right;
						return (*this);
					}
					_nodePtr = _nodePtr->parent;
				}
				return (*this);   //? sinon = map.end()
			};

			MapIterator operator++(int){
				MapIterator	copy(*this);




				if (copy.getNodePtr() == NULL)
					return copy;

				if (_nodePtr->right){
					_nodePtr = _nodePtr->right;
					while (_nodePtr->left)
						_nodePtr = _nodePtr->left;
					return (copy);
				}
				if (_nodePtr->parent){
					_nodePtr = _nodePtr->parent;
					if (_comp(copy._nodePtr->content.first, _nodePtr->content.first))
						return copy;
				}
				else
					return copy;
				while (!_comp(copy._nodePtr->content.first, _nodePtr->content.first)){
					if (_nodePtr->right && _comp(copy._nodePtr->content.first, _nodePtr->right->content.first) && _nodePtr->right != copy._nodePtr){
						_nodePtr = _nodePtr->right;
						return (copy);
					}
					if (_nodePtr->parent)
						_nodePtr = _nodePtr->parent;
					else
					{
						Node* nul = 0;
						_nodePtr = nul;
						return (copy);
					}
					if (_comp(copy._nodePtr->content.first, _nodePtr->content.first)){
						return (copy);
					}
				}
				return (copy);
			};

			MapIterator& operator--(){
				nodePtr origin = _nodePtr;

				if (_nodePtr->left){
					_nodePtr = _nodePtr->left;
					return (*this);
				}
				if (_nodePtr->parent)
					_nodePtr = _nodePtr->parent;
				else
					return (*this);
				while (!_comp(origin->content.first, _nodePtr->content.first)){
					if (_comp(origin->content.first, _nodePtr->left->content.first) && _nodePtr->left != origin){
						_nodePtr = _nodePtr->left;
						return (*this);
					}
					if (_nodePtr->parent)
						_nodePtr = _nodePtr->parent;
					else
						return (*this);
				}
				return (*this);
			};

			MapIterator operator--(int){
				MapIterator	copy(*this);
				if (copy.getNodePtr() == NULL)
					return copy;

				if (_nodePtr->left){
					_nodePtr = _nodePtr->left;
					return (copy);
				}
				if (_nodePtr->parent && !_comp(_nodePtr->parent->content.first, copy._nodePtr->content.first))
						_nodePtr = _nodePtr->parent;
				// else if (_nodePtr->parent && _comp(_nodePtr->parent->content.first, copy._nodePtr->content.first)){

				//  	_nodePtr = _nodePtr->parent;
				// }
				// else{
				// 	Node* nul = 0;
				// 	_nodePtr = nul;
				// 	return (copy);
				// }
				// if (_nodePtr->parent)
				// 	_nodePtr = _nodePtr->parent;
				// else
				// 	return copy;
				while (!_comp(_nodePtr->content.first, copy._nodePtr->content.first)){
					if (_nodePtr->left && !_comp(_nodePtr->content.first, copy._nodePtr->left->content.first && _nodePtr->left != copy._nodePtr)){
						_nodePtr = _nodePtr->left;
						return (copy);
					}
					if (_nodePtr->parent && _comp(_nodePtr->parent->content.first, copy._nodePtr->content.first))
						_nodePtr = _nodePtr->parent;
					else{
						Node* nul = 0;
						_nodePtr = nul;
						return (copy);
					}
				}
				return (copy);
			};



			Node* findMin(Node* t)
    		{
    		    	if(t == NULL)
    					return NULL;
    		    	else if(t->left == NULL)
    		        	return t;
    		    	else
    		        	return findMin(t->left);
    		}


		};
}