#pragma once

template<class T>
class IDataStorage
{
public:
	virtual void Store(T data) = 0;

	virtual T Restore() = 0;

	virtual ~IDataStorage() {}
};