#include "TargetGenerator.hpp"


TargetGenerator::TargetGenerator(){};
TargetGenerator::~TargetGenerator(){
	for (std::vector<ATarget*>::iterator it = _targbook.begin(); it != _targbook.end(); it++){
			delete (*it);
		}
};

void TargetGenerator::learnTargetType(ATarget* TargetType){
    _targbook.push_back(TargetType->clone());
};



void TargetGenerator::forgetTargetType(const std::string& TargetType){
    if (_targbook.begin() != _targbook.end()){
	for (std::vector<ATarget*>::iterator it = _targbook.begin(); it != _targbook.end(); it++){
		if ((*it)->getType() == TargetType){
			delete *it;
			_targbook.erase(it);
			return;
		}
	}}
};



ATarget* TargetGenerator::createTarget(const std::string& TargetType){
	for (std::vector<ATarget*>::iterator it = _targbook.begin(); it != _targbook.end(); it++){
		if ((*it)->getType() == TargetType)
			return (*it);
	}
    return NULL;
};