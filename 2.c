#include <stdio.h>

struct Student 
{
    int roll_no;
    char name[100];
    int chem_marks;
    int maths_marks;
    int phy_marks;
};
float calculatePercentage(int chem_marks, int maths_marks, int phy_marks) 
{
    int total_marks = chem_marks + maths_marks + phy_marks;
    return (float)total_marks / 300 * 100;
}
void displayStudentDetails(struct Student student) 
{
    float percentage = calculatePercentage(student.chem_marks, student.maths_marks, student.phy_marks);
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("Chemistry Marks: %d\n", student.chem_marks);
    printf("Mathematics Marks: %d\n", student.maths_marks);
    printf("Physics Marks: %d\n", student.phy_marks);
    printf("Percentage: %.2f%%\n", percentage);
    printf("----------------------------------------\n");
}
main() 
{
    struct Student students[5];
    for (int i = 0; i < 5; ++i) 
	{
        printf("Enter details of Student %d:\n", i + 1);
        printf("Roll no => ");
        scanf("%d", &students[i].roll_no);
        getchar();

        printf("Name => ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        size_t len = strlen(students[i].name);
        if (len > 0 && students[i].name[len-1] == '\n') 
		{
            students[i].name[len-1] = '\0';
        }

        printf("Chemistry => ");
        scanf("%d", &students[i].chem_marks);

        printf("Mathematics => ");
        scanf("%d", &students[i].maths_marks);

        printf("Physics => ");
        scanf("%d", &students[i].phy_marks);

        getchar(); 
        printf("----------------------------------------\n");
    }

    for (int i = 0; i < 5; ++i) 
	{
        displayStudentDetails(students[i]);
    }
}
