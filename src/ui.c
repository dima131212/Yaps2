#include <stdio.h>
#include <locale.h>
#include "ui.h"
#include "collection.h"
#include "domain.h"

void runMenu() {
    setlocale(LC_ALL, "Russian");
    Node* root = NULL;
    Record r;
    int choice;

    while (1) {
        printf("\n����:\n1. �������� ������\n2. ������� ������\n3. ����� �� ��������\n4. ����� ������\n5. �����\n");
        int result = scanf_s("%d", &choice);

        if (result != 1) {
            printf("������: ����� ������ �����!\n");
            choice = -1;
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }

        if (choice == 1) {
            char student[50], subject[50];
            int grade =0;
            printf("������� ���, �������, ������: ");

            scanf_s("%49s %49s %d",
                r.student, (unsigned)(sizeof(r.student) / sizeof(r.student[0])),
                r.subject, (unsigned)(sizeof(r.subject) / sizeof(r.subject[0])),
                &r.grade);


            root = insert(root, r);
        }
        else if (choice == 2) {
            char student[50], subject[50];
            printf("������� ��� � �������: ");

            scanf_s("%49s %49s",
                r.student, (unsigned)(sizeof(r.student) / sizeof(r.student[0])),
                r.subject, (unsigned)(sizeof(r.subject) / sizeof(r.subject[0])));
            r.grade = 0;

            root = delete(root, r);
        }
        else if (choice == 3) {
            char subject[50];
            printf("������� �������: ");
            scanf_s("%49s", subject, (unsigned)(sizeof(subject) / sizeof(subject[0])));
            searchBySubject(root, subject);
        }
        else if (choice == 4) {
            printf("��� ������ � ������:\n");
            printTree(root);
        }
        else if (choice == 5) break;
    }
}
