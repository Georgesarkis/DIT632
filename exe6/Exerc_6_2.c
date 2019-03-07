// Program for exercise 6.2alt in DIT165
// Version 2017-12-31
// **************************************
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define num_elems 200
int array[200];
int max_value;

void *runner(void *param);
void *sort (void *param);
void *search (void *param);

int main() {
	time_t t;
	pthread_t tid, tid2 , tid3;
	pthread_attr_t attr , attr2 , attr3;
	
	srand((unsigned) time(&t));
	pthread_attr_init(&attr);

	printf("Enter max value\n");
	scanf("%d", &max_value);

	pthread_create(&tid, &attr, runner, NULL);
	pthread_join(tid, NULL);

	pthread_attr_init(&attr2);

	pthread_create(&tid2, &attr2, sort, NULL);
	pthread_join(tid2, NULL);

	pthread_attr_init(&attr3);

	pthread_create(&tid3, &attr3, search, NULL);
	pthread_join(tid3, NULL);

	return 0;
}

void *runner(void *param) {
	int c = 0, n=0;
    printf("runner funcation: generates a random list\n");
	for (c = 0; c < num_elems; c++) {
		for(n=0; n<1000; n++); // To delay a bit 
		array[c] = rand() % max_value;
	}

	pthread_exit(0);
}


void *sort (void *param){
    	int c, d, swap;
    printf("sort the list generated by the runner funcation\n");
	for (c = 0; c < num_elems; c++) {
		for (d = 0; d < num_elems - c - 1; d++) {
			if (array[d] > array[d + 1]) {
				swap = array[d];
				array[d] = array[d + 1];
				array[d + 1] = swap;
			}
		}
	}
}

void *search (void *param){
    printf("searching funcation: searches if the val is in the list\n");
    int search;
	printf("Enter value to find\n");
	scanf("%d", &search);

	int first = 0;
	int last = num_elems - 1;
	int middle = (first + last) / 2;
	int n;
	for(n=0; n<num_elems; n++){
	    printf("\n %d", array[n]);
	}

	while (first <= last) {
		if (array[middle] < search)
			first = middle + 1;
		else if (array[middle] == search) {
			printf("%d found at location %d.\n", search, middle + 1);
			break;
		} else
			last = middle - 1;

		middle = (first + last) / 2;
	}
	if (first > last)
		printf("Not found! %d is not present in the list.\n", search);

}