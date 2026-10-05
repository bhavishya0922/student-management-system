#include "../include/system.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

StudentManagementSystem::StudentManagementSystem(const std::string& filename) : storageFile(filename) {
    loadFromFile();
    if (students.empty()) {
        // Pre-populate with realistic mock records for immediate verification
        addStudent(Student(101, "Bhavishya Dewangan", 3, {92, 88, 90, 85, 87}));
        addStudent(Student(102, "Aryan Sharma", 3, {85, 82, 89, 80, 84}));
        addStudent(Student(103, "Priya Verma", 3, {95, 94, 91, 93, 96}));
        addStudent(Student(104, "Rahul Sahu", 3, {72, 68, 75, 71, 70}));
    }
}

StudentManagementSystem::~StudentManagementSystem() {
    saveToFile();
}

void StudentManagementSystem::loadFromFile() {
    std::ifstream file(storageFile);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            Student s = Student::fromCSV(line);
            if (s.getRollNo() != 0) students.push_back(s);
        }
    }
}

void StudentManagementSystem::saveToFile() {
    std::ofstream file(storageFile);
    if (!file.is_open()) return;
    for (const auto& s : students) {
        file << s.toCSV() << "\n";
    }
}

bool StudentManagementSystem::addStudent(const Student& s) {
    if (findByRollNo(s.getRollNo()) != nullptr) return false;
    students.push_back(s);
    saveToFile();
    return true;
}

bool StudentManagementSystem::deleteStudent(int rollNo) {
    auto it = std::remove_if(students.begin(), students.end(), [rollNo](const Student& s) {
        return s.getRollNo() == rollNo;
    });
    if (it != students.end()) {
        students.erase(it, students.end());
        saveToFile();
        return true;
    }
    return false;
}

bool StudentManagementSystem::updateStudent(int rollNo, const std::string& newName, int newSem, const std::vector<double>& newMarks) {
    for (auto& s : students) {
        if (s.getRollNo() == rollNo) {
            s.updateDetails(newName, newSem, newMarks);
            saveToFile();
            return true;
        }
    }
    return false;
}

const Student* StudentManagementSystem::findByRollNo(int rollNo) const {
    for (const auto& s : students) {
        if (s.getRollNo() == rollNo) return &s;
    }
    return nullptr;
}

std::vector<Student> StudentManagementSystem::findByName(const std::string& keyword) const {
    std::vector<Student> results;
    for (const auto& s : students) {
        if (s.getName().find(keyword) != std::string::npos) {
            results.push_back(s);
        }
    }
    return results;
}

void StudentManagementSystem::displayAll() const {
    if (students.empty()) {
        std::cout << "\n[!] No student records registered in the system.\n";
        return;
    }
    std::cout << "\n+----------+------------------------+------+---------+--------------------+\n";
    std::cout << "| Roll No  | Student Name           | Sem  | Percent | Academic Grade     |\n";
    std::cout << "+----------+------------------------+------+---------+--------------------+\n";
    for (const auto& s : students) {
        s.displayRow();
    }
    std::cout << "+----------+------------------------+------+---------+--------------------+\n";
}

void StudentManagementSystem::displaySummary() const {
    if (students.empty()) return;
    double maxP = 0.0, minP = 100.0, totalP = 0.0;
    std::string topper = "";

    for (const auto& s : students) {
        double p = s.getPercentage();
        totalP += p;
        if (p > maxP) { maxP = p; topper = s.getName(); }
        if (p < minP) minP = p;
    }

    std::cout << "\n--- Class Performance Metrics ---\n";
    std::cout << "Enrolled Students: " << students.size() << "\n";
    std::cout << "Class Average    : " << std::fixed << std::setprecision(2) << (totalP / students.size()) << "%\n";
    std::cout << "Class Topper     : " << topper << " (" << maxP << "%)\n";
    std::cout << "Lowest Average   : " << minP << "%\n";
}
