#include "../include/student.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <numeric>

Student::Student() : rollNo(0), name(""), semester(1), percentage(0.0), letterGrade("F") {}

Student::Student(int roll, const std::string& n, int sem, const std::vector<double>& marks)
    : rollNo(roll), name(n), semester(sem), subjectMarks(marks) {
    calculateMetrics();
}

void Student::calculateMetrics() {
    if (subjectMarks.empty()) {
        percentage = 0.0;
        letterGrade = "F";
        return;
    }
    double total = std::accumulate(subjectMarks.begin(), subjectMarks.end(), 0.0);
    percentage = total / subjectMarks.size();

    if (percentage >= 90.0) letterGrade = "O (Outstanding)";
    else if (percentage >= 80.0) letterGrade = "A+ (Excellent)";
    else if (percentage >= 70.0) letterGrade = "A (Very Good)";
    else if (percentage >= 60.0) letterGrade = "B+ (Good)";
    else if (percentage >= 50.0) letterGrade = "B (Above Average)";
    else if (percentage >= 40.0) letterGrade = "C (Pass)";
    else letterGrade = "F (Fail)";
}

void Student::updateDetails(const std::string& newName, int newSem, const std::vector<double>& newMarks) {
    name = newName;
    semester = newSem;
    subjectMarks = newMarks;
    calculateMetrics();
}

std::string Student::toCSV() const {
    std::stringstream ss;
    ss << rollNo << "," << name << "," << semester;
    for (double m : subjectMarks) {
        ss << "," << m;
    }
    return ss.str();
}

Student Student::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> parts;
    while (std::getline(ss, token, ',')) {
        parts.push_back(token);
    }
    if (parts.size() < 8) return Student();

    int roll = std::stoi(parts[0]);
    std::string n = parts[1];
    int sem = std::stoi(parts[2]);
    std::vector<double> marks;
    for (size_t i = 3; i < parts.size(); i++) {
        marks.push_back(std::stod(parts[i]));
    }
    return Student(roll, n, sem, marks);
}

void Student::displayRow() const {
    std::cout << "| " << std::setw(8) << rollNo
              << " | " << std::setw(22) << (name.length() > 22 ? name.substr(0, 19) + "..." : name)
              << " | " << std::setw(4) << semester
              << " | " << std::setw(7) << std::fixed << std::setprecision(2) << percentage << "%"
              << " | " << std::setw(18) << letterGrade << " |\n";
}
