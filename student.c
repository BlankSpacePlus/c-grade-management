// 课程门数为6门
# define COURSENUM 6
// 课程最多人数为100
# define MAXSIZE 100

/**
 * 学生结构体
 */
typedef struct Student {
    // 学号
    int id;
    // 姓名
    char name[20];
    // 各门课的成绩
    float scores[COURSENUM];
    // 平均分
    float averageGrade;
} student;

/**
 * 学生链表的结构体
 */
typedef struct Students {
    // 学生数组空间起始地址
    StuType *elem;
    // 学生实际个数
    int length;
} studentList;
