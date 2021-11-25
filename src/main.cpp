#include "../inc/headers/game.h"
#include "../inc/headers/rules/pass_rule.h"
#include "../inc/headers/rules/enemies_killed_rule.h"

int main(){
	Game<Pass_rule<1>, Enemies_killed_rule<0>> game;
	game.start();
	return 0;
}
