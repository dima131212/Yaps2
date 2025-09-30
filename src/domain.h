#ifndef DOMAIN_H
#define DOMAIN_H

typedef struct {
    char student[50];
    char subject[50];
    int grade;
} Record;

int compareRecords(Record a, Record b);

#endif
