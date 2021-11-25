#ifndef ENEMIES_KILLED_RULE_H
#define ENEMIES_KILLED_RULE_H

template <size_t K>
class Enemies_killed_rule{
public:
	bool checker(const Game_i& game_object) const{
		return game_object.check_killed_enemies() >= K;
	}
};

#endif // ENEMIES_KILLED_RULE_H
