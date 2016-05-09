#ifndef BASE_RECEIVER_H
#define BASE_RECEIVER_H

#include <memory>

class PostOffice;
class Receiver;

class _SharedReceiverData
{
public:
	_SharedReceiverData();
    ~_SharedReceiverData() {};

	Receiver * GetReceiver();

protected:
	PostOffice& GetManager();
    void SetGetReceiverFor(void * ptr);


	template <typename T>
	class _Checker
	{
	public:
	    void * operator()(T obj) {
			void* voidPtrVal = nullptr;
			if(std::is_const<T>::value)
			{
				// If pointer is const, remove qualifier, then
				// interpret pointer as being void*
				voidPtrVal = static_cast<void*>(const_cast<T*>(&obj));
			}
			else
			{
				voidPtrVal = static_cast<void*>(&obj);
			}
			return voidPtrVal;
		}
	};

    Receiver* objectReceiver;
};

#endif
