/* shared.h
 * Holds constants that are shared between many files
 *
 */
#ifndef SHARED_H
#define SHARED_H

namespace constants{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int SPRITE_SCALE = 2;
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