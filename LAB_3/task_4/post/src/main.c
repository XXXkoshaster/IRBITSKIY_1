#include "../include/core.h"

void case_1(POST* post);
void case_2(POST* post);
void case_3(POST* post);
void case_4(POST* post);
void case_5(POST* post);
void case_6(POST* post);
void handle_user_input(POST* post);
int is_deliveried(const MAIL* mail);
int compare_creation_time(const void* a, const void* b);

int main() {
    RESPONSES response = create_post(NULL);
    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        return 1;
    }

    POST* post = (POST*)response.data;
    handle_user_input(post);
    delete_post(post);
    return 0;
}

void handle_user_input(POST* post)
{
  while(1) {
    printf("\nChoose option:\n");
    printf("1. Add MAIL to POST\n");
    printf("2. Remove MAIL from POST\n");
    printf("3. Find MAIL by postal ID\n");
    printf("4. Sort MAILS\n");
    printf("5. Find deliveried MAILS\n");
    printf("6. Find not deliveried MAILS\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 7)
        break;

    switch (choice) {
      case 1: {
        case_1(post);
        break;
      }
      case 2: {
        case_2(post);
        break;
      }
      case 3: {
        case_3(post);
        break;
      }
      case 4: {
        case_4(post);
        break;
      }
      case 5: {
        case_5(post);
        break;
      }
      case 6: {
        case_6(post);
        break;
      }
      default: {
        printf("Invalid choice\n");
        break;
      }
    }
  }
}

void case_1(POST* post) 
{
    ADDRESS recipient_address;
    double weight;
    char postal_id[100];
    char time_delivery[100];
    char time_creation[100];

    recipient_address.city.data = (char*)malloc(100 * sizeof(char));
    recipient_address.street.data = (char*)malloc(100 * sizeof(char));
    recipient_address.building.data = (char*)malloc(100 * sizeof(char));
    recipient_address.index.data = (char*)malloc(100 * sizeof(char));

    printf("Enter recipient address (city, street, home number, building, apartment number, index): ");
    scanf("%s %s %d %s %d %s", recipient_address.city.data, recipient_address.street.data, &recipient_address.home_number, recipient_address.building.data, &recipient_address.apartment_number, recipient_address.index.data);
    printf("Enter weight: ");
    scanf("%lf", &weight);
    printf("Enter postal ID: ");
    scanf("%s", postal_id);
    printf("Enter delivery time: ");
    scanf("%s", time_delivery);
    printf("Enter creation time: ");
    scanf("%s", time_creation);

    RESPONSES response = create_mail(recipient_address, weight, postal_id, time_delivery, time_creation);    
    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        return;
    }
    
    MAIL* mail = (MAIL*)response.data;

    response = add_mail_to_post(post, *mail); 
    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        free(mail);
        return;
    } 

    free(mail);
    return;
}

void case_2(POST* post)
{
    char postal_id[100];
    printf("Enter postal ID: ");
    scanf("%s", postal_id);

    RESPONSES response = remove_mail_from_post(post, postal_id);
    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        return;
    }

    return;
}

void case_3(POST* post)
{
    char postal_id[100];
    printf("Enter postal ID: ");
    scanf("%s", postal_id);

    RESPONSES response = find_mail_by_postal_id(post, postal_id);
    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        return;
    }

    MAIL* mail = (MAIL*)response.data;
    print_mail(mail);

    return;
}

void case_4(POST* post)
{
    RESPONSES response = sort_mails(post);
    if (response.status != DONE) {
        printf("Error: %s\n", response.message);
        return;
    }

    for (int i = 0; i < post->mail_count; i++) {
        print_mail(&post->mails[i]);
    }

    return;
}

void case_5(POST* post) 
{
    printf("Deliveried mails:\n");

    qsort(post->mails, post->mail_count, sizeof(MAIL), compare_creation_time);

    for(int i = 0; i < post->mail_count; i++) {
        if (is_deliveried(&post->mails[i])) {
            print_mail(&post->mails[i]);
        }
    }
}

void case_6(POST* post) 
{
    printf("Not deliveried mails:\n");

    qsort(post->mails, post->mail_count, sizeof(MAIL), compare_creation_time);

    for(int i = 0; i < post->mail_count; i++) {
        if (!is_deliveried(&post->mails[i])) {
            print_mail(&post->mails[i]);
        }
    }
}

int is_deliveried(const MAIL* mail) {
    time_t now = time(NULL);
    struct tm tm;
    strptime(mail->time_delivery.data, "%d:%m:%Y_%H:%M:%S", &tm);
    time_t delivery_time = mktime(&tm);
    return difftime(now, delivery_time) >= 0;
}

int compare_creation_time(const void* a, const void* b) {
    MAIL* mail_a = (MAIL*)a;
    MAIL* mail_b = (MAIL*)b;

    struct tm tm_a, tm_b;
    strptime(mail_a->time_creation.data, "%d:%m:%Y_%H:%M:%S", &tm_a);
    strptime(mail_b->time_creation.data, "%d:%m:%Y_%H:%M:%S", &tm_b);

    time_t time_a = mktime(&tm_a);
    time_t time_b = mktime(&tm_b);

    return difftime(time_a, time_b);
}