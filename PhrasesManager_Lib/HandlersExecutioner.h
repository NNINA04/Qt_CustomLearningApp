#pragma once

#include "IHandler.h"

template<class T>
class HandlersExecutioner
{
    std::vector<IHandler<T>*> _handlers;
public:
    void AddHandler(IHandler<T>* handler)
    {
        _handlers.push_back(handler);
    }

    void Handle(T& obj) const
    {
        for (auto& val : _handlers)
            val->Handle(obj);
    }
};
