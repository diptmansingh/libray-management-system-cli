# Library Management System (CLI)

## Description
This is a fully functional, command-line Library Management System built entirely in C. It serves as a digital ledger to track book inventory and manage borrowing records without the need for an external database. 

The system is designed with a role-based architecture, offering specific functionalities for Librarians (Admins), Faculty, and Students. Under the hood, it heavily utilizes fundamental C concepts—including nested `structs`, arrays, and control flow logic—to store, retrieve, modify, and delete user and book records directly in memory.

## Key Features
* **Role-Based Access:** Distinct menus and workflows for Librarians, Faculty, and Students.
* **Admin Controls (Librarian):** Full CRUD (Create, Read, Update, Delete) capabilities for user profiles and borrowed book logs.
* **Self-Service Issue & Return:** Dedicated flows allowing students and faculty to borrow and return up to 10 books per profile.
* **Data Tracking:** Captures enrollment IDs, course details, issue dates, and specific book codes/titles.

## Prerequisites
To compile and run this program, you will need a C compiler installed on your system, such as GCC.

## How to Compile and Run
1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/diptmansingh/library-management-system-cli.git
   ```
2. Navigate into the project directory:
   ```bash
   cd library-management-system-cli
   ```
3. Compile the C file using GCC:
   ```bash
   gcc main.c -o library_manager
   ```
4. Run the executable:
   * **On Linux/macOS:** `./library_manager`
   * **On Windows:** `library_manager.exe`

## Usage Instructions
Upon running the program, you will be prompted to select a role:
1. **Librarian:** Access administrative functions to issue/return books, view all records, and modify or delete existing entries.
2. **Faculty:** A streamlined flow to issue or return books under a faculty ID.
3. **Student:** A streamlined flow to issue or return books under a student enrollment number.

Follow the on-screen terminal prompts to navigate the menus and input data.

## Future Enhancements
* **Persistent Storage:** Integrate a database management system (like MySQL or SQLite) to replace the volatile in-memory arrays so data persists after the program closes.
* **Security & Authentication:** Implement secure login screens with password protection for the Librarian role to prevent unauthorized record modification.
* **Web Integration:** Develop a full-stack web frontend to provide a graphical user interface that hooks into this core logic. 
* **Input Validation:** Add robust error handling to prevent application crashes from unexpected user inputs.

---
*Created as a foundational project demonstrating memory management and data structures in C.*
