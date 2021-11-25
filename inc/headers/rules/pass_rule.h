#ifndef PASS_RULE_H
#define PASS_RULE_H

template <size_t P>
class Pass_rule{
public:
	bool checker(const Game_i& game_object) const{
		return game_object.check_pass() >= P;
	}
};

#endif // PASS_RULE_H
