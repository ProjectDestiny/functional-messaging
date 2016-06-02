#ifndef POST_OFFICE_H
#define POST_OFFICE_H

#include <utility>
#include <unordered_map>
#include "opaque-receiver.hpp"
#include "receiver.hpp"

class PostOffice
{
public:
	template <typename T>
	OpaqueReceiver* GetReceiverFor(const void* ptr);

private:
	// associates an object pointer to its own receiver
	// is this a good idea?
	// Could we use a uint64? This would imply 64 bit architecture
	// for the addresses of pointers. If x32, then this would not
	// be optimal
	std::unordered_map<const void*, OpaqueReceiver*> clientReceivers;
};

template <typename T>
OpaqueReceiver* PostOffice::GetReceiverFor(const void * ptr) {
    auto it = clientReceivers.find(ptr);
	if(it == clientReceivers.end()) {
		OpaqueReceiver * newReceiver = new Receiver<T>;
        //clientReceivers.insert(std::make_pair<const void*,OpaqueReceiver* >(ptr,newReceiver));
		return newReceiver;
	} else {
	    return nullptr;
	}
}

#endif
