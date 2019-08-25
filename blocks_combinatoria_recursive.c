#include <stdio.h>

int countPath(int blocks_south, int blocks_west) {      // non-tail recursive
    
    if (blocks_south == 0 && blocks_west == 0) {
        return 1;      // reached destination
    } else if (blocks_south == 0) {
        return countPath(0, blocks_west - 1);
    } else if (blocks_west == 0) {
        return countPath(blocks_south - 1, 0);
    } else {
        return countPath(blocks_south - 1, blocks_west) + countPath(blocks_south, blocks_west - 1);
    }                                   

}


int main(int argc, char **argv) {

    int blocks_south, blocks_west;

    if (argc != 3) {                   // check for two numbers as input
        printf("Please input the number of blocks south and the number of blocks west at the start");
        return -1;
    }

    blocks_south = atoi(argv[1]);
    blocks_west = atoi(argv[2]);

    if (argv[1] <= 0 || argv[2] <= 0) {                        // error if one arg <= 0
        printf("Please input natural numbers");
        return -1;
    }

    int result = countPath(blocks_south, blocks_west);           
    printf("result: %d\r\n", result);

    return 0;
}