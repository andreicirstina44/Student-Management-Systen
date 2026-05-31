Student Management System (C)
Description

This program implements a Student Management System using a Binary Search Tree (BST) in C. It allows users to:

Add student records.

Search for a student by ID.

Display all students in the tree.

Delete a student by ID.

Calculate the height of the tree.

Calculate the class average grade.

The program interacts with the user through a simple menu-driven interface.

Features

Add Student: Allows adding a new student with an ID, name, and grade.

Search Student: Enables searching for a student by ID.

Display All Students: Displays all student records in ascending order of their IDs (in-order traversal of the BST).

Delete Student: Allows deleting a student by ID, managing all cases in a binary search tree (leaf, single child, two children).

Tree Height: Displays the height of the tree.

Class Average Grade: Calculates the average grade of all students in the tree.

Memory Management: Dynamically allocates memory for nodes and ensures proper cleanup when the program exits.

File Structure

student_management.c: The main program code with the student management system implementation.

README.md: This file containing the documentation.

Compilation and Execution

To compile and run the program:

Open a terminal (Linux/macOS) or command prompt (Windows).

Navigate to the directory where proiect.c is located.

Run the following commands:

gcc proiect.c -o proiect
./proiect


Follow the on-screen prompts to interact with the system.

Functionality Overview
1. Add Student

Input: Student ID, Name, Grade

Adds a new student record to the binary search tree.

2. Search Student

Input: Student ID

Searches for a student by their ID. If found, displays the student's details (ID, Name, Grade).

3. Display All Students

Displays all student records in ascending order of IDs using an in-order traversal of the tree.

4. Delete Student

Input: Student ID

Deletes a student from the tree by ID. Handles all cases for deletion in a binary search tree:

If the node has no children (leaf), it is simply removed.

If the node has one child, the child takes the place of the node.

If the node has two children, the node is replaced by its in-order successor (smallest node in the right subtree).

5. Tree Height

Displays the height of the tree, which is the longest path from the root to any leaf.

6. Class Average Grade

Calculates and displays the average grade of all students in the tree.

Code Explanation
Structures

Student: Defines a student with an ID, name, and grade.

TreeNode: Defines a node in the binary search tree. Each node contains a Student and pointers to left and right child nodes.

Functions

createNode: Creates a new tree node with a given student.

insertNode: Inserts a student into the tree while maintaining the binary search tree property.

searchNode: Searches for a student by their ID in the tree.

inorderTraversal: Traverses the tree in-order to display all students.

treeHeight: Calculates the height of the tree.

deleteNode: Deletes a node (student) from the tree.

findMin: Finds the minimum value (leftmost node) in a subtree.

calculateAverage: Calculates the average grade of all students in the tree.

freeTree: Frees the dynamically allocated memory of the tree.

Main Loop

The program displays a menu with options for the user. After the user selects an option, the corresponding function is called. The menu loops until the user chooses to exit the program.

Example Output
====== STUDENT MANAGEMENT SYSTEM ======
1. Add student
2. Search student
3. Display all students
4. Delete student
5. Tree height
6. Class average grade
0. Exit
Choose an option: 1
Enter student ID: 101
Enter student name: John Doe
Enter student grade: 90.5

====== STUDENT MANAGEMENT SYSTEM ======
1. Add student
2. Search student
3. Display all students
4. Delete student
5. Tree height
6. Class average grade
0. Exit
Choose an option: 3
ID: 101 | Name: John Doe | Grade: 90.50

Memory Management

The program uses dynamic memory allocation for each student node. The freeTree function ensures all dynamically allocated memory is freed when the program exits to avoid memory leaks.