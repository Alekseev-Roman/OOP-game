#include "../../inc/headers/signals/basic_signal_output.h"

void Basic_signal_output::signal_send(const Signal& signal){
	for(auto& sub:subscribes){
		sub->signal_accept(signal);
	}
}

void Basic_signal_output::subscribe(std::shared_ptr<Signal_input> sig_i){
	subscribes.insert(sig_i);
}

void Basic_signal_output::unsubscribe(std::shared_ptr<Signal_input> sig_i){
	subscribes.erase(sig_i);
}

void Basic_signal_output::delete_subscribes(){
	subscribes = {};
}
