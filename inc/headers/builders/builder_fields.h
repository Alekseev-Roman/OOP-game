#ifndef BUILDER_FIELDS_H
#define BUILDER_FIELDS_H

#include "../../interfaces/game_i.h"

#include "../field.h"
#include "../painter_SFML.h"
#include "../start_cell.h"
#include "../finish_cell.h"

#include "../../../textures.txt"

class Builder_fields{
public:
	Builder_fields();
	Field& create(Field& field, std::shared_ptr<Painter> painter, Game_i& game);
};

#endif // BUILDER_FIELDS_H
