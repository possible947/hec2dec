/*
 * main.c
 *
 *  Created on: 05 рту. 2014 у.
 *      Author: Viktor
 */
#include "hec2dec.h"

int main() {
	char in[7], c;
	int pos = 0;
	while ((c = getchar()) != '\n' || pos <= 5) {
		in[pos] = c;
		pos = pos + 1;
	}
	in[pos] = '\0';
	int res = hec2dec(in);
	if (res != -1) {
		printf("%d", hec2dec(in));
		return 0;
	}
	printf("error");
	return -1;
}

