#include "../include/core.h"

#define INVALID_USAGE 1
#define INVALID_FLAG 2
#define SUCCESS 0

void coount_students(FILE* file, int* count);
void handle_user_input(STUDENT* students, int count);
RESPONSES read_studens_from_file(const char* filename, STUDENT** students, int* count);
void case_1(STUDENT* students, int count);
void case_2(STUDENT* students, int count);
void case_3(STUDENT* students, int count);
void case_4(STUDENT* students, int count);
void case_5(STUDENT* students, int count);
void case_6(STUDENT* students, int count);
void case_7(STUDENT* students, int count);

int main(int argc, char** argv)
{
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return INVALID_USAGE;
  }

  STUDENT* students = NULL;
  int count = 0;

  RESPONSES response = read_studens_from_file(argv[1], &students, &count);
  if (response.status != DONE) {
    printf("Error reading students from file (%s)\n", response.message);
    return response.status;
  }

  handle_user_input(students, count);

  return SUCCESS;
}

RESPONSES read_studens_from_file(const char* filename, STUDENT** students, int* count)
{
  FILE* file;
  RESPONSES response;

  response = decarator_fopen(filename, "r", &file);
  if (response.status != DONE)
    return response;
  
  coount_students(file, count);
  fclose(file);

  return read_studens(filename, students, *count);
}

void handle_user_input(STUDENT* students, int count)
{
  while(1) {
    printf("\nChoose option:\n");
    printf("1. Search student by ID\n");
    printf("2. Search students by last name\n");
    printf("3. Search students by first name\n");
    printf("4. Search students by group\n");
    printf("5. Write student by ID to file\n");
    printf("6. Write students above average to file\n");
    printf("7. Wryte students by sort to file\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 8)
        break;

    switch (choice) {
      case 1: {
        case_1(students, count);
        break;
      }
      case 2: {
        case_2(students, count);
        break;
      }
      case 3: {
        case_3(students, count);
        break;
      }
      case 4: {
        case_4(students, count);
        break;
      }
      case 5: {
        case_5(students, count);
        break;
      }
      case 6: {
        case_6(students, count);
        break;
      }
      case 7: {
        case_7(students, count);
        break;
      }
      default: {
        printf("Invalid choice\n");
        break;
      }
    }
  }
}

void case_1(STUDENT* students, int count)
{
  int id;
  printf("Enter student ID: ");
  scanf("%d", &id);
  
  STUDENT result;
  RESPONSES response = search_student_by_id(students, count, id, &result);
  
  if (response.status == DONE) {
    printf("Student found: FIO: %s %s, Group: %s", result.first_name, result.last_name, result.group);
    printf("Average mark: %.2f\n", calculate_average_mark(result));
  } else {
    printf("Student not found (%s)\n", response.message);
  }
}

void case_2(STUDENT* students, int count)
{         
  char last_name[50];
  printf("Enter student last name:");
  scanf("%s", last_name);
  
  STUDENT* results = NULL;
  int results_count = 0;
  
  RESPONSES response = search_students_by_last_name(students, count, last_name, &results, &results_count);
  
  if (response.status == DONE) {
    printf("Students found:\n");
    
    for (int i = 0; i < results_count; i++) {
      printf("ID: %d, Name: %s %s, Group: %s", results[i].id, results[i].first_name, results[i].last_name, results[i].group);
      printf("Average mark: %.2f\n", calculate_average_mark(results[i]));
    }

    free(results);
  } else {
    printf("Students not found (%s)\n", response.message);
  }
}

void case_3(STUDENT* students, int count)
{
  char first_name[50];
  printf("Enter student first name:");
  scanf("%s", first_name);
  
  STUDENT* results = NULL;
  int results_count = 0;
  
  RESPONSES response = search_students_by_first_name(students, count, first_name, &results, &results_count);
  
  if (response.status == DONE) {
    printf("Students found:\n");
    
    for (int i = 0; i < results_count; i++) {
      printf("ID: %d, FIO: %s %s, Group: %s", results[i].id, results[i].first_name, results[i].last_name, results[i].group);
      printf("Average mark: %.2f\n", calculate_average_mark(results[i]));
    }

    free(results);
  } else {
    printf("Students not found (%s)\n", response.message);
  }
}

void case_4(STUDENT* students, int count)
{
  char group[50];
  printf("Enter student first name:");
  scanf("%s", group);
  
  STUDENT* results = NULL;
  int results_count = 0;
  
  RESPONSES response = search_students_by_group(students, count, group, &results, &results_count);
  
  if (response.status == DONE) {
    printf("Students found:\n");
    
    for (int i = 0; i < results_count; i++) {
      printf("ID: %d, FIO: %s %s, Group: %s", results[i].id, results[i].first_name, results[i].last_name, results[i].group);
      printf("Average mark: %.2f\n", calculate_average_mark(results[i]));
    }

    free(results);
  } else {
    printf("Students not found (%s)\n", response.message);
  }
}

void case_5(STUDENT* students, int count)
{
  int id;
  char output_filename[4096];
  
  printf("Enter student ID: ");
  scanf("%d", &id);
  printf("Enter output filename: ");
  scanf("%s", output_filename);

  RESPONSES response = write_student_by_id_to_file(output_filename, id, students, count);
  
  if (response.status == DONE) {
    printf("Student written to file\n");
  } else {
    printf("Error writing student to file (%s)\n", response.message);
  }
}

void case_6(STUDENT* students, int count)
{
  char output_filename[4096];
  
  printf("Enter output filename: ");
  scanf("%s", output_filename);

  RESPONSES response = write_students_above_average_to_file(output_filename, students, count);
  
  if (response.status == DONE) {
    printf("Students written to file\n");
  } else {
    printf("Error writing students to file (%s)\n", response.message);
  }
}

void case_7(STUDENT* students, int count)
{
  char output_filename[4096];
  char sort_flag[50];

  printf("Enter output filename: ");
  scanf("%s", output_filename);

  printf("Enter sort flag (id/first_name/last_name/group): ");
  scanf("%s", sort_flag);

  RESPONSES response = write_students_by_sort_to_file(output_filename, students, count, sort_flag);

  if (response.status == DONE) {
    printf("Students written to file\n");
  } else {
    printf("Error writing students to file (%s)\n", response.message);
  }
}

void coount_students(FILE* file, int* count)
{
    char buffer[256];
    *count = 0;

    while (fgets(buffer, 256, file) != NULL)
        (*count)++;
    
    *count /= 9;
}
