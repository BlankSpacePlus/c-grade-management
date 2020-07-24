# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "student.c"

/**
 * 批量新增学生成绩信息
 * @param sa 学生成绩信息列表
 * @param n 待添加的学生人数
 */
void create(studentList *sa, int n) {
    int i, j;
    char temp;
    float ave = 0, sum = 0;
    for (i = 0; i < n; i++) {
        printf("请输入第%d个学生的信息：\n", i+1);
        printf("学号：");
        scanf("%d%c", &sa->elem[i].id, &temp);
        //为了姓名读入正确，需要去掉录入学号信息时输入的回车
        printf("姓名：");
        gets(sa->elem[i].name);
        printf("六门课的成绩：英语、哲学、高等数学、数据结构、操作系统、计算机网络：");
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
 * 展示学生成绩信息
 * @param sa 学生成绩信息列表
 */
void display(studentList sa) {
    int i, j;
    printf("%d个学生的信息如下：\n", sa.length);
    printf("学号、姓名、英语、哲学、高等数学、数据结构、操作系统、计算机网络、平均分\n");
    for (i = 0; i < sa.length; i++) {
        printf("%d  %s", sa.elem[i].id, sa.elem[i].name);
        for (j = 0; j < COURSENUM; j++) {
            printf("%8.1f", sa.elem[i].scores[j]);
        }
        printf("%8.1f\n", sa.elem[i].averageGrade);
    }
}

/**
 * 根据ID查找学生成绩信息
 * @param sa 学生成绩信息列表
 * @param id 待查询的学生ID
 */
void searchById(studentList sa, int id) {
    int i, j;
    for (i = 0; i < sa.length; i++) {
        if (sa.elem[i].id == id) {
            printf("学号、姓名、英语、哲学、高等数学、数据结构、操作系统、计算机网络、平均分\n");
            printf("%d  %s", sa.elem[i].id, sa.elem[i].name);
            for (j = 0; j < COURSENUM; j++) {
                printf("%8.1f", sa.elem[i].scores[j]);
            }
            printf("%8.1f\n", sa.elem[i].averageGrade);
            break;
        }
    }
    if (i == sa.length){
        printf("查无此人！\n");
    }
}

/**
 * 依据学生姓名查找学生成绩信息
 * @param sa 学生成绩信息列表
 * @param name 待查询的学生姓名
 */
void searchByName(studentList sa, char *name) {
    int i, j, flag = 0;
    for (i = 0; i < sa.length; i++) {
        if (strcmp(sa.elem[i].name, name) == 0) {
            printf("学号、姓名、英语、哲学、高等数学、数据结构、操作系统、计算机网络、平均分\n");
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
        printf("查无此人！\n");
    }
}

/**
 * 在学生成绩列表中添加单个学生成绩信息
 * @param sa 学生成绩列表
 */
void add(studentList *sa) {
    int i;
    float sum = 0;
    char temp;
    printf("请输入该学生的信息：\n");
    printf("学号：");
    scanf("%d%c", &sa->elem[sa->length].id, &temp);
    //为了姓名读入正确，需要去掉录入学号信息时输入的回车
    printf("姓名：");
    gets(sa->elem[sa->length].name);
    printf("六门课的成绩：英语、哲学、高等数学、数据结构、操作系统、计算机网络：");
    for (i = 0; i < COURSENUM; i++) {
        scanf("%f", &sa->elem[sa->length].scores[i]);
        sum+=sa->elem[sa->length].scores[i];
    }
    sa->elem[sa->length].averageGrade = sum / COURSENUM;
    sa->length++;
}

/**
 * 根据学生学号删除学生成绩信息
 * @param sa 学生成绩列表
 * @param id 待删除的学生ID
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
        printf("查无此人！\n");
    }
}

/**
 * 计算成绩平均值
 * @param sa 学生成绩列表
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
 * 根据ID修改学生成绩信息
 * @param sa 学生成绩列表
 * @param id 待修改的学生ID
 */
void modifyById(studentList *sa, int id) {
    int selected;
    int flag = 0;
    char temp;
    for (int i = 0; i < sa->length; i++) {
        if (sa->elem[i].id == id) {
            for (;;) {
                printf("------请选择要修改的项目：------\n");
                printf("        1:姓名\n");
                printf("        2:英语成绩\n");
                printf("        3:哲学成绩\n");
                printf("        4:高等数学成绩\n");
                printf("        5:数据结构成绩\n");
                printf("        6:操作系统成绩\n");
                printf("        7:计算机网络成绩\n");
                printf("        8:返回主菜单\n");
                scanf("%d", &selected);
                scanf("%c", &temp);
                switch (selected) {
                    case 1:
                        printf("请输姓名：");
                        gets(sa->elem[i].name);
                        break;
                    case 2:
                        printf("请输入英语成绩：");
                        scanf("%f", &sa->elem[i].scores[0]);
                        calculateAverage(sa);
                        break;
                    case 3:
                        printf("请输入哲学成绩：");
                        scanf("%f", &sa->elem[i].scores[1]);
                        calculateAverage(sa);
                        break;
                    case 4:
                        printf("请输入高等数学成绩：");
                        scanf("%f", &sa->elem[i].scores[2]);
                        calculateAverage(sa);
                        break;
                    case 5:
                        printf("请输入数据结构成绩：");
                        scanf("%f", &sa->elem[i].scores[3]);
                        calculateAverage(sa);
                        break;
                    case 6:
                        printf("请输入操作系统成绩：");
                        scanf("%f", &sa->elem[i].scores[4]);
                        calculateAverage(sa);
                        break;
                    case 7:
                        printf("请输入计算机网络成绩：");
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
        printf("查无此人！\n");
    }
}

/**
 * 根据某一指定科目排序
 * @param sa 学生成绩列表
 * @param course 待排序的科目
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
 * 根据科目排序
 * @param sa 学生成绩列表
 */
void sortByCourse(studentList *sa) {
    int selected;
    for (;;) {
        printf("------请选择排序依据的科目：------\n");
        printf("        1:英语\n");
        printf("        2:哲学\n");
        printf("        3:高等数学\n");
        printf("        4:数据结构\n");
        printf("        5:操作系统\n");
        printf("        6:计算机网络\n");
        printf("        7:返回主菜单\n");
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
 * 统计某一具体科目的分数段
 * @param sa 学生成绩列表
 * @param course 待统计的科目
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
            printf("英语成绩分数段分布人数：60分以下、60~69分、70~79分、80~89分、90分以上分别为：\n");
            break;
        case 1:
            printf("哲学成绩分数段分布人数：60分以下、60~69分、70~79分、80~89分、90分以上分别为：\n");
            break;
        case 2:
            printf("高等数学成绩分数段分布人数：60分以下、60~69分、70~79分、80~89分、90分以上分别为：\n");
            break;
        case 3:
            printf("数据结构成绩分数段分布人数：60分以下、60~69分、70~79分、80~89分、90分以上分别为：\n");
            break;
        case 4:
            printf("操作系统成绩分数段分布人数：60分以下、60~69分、70~79分、80~89分、90分以上分别为：\n");
            break;
        case 5:
            printf("计算机网络成绩分数段分布人数：60分以下、60~69分、70~79分、80~89分、90分以上分别为：\n");
            break;
    }
    for (int i = 0; i < 5; i++) {
        printf("%6d", num[i]);
    }
    printf("\n");
}

/**
 * 统计学科分数段信息
 * @param sa
 */
void levelByCourse(studentList sa) {
    int selected;
    for (;;) {
        printf("------请选择统计分数段的科目：------\n");
        printf("        1:英语\n");
        printf("        2:哲学\n");
        printf("        3:高等数学\n");
        printf("        4:数据结构\n");
        printf("        5:操作系统\n");
        printf("        6:计算机网络\n");
        printf("        7:返回主菜单\n");
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
 * 主函数 程序的入口
 * @return main()返回值
 */
int main() {
    int selected = 10, count, num;
    studentList sa;
    char name[20], temp;
    sa.elem = (student *)malloc(sizeof(student)*MAXSIZE);
    for (;;) {
        printf("------本程序为学生程序管理系统，请选择系统功能：------\n");
        printf("        1:录入全部学生信息\n");
        printf("        2:按学号查询学生信息\n");
        printf("        3:按姓名查询学生信息\n");
        printf("        4:添加一个学生信息\n");
        printf("        5:按学号删除学生信息\n");
        printf("        6:按学号修改学生信息\n");
        printf("        7:显示所有学生信息\n");
        printf("        8:按课程成绩从高到低显示所有学生信息\n");
        printf("        9:按分数段统计学生信息\n");
        printf("        0:退出程序\n");
        scanf("%d", &selected);
        switch (selected) {
            case 1:
                printf("请输入学生个数：");
                scanf("%d", &count);
                create(&sa, count);
                break;
            case 2:
                printf("请输入要查询的学生的学号：");
                scanf("%d", &num);
                searchById(sa, num);
                break;
            case 3:
                //将菜单选择时键入的回车符删掉
                scanf("%c", &temp);
                printf("请输入要查询的学生的姓名：");
                gets(name);
                searchByName(sa, name);
                break;
            case 4:
                add(&sa);
                break;
            case 5:
                printf("请输入要删除的学生的学号：");
                scanf("%d", &num);
                deleteById(&sa, num);
                break;
            case 6:
                printf("请输入要修改信息的学生的学号：");
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
