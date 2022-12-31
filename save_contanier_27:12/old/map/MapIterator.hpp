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

			MapIterator(const nodePtr node = 0, const key_comp& comp = key_comp()): _nodePtr(node), _comp(comp){};

			MapIterator(pointer node, const key_comp& comp = key_comp()): _comp(comp){
				_nodePtr = node;
			};

			template <class W, class Comp, typename Nod>
			MapIterator(const MapIterator<W, Comp, Nod> &copy){
				_nodePtr = (Node*)(copy.getNodePtr());
				_comp = (Compare)(copy.getComp());
			};


			~MapIterator(){};


			
			nodePtr getNodePtr() const {
				return _nodePtr;
			};

			key_comp getComp() const {
				return _comp;
			};



			bool operator==(const MapIterator& it) const {
				if (it._nodePtr == it._nodePtr->last)
					return true;
				return (it._nodePtr == _nodePtr);
			}

            bool operator!=(const MapIterator& it) const {

				return (it._nodePtr != _nodePtr);
			}
	

			template <class W, class Comp, typename Nod>
			MapIterator& operator=(const MapIterator<W, Comp, Nod>& rhs) {
				
				_nodePtr = (Node*)(rhs.getNodePtr());
			//	_nodePtr->content = (W)(rhs.getNodePtr()->content);
				// _nodePtr->left = copy.getNodePtr()->left;
				// _nodePtr->parent = copy.getNodePtr()->parent;
				// _nodePtr->last = copy.getNodePtr()->last;
				_comp = (Compare)(rhs.getComp());
				return (*this);
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
				//std::cout << _nodePtr->isLast << "\n";
				if (origin == origin->last)
				{
					_nodePtr = _nodePtr->last;
					//std::cout << "vserxvsare1\n";
					return (*this);
				
				}
				//std::cout << "vserxvsare\n";
				if (_nodePtr->right){
					_nodePtr = _nodePtr->right;
					while (_nodePtr->left)
						_nodePtr = _nodePtr->left;
					//std::cout << "vserxvsare2\n";
					return (*this);
				}
				if (_nodePtr->parent){
					_nodePtr = _nodePtr->parent;
					if (_comp(origin->content.first, _nodePtr->content.first))
					{//std::cout << "vserxvsare3\n";
						return (*this);}
				}
				else{
					_nodePtr = _nodePtr->last;
					return (*this);
				}
				while (!_comp(origin->content.first, _nodePtr->content.first)){
					if (_nodePtr->right && _comp(origin->content.first, _nodePtr->right->content.first) && _nodePtr->right != origin){
						_nodePtr = _nodePtr->right;
						return (*this);
					}
					if (_nodePtr->parent)
						_nodePtr = _nodePtr->parent;
					else
					{
						_nodePtr = _nodePtr->last;
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

					////std::cout << "vserxvsare\n";
				if (copy.getNodePtr() == NULL){
					_nodePtr = _nodePtr->right;
					return copy;
				}
				if ( _nodePtr == _nodePtr->last)
				{
					_nodePtr = _nodePtr->last->left;
					return (copy);
				
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
				else{
					_nodePtr = _nodePtr->last;
					return copy;
				}
				while (!_comp(copy._nodePtr->content.first, _nodePtr->content.first)){
					if (_nodePtr->right && _comp(copy._nodePtr->content.first, _nodePtr->right->content.first) && _nodePtr->right != copy._nodePtr){
						_nodePtr = _nodePtr->right;
						return (copy);
					}
					if (_nodePtr->parent)
						_nodePtr = _nodePtr->parent;
					else
					{
						////std::cout << "gnas\n";
						_nodePtr = _nodePtr->last;
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
				if ( _nodePtr == _nodePtr->last)
				{
					////std::cout << "vserxvsare\n";
					_nodePtr = _nodePtr->last->left;
					return (*this);
				
				}
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
				if ( _nodePtr == _nodePtr->last)
				{
					////std::cout << "vserxvsare\n";
					_nodePtr = _nodePtr->last->left;
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