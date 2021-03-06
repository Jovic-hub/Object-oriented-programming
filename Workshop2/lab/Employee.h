
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#define DATAFILE "employees.csv"


namespace sdds {
    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };
    void sort();
    bool load(Employee& st);
    bool load();
    void display(const Employee& employee);
    void display();
    void deallocateMemory();

}
#endif
