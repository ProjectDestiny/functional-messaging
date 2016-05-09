#ifndef POST_OFFICE_H
#define POST_OFFICE_H

class Receiver;

#include <unordered_map>

class PostOffice
{
public:
	Receiver* GetReceiverFor(void* ptr);
private:
	// associates an object pointer to its own receiver
	std::unordered_map<void*, Receiver*> clientReceivers;
};

#endif
