#include "../../inc/headers/signals/basic_signal_input.h"

void Basic_signal_input::signal_accept(const Signal& signal){
	signal.signal_processing(*this);
}

