#ifndef RESPONSE_H
#define RESPONSE_H

/*
 */
#include <string>
#include <unordered_map>

class ResponseComponent
{

};

class Response
{
public:
private:
	// the event this response
	std::string eventResponse;
	typedef std::unordered_map<std::string, ResponseComponent*> ResponseComponents;
	ResponseComponents optionComponents;
};

template <typename T>
class ConcreteResponse
{

};


/*
 A Receiver is a collection of all messages an any object can receive.
 */
class PostOfficeSubscriber {
public:
	PostOfficeSubscriber (void * ptr) : data() {
		data = std::make_shared<void *>(ptr);
	}

	virtual ~PostOfficeSubscriber () {}

    std::shared_ptr<void *>& get() { return data; }

protected:
	std::shared_ptr<void *> data;
};


#endif
