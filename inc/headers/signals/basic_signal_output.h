#ifndef BASIC_SIGNAL_OUTPUT_H
#define BASIC_SIGNAL_OUTPUT_H

#include "../../interfaces/signal_output.h"
#include <set>

class Basic_signal_output: public Signal_output{
public:
	void signal_send(const Signal& signal);
	void subscribe(std::shared_ptr<Signal_input> sig_i);
	void unsubscribe(std::shared_ptr<Signal_input> sig_i);
	void delete_subscribes();

private:
	std::set<std::shared_ptr<Signal_input>> subscribes;
};

#endif // BASIC_SIGNAL_OUTPUT_H
