#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Patient {
public:
    int ID;
    string name;
    int age;
    string gender;
    string contact;
    string medicalHistory;

    void inputPatientData() {
        cout << "Enter ID: "; cin >> ID;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, name);
        cout << "Enter Age: "; cin >> age;
        cin.ignore();
        cout << "Enter Gender: "; getline(cin, gender);
        cout << "Enter Contact: "; getline(cin, contact);
        cout << "Enter Medical History: "; getline(cin, medicalHistory);
    }

    void displayPatientData() const {
        cout << setw(5) << ID << setw(15) << name
             << setw(5) << age << setw(10) << gender
             << setw(15) << contact << setw(20) << medicalHistory << "\n";
    }
};

class Doctor {
public:
    int ID;
    string name;
    string specialization;
    string contact;
    bool availability;

    void inputDoctorData() {
        cout << "Enter ID: "; cin >> ID;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, name);
        cout << "Enter Specialization: "; getline(cin, specialization);
        cout << "Enter Contact: "; getline(cin, contact);
        availability = true;
    }

    void displayDoctorData() const {
        cout << setw(5) << ID << setw(15) << name
             << setw(15) << specialization << setw(15) << contact
             << setw(10) << (availability ? "Available" : "Not Available") << "\n";
    }
};

class Appointment {
public:
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
    string time;

    void inputAppointmentData() {
        cout << "Enter Appointment ID: "; cin >> appointmentID;
        cout << "Enter Patient ID: "; cin >> patientID;
        cout << "Enter Doctor ID: "; cin >> doctorID;
        cin.ignore();
        cout << "Enter Date (YYYY-MM-DD): "; getline(cin, date);
        cout << "Enter Time (HH:MM): "; getline(cin, time);
    }

    void displayAppointmentData() const {
        cout << setw(10) << appointmentID << setw(10) << patientID
             << setw(10) << doctorID << setw(15) << date
             << setw(10) << time << "\n";
    }
};

class Hospital {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

    void savePatientsToFile() {
        ofstream outFile("patients.txt");
        if (!outFile) {
            cerr << "Error opening patients.txt for writing.\n";
            return;
        }
        for (const auto& patient : patients) {
            outFile << patient.ID << "\n" << patient.name << "\n" << patient.age << "\n"
                    << patient.gender << "\n" << patient.contact << "\n" << patient.medicalHistory << "\n";
        }
        outFile.close();
        cout << "Patients data saved successfully.\n";
    }

    void loadPatientsFromFile() {
        ifstream inFile("patients.txt");
        if (!inFile) {
            cerr << "Error opening patients.txt for reading.\n";
            return;
        }
        Patient patient;
        while (inFile >> patient.ID) {
            inFile.ignore();
            if (!getline(inFile, patient.name)) break;
            if (!(inFile >> patient.age)) break;
            inFile.ignore();
            if (!getline(inFile, patient.gender)) break;
            if (!getline(inFile, patient.contact)) break;
            if (!getline(inFile, patient.medicalHistory)) break;
            patients.push_back(patient);
        }
        inFile.close();
        cout << "Patients data loaded successfully.\n";
    }

    void saveDoctorsToFile() {
        ofstream outFile("doctors.txt");
        if (!outFile) {
            cerr << "Error opening doctors.txt for writing.\n";
            return;
        }
        for (const auto& doctor : doctors) {
            outFile << doctor.ID << "\n" << doctor.name << "\n" << doctor.specialization << "\n"
                    << doctor.contact << "\n" << doctor.availability << "\n";
        }
        outFile.close();
        cout << "Doctors data saved successfully.\n";
    }

    void loadDoctorsFromFile() {
        ifstream inFile("doctors.txt");
        if (!inFile) {
            cerr << "Error opening doctors.txt for reading.\n";
            return;
        }
        Doctor doctor;
        while (inFile >> doctor.ID) {
            inFile.ignore();
            if (!getline(inFile, doctor.name)) break;
            if (!getline(inFile, doctor.specialization)) break;
            if (!getline(inFile, doctor.contact)) break;
            if (!(inFile >> doctor.availability)) break;
            doctors.push_back(doctor);
        }
        inFile.close();
        cout << "Doctors data loaded successfully.\n";
    }

    void saveAppointmentsToFile() {
        ofstream outFile("appointments.txt");
        if (!outFile) {
            cerr << "Error opening appointments.txt for writing.\n";
            return;
        }
        for (const auto& appointment : appointments) {
            outFile << appointment.appointmentID << "\n" << appointment.patientID << "\n"
                    << appointment.doctorID << "\n" << appointment.date << "\n" << appointment.time << "\n";
        }
        outFile.close();
        cout << "Appointments data saved successfully.\n";
    }

    void loadAppointmentsFromFile() {
        ifstream inFile("appointments.txt");
        if (!inFile) {
            cerr << "Error opening appointments.txt for reading.\n";
            return;
        }
        Appointment appointment;
        while (inFile >> appointment.appointmentID >> appointment.patientID >> appointment.doctorID) {
            inFile.ignore();
            if (!getline(inFile, appointment.date)) break;
            if (!getline(inFile, appointment.time)) break;
            appointments.push_back(appointment);
        }
        inFile.close();
        cout << "Appointments data loaded successfully.\n";
    }

public:
    Hospital() {
        loadPatientsFromFile();
        loadDoctorsFromFile();
        loadAppointmentsFromFile();
    }

    ~Hospital() {
        savePatientsToFile();
        saveDoctorsToFile();
        saveAppointmentsToFile();
    }

    void managePatients() {
        int choice;
        do {
            cout << "Patient Management\n";
            cout << "1. Add Patient\n";
            cout << "2. View Patients\n";
            cout << "3. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    Patient patient;
                    patient.inputPatientData();
                    patients.push_back(patient);
                    break;
                }
                case 2: {
                    cout << setw(5) << "ID" << setw(15) << "Name"
                         << setw(5) << "Age" << setw(10) << "Gender"
                         << setw(15) << "Contact" << setw(20) << "Medical History" << "\n";
                    for (const auto& patient : patients) {
                        patient.displayPatientData();
                    }
                    break;
                }
                case 3:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 3);
    }

    void manageDoctors() {
        int choice;
        do {
            cout << "Doctor Management\n";
            cout << "1. Add Doctor\n";
            cout << "2. View Doctors\n";
            cout << "3. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    Doctor doctor;
                    doctor.inputDoctorData();
                    doctors.push_back(doctor);
                    break;
                }
                case 2: {
                    cout << setw(5) << "ID" << setw(15) << "Name"
                         << setw(15) << "Specialization" << setw(15) << "Contact"
                         << setw(10) << "Status" << "\n";
                    for (const auto& doctor : doctors) {
                        doctor.displayDoctorData();
                    }
                    break;
                }
                case 3:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 3);
    }

    void manageAppointments() {
        int choice;
        do {
            cout << "Appointment Management\n";
            cout << "1. Schedule Appointment\n";
            cout << "2. View Appointments\n";
            cout << "3. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    Appointment appointment;
                    appointment.inputAppointmentData();
                    appointments.push_back(appointment);
                    break;
                }
                case 2: {
                    cout << setw(10) << "Appt ID" << setw(10) << "Patient ID"
                         << setw(10) << "Doctor ID" << setw(15) << "Date"
                         << setw(10) << "Time" << "\n";
                    for (const auto& appointment : appointments) {
                        appointment.displayAppointmentData();
                    }
                    break;
                }
                case 3:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 3);
    }
};

int main() {
    Hospital hospital;
    int choice;
    do {
        cout << "Hospital Management System\n";
        cout << "1. Manage Patients\n";
        cout << "2. Manage Doctors\n";
        cout << "3. Manage Appointments\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hospital.managePatients();
                break;
            case 2:
                hospital.manageDoctors();
                break;
            case 3:
                hospital.manageAppointments();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
