#ifndef POST_OFFICE_H
#define POST_OFFICE_H

class Receiver;

#include <unordered_map>

class PostOffice
{
public:
	Receiver* GetReceiverFor(const void* ptr);
private:
	// associates an object pointer to its own receiver
	// is this a good idea?
	// Could we use a uint64? This would imply 64 bit architecture
	// for the addresses of pointers. If x32, then this would not
	// be optimal
	std::unordered_map<const void*, Receiver*> clientReceivers;
};

#endif
