/* shared.h
 * Holds constants and enums shared between files
 *
 */
#ifndef SHARED_H
#define SHARED_H

namespace constants{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 512;
	const int SPRITE_SCALE = 1;
};

namespace directions{
	enum Direction{
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
};
#endif