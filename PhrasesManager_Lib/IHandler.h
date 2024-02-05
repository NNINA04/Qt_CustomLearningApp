#pragma once

template<class T>
class IHandler
{
public:
    virtual void Handle(T& handableObj) const = 0;
};
