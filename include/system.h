#ifndef SYSTEM_H
#define SYSTEM_H

#include "student.h"
#include <vector>
#include <string>

class StudentManagementSystem {
private:
    std::vector<Student> students;
    std::string storageFile;

    void loadFromFile();
    void saveToFile();

public:
    StudentManagementSystem(const std::string& filename = "students_db.csv");
    ~StudentManagementSystem();

    bool addStudent(const Student& s);
    bool deleteStudent(int rollNo);
    bool updateStudent(int rollNo, const std::string& newName, int newSem, const std::vector<double>& newMarks);
    const Student* findByRollNo(int rollNo) const;
    std::vector<Student> findByName(const std::string& keyword) const;
    void displayAll() const;
    void displaySummary() const;
};

#endif // SYSTEM_H
