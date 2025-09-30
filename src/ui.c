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
        printf("\nМеню:\n1. Добавить запись\n2. Удалить запись\n3. Поиск по предмету\n4. Вывод дерева\n5. Выход\n");
        int result = scanf_s("%d", &choice);

        if (result != 1) {
            printf("Ошибка: нужно ввести число!\n");
            choice = -1;
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }

        if (choice == 1) {
            char student[50], subject[50];
            int grade =0;
            printf("Введите имя, предмет, оценку: ");

            scanf_s("%49s %49s %d",
                r.student, (unsigned)(sizeof(r.student) / sizeof(r.student[0])),
                r.subject, (unsigned)(sizeof(r.subject) / sizeof(r.subject[0])),
                &r.grade);


            root = insert(root, r);
        }
        else if (choice == 2) {
            char student[50], subject[50];
            printf("Введите имя и предмет: ");

            scanf_s("%49s %49s",
                r.student, (unsigned)(sizeof(r.student) / sizeof(r.student[0])),
                r.subject, (unsigned)(sizeof(r.subject) / sizeof(r.subject[0])));
            r.grade = 0;

            root = delete(root, r);
        }
        else if (choice == 3) {
            char subject[50];
            printf("Введите предмет: ");
            scanf_s("%49s", subject, (unsigned)(sizeof(subject) / sizeof(subject[0])));
            searchBySubject(root, subject);
        }
        else if (choice == 4) {
            printf("Все записи в дереве:\n");
            printTree(root);
        }
        else if (choice == 5) break;
    }
}
