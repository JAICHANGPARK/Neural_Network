#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define BUFSIZE 256

int main(){

	char linebuff[BUFSIZE];
	double data;
	double sum = 0.0;
	double sum2 = 0.0;

	while (fgets(linebuff,BUFSIZE,stdin)!=NULL)
	{
		if (sscanf_s(linebuff, "%lf", &data) != 0){
			sum += data;
			sum2 += data * data;
			printf("%lf \t %lf \n", sum, sum2);
		}
	}

	return 0;
}