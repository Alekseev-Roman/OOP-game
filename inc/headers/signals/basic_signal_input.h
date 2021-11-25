#ifndef BASIC_SIGNAL_INPUT_H
#define BASIC_SIGNAL_INPUT_H

#include "../../interfaces/signal_input.h"

class Basic_signal_input: public Signal_input{
public:
	void signal_accept(const Signal& signal);
};

#endif // BASIC_SIGNAL_INPUT_H
