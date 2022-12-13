#pragma once

#include <cstddef>

#include "../IteratorTraits.hpp"
#include "Map.hpp"
#include <iterator>


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

			MapIterator(const MapIterator<Key, T, Compare, Node> &copy){
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

			MapIterator& operator*() const {
				return _nodePtr->content;
			}
			
			MapIterator& operator->() const {
				return (&_nodePtr->content);
			}

			MapIterator& operator++(){
				nodePtr origin = _nodePtr;

				if (_nodePtr->right){
					_nodePtr = _nodePtr->right;
					return (*this);
				}
				_nodePtr = _nodePtr->parent;
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

				if (_nodePtr->right){
					_nodePtr = _nodePtr->right;
					return (copy);
				}
				_nodePtr = _nodePtr->parent;
				while (!_comp(copy._nodePtr->content.first, _nodePtr->content.first)){
					if (_comp(copy._nodePtr->content.first, _nodePtr->right->content.first && _nodePtr->right != copy._nodePtr)){
						_nodePtr = _nodePtr->right;
						return (copy);
					}
					_nodePtr = _nodePtr->parent;
				}
				return (copy);
			};

			MapIterator& operator--(){
				nodePtr origin = _nodePtr;

				if (_nodePtr->left){
					_nodePtr = _nodePtr->left;
					return (*this);
				}
				_nodePtr = _nodePtr->parent;
				while (!_comp(origin->content.first, _nodePtr->content.first)){
					if (_comp(origin->content.first, _nodePtr->left->content.first && _nodePtr->left != origin)){
						_nodePtr = _nodePtr->left;
						return (*this);
					}
					_nodePtr = _nodePtr->parent;
				}
				return (*this);
			};

			MapIterator operator--(int){
				MapIterator	copy(*this);

				if (_nodePtr->left){
					_nodePtr = _nodePtr->left;
					return (copy);
				}
				_nodePtr = _nodePtr->parent;
				while (!_comp(copy._nodePtr->content.first, _nodePtr->content.first)){
					if (_comp(copy._nodePtr->content.first, _nodePtr->left->content.first && _nodePtr->left != copy._nodePtr)){
						_nodePtr = _nodePtr->left;
						return (copy);
					}
					_nodePtr = _nodePtr->parent;
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