#include <stdio.h>
#include <string.h>

struct 	student {
	char	name[20+1];
	int		year;
	float	score;
};

void main(int arc, char **argv) {
	int size = 0;

	struct student	student_hong = {"hong", 2009, 95.5};

	struct student	student_lee = {0, };
	strcpy(student_lee.name, "lee");
	student_lee.year = 2009;
	student_lee.score = 95.5;

	size = sizeof(student_hong);
	printf("구조체 변수 student_hong의 크기: %d\n", size);
	printf("student_hong의 name: %s\n", student_hong.name);
	printf("student_hong의 year: %d\n", student_hong.year);
	printf("student_hong의 score: %f\n", student_hong.score);

	printf("student_lee의 name: %s\n", student_lee.name);
	printf("student_lee의 year: %d\n", student_lee.year);
	printf("student_lee의 score: %f\n", student_lee.score);
}
