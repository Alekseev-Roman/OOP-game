#include "../../inc/headers/logger/operators.h"

std::ostream& operator <<(std::ostream& stream, const Cell_element& entity){
	stream << "Entity (" << entity.get_x() << "; " << entity.get_y() << ")";
	return stream;
}