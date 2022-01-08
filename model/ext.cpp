#ifndef EXT
#define EXT 1

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

/**
 * @brief This is mostly used to print the surfaces (represent by an int in BIP)
 * 
 * @param connection_surface The surface in int format (see structure dir_type)
 * @return char* --- The surface name
 */
char* connection (int connection_surface) {
	switch (connection_surface) {
		case dir_type::top: return (char*)("Top");
		case dir_type::front: return (char*)("Front");
		case dir_type::left: return (char*)("Left");
		case dir_type::right: return (char*)("Right");
		case dir_type::back: return (char*)("Back");
		case dir_type::bottom: return (char*)("Bottom");
		default: return (char*)("No_connection");
	}
}
#endif