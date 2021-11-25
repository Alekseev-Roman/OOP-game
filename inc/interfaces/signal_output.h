#ifndef SIGNAL_OUTPUT_H
#define SIGNAL_OUTPUT_H

#include <memory>
#include "signal_input.h"
#include "signal.h"

class Signal_output{
public:
	virtual ~Signal_output() = default;
	virtual void signal_send(const Signal& signal) = 0;
	virtual void subscribe(std::shared_ptr<Signal_input> sig_i) = 0;
	virtual void unsubscribe(std::shared_ptr<Signal_input> sig_i) = 0;
	virtual void delete_subscribes() = 0;
};

#endif // SIGNAL_OUTPUT_H
