#ifndef EXT
#define EXT

using namespace std;
#include "stdio.h"
#include <iostream>
#include<cstdlib>

const char* connection (int connection_surface) {
	switch (connection_surface) {
		case 1: return "Left ";
		case 2: return "Right ";
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
#endif