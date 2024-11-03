#include "../include/core.h"

RESPONSES create_mail(ADDRESS recipient_address, double weight, const char* postal_id, const char* time_delivery, const char* time_creation)
{
    MAIL* mail = (MAIL*)malloc(sizeof(MAIL));
    if (mail == NULL)
        return create_error_response(INVALID_ALLOCATION_MEMORY, "invalid allocation memory for mail");

    mail->recipient_address = recipient_address;
    mail->weight = weight;
    mail->postal_id = *(create_string_decorator(postal_id));
    mail->time_delivery = *(create_string_decorator(time_delivery));
    mail->time_creation = *(create_string_decorator(time_creation));

    return create_success_response(mail);
}

RESPONSES delete_mail(MAIL* mail)
{
    if (mail == NULL)
        return create_error_response(INVALID_INPUT, "mail is NULL");

    delete_string(&mail->postal_id);
    delete_string(&mail->time_delivery);
    delete_string(&mail->time_creation);

    return create_success_response(NULL);
}

RESPONSES create_post(ADDRESS* current_address)
{
    POST* post = (POST*)malloc(sizeof(POST));
    if (post == NULL)
        return create_error_response(INVALID_ALLOCATION_MEMORY, "invalid allocation memmory for post");

    post->current_address = current_address;
    post->mails = NULL;
    post->mail_count = 0;

    return create_success_response(post);
}

RESPONSES delete_post(POST* post)
{
    if (post == NULL)
        return create_error_response(INVALID_INPUT, "post is NULL");

    for (int i = 0; i < post->mail_count; i++)
        delete_mail(&post->mails[i]);
    
    if (post->mails != NULL)
        free(post->mails);

    free(post);

    return create_success_response(NULL);
}

RESPONSES add_mail_to_post(POST* post, MAIL mail)
{
    if(post == NULL)
        return create_error_response(INVALID_INPUT, "post is NULL");
    
    MAIL* new_mails = (MAIL*)realloc(post->mails, (post->mail_count + 1) * sizeof(MAIL));
    if (new_mails == NULL)
        return create_error_response(INVALID_ALLOCATION_MEMORY, "invalid allocation memory for mails");

    post->mails = new_mails;
    post->mails[post->mail_count] = mail;
    post->mail_count++;
    
    return create_success_response(NULL);
}

RESPONSES remove_mail_from_post(POST* post, const char* postal_id)
{
    if (post == NULL)
        return create_error_response(INVALID_INPUT, "post is NULL");
    
    for (int i = 0; i < post->mail_count; i++) {
        if (my_strcmp(post->mails[i].postal_id.data, postal_id) == 0) {
            delete_mail(&post->mails[i]);
            
            for (int j = i; j < post->mail_count - 1; j++)
                post->mails[j] = post->mails[j + 1];

            post->mail_count--;
            post->mails = (MAIL*)realloc(post->mails, post->mail_count * sizeof(MAIL));

            return create_success_response(NULL);
        }
    }

    return create_error_response(NOT_FOUND, "mail not found");
}

RESPONSES find_mail_by_postal_id(POST* post, const char* postal_id)
{
    if (post == NULL)
        return create_error_response(INVALID_INPUT, "post is NULL");
    
    for (int i = 0; i < post->mail_count; i++) {
        if (my_strcmp(post->mails[i].postal_id.data, postal_id) == 0)
            return create_success_response(&post->mails[i]);
    }

    return create_error_response(NOT_FOUND, "mail not found");
}

int comparator_mails(const void* a, const void* b)
{
    MAIL* mail_a = (MAIL*)a;
    MAIL* mail_b = (MAIL*)b;

    int postal_code_cmp = my_strcmp(mail_a->recipient_address.index.data, mail_b->recipient_address.index.data);
    if (postal_code_cmp != 0)
        return postal_code_cmp;
    
    return my_strcmp(mail_a->postal_id.data, mail_b->postal_id.data);
}

RESPONSES sort_mails(POST* post)
{
    if (post == NULL)
        return create_error_response(INVALID_INPUT, "post is NULL");

    qsort(post->mails, post->mail_count, sizeof(MAIL), comparator_mails);

    return create_success_response(NULL);
}

RESPONSES print_mail(const MAIL* mail)
{
    if (mail == NULL)
        return create_error_response(INVALID_INPUT, "mail is NULL");
    
    printf("Postal ID: %s\n", mail->postal_id.data);
    printf("Recipient Address: %s, %s, %d, %s, %d, %s\n",
           mail->recipient_address.city.data,
           mail->recipient_address.street.data,
           mail->recipient_address.home_number,
           mail->recipient_address.building.data,
           mail->recipient_address.apartment_number,
           mail->recipient_address.index.data);
    printf("Weight: %.2f\n", mail->weight);
    printf("Creation Time: %s\n", mail->time_creation.data);
    printf("Delivery Time: %s\n", mail->time_delivery.data);

    return create_success_response(NULL);
}

RESPONSES print_all_mails(const POST* post)
{
    if (post == NULL)
        return create_error_response(INVALID_INPUT, "post is NULL");

    for (int i = 0; i < post->mail_count; i++) {
        RESPONSES response = print_mail(&post->mails[i]);
        handle_error(response);
        printf("\n");
    }

    return create_success_response(NULL);
}