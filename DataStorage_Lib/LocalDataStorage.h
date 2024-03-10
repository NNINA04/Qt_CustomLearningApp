#pragma once

#include "IDataStorage.h"

template<class T>
class LocalDataStorage
    : public IDataStorage<T*>
{
    //const string _PATH;
    std::string _PATH;
public:
    //LocalDataStorage(const string& PATH)
    LocalDataStorage(std::string PATH)
        : _PATH(PATH) {}

    virtual void Store(T* data) override
    {
        std::ofstream fs(_PATH, std::ios_base::binary);
        fs.write((char*)data, sizeof(T));
        fs.close();
    }

    virtual T* Restore() override
    {
        std::ifstream fs(_PATH, std::ios_base::binary);

        bool emptyFile = fs.peek() == EOF;
        if (emptyFile)
            throw std::exception("The file is empty");

        size_t objSize = sizeof(T);
        T* obj = (T*)malloc(objSize);
        fs.read((char*)obj, objSize); // Check for errors
        fs.close();
        return obj;
    }
};
