#include<stdio.h>
#include<string.h>

typedef struct student_score {
	char name[30];
	float kor;
	float eng;
	float mat;
	float avg;
	
}Student;

void SetStudent(Student*, char*, float, float, float);

int main() {
	Student* ptr_student_new = (Student*)malloc(sizeof(Student) * 5);
	SetStudent(ptr_student_new, "lee", 81, 79, 99);
	SetStudent(ptr_student_new+1, "kim", 80, 82, 78);
	SetStudent(ptr_student_new+2, "park", 79, 85, 75);
	SetStudent(ptr_student_new+3, "hong", 75, 87, 82);
	SetStudent(ptr_student_new+4, "jung", 90, 89, 65);

	for (int i = 0; i < 5; i++) {
		printf("%s    %f    %f    %f    %f\n", (ptr_student_new + i)->name, (ptr_student_new + i)->kor, (ptr_student_new + i)->eng, (ptr_student_new + i)->mat, (ptr_student_new + i)->avg);
	}
	return 0;
}

void SetStudent(Student* st_ptr, char* n, float k, float e, float m) {
	strcpy_s(st_ptr->name, 30, n);
	st_ptr->kor = k;
	st_ptr->eng = e;
	st_ptr->mat = m;
	st_ptr->avg = (k + e + m) / 3;

}

/*
* 해당하는 학생의 각 과목별 성적및 평균성적 산출 프로그램
	name	kor	eng	mat
	lee		81	79	99
	kim		80	82	78
	park	79	85	75
	hong	75	87	82
	jung	90	89	65
*/