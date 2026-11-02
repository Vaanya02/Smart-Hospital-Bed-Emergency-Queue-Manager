Smart Hospital Bed & Emergency Queue Manager 🏥

A modular C programming project developed for the Logical Thinking and Problem Solving course (B.Tech 1st Year). This project models an automated triage and hospital bed allocation system that prioritizes patients dynamically based on medical emergency levels.

📌 Project Overview

In emergency healthcare management, bed allocation based on arrival order can lead to critical delays for severe patients. The Smart Hospital Bed & Emergency Queue Manager solves this problem by maintaining a dynamic queue sorted by medical priority (Severity Level) rather than arrival time.

It allows hospital administrative staff and nurses to admit, search, update, discharge, and visualize patient bed allocations interactively while saving daily reports for record-keeping.



🎯 Syllabus Alignment & Features

This project was built to demonstrate core principles across all units of the Logical Thinking & Problem Solving (C Programming) syllabus:

1. Unit I: Control Structures & Loops

Interactive Menu System: Powered by while loops and nested switch-case statements.

Triage Validation & Categorization: Implemented using if-else branching logic.

2. Unit II: Arrays, Strings, Searching & Sorting

Automatic Queue Priority (Bubble Sort): Automatically re-orders admitted patients based on their medical urgency (1 = Emergency, 2 = Urgent, 3 = Routine).

String Manipulation & Linear Search: searchPatient() uses standard string functions (strcmp) to locate specific patients.

Bed Re-allocation: Dynamic shift operations in 1D structure arrays handle patient discharges.

3. Unit III: Structures, Modular Functions & File Handling

Structures (struct Patient): Encapsulates patient details (ID, Name, Severity).

Modular Code Architecture: Logical separation into clean, self-contained C functions.

Data Persistence: Reads existing patient logs from hospital_queue_report.txt on startup and exports updated logs using C File I/O (fopen, fprintf, fgets).

🚀 List of Functionalities (10 Core Features)

Admit New Patient: Register patient details with dynamic severity assignment.

View Bed Allocation List: Display beds ordered strictly by medical emergency priority.

Search Patient by Name: Quick linear lookup to retrieve bed placement and status.

Discharge Patient: Clear a bed and shift waiting patients automatically.

Hospital Occupancy Dashboard: Displays statistics on occupied vs. free beds and severity breakdowns.

Update Patient Severity: Re-evaluate and promote/demote patient triage status on the fly.

Filter by Severity Level: View patients belonging to a specific triage group.

Clear All Records: Quick database reset for shift handovers.

Persistent Report Exporter: Export formatted bed allocation records to text files.

Auto-Load on Startup: Load previously saved sessions automatically when the program launches.

🛠️ How to Run

Running on ByteXL Online IDE

Log in to your ByteXL portal and open the C workspace.

Create a new file named hospital_manager.c.

Copy and paste the project C code into the editor.

Click Compile & Run.

Running via GCC Compiler (Local Terminal)

# 1. Compile the program
gcc hospital_manager.c -o hospital_manager

# 2. Run the executable
./hospital_manager


📁 Repository Structure

├── README.md                  # Project documentation (this file)
├── hospital_manager.c          # Full C source code
└── hospital_queue_report.txt  # Auto-generated runtime report file


👨‍💻 Author

Course: Logical Thinking and Problem Solving

Degree: B.Tech 1st Year

Platform: ByteXL / GitHub
