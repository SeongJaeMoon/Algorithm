#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct 	student {
	char	name[20+1];
	int		year;
	float	score;
};

void main(int arc, char **argv) {
	int	*ptr_int = NULL;
	int **pptr_int_array = NULL;
	int i = 0, j = 0;
	int row = 3;
	int col = 4;
	int value = 0;
	struct student student_lee;
	struct student *ptr_student = NULL;
	struct student *ptr_student_new = NULL;

	ptr_int = (int *) malloc(sizeof(int) * 100);
	if (ptr_int != NULL) {
		printf("메모리 할당에 성공하였습니다\n");

		memset(ptr_int, 0, sizeof(int) * 100);

		free(ptr_int);
	}

	pptr_int_array = (int **) malloc(sizeof(int*) * row);
	memset(pptr_int_array, 0, sizeof(int*) * row);

	for(i = 0; i < row; i++) {
		pptr_int_array[i] = (int *) malloc(sizeof(int) * col);
		memset(pptr_int_array[i], 0, sizeof(int) * col);
	}

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			value++;
			pptr_int_array[i][j] = value;
		}
	}

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			printf("%d\t", *(*(pptr_int_array + i) + j) );
		}
		printf("\n");
	}

	for(i = 0; i < row; i++) {
		free(pptr_int_array[i]);
	}
	free(pptr_int_array);

	ptr_student = &student_lee;
	strcpy(ptr_student->name, "lee");
	ptr_student->score = 80.1f;
	ptr_student->year = 2005;

	printf("%s, %f, %d\n", student_lee.name, 
							student_lee.score, 
							student_lee.year);

	ptr_student_new = (struct student*) malloc(sizeof(struct student) * 1);
	if (ptr_student_new != NULL) {
		strcpy((*ptr_student_new).name, "new");
		(*ptr_student_new).score = 99.9f;
		(*ptr_student_new).year = 2010;

		printf("%s, %f, %d\n", ptr_student_new->name, 
							ptr_student_new->score, 
							ptr_student_new->year);

		free(ptr_student_new);
	}
}
