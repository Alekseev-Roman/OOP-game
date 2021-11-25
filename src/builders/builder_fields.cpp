#include "../../inc/headers/builders/builder_fields.h"

Builder_fields::Builder_fields(){}

Field& Builder_fields::create(Field& field, std::shared_ptr<Painter> painter, Game_i& game){
	painter->set_field(field);
	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 15; x++){
			if(((x <= 2 || x == 8 ) && y == 4) || (y == 0 && (x == 2 || x == 7 || x == 8 || x == 9 || x == 14)) ||
				(y == 1 && (x == 2 || x == 3 || x == 4 || x == 9 || x >= 12)) || 
				(y == 2 && x == 12) || (y == 3 && (x == 6 || x == 7 || x == 8 || x == 9 || x == 12)) ||
				(y == 4 && (x <= 2 || x == 8)) || (y == 5 && (x == 2 || x == 4 || x == 5 || x == 6 || x == 8 || x >= 13)) ||
				(y == 6 && (x == 8 || x == 9 || x == 10 || x == 14)) || (y == 8 && (x == 12 || (x >= 2 && x <= 6))) || 
				(y == 9 && (x == 12 || (x >= 6 && x <= 9)))){

				field.set_cell(std::make_unique<Cell>(true), x, y);

				if(((x == 2 || x == 14) && y == 0) || (x == 12 && (y == 2 || y ==9)) || (x == 8 && (y == 4 || y == 5)))
					painter->paint_cell(WALL_STRAIGHT_V_TEXTURE, x, y);
				if(((x == 3 || x == 13) && y == 1) || (x == 8 && y ==0) || (x == 7 && y == 3) || (x <= 1 && y == 4) ||
					(x == 5 && y == 5) || (x == 9 && y == 6) || ((x >= 3 && x <= 5) && y == 8) || ((x == 7 || x == 8) && y == 9))
					painter->paint_cell(WALL_STRAIGHT_H_TEXTURE, x, y);

				if(x == 8 && y == 3)
					painter->paint_cell(WALL_CROSSING_TEXTURE, x, y);

				if((x == 2 && y == 1) || (x == 8 && y == 6) || (x == 6 && y == 9))
					painter->paint_cell(WALL_ANGLE_LB_TEXTURE, x, y);
				if(x == 12 && y == 1)
					painter->paint_cell(WALL_ANGLE_LT_TEXTURE, x, y);
				if(x == 14 && y == 1)
					painter->paint_cell(WALL_ANGLE_RB_TEXTURE, x, y);
				if((x == 9 && y == 0) || (x == 2 && y == 4) || (x == 14 && y == 5) || (x == 6 && y == 8))
					painter->paint_cell(WALL_ANGLE_RT_TEXTURE, x, y);

				if((x == 4 && y == 1) || (x == 9 && (y == 9 || y == 3)) || (x == 6 && y == 5) || (x == 10 && y == 6))
					painter->paint_cell(WALL_END_R_TEXTURE, x, y);
				if((x == 7 && y == 0) || (x == 6 && y == 3) || ((x == 4 || x == 13) && y == 5) || (x == 2 && y == 8))
					painter->paint_cell(WALL_END_L_TEXTURE, x, y);
				if((x == 9 && y == 1) || (x == 12 && y == 3) || (x == 2 && y == 5) || (x == 14 && y == 6))
					painter->paint_cell(WALL_END_B_TEXTURE, x, y);
				if(x == 12 && y == 8)
					painter->paint_cell(WALL_END_T_TEXTURE, x, y);

			} else {
				field.set_cell(std::make_unique<Cell>(false), x, y);
				painter->paint_cell(CELL_TEXTURE, x, y);
			}
		}
	}
	field.set_cell(std::make_unique<Start_cell>(), 0, 0);
	painter->paint_cell(START_TEXTURE, 0, 0);

	field.set_cell(std::make_unique<Finish_cell>(game), 0, 3);
	painter->paint_cell(FINISH_TEXTURE, 0, 3);

	return field;
}
