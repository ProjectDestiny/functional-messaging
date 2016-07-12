#ifndef POST_OFFICE_H
#define POST_OFFICE_H

#include <utility>
#include <unordered_map>
#include "opaque-receiver.hpp"

class OpaqueReceiver;

class PostOffice
{
public:
	OpaqueReceiver* GetReceiverFor(const void* ptr);
	OpaqueReceiver* SetReceiverFor(const void* ptr, OpaqueReceiver* receiver);

private:
	// associates an object pointer to its own receiver
	// is this a good idea?
	// Could we use a uint64? This would imply 64 bit architecture
	// for the addresses of pointers. If x32, then this would not
	// be optimal
	std::unordered_map<const void*, OpaqueReceiver*> clientReceivers;
};

#endif
