
# Student Record System (C)

## Overview

A **console-based Student Record System** developed in **C** using file handling. The program allows users to add, delete, search, and display student records stored persistently in a file.

---

## Features

* Add new student records
* Delete student records using roll number
* Search student details by roll number
* Display all stored student records

---

## Technologies Used

* **Language:** C
* **Concepts:** Structures, File Handling, Loops, Conditional Statements

---

## Data Structure

```c
struct record {
    char Name[20];
    int Rollno;
    int Phoneno;
    char Address[100];
};
```

---

## File Handling

| File Name     | Description                         |
| ------------- | ----------------------------------- |
| `student.txt` | Stores student records              |
| `stud.txt`    | Temporary file used during deletion |

---



## Menu Options

1. Insert student record
2. Delete student record
3. Search student record
4. Display all records
5. Exit

---


