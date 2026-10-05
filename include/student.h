#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    int rollNo;
    std::string name;
    int semester;
    std::vector<double> subjectMarks; // 5 Core subjects: DSA, OOP, DBMS, OS, DiscreteMath
    double percentage;
    std::string letterGrade;

    void calculateMetrics();

public:
    Student();
    Student(int roll, const std::string& n, int sem, const std::vector<double>& marks);

    int getRollNo() const { return rollNo; }
    std::string getName() const { return name; }
    int getSemester() const { return semester; }
    double getPercentage() const { return percentage; }
    std::string getGrade() const { return letterGrade; }
    const std::vector<double>& getMarks() const { return subjectMarks; }

    void updateDetails(const std::string& newName, int newSem, const std::vector<double>& newMarks);
    std::string toCSV() const;
    static Student fromCSV(const std::string& line);
    void displayRow() const;
};

#endif // STUDENT_H
