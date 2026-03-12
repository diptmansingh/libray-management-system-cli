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
   git clone [https://github.com/diptmansingh/library-management-system-cli.git](https://github.com/diptmansingh/library-management-system-cli.git)
