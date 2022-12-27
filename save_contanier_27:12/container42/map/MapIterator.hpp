#pragma once

#include <cstddef>

#include "../IteratorTraits.hpp"



namespace ft {

	template <class T, class Compare, typename Node>
		class MapIterator{
			public:
    			typedef std::bidirectional_iterator_tag		iterator_category;
    			typedef T         		value_type;
    			typedef ptrdiff_t  		difference_type;
    			typedef T*   		pointer;
    			typedef T&		reference;
				typedef Compare			key_comp;
				typedef Node*			nodePtr;

			private:
					nodePtr		_nodePtr;
					key_comp	_comp;

			public:

			MapIterator(nodePtr node = 0, const key_comp& comp = key_comp()): _nodePtr(node), _comp(comp){};

			MapIterator(pointer node, const key_comp& comp = key_comp()): _comp(comp), _nodePtr(node){};

			MapIterator(const MapIterator<const T, Compare, Node> &copy){
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

				
				nodePtr origin = _nodePtr;
				// if (origin->right->isLast){
				// 	_nodePtr = _nodePtr->right;
				// 	return (*this);
				// }
				if (_nodePtr->right){
					_nodePtr = _nodePtr->right;
					while (_nodePtr->left)
						_nodePtr = _nodePtr->left;
					return (*this);
				}
				if (_nodePtr->parent){
					_nodePtr = _nodePtr->parent;
					if (_comp(origin->content.first, _nodePtr->content.first))
						return (*this);
				}
				else
					return (*this);
				while (!_comp(origin->content.first, _nodePtr->content.first)){
					if (_nodePtr->right && _comp(origin->content.first, _nodePtr->right->content.first) && _nodePtr->right != origin){
						_nodePtr = _nodePtr->right;
						return (*this);
					}
					if (_nodePtr->parent)
						_nodePtr = _nodePtr->parent;
					else
					{
						Node* nul = 0;
						_nodePtr = nul;
						return (*this);
					}
					if (_comp(origin->content.first, _nodePtr->content.first)){
						return (*this);
					}
				}
				return (*this);

			};

			MapIterator operator++(int){
				MapIterator	copy(*this);
				// if (copy.getNodePtr()->right->isLast){
				// 	_nodePtr = _nodePtr->right;
				// 	return copy;
				// }

				if (copy.getNodePtr() == NULL){
					_nodePtr = _nodePtr->right;
					return copy;
				}

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
				if (origin->isLast)
				{
					_nodePtr = _nodePtr->parent;
					return (*this);
				}
				if (_nodePtr->left && _comp(_nodePtr->left->content.first, origin->content.first)){
					_nodePtr = _nodePtr->left;
					while (_nodePtr->right)
						_nodePtr = _nodePtr->right;
					return (*this);
				}
				if (_nodePtr->parent && _comp(_nodePtr->parent->content.first, origin->content.first)){
					_nodePtr = _nodePtr->parent;

						return (*this);
				}
				while (_nodePtr->parent){
					_nodePtr = _nodePtr->parent;
					if (_comp(_nodePtr->content.first, origin->content.first))
						return (*this);
					if (_comp(_nodePtr->content.first, origin->content.first) && _nodePtr->left){
						_nodePtr = _nodePtr->left;
						while (_nodePtr->right)
							_nodePtr = _nodePtr->right;
						return (*this);
					}
				}
				Node* nul = 0;
				_nodePtr = nul;
				return (*this);

				return (*this);
			};

			MapIterator operator--(int){
				MapIterator	copy(*this);
				if (copy.getNodePtr()->isLast)
				{
					_nodePtr = _nodePtr->parent;
					return (copy);
				}
				if (copy.getNodePtr() == NULL)
					return copy;

				if (_nodePtr->left && _comp(_nodePtr->left->content.first, copy._nodePtr->content.first)){
					_nodePtr = _nodePtr->left;
					while (_nodePtr->right)
						_nodePtr = _nodePtr->right;
					return (copy);
				}
				if (_nodePtr->parent && _comp(_nodePtr->parent->content.first, copy._nodePtr->content.first)){
					_nodePtr = _nodePtr->parent;

						return (copy);
				}
				while (_nodePtr->parent){
					_nodePtr = _nodePtr->parent;
					if (_comp(_nodePtr->content.first, copy._nodePtr->content.first))
						return (copy);
					if (_comp(_nodePtr->content.first, copy._nodePtr->content.first) && _nodePtr->left){
						_nodePtr = _nodePtr->left;
						while (_nodePtr->right)
							_nodePtr = _nodePtr->right;
						return (copy);
					}
				}
				Node* nul = 0;
				_nodePtr = nul;
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