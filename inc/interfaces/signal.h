#ifndef SIGNAL_H
#define SIGNAL_H

#include "signal_input.h"

class Signal_input;

class Signal{
public:
	virtual ~Signal() = default;
	virtual void signal_processing(Signal_input& signal) const = 0;
};

#endif // SIGNAL_H
