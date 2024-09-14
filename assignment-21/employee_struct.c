#include <stdio.h>

/* regarding line 34: https://stackoverflow.com/questions/6282198/reading-string-from-input-with-space-character */

/* first structure hold all the details for an employee */
struct employee_details {
    char firstName[20];
    char lastName[20];
    char title[25];
    int employee_ID;
    int SSN;
};

/* second structure will hold each employee, by using the first struct to store those details */
struct employee {
    struct employee_details employee1;
    struct employee_details employee2;
} employees;

void get_employee_details(struct employee_details *person) {
    /* get_employee_details: Get input about each employee, and store it. */
    printf("Enter the employee's first name: ");
    /* limit scanf to only 20 characters for the first name */
    scanf("%20s", person->firstName);
    //fgets(person->firstName, 20, stdin);
    printf("Enter the employee's last name: ");
    scanf("%20s", person->lastName);
    //fgets(person->lastName, 20, stdin);
    printf("Enter the employee's ID: ");
    scanf("%d", &person->employee_ID);
    printf("Enter the employee's SSN: ");
    scanf("%d", &person->SSN);
    printf("Enter the employee's title: ");
    /*scanf(" %[^\n]%*c", person->title); */
    /* use empty scanf so that fgets can scan your input */
    scanf(" %c", NULL);
    fgets(person->title, 25, stdin);
}

void print_employee_details(struct employee_details *person) {
    /* print_employee_details: Prints any existing employee's details that was previously saved. */
    printf("* * * * * * * * * *\nEmployee %s %s, %s\n", person->firstName, person->lastName, person->title);
    printf("Employee's ID: %d\nEmployee's SSN: %d\n* * * * * * * * * *\n\n", person->employee_ID, person->SSN);
}


int main(void) {
    /* initialize and assign a employee_details pointer to point to the first employee */
    struct employee_details *employee1_pointer;
    employee1_pointer = &employees.employee1;
    /* initialize and assign a employee_details pointer to point to the second employee */
    struct employee_details *employee2_pointer;
    employee2_pointer = &employees.employee2;

    /* Get employee information, for each employee */
    get_employee_details(employee1_pointer);
    printf("\n");
    get_employee_details(employee2_pointer);

    /* Now print that information for each employee */
    print_employee_details(employee1_pointer);
    print_employee_details(employee2_pointer);

    return 0;
}
