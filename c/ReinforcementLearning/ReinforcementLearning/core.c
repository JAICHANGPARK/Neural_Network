#include <stdio.h>
#include <stdlib.h>

#define GENMAX 500
#define NODE_NUMBER 15
#define ALPHA 0.1
#define GAMMA 0.9
#define EPSILON 0.3
#define SEED 32767

double random_num_gen_1() {
	return (double)rand() / RAND_MAX;
}

int random_num_gen_1_int() {
	int random;

	while ((random = rand()) == RAND_MAX)
	{
	}
	return (int)((double)random / RAND_MAX * 2);
}

int random_num_gen_100() {
	int random;
	while ((random = rand()) == RAND_MAX)
	{
	}
	return (int)((double)random / RAND_MAX * 101);
}

void print_q_value(int qvalue[NODE_NUMBER]) {

	int i = 0;

	for (int i = 0; i < NODE_NUMBER; i++)
	{
		printf("%d \t", qvalue[i]);
	}
	printf("\n");
}
int update_qvalue(int s, int qvalue[NODE_NUMBER]) {

	int q_value;
	int q_max;

	if (s > 6)
	{
		if (s == 14) {
			q_value = qvalue[s] + ALPHA*(1000 - qvalue[s]);
		}else if (s == 11){
			q_value = qvalue[s] + ALPHA * (500 - qvalue[s]);
		}else{
			q_value = qvalue[s];
		}
	}else{
		if (qvalue[2 * s + 1] > qvalue[2 * s + 2]){
			q_max = qvalue[2 * s + 1];
		}else{
			q_max = qvalue[2 * s + 2];
		}

		q_value = qvalue[s] + ALPHA * (GAMMA*q_max - qvalue[s]);
	}
	return q_value;
}

int select_action(int olds, int qvalue[NODE_NUMBER]) {
	
	int s = 0;

	if (random_num_gen_1() < EPSILON)
	{
		if (random_num_gen_1_int() == 0) {
			s = 2 * olds + 1;

		}
		else
		{
			s = 2 * olds + 2;
		}
	}
	else
	{
		if (qvalue[2 * olds + 1] > qvalue[2 * olds + 2]) {
			s = 2 * olds + 1;
		}
		else
		{
			s = s * olds + 2;
		}
		
	}
	return s;

}
int main() {
	int i = 0, s = 0, t = 0;
	int qvalue[NODE_NUMBER];
	srand(SEED);

	for (int i = 0; i < NODE_NUMBER; i++)
	{
		qvalue[i] = random_num_gen_100();
	}
	print_q_value(qvalue);

	for (int i = 0; i < GENMAX; i++)
	{
		s = 0;
		for (int t = 0; t < 3; t++)
		{
			s = select_action(s, qvalue);
			qvalue[s] = update_qvalue(s, qvalue);

		}
		print_q_value(qvalue);
	}

	return 0;
}