# 🎓 Student Management System — Modular C++ Application

<div align="center">

  [![C++](https://img.shields.io/badge/Language-Modern_C%2B%2B17-blue?style=for-the-badge&logo=c%2B%2B)](https://en.cppreference.com/)
  [![Architecture](https://img.shields.io/badge/Architecture-Modular_OOP-purple?style=for-the-badge)](https://en.wikipedia.org/wiki/Object-oriented_programming)
  [![Storage](https://img.shields.io/badge/Persistence-CSV_File_I%2FO-orange?style=for-the-badge)](https://en.wikipedia.org/wiki/Comma-separated_values)
  [![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](LICENSE)

  <br/>

  **A modular, object-oriented academic record management and grading engine engineered in Modern C++ featuring file persistence, automated percentage calculation, letter-grade mapping, and cohort performance statistics.**

  <br/>

  [System Features](#-features) • [Architecture](#-architecture) • [Compilation & Run](#-compilation--execution) • [Author](#-author)

</div>

---

## 📌 Project Overview

This repository hosts a practical academic software project developed during my 3rd semester of B.Tech in Computer Science & Engineering. 

Designed around core **Object-Oriented Programming (OOP)** principles, the application separates entity encapsulation (`Student`), collection management (`StudentManagementSystem`), and stream persistence (`CSV I/O`) into a decoupled, clean codebase.

---

## ✨ Features

- **📝 Complete CRUD Operations**: Add, search, update, and remove student academic records.
- **📊 Automatic Grade & Percentage Computation**: Evaluates across 5 core Computer Science semester subjects and maps percentages to institutional letter grades (O, A+, A, B+, B, C, F).
- **💾 Disk Persistence**: Automatically serializes records to `students_db.csv` on modification and loads existing records on application startup.
- **🔍 Fast Search Filters**: Search instantly by exact primary key (Roll Number) or string substring match (Student Name).
- **📈 Cohort Analytics**: Displays class average, topper rank, and score distribution metrics.

---

## 🏗️ Architecture & Class Design

```text
student-management-system/
├── include/
│   ├── student.h       # Student entity definition & metrics calculation
│   └── system.h        # StudentManagementSystem collection & file I/O
├── src/
│   ├── student.cpp     # Student implementation & CSV serialization
│   ├── system.cpp      # System logic & cohort statistics
│   └── main.cpp        # CLI entry point & verification runner
├── students_db.csv     # Persistent CSV database
├── Makefile            # Build automation
├── .gitignore          # Compiler artifacts exclusion
└── README.md           # Documentation
```

---

## ⚙️ Compilation & Execution

### Prerequisites
- GCC / MinGW (`g++`) or Clang supporting C++17.

### Build and Run
```bash
# 1. Clone repository
git clone https://github.com/bhavishya0922/student-management-system.git
cd student-management-system

# 2. Compile using g++
g++ -std=c++17 -Wall -Wextra src/*.cpp -Iinclude -o sms

# 3. Execute application
./sms

# Run demo verification mode:
./sms --demo
```

---

## 📄 License

This repository is licensed under the [MIT License](LICENSE).

---

## 👨‍💻 Author

**Bhavishya Dewangan**  
*B.Tech Computer Science & Engineering (3rd Semester)*  
*Raipur, Chhattisgarh, India*  
GitHub: [@bhavishya0922](https://github.com/bhavishya0922) | Email: bhavish0922@gmail.com
