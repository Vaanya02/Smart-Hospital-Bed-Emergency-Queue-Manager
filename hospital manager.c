#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BEDS 10

// Unit III: Structure to store patient information
struct Patient {
    int id;
    char name[30]; // Unit II: Strings
    int severity;  // 1 = High Emergency, 2 = Urgent, 3 = Routine
};

// Unit II: Sorting basics - sorts patients so emergencies come first
void sortPatients(struct Patient p[], int n) {
    struct Patient temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].severity > p[j + 1].severity) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// 2. View Bed Allocation List
void viewPatients(struct Patient p[], int n) {
    if (n == 0) {
        printf("\n[Info] No patients currently admitted in hospital beds.\n");
        return;
    }
    
    sortPatients(p, n);
    
    printf("\n==================================================\n");
    printf("        SMART HOSPITAL BED ALLOCATION LIST        \n");
    printf("==================================================\n");
    printf("Bed No.\tPatient Name\tTriage Status\n");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("Bed %d\t%s\t\t", i + 1, p[i].name);
        
        // Unit I: Decision control structures (if-else)
        if (p[i].severity == 1) {
            printf("[EMERGENCY - Priority]\n");
        } else if (p[i].severity == 2) {
            printf("[Urgent Care]\n");
        } else {
            printf("[Routine Checkup]\n");
        }
    }
    printf("--------------------------------------------------\n");
}

// 1. Admit New Patient
void addPatient(struct Patient p[], int *n) {
    if (*n >= MAX_BEDS) {
        printf("\n[Error] Hospital beds are full! (Maximum capacity: %d beds).\n", MAX_BEDS);
        return;
    }
    
    p[*n].id = *n + 1;
    printf("\nEnter Patient Name: ");
    scanf("%s", p[*n].name);
    printf("Enter Severity Level (1 = Emergency, 2 = Urgent, 3 = Routine): ");
    scanf("%d", &p[*n].severity);
    
    (*n)++;
    sortPatients(p, *n);
    printf("\n[Success] Patient admitted and priority bed assigned!\n");
}

// 3. Search Patient by Name (Unit II: String operations & searching)
void searchPatient(struct Patient p[], int n) {
    if (n == 0) {
        printf("\n[Info] Database is empty. No patients to search.\n");
        return;
    }

    char searchName[30];
    printf("\nEnter Patient Name to search: ");
    scanf("%s", searchName);
    
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(p[i].name, searchName) == 0) {
            printf("\n[Found] Patient '%s' is in Bed %d (Severity Level: %d)\n", 
                   p[i].name, i + 1, p[i].severity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\n[Not Found] No patient named '%s' found in the system.\n", searchName);
    }
}

// 4. Discharge Patient
void dischargePatient(struct Patient p[], int *n) {
    if (*n == 0) {
        printf("\n[Info] No patients to discharge.\n");
        return;
    }

    viewPatients(p, *n);
    int bedNo;
    printf("\nEnter Bed Number to discharge: ");
    scanf("%d", &bedNo);

    if (bedNo < 1 || bedNo > *n) {
        printf("\n[Error] Invalid Bed Number!\n");
        return;
    }

    for (int i = bedNo - 1; i < *n - 1; i++) {
        p[i] = p[i + 1];
    }
    (*n)--;
    printf("\n[Success] Patient from Bed %d discharged. Bed is now available!\n", bedNo);
}

// 7. Hospital Bed Occupancy Dashboard (Unit I & II: Counters & stats)
void showStatistics(struct Patient p[], int n) {
    int emergency = 0, urgent = 0, routine = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].severity == 1) emergency++;
        else if (p[i].severity == 2) urgent++;
        else if (p[i].severity == 3) routine++;
    }

    printf("\n===================================\n");
    printf("   HOSPITAL OCCUPANCY DASHBOARD    \n");
    printf("===================================\n");
    printf("Total Beds Available: %d\n", MAX_BEDS);
    printf("Occupied Beds:        %d\n", n);
    printf("Free Beds:            %d\n", MAX_BEDS - n);
    printf("-----------------------------------\n");
    printf("Emergency Cases (Lv 1): %d\n", emergency);
    printf("Urgent Cases (Lv 2):    %d\n", urgent);
    printf("Routine Cases (Lv 3):   %d\n", routine);
    printf("===================================\n");
}

// 8. Update Patient Severity
void updateSeverity(struct Patient p[], int n) {
    if (n == 0) {
        printf("\n[Info] No patients in the system to update.\n");
        return;
    }

    viewPatients(p, n);
    int bedNo;
    printf("\nEnter Bed Number of the patient to update: ");
    scanf("%d", &bedNo);

    if (bedNo < 1 || bedNo > n) {
        printf("\n[Error] Invalid Bed Number!\n");
        return;
    }

    printf("Enter New Severity Level (1 = Emergency, 2 = Urgent, 3 = Routine): ");
    scanf("%d", &p[bedNo - 1].severity);
    sortPatients(p, n);
    printf("\n[Success] Patient severity updated and queue re-prioritized!\n");
}

// 9. Filter Patients by Severity Level
void filterBySeverity(struct Patient p[], int n) {
    if (n == 0) {
        printf("\n[Info] No patients in the system.\n");
        return;
    }

    int targetSeverity;
    printf("\nEnter Severity Level to filter by (1 = Emergency, 2 = Urgent, 3 = Routine): ");
    scanf("%d", &targetSeverity);

    int count = 0;
    printf("\n--- FILTERED PATIENT LIST (Severity Level %d) ---\n", targetSeverity);
    for (int i = 0; i < n; i++) {
        if (p[i].severity == targetSeverity) {
            printf("Patient Name: %s (Admitted in system)\n", p[i].name);
            count++;
        }
    }
    if (count == 0) {
        printf("No patients found with severity level %d.\n", targetSeverity);
    }
}

// 10. Clear All Records
void clearAllRecords(int *n) {
    *n = 0;
    printf("\n[Success] All patient records have been cleared from the system!\n");
}

// 6. Load Previous Records on Startup (Unit III: File Reading)
void loadFromFile(struct Patient p[], int *n) {
    FILE *file = fopen("hospital_queue_report.txt", "r");
    if (file == NULL) {
        return; // No previous file found, safe to ignore on first run
    }

    char line[100];
    int count = 0;
    // Simple parser reading lines from text report
    while (fgets(line, sizeof(line), file) != NULL) {
        // Look for lines containing patient data format
        char name[30];
        int sev;
        if (sscanf(line, "Bed %*d | Patient: %s | Severity Level: %d", name, &sev) == 2) {
            if (count < MAX_BEDS) {
                strcpy(p[count].name, name);
                p[count].severity = sev;
                p[count].id = count + 1;
                count++;
            }
        }
    }
    *n = count;
    fclose(file);
    if (*n > 0) {
        sortPatients(p, *n);
        printf("[Info] Loaded %d patient record(s) from previous session.\n", *n);
    }
}

// 5. Save Report & Exit (Unit III: File Writing)
void saveToFile(struct Patient p[], int n) {
    FILE *file = fopen("hospital_queue_report.txt", "w");
    if (file == NULL) {
        printf("[Error] Opening file for writing failed!\n");
        return;
    }

    fprintf(file, "--- HOSPITAL BED ALLOCATION REPORT ---\n");
    for (int i = 0; i < n; i++) {
        fprintf(file, "Bed %d | Patient: %s | Severity Level: %d\n", 
                i + 1, p[i].name, p[i].severity);
    }

    fclose(file);
    printf("\n[Success] Report successfully saved to 'hospital_queue_report.txt'!\n");
}

int main() {
    struct Patient patients[MAX_BEDS];
    int n = 0;
    int choice;

    // Automatically load any saved records when program starts
    loadFromFile(patients, &n);

    // Unit I: Looping & Switch-case Menu Control Structure
    while (1) {
        printf("\n=========================================\n");
        printf("    SMART HOSPITAL MANAGEMENT SYSTEM     \n");
        printf("=========================================\n");
        printf("1. Admit New Patient\n");
        printf("2. View Bed Allocation List\n");
        printf("3. Search Patient by Name\n");
        printf("4. Discharge Patient\n");
        printf("5. Show Occupancy Dashboard (Stats)\n");
        printf("6. Update Patient Severity\n");
        printf("7. Filter Patients by Severity Level\n");
        printf("8. Clear All Records\n");
        printf("9. Save Report to File\n");
        printf("10. Save & Exit Program\n");
        printf("Enter your choice (1-10): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                addPatient(patients, &n);
                break;
            case 2:
                viewPatients(patients, n);
                break;
            case 3:
                searchPatient(patients, n);
                break;
            case 4:
                dischargePatient(patients, &n);
                break;
            case 5:
                showStatistics(patients, n);
                break;
            case 6:
                updateSeverity(patients, n);
                break;
            case 7:
                filterBySeverity(patients, n);
                break;
            case 8:
                clearAllRecords(&n);
                break;
            case 9:
                saveToFile(patients, n);
                break;
            case 10:
                saveToFile(patients, n);
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\n[Error] Invalid choice! Please select between 1 and 10.\n");
        }
    }

    return 0;
}