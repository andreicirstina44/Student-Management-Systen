#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ==========================
   Structure Definitions
   ========================== */

typedef struct Student {
    int id;
    char name[50];
    float grade;
} Student;

typedef struct TreeNode {
    Student student;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/* ==========================
   Function Prototypes
   ========================== */

TreeNode* createNode(Student s);
TreeNode* insertNode(TreeNode* root, Student s);
TreeNode* searchNode(TreeNode* root, int id);
void inorderTraversal(TreeNode* root);
int treeHeight(TreeNode* root);
TreeNode* deleteNode(TreeNode* root, int id);
TreeNode* findMin(TreeNode* root);
void calculateAverage(TreeNode* root, float* sum, int* count);
void freeTree(TreeNode* root);

/* ==========================
   Function Definitions
   ========================== */

TreeNode* createNode(Student s) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->student = s;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insertNode(TreeNode* root, Student s) {
    if (root == NULL)
        return createNode(s);

    if (s.id < root->student.id)
        root->left = insertNode(root->left, s);
    else if (s.id > root->student.id)
        root->right = insertNode(root->right, s);
    else
        printf("Student with this ID already exists!\n");

    return root;
}

TreeNode* searchNode(TreeNode* root, int id) {
    if (root == NULL || root->student.id == id)
        return root;

    if (id < root->student.id)
        return searchNode(root->left, id);
    else
        return searchNode(root->right, id);
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("ID: %d | Name: %s | Grade: %.2f\n",
               root->student.id,
               root->student.name,
               root->student.grade);
        inorderTraversal(root->right);
    }
}

int treeHeight(TreeNode* root) {
    if (root == NULL)
        return 0;

    int left = treeHeight(root->left);
    int right = treeHeight(root->right);

    return 1 + (left > right ? left : right);
}

TreeNode* findMin(TreeNode* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int id) {
    if (root == NULL)
        return root;

    if (id < root->student.id)
        root->left = deleteNode(root->left, id);
    else if (id > root->student.id)
        root->right = deleteNode(root->right, id);
    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = findMin(root->right);
        root->student = temp->student;
        root->right = deleteNode(root->right, temp->student.id);
    }
    return root;
}

void calculateAverage(TreeNode* root, float* sum, int* count) {
    if (root != NULL) {
        calculateAverage(root->left, sum, count);
        *sum += root->student.grade;
        (*count)++;
        calculateAverage(root->right, sum, count);
    }
}

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

/* ==========================
   Main Program (Menu)
   ========================== */

int main() {
    TreeNode* root = NULL;
    int choice, id;
    Student s;

    do {
        printf("\n====== STUDENT MANAGEMENT SYSTEM ======\n");
        printf("1. Add student\n");
        printf("2. Search student\n");
        printf("3. Display all students\n");
        printf("4. Delete student\n");
        printf("5. Tree height\n");
        printf("6. Class average grade\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter student ID: ");
            scanf("%d", &s.id);

            printf("Enter student name: ");
            scanf(" %[^\n]", s.name);

            printf("Enter student grade: ");
            scanf("%f", &s.grade);

            root = insertNode(root, s);
            break;

        case 2:
            printf("Enter student ID to search: ");
            scanf("%d", &id);

            TreeNode* result = searchNode(root, id);
            if (result)
                printf("Found -> ID: %d | Name: %s | Grade: %.2f\n",
                       result->student.id,
                       result->student.name,
                       result->student.grade);
            else
                printf("Student not found!\n");
            break;

        case 3:
            if (root == NULL)
                printf("Tree is empty.\n");
            else
                inorderTraversal(root);
            break;

        case 4:
            printf("Enter student ID to delete: ");
            scanf("%d", &id);
            root = deleteNode(root, id);
            printf("Student deleted (if existed).\n");
            break;

        case 5:
            printf("Tree height: %d\n", treeHeight(root));
            break;

        case 6: {
            float sum = 0;
            int count = 0;
            calculateAverage(root, &sum, &count);
            if (count == 0)
                printf("No students in tree.\n");
            else
                printf("Class average grade: %.2f\n", sum / count);
            break;
        }

        case 0:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid option!\n");
        }

    } while (choice != 0);

    freeTree(root);
    return 0;
}