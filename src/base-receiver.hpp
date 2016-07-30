#ifndef BASE_RECEIVER_H
#define BASE_RECEIVER_H

#include <memory>
#include <type_traits>
#include <iostream>

class PostOffice;
class OpaqueReceiver;

class _SharedReceiverData
{
public:
	_SharedReceiverData();
    ~_SharedReceiverData() {};

	OpaqueReceiver * GetReceiver();

protected:
	PostOffice& GetPostOffice();
	bool CanGetReceiverFor(const void * ptr);
	void SetReceiverFor(const void * ptr);
	void SetNewReceiverFor(const void * ptr, OpaqueReceiver * receiver);

	template <typename T>
	class _ConstCaster
	{
	public:
	    void * operator()(T & obj) {
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

	template <typename T>
	class _ConstCaster<T *>
	{
	public:
	    void * operator()(T * obj) {
			void* voidPtrVal = nullptr;
			if(std::is_const<T*>::value)
			{
				// If pointer is const, remove qualifier, then
				// interpret pointer as being void*
				voidPtrVal = static_cast<void*>(const_cast<T*>(obj));
			}
			else
			{
				voidPtrVal = static_cast<void*>(obj);
			}
			return voidPtrVal;
		}
	};

	template <typename T>
	class _ConstCaster<T const>
	{
	public:
		void const * operator()(T const & obj) {
			return static_cast<void const *>(&obj);;
		}
	};

    OpaqueReceiver* objectReceiver;
};

#endif
