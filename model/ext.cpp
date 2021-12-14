#ifndef EXT
#define EXT

using namespace std;
#include "stdio.h"
#include <iostream>
#include<cstdlib>

typedef enum {
	top = 1,
	front = 2,
	left = 4,
	right = 8,
	back = 16,		
	bottom = 32

} dir_type;


char* connection (int connection_surface) {
	switch (connection_surface) {
		case dir_type::top: return "Top";
		case dir_type::front: return "Front";
		case dir_type::left: return "Left";
		case dir_type::right: return "Right";
		case dir_type::back: return "Back";
		case dir_type::bottom: return "Bottom";
		default: return "No_connection";
	}
}
#endif