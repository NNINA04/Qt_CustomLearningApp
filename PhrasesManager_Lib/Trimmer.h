#pragma once

#include "IHandler.h"

class Trimmer
    : public IHandler<std::set<std::pair<std::string, std::string>>>
{
public:
    virtual void Handle(std::set<std::pair<std::string, std::string>>& handableObj) const
    {
        for (size_t i = 0; i < handableObj.size(); ++i)
        {
            auto it = next(handableObj.begin(), i);
            auto& phrase = *it;

            std::pair<std::string, std::string> newPhrase(Trim(phrase.first), Trim(phrase.second));

            if (phrase == newPhrase)
                continue;

            handableObj.insert(newPhrase);
            handableObj.erase(it--);
        }
    }
private:
    // trim from left
    inline std::string& LTrim(std::string& s, const char* t = " \t\n\r\f\v") const
    {
        s.erase(0, s.find_first_not_of(t));
        return s;
    }

    // trim from right
    inline std::string& RTrim(std::string& s, const char* t = " \t\n\r\f\v") const
    {
        s.erase(s.find_last_not_of(t) + 1);
        return s;
    }

    // trim from left & right
    inline std::string Trim(std::string s, const char* t = " \t\n\r\f\v") const
    {
        return LTrim(RTrim(s, t), t);
    }
};
