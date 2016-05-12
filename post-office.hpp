#ifndef POST_OFFICE_H
#define POST_OFFICE_H

#include <unordered_map>

class PostOffice
{
public:
	Receiver* GetReceiverFor(const void* ptr);
private:
	// associates an object pointer to its own receiver
	// is this a good idea?
	std::unordered_map<const void*, Receiver*> clientReceivers;
};

#endif
