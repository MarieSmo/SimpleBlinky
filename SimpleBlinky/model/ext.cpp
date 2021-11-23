#include "stdio.h"

#include <iostream>


#define dir_modulus 63

typedef enum {
	left = 1,
	right = 2
} dir_type;


const char* connection (int connection_surface) {
	switch (connection_surface) {
		case left: return "Left ";
		case right: return "Right ";
		default: return "No_connection ";
	}
}

//what connected
int what_connected (const int seed_check, const int leaf_check){
	int seed = seed_check;
	int leaf = leaf_check;
	
	printf("\033[32m[Bogdan's output]:\033[0m SEEDs: ");
	
	if(seed == 0) printf(connection(seed));

    for(int i=0; i<2; i++){
        if(seed&(1<<i)){
            int s_outnumber = 1<<i;
            printf(connection(s_outnumber));			
        }
    }

	printf("\n\033[32m[Bogdan's output]:\033[0m LEAFs: ");
	
	if(leaf == 0) printf(connection(leaf));
    
	for(int i=0; i<2; i++){
        if(leaf&(1<<i)){
            int l_outnumber = 1<<i;
            printf(connection(l_outnumber));
        }
    }
	printf("\n");
	return 1;
}