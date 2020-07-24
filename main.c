# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "student.c"

/**
 * ��������ѧ���ɼ���Ϣ
 * @param sa ѧ���ɼ���Ϣ�б�
 * @param n ����ӵ�ѧ������
 */
void create(studentList *sa, int n) {
    int i, j;
    char temp;
    float ave = 0, sum = 0;
    for (i = 0; i < n; i++) {
        printf("�������%d��ѧ������Ϣ��\n", i+1);
        printf("ѧ�ţ�");
        scanf("%d%c", &sa->elem[i].id, &temp);
        //Ϊ������������ȷ����Ҫȥ��¼��ѧ����Ϣʱ����Ļس�
        printf("������");
        gets(sa->elem[i].name);
        printf("���ſεĳɼ���Ӣ���ѧ���ߵ���ѧ�����ݽṹ������ϵͳ����������磺");
        for (j = 0; j < COURSENUM; j++) {
            scanf("%f", &sa->elem[i].scores[j]);
            sum+=sa->elem[i].scores[j];
        }
        sa->elem[i].averageGrade = sum / COURSENUM;
        sa->length = n;
        sum = 0;
    }
}

/**
 * չʾѧ���ɼ���Ϣ
 * @param sa ѧ���ɼ���Ϣ�б�
 */
void display(studentList sa) {
    int i, j;
    printf("%d��ѧ������Ϣ���£�\n", sa.length);
    printf("ѧ�š�������Ӣ���ѧ���ߵ���ѧ�����ݽṹ������ϵͳ����������硢ƽ����\n");
    for (i = 0; i < sa.length; i++) {
        printf("%d  %s", sa.elem[i].id, sa.elem[i].name);
        for (j = 0; j < COURSENUM; j++) {
            printf("%8.1f", sa.elem[i].scores[j]);
        }
        printf("%8.1f\n", sa.elem[i].averageGrade);
    }
}

/**
 * ����ID����ѧ���ɼ���Ϣ
 * @param sa ѧ���ɼ���Ϣ�б�
 * @param id ����ѯ��ѧ��ID
 */
void searchById(studentList sa, int id) {
    int i, j;
    for (i = 0; i < sa.length; i++) {
        if (sa.elem[i].id == id) {
            printf("ѧ�š�������Ӣ���ѧ���ߵ���ѧ�����ݽṹ������ϵͳ����������硢ƽ����\n");
            printf("%d  %s", sa.elem[i].id, sa.elem[i].name);
            for (j = 0; j < COURSENUM; j++) {
                printf("%8.1f", sa.elem[i].scores[j]);
            }
            printf("%8.1f\n", sa.elem[i].averageGrade);
            break;
        }
    }
    if (i == sa.length){
        printf("���޴��ˣ�\n");
    }
}

/**
 * ����ѧ����������ѧ���ɼ���Ϣ
 * @param sa ѧ���ɼ���Ϣ�б�
 * @param name ����ѯ��ѧ������
 */
void searchByName(studentList sa, char *name) {
    int i, j, flag = 0;
    for (i = 0; i < sa.length; i++) {
        if (strcmp(sa.elem[i].name, name) == 0) {
            printf("ѧ�š�������Ӣ���ѧ���ߵ���ѧ�����ݽṹ������ϵͳ����������硢ƽ����\n");
            printf("%d  %s", sa.elem[i].id, sa.elem[i].name);
            for (j = 0; j < COURSENUM; j++) {
                printf("%8.1f", sa.elem[i].scores[j]);
            }
            printf("%8.1f\n", sa.elem[i].averageGrade);
            flag = 1;
            break;
        }
    }
    if (!flag) {
        printf("���޴��ˣ�\n");
    }
}

/**
 * ��ѧ���ɼ��б�����ӵ���ѧ���ɼ���Ϣ
 * @param sa ѧ���ɼ��б�
 */
void add(studentList *sa) {
    int i;
    float sum = 0;
    char temp;
    printf("�������ѧ������Ϣ��\n");
    printf("ѧ�ţ�");
    scanf("%d%c", &sa->elem[sa->length].id, &temp);
    //Ϊ������������ȷ����Ҫȥ��¼��ѧ����Ϣʱ����Ļس�
    printf("������");
    gets(sa->elem[sa->length].name);
    printf("���ſεĳɼ���Ӣ���ѧ���ߵ���ѧ�����ݽṹ������ϵͳ����������磺");
    for (i = 0; i < COURSENUM; i++) {
        scanf("%f", &sa->elem[sa->length].scores[i]);
        sum+=sa->elem[sa->length].scores[i];
    }
    sa->elem[sa->length].averageGrade = sum / COURSENUM;
    sa->length++;
}

/**
 * ����ѧ��ѧ��ɾ��ѧ���ɼ���Ϣ
 * @param sa ѧ���ɼ��б�
 * @param id ��ɾ����ѧ��ID
 */
void deleteById(studentList *sa, int id) {
    int i, j, flag = 0;
    for (i = 0; i < sa->length; i++) {
        if (sa->elem[i].id == id) {
            for (j = i; j < sa->length; j++) {
                sa->elem[j] = sa->elem[j+1];
            }
            sa->length--;
            flag = 1;
            break;
        }
    }
    if (!flag) {
        printf("���޴��ˣ�\n");
    }
}

/**
 * ����ɼ�ƽ��ֵ
 * @param sa ѧ���ɼ��б�
 */
void calculateAverage(studentList *sa) {
    int i, j;
    float ave = 0, sum = 0;
    for (j = 0; j < COURSENUM; j++) {
        scanf("%f", &sa->elem[i].scores[j]);
        sum+=sa->elem[i].scores[j];
    }
    sa->elem[sa->length].averageGrade = sum / COURSENUM;
}

/**
 * ����ID�޸�ѧ���ɼ���Ϣ
 * @param sa ѧ���ɼ��б�
 * @param id ���޸ĵ�ѧ��ID
 */
void modifyById(studentList *sa, int id) {
    int selected;
    int flag = 0;
    char temp;
    for (int i = 0; i < sa->length; i++) {
        if (sa->elem[i].id == id) {
            for (;;) {
                printf("------��ѡ��Ҫ�޸ĵ���Ŀ��------\n");
                printf("        1:����\n");
                printf("        2:Ӣ��ɼ�\n");
                printf("        3:��ѧ�ɼ�\n");
                printf("        4:�ߵ���ѧ�ɼ�\n");
                printf("        5:���ݽṹ�ɼ�\n");
                printf("        6:����ϵͳ�ɼ�\n");
                printf("        7:���������ɼ�\n");
                printf("        8:�������˵�\n");
                scanf("%d", &selected);
                scanf("%c", &temp);
                switch (selected) {
                    case 1:
                        printf("����������");
                        gets(sa->elem[i].name);
                        break;
                    case 2:
                        printf("������Ӣ��ɼ���");
                        scanf("%f", &sa->elem[i].scores[0]);
                        calculateAverage(sa);
                        break;
                    case 3:
                        printf("��������ѧ�ɼ���");
                        scanf("%f", &sa->elem[i].scores[1]);
                        calculateAverage(sa);
                        break;
                    case 4:
                        printf("������ߵ���ѧ�ɼ���");
                        scanf("%f", &sa->elem[i].scores[2]);
                        calculateAverage(sa);
                        break;
                    case 5:
                        printf("���������ݽṹ�ɼ���");
                        scanf("%f", &sa->elem[i].scores[3]);
                        calculateAverage(sa);
                        break;
                    case 6:
                        printf("���������ϵͳ�ɼ���");
                        scanf("%f", &sa->elem[i].scores[4]);
                        calculateAverage(sa);
                        break;
                    case 7:
                        printf("��������������ɼ���");
                        scanf("%f", &sa->elem[i].scores[5]);
                        calculateAverage(sa);
                        break;
                    case 8:
                        return;
                }
            }
            flag = 1;
            break;
        }
    }
    if (!flag) {
        printf("���޴��ˣ�\n");
    }
}

/**
 * ����ĳһָ����Ŀ����
 * @param sa ѧ���ɼ��б�
 * @param course ������Ŀ�Ŀ
 */
void sortByOneCourse(studentList *sa, int course) {
    int i, j, max;
    student stu;
    for (i = 0; i < sa->length; i++) {
        max = i;
        for (j = i+1; j < sa->length; i++) {
            if (sa->elem[j].scores[course] > sa->elem[max].scores[course]) {
                max = j;
            }
        }
        if (max != i) {
            stu.id = sa->elem[i].id;
            strcpy(stu.name, sa->elem[i].name);
            for (j = 0; j < COURSENUM; j++) {
                stu.scores[j] = sa->elem[i].scores[j];
            }
            sa->elem[i].id = sa->elem[max].id;
            strcpy(sa->elem[i].name, sa->elem[max].name);
            for (j = 0; j < COURSENUM; j++) {
                sa->elem[i].scores[j] = sa->elem[max].scores[j];
            }
            sa->elem[max].id = stu.id;
            strcpy(sa->elem[max].name, stu.name);
            for (j = 0; j < COURSENUM; j++) {
                sa->elem[max].scores[j] = stu.scores[j];
            }
        }
    }
}

/**
 * ���ݿ�Ŀ����
 * @param sa ѧ���ɼ��б�
 */
void sortByCourse(studentList *sa) {
    int selected;
    for (;;) {
        printf("------��ѡ���������ݵĿ�Ŀ��------\n");
        printf("        1:Ӣ��\n");
        printf("        2:��ѧ\n");
        printf("        3:�ߵ���ѧ\n");
        printf("        4:���ݽṹ\n");
        printf("        5:����ϵͳ\n");
        printf("        6:���������\n");
        printf("        7:�������˵�\n");
        scanf("%d", &selected);
        switch (selected) {
            case 1:
                sortByOneCourse(sa, 0);
                break;
            case 2:
                sortByOneCourse(sa, 1);
                break;
            case 3:
                sortByOneCourse(sa, 2);
                break;
            case 4:
                sortByOneCourse(sa, 3);
                break;
            case 5:
                sortByOneCourse(sa, 4);
                break;
            case 6:
                sortByOneCourse(sa, 5);
                break;
            case 7:
                return;
        }
    }
}

/**
 * ͳ��ĳһ�����Ŀ�ķ�����
 * @param sa ѧ���ɼ��б�
 * @param course ��ͳ�ƵĿ�Ŀ
 */
void levelByOneCourse(studentList sa, int course) {
    int num[6] = {0};
    for (int i = 0; i < sa.length; i++) {
        if (sa.elem[i].scores[course] < 60) {
            num[0]++;
        } else if (sa.elem[i].scores[course] < 70) {
            num[1]++;
        } else if (sa.elem[i].scores[course] < 80) {
            num[2]++;
        } else if (sa.elem[i].scores[course] < 90) {
            num[3]++;
        } else {
            num[4]++;
        }
    }
    switch (course) {
        case 0:
            printf("Ӣ��ɼ������ηֲ�������60�����¡�60~69�֡�70~79�֡�80~89�֡�90�����Ϸֱ�Ϊ��\n");
            break;
        case 1:
            printf("��ѧ�ɼ������ηֲ�������60�����¡�60~69�֡�70~79�֡�80~89�֡�90�����Ϸֱ�Ϊ��\n");
            break;
        case 2:
            printf("�ߵ���ѧ�ɼ������ηֲ�������60�����¡�60~69�֡�70~79�֡�80~89�֡�90�����Ϸֱ�Ϊ��\n");
            break;
        case 3:
            printf("���ݽṹ�ɼ������ηֲ�������60�����¡�60~69�֡�70~79�֡�80~89�֡�90�����Ϸֱ�Ϊ��\n");
            break;
        case 4:
            printf("����ϵͳ�ɼ������ηֲ�������60�����¡�60~69�֡�70~79�֡�80~89�֡�90�����Ϸֱ�Ϊ��\n");
            break;
        case 5:
            printf("���������ɼ������ηֲ�������60�����¡�60~69�֡�70~79�֡�80~89�֡�90�����Ϸֱ�Ϊ��\n");
            break;
    }
    for (int i = 0; i < 5; i++) {
        printf("%6d", num[i]);
    }
    printf("\n");
}

/**
 * ͳ��ѧ�Ʒ�������Ϣ
 * @param sa
 */
void levelByCourse(studentList sa) {
    int selected;
    for (;;) {
        printf("------��ѡ��ͳ�Ʒ����εĿ�Ŀ��------\n");
        printf("        1:Ӣ��\n");
        printf("        2:��ѧ\n");
        printf("        3:�ߵ���ѧ\n");
        printf("        4:���ݽṹ\n");
        printf("        5:����ϵͳ\n");
        printf("        6:���������\n");
        printf("        7:�������˵�\n");
        scanf("%d", &selected);
        switch (selected) {
            case 1:
                levelByOneCourse(sa, 0);
                break;
            case 2:
                levelByOneCourse(sa, 1);
                break;
            case 3:
                levelByOneCourse(sa, 2);
                break;
            case 4:
                levelByOneCourse(sa, 3);
                break;
            case 5:
                levelByOneCourse(sa, 4);
                break;
            case 6:
                levelByOneCourse(sa, 5);
                break;
            case 7:
                return;
        }
    }
}

/**
 * ������ ��������
 * @return main()����ֵ
 */
int main() {
    int selected = 10, count, num;
    studentList sa;
    char name[20], temp;
    sa.elem = (student *)malloc(sizeof(student)*MAXSIZE);
    for (;;) {
        printf("------������Ϊѧ���������ϵͳ����ѡ��ϵͳ���ܣ�------\n");
        printf("        1:¼��ȫ��ѧ����Ϣ\n");
        printf("        2:��ѧ�Ų�ѯѧ����Ϣ\n");
        printf("        3:��������ѯѧ����Ϣ\n");
        printf("        4:���һ��ѧ����Ϣ\n");
        printf("        5:��ѧ��ɾ��ѧ����Ϣ\n");
        printf("        6:��ѧ���޸�ѧ����Ϣ\n");
        printf("        7:��ʾ����ѧ����Ϣ\n");
        printf("        8:���γ̳ɼ��Ӹߵ�����ʾ����ѧ����Ϣ\n");
        printf("        9:��������ͳ��ѧ����Ϣ\n");
        printf("        0:�˳�����\n");
        scanf("%d", &selected);
        switch (selected) {
            case 1:
                printf("������ѧ��������");
                scanf("%d", &count);
                create(&sa, count);
                break;
            case 2:
                printf("������Ҫ��ѯ��ѧ����ѧ�ţ�");
                scanf("%d", &num);
                searchById(sa, num);
                break;
            case 3:
                //���˵�ѡ��ʱ����Ļس���ɾ��
                scanf("%c", &temp);
                printf("������Ҫ��ѯ��ѧ����������");
                gets(name);
                searchByName(sa, name);
                break;
            case 4:
                add(&sa);
                break;
            case 5:
                printf("������Ҫɾ����ѧ����ѧ�ţ�");
                scanf("%d", &num);
                deleteById(&sa, num);
                break;
            case 6:
                printf("������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�");
                scanf("%d", &num);
                modifyById(&sa, num);
                break;
            case 7:
                display(sa);
                break;
            case 8:
                sortByCourse(&sa);
                break;
            case 9:
                levelByCourse(sa);
                break;
            case 0:
                return 0;
        }
    }
}
