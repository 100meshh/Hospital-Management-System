
# **Hospital Management System**  
# **Read Me by Chatgpt**

## **Overview**  
The **Hospital Management System** is a C++ console-based application designed to streamline hospital operations. It provides tools to manage patients, doctors, and appointments, allowing for efficient data handling and persistence using text files.  

---

## **Features**  
1. **Patient Management**  
   - Add new patients.  
   - View a list of all registered patients with details.  

2. **Doctor Management**  
   - Add new doctors to the system.  
   - View a list of all registered doctors, including their availability status.  

3. **Appointment Management**  
   - Schedule new appointments by linking patients and doctors.  
   - View a list of all scheduled appointments.  

4. **File Persistence**  
   - Automatically saves and loads data from text files (`patients.txt`, `doctors.txt`, `appointments.txt`) for data consistency across sessions.  

---

## **Project Structure**  

### **Files**  
- `main.cpp`: Contains the complete implementation of the Hospital Management System.  
- `patients.txt`: Stores patient details.  
- `doctors.txt`: Stores doctor details.  
- `appointments.txt`: Stores appointment details.  

### **Classes**  
1. **`Patient`**  
   - Attributes: `ID`, `name`, `age`, `gender`, `contact`, `medicalHistory`.  
   - Methods:  
     - `inputPatientData()`: Accepts patient details from the user.  
     - `displayPatientData()`: Displays patient details in a formatted manner.  

2. **`Doctor`**  
   - Attributes: `ID`, `name`, `specialization`, `contact`, `availability`.  
   - Methods:  
     - `inputDoctorData()`: Accepts doctor details from the user.  
     - `displayDoctorData()`: Displays doctor details, including their availability status.  

3. **`Appointment`**  
   - Attributes: `appointmentID`, `patientID`, `doctorID`, `date`, `time`.  
   - Methods:  
     - `inputAppointmentData()`: Accepts appointment details from the user.  
     - `displayAppointmentData()`: Displays appointment details in a formatted manner.  

4. **`Hospital`**  
   - Manages patients, doctors, and appointments through vectors and file operations.  
   - Handles the menu-driven interface.  

---

## **Setup and Usage**  

### **Prerequisites**  
- A C++ compiler (e.g., GCC, Clang, or Visual Studio).  

### **Steps to Run**  
1. Clone or download this repository to your local machine.  
2. Open a terminal or your IDE and navigate to the project folder.  
3. Compile the program:  
   ```bash  
   g++ main.cpp -o hospital_management  
   ```  
4. Run the program:  
   ```bash  
   ./hospital_management  
   ```  

### **How to Use**  
1. Choose from the menu to manage patients, doctors, or appointments.  
2. Follow the prompts to add or view data.  
3. Exit the program when done. Data will be saved automatically to the respective text files.  

---

## **File Formats**  

### **patients.txt**  
Stores patient details in the following format:  
```
<ID>  
<Name>  
<Age>  
<Gender>  
<Contact>  
<Medical History>  
```  

### **doctors.txt**  
Stores doctor details in the following format:  
```
<ID>  
<Name>  
<Specialization>  
<Contact>  
<Availability (1 for available, 0 for not available)>  
```  

### **appointments.txt**  
Stores appointment details in the following format:  
```
<Appointment ID>  
<Patient ID>  
<Doctor ID>  
<Date>  
<Time>  
```  

---

## **Future Enhancements**  
- Add a graphical user interface (GUI) for improved user interaction.  
- Include search functionality to quickly find patients, doctors, or appointments.  
- Enhance file handling with error recovery mechanisms.  
- Implement user authentication for security.  

---