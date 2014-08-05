/*
 * hec2dec.h
 *
 *  Created on: 04 рту. 2014 у.
 *      Author: Viktor
 */
#include <stdio.h>
#ifndef HEC2DEC_H_
#define HEC2DEC_H_
int hec2dec(char[]); /* function get string in format 0x**** or 0X**** or **** and return number if succes or -1 if error */
int in2hec(char in[]); /* function get string in format 0x**** or 0X**** or **** and set hec string in input array in format **** [0-9 a,b,c,d,e,f]. return 0 if succes or 1 if error */
int dec(char);

int in2hec(char in[]) {
	char hec[5];
	hec[4] = '\0';
	int pos = 0, kol = 0, try = 0;
	if (in[1] == 'x' || in[1] == 'X')
		pos = 2;
	while (kol <= 3) {
		if (in[pos] == '0' || in[pos] == '1' || in[pos] == '2' || in[pos] == '3'
				|| in[pos] == '4' || in[pos] == '5' || in[pos] == '6'
				|| in[pos] == '7' || in[pos] == '8' || in[pos] == '9') {
			hec[kol] = in[pos];
			try = 1;
		}
		if (in[pos] == 'a' || in[pos] == 'A') {
			hec[kol] = 'a';
			try = 1;
		}
		if (in[pos] == 'b' || in[pos] == 'B') {
			hec[kol] = 'b';
			try = 1;
		}
		if (in[pos] == 'c' || in[pos] == 'C') {
			hec[kol] = 'c';
			try = 1;
		}
		if (in[pos] == 'd' || in[pos] == 'D') {
			hec[kol] = 'd';
			try = 1;
		}
		if (in[pos] == 'e' || in[pos] == 'E') {
			hec[kol] = 'e';
			try = 1;
		}
		if (in[pos] == 'f' || in[pos] == 'F') {
			hec[kol] = 'f';
			try = 1;
		}
		if (try) {
			pos = pos + 1;
			kol = kol + 1;
			try = 0;
		} else
			return 1;
	}
	for (pos = 0; pos <= 3; pos = pos + 1)
		in[pos] = hec[pos];
	return 0;
}

int dec(char in) {
	if (in == '0' || in == '1' || in == '2' || in == '3' || in == '4'
			|| in == '5' || in == '6' || in == '7' || in == '8' || in == '9')
		return ('0' - in);
	if (in == 'a' || in == 'A')
		return 10;
	if (in == 'b' || in == 'B')
		return 11;
	if (in == 'c' || in == 'C')
		return 12;
	if (in == 'd' || in == 'D')
		return 13;
	if (in == 'e' || in == 'E')
		return 14;
	if (in == 'f' || in == 'F')
		return 15;
	else
		return -1;
}

int hec2dec(char in[]) {
	int res = in2hec(in);
	if (res == 1)
		return -1;
	res = dec(in[3]);
	res = res + dec(in[2]) * 16;
	res = res + dec(in[1]) * (16 * 16);
	res = res + dec(in[0]) * (16 * 16 * 16);
	return res;
}

#endif /* HEC2DEC_H_ */
