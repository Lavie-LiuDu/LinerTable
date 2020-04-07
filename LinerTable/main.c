//
//  main.c
//  LinerTable
//
//  Created by Lavie on 2020/4/4.
//  Copyright © 2020 com.Lavie. All rights reserved.
//  顺序表
//  实现顺序表的初始化，增删查

#include <stdio.h>
#include "stdlib.h"


#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Data;
typedef int Statue;

/// 顺序表结构设计
typedef struct{
    Data *data;
    int length;
} LinerTable;


Statue initLinerTable(LinerTable *T);
Statue insertLinerData(LinerTable *T, int index, Data a);
Statue deleteLinerData(LinerTable *T, int index);
Statue indexOfLinerData(LinerTable *T, int index, Data *a);
Statue printfLinerData(LinerTable *T);

int main(int argc, const char * argv[]) {
    // insert code here...

    LinerTable list;
    Statue result;
    
    
    result = initLinerTable(&list);
    printf("初始化后: list.Length = %d  \n", list.length);
    
    for (int j = 1; j < 10; j++) {
        result = insertLinerData(&list, j, j);
    }
    printf("添加数据后: list.Length = %d  \n", list.length);

    Data a;
    result = indexOfLinerData(&list, 3, &a);
    printf("取的值为第3个数据为: %d \n", a);
    
    result = deleteLinerData(&list, 5);
    printf("删除第5个数据，length: %d \n", list.length);

    printfLinerData(&list);
    
    return 0;
}


/// MARK: 初始化
Statue initLinerTable(LinerTable *T) {
    // 头结点便于空表和非空表的统一处理
    T->data = malloc(sizeof(MAXSIZE));
    if (T->data == NULL) {
        return ERROR;
    }
    T->length = 0;
    return OK;
}

/// MARK: 增加L的第index位置的数据，L长度+1
Statue insertLinerData(LinerTable *T, int index, Data a) {
    
    // 判断index合法性
    if(index < 1 || index > T->length+1) return ERROR;
    if(T->length >= MAXSIZE) return ERROR;
    
    //插入数据不在表尾,则先移动出空余位置
    if (index <= T->length) {
        for (int j = T->length - 1; j >= index - 1; j--) {
            T->data[j + 1] = T->data[j];
        }
    }
    //找到位置赋值
    T->data[index -1] = a;
    // 长度+1
    ++T->length;
    
    return OK;
}


/// MARK: 删除L的第i个数据元素,L的长度减1
Statue deleteLinerData(LinerTable *T, int index) {
    
    // 判断index的合法性
    if (index > T->length || index < 1) return ERROR;
    // 判断非空表
    if (T->length == 0) return ERROR;
    
    for (int j = index; j < T->length; j++) {
        T->data[j-1] = T->data[j];
    }
    T->length --;
    
    return OK;
}



/// MARK: 查
Statue indexOfLinerData(LinerTable *T, int index, Data *a) {
    
    // 判断index的合法性
    if (index > T->length || index < 1) return ERROR;
    // 头结点的缘故
    *a = T->data[index - 1];
    
    return OK;
}

/// MARK: 顺序输出
Statue printfLinerData(LinerTable *T) {
    
    for (int i = 1; i < T->length + 1; i++) {
        printf("数据:%d", T->data[i]);
    }
    printf("查询完毕\n");
    return OK;
}

