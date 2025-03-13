#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} employee_t;

// 顯示員工資訊
void emp_info(employee_t emp) {
    printf("姓名: %s, 年齡: %d, 薪水: %.2f\n", emp.name, emp.age, emp.salary);
}

// 計算平均年齡
int emp_aveage_age(employee_t emp[], int n) {
    int total_age = 0;
    for (int i = 0; i < n; i++) {
        total_age += emp[i].age;
    }
    return (n > 0) ? total_age / n : 0;
}

// 寫入員工資料到 binary 檔案
void emp_writefile(employee_t emp[], int n) {
    FILE *file = fopen("employee.bin", "wb");
    if (file == NULL) {
        printf("無法開啟檔案!\n");
        return;
    }
    fwrite(emp, sizeof(employee_t), n, file);
    fclose(file);
}

// 讀取員工資料並輸出到螢幕
void emp_readfile(employee_t emp[], int n) {
    FILE *file = fopen("employee.bin", "rb");
    if (file == NULL) {
        printf("無法開啟檔案!\n");
        return;
    }
    fread(emp, sizeof(employee_t), n, file);
    fclose(file);

    for (int i = 0; i < n; i++) {
        emp_info(emp[i]); // 顯示每位員工資訊
    }
}

int main() {
    int n = 3; // 設定員工數量
    employee_t employees[3] = {
        {"Alice", 30, 50000.0},
        {"Bob", 25, 45000.0},
        {"Charlie", 35, 55000.0}
    };

    // 寫入資料
    emp_writefile(employees, n);

    // 讀取並輸出資料
    employee_t emp_read[3];
    emp_readfile(emp_read, n);

    return 0;
}
