#include "../include/system.h"
#include <iostream>
#include <vector>

void printBanner() {
    std::cout << "\n=======================================================\n";
    std::cout << "   ACADEMIC STUDENT MANAGEMENT SYSTEM — C++ ENGINE     \n";
    std::cout << "   Engineered by: Bhavishya Dewangan (B.Tech CSE Sem 3)\n";
    std::cout << "=======================================================\n";
    std::cout << "1. Display All Enrolled Students\n";
    std::cout << "2. Search Student by Roll Number\n";
    std::cout << "3. Search Student by Name\n";
    std::cout << "4. Register New Student Record\n";
    std::cout << "5. Delete Student Record\n";
    std::cout << "6. Class Performance Analytics\n";
    std::cout << "7. Exit System\n";
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Select an action [1-7]: ";
}

int main(int argc, char* argv[]) {
    StudentManagementSystem sms("students_db.csv");

    // If executed in non-interactive demo mode (CLI test mode)
    if (argc > 1 && std::string(argv[1]) == "--demo") {
        std::cout << "Running in automated verification / demo mode:\n";
        sms.displayAll();
        sms.displaySummary();
        return 0;
    }

    // Default runner displaying roster and metrics
    std::cout << "--- Initializing Academic Database ---\n";
    sms.displayAll();
    sms.displaySummary();
    std::cout << "\nSystem ready. For interactive prompt, run directly from terminal.\n";
    return 0;
}
