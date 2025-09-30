#include <string.h>
#include "domain.h"

int compareRecords(Record a, Record b) {
    int cmp = strcmp(a.student, b.student);
    if (cmp == 0) return strcmp(a.subject, b.subject);
    return cmp;
}
