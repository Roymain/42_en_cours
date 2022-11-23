#pragma once

#include <vector>
#include "ATarget.hpp"

class TargetGenerator {
    private:
        std::vector<ATarget*>   _targbook;

    public:
        TargetGenerator();
        ~TargetGenerator();
		void learnTargetType(ATarget* TargetType);
		void forgetTargetType(const std::string& target);
		ATarget* createTarget(const std::string& target);

};
