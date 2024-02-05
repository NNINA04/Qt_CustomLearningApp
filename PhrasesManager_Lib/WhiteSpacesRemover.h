#pragma once

#include "IHandler.h"

class WhiteSpacesRemover
    : public IHandler<std::set<std::pair<std::string, std::string>>>
{
public:
    virtual void Handle(std::set<std::pair<std::string, std::string>>& handableObj) const
    {
        handableObj.erase(handableObj.find({ "","" }));
    }
};
