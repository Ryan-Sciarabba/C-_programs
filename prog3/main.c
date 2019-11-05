#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <errno.h>

const int LINE_CNT = 20;

int check_args_for_how_many_bits(int argc, char *argv[]);
void print_bin(uint64_t num, unsigned int bit_cnt);

/*
 *  ALL YOU NEED TO DO IS MODIFY THIS FUNCTION
 *  (BOTTOM OF CODE) TO RETURN A BIT PATTERN OF
 *  ALL ZEROS WITH ITS LOWEST "bit_cnt" BITS
 *  RANDOMIZED.
 */
uint64_t rand_bits(unsigned int bit_cnt);

int main(int argc, char *argv[]) {

	int i;
	int how_many_bits = check_args_for_how_many_bits(argc, argv);

	srand(time(NULL));

	/* Print a bunch of strings of 64 random bits */
	for(i = 0; i < LINE_CNT; i++) {
		uint64_t val64 = rand_bits(how_many_bits);
		print_bin(val64, 64);
	}

	/* Print a bunch of strings of 32 random bits */
	for(i = 0; i < LINE_CNT; i++) {
		uint32_t val32 = (uint32_t)rand_bits(how_many_bits);
		print_bin(val32, 32);
	}

	return EXIT_SUCCESS;
}


int check_args_for_how_many_bits(int argc, char *argv[]) {

	int how_many_bits;

	if(argc != 2) {
		fprintf(stderr, "usage:   prog3 <count>\n");
		fprintf(stderr, "  <count> is how many low order bits should be randomized\n");
		exit(EXIT_FAILURE);
	}

	how_many_bits = strtol(argv[1], NULL, 10);
	if(errno == ERANGE) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	else if(how_many_bits <= 0 || how_many_bits > 64){
		fprintf(stderr, "Need a bit count between [1, 64]\n");
		exit(EXIT_FAILURE);
	}

	return how_many_bits;
}


void print_bin(uint64_t num, unsigned int bit_cnt) {

	int top_bit_cnt;

	if(bit_cnt <= 0) return;
	if(bit_cnt > 64) bit_cnt = 64;

	top_bit_cnt = 64;
	while(top_bit_cnt > bit_cnt) {
		top_bit_cnt--;
		printf(" ");
	}

	while(bit_cnt > 0) {
		bit_cnt--;
		printf("%d", (num & ((uint64_t)1 << bit_cnt)) != 0);
	}
	printf("\n");

	return;
}


/*
 * Name: rand_bits
 * Function: Returns a 64 bit pattern with all zeros except for the
 *           lowest requested bits, which are randomized.  This allows
 *           for arbitrary length random bit patterns in a portable fashion
 *           as the C standard "rand()" function is only required to return
 *           random numbers between 0 and 32767... effectively, a random
 *           15 bit pattern.
 * Parameter, "bit_cnt":  How many of the lowest bits, including the
 *           lowest order bit (bit 0) to be randomized
 * Return: A 64 bit pattern with the low bit_cnt bits randomized.
 */
uint64_t rand_bits(unsigned int bit_cnt) {

	uint64_t result;
	uint64_t mask = 0xFFFFFFFFFFFFFFFF>>(64 - bit_cnt);
    for(int i = 0; i < 4; i++){
        result = result<<15;
        result = result + rand();
    }
    result = result & mask;
	return result;
}
