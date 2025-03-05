#include "../headers/common.h"
#include "../headers/localShared.h"

#define BUFFER_SIZE 1000

void teststoutfeatures();
int testMemAlloc();
int testPrintBTree(const char *orientation);
void teststdinfeatures();
void teststdinfeatures2();
void teststdinfeatures2();

int testcallocinteger(int cout);
void printTreePortraitLeftSideUp(struct charNode *node, int level);
void printTreePortraitRightSideUp(struct charNode *node, int level);
void printTreeLandscape(struct charNode *node, int level);
void buildAndPrintSampleTree(void (*printTree)(struct charNode *node, int level));

int main(int argc, char *argv[]) 
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <your_name> <bTree_orientation>\nOrientation: { PR: Portrait right side up, PL: Portrait left side up, L: Landscap }\n", argv[0]);
        return 1;
    }

    printf("Path & Program: %s.\n", argv[0]);

    char *name = argv[1];
    printf("Hello, %s!\n", name);

    if (testPrintBTree(argv[2]) == EXIT_FAILURE) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int testPrintBTree(const char *orientation)
{
    printf("--- build and print tree --- \n");
    void (*pTree)(struct charNode *node, int level);

    if (strcmp("L", orientation))
    {
        printf("Thanks, L => tree will be printed with landscape orientation.\n");
        pTree = &printTreeLandscape;       
    }
    else if (strcmp("PL", orientation))
    {
        printf("Thanks, PL => tree will be printed with portrait left side up orientation.\n");
        pTree = &printTreePortraitLeftSideUp;
    }
    else if (strcmp("PR", orientation))
    {
        printf("Thanks, PR => tree will be printed with portrait right side up orientation.\n");
        pTree = &printTreePortraitRightSideUp;
    }
    else
    {
        printf("Invalid tree orientation. Please use 'PR', 'PL' or 'L'.\n");
        return EXIT_FAILURE;
    }

    buildAndPrintSampleTree(pTree);

    return EXIT_SUCCESS;
}

// if (testMemAlloc() == EXIT_FAILURE) return EXIT_FAILURE;
int testMemAlloc()
{
    int result = testcallocinteger(10);
    if (result == EXIT_FAILURE)
    {
        fprintf(stderr, "Memory allocation failed unexpectedly.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void teststoutfeatures()
{
    // By default, the stdout stream is using line-by-line buffering - the buffer will flush
    // when a newline character is encountered (or when the buffer is full)
    printf("Hello, World!\n");
    printf("My number: %d\n", 100);

    /**
    *  Useful format specifiers!
    *  %c  (Characters)
    *  %d  (Signed Integers)
    *  %u  (Unsigned Integers)
    *  %zu (For size_t values - like when you use the sizeof function)
    *  %f  (Floats)
    *  %lf (Doubles)
    *  %p  (Pointers)
    */

    // You can use the putchar function to print a single character to stdout
    putchar('A');
    putchar('\n');

    // This printf usage is buffered - it's not immediately printed to the console
    printf("This will be buffered...");

    // You can flush the buffer manually via 'fflush'
    fflush(stdout);  // Flush the output buffer to stdout

    // You can change the  buffering mode of stdout such that it is unbuffered.
    // This means that every time you print to stdout, the buffer will immediately be written 
    setvbuf(stdout, NULL, _IONBF, 0);  // _IONBF means no buffering
    printf("This should print immediately without buffering.");
    
    // You can reset to line-by-line buffering like this
    setvbuf(stdout, NULL, _IOLBF, 0);  // _IOLBF for line buffering (default for stdout on many systems)
    printf("\nBack to line buffering.\n");

    // You can also use the fprintf function to print to a specific file stream
    FILE *file = fopen("output.txt1", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "This is written to a file.\n");
    fclose(file);

    // You can also use the fputs function to write a string to a file
    file = fopen("output2.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fputs("This is another line written to a file.\n", file);
    fclose(file);

    // You can also use the fputc function to write a single character to a file
    file = fopen("output3.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    fputc('A', file);
    fputc('Z', file);
    fputc('\n', file);
    fclose(file);
}

void teststdinfeatures()
{
    char name[30];
    char buffer[BUFFER_SIZE];
    int age;
    char c;

    printf("Please enter your name: ");
    scanf("%29s", name);        // Limit to 29 chars to avoid buffer overflow
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("You entered: %s, age %d\n", name, age);

    // Gotcha! scanf leaves a newline in the stdin buffer
    // Consume the newline left in the buffer by scanf
    while ((c = getchar()) != '\n' && c != EOF);

    // You can use getchar for single character input
    printf("Press any key followed by Enter: ");
    c = getchar();
    printf("You pressed: %c\n", c);

    // Using gets (DEPRECATED and UNSAFE due to buffer overflow risks)
    // printf("Enter a line of text (gets - unsafe): ");
    // gets(buffer);  // This might overflow if input exceeds BUFFER_SIZE
    // printf("You entered (gets): %s\n", buffer);

    // Instead of gets you can use fgets which is safer
    printf("Enter another line of text (fgets): ");
    fgets(buffer, BUFFER_SIZE, stdin);  // Safely reads up to BUFFER_SIZE-1 characters

    // // Let's clear the stdin buffer of any newline or EOF characters again after using fgets
    while ((c = getchar()) != '\n' && c != EOF);

    // Read until EOF to show handling of input stream
    printf("Enter lines of text. Type 'exit' to finish:\n");
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        if (strcmp(buffer, "exit\n") == 0) { // Check for the user typing 'exit' followed by pressing 'Enter'
            break;
        }
        printf("You typed: %s", buffer);  // includes a newline
    }
}

void teststdinfeatures2()
{
    // The scanf function is the "go-to" function for reading from stdin
    // By default, the stdin stream is using line-by-line buffering - the buffer will flush
    // when a newline character is encountered (or when the buffer is full)
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("You entered: %d\n", number);

    // You can use the getchar function to read a single character from stdin
    char c;
    printf("Enter a character: ");
    c = getchar();
    printf("You entered: %c\n", c);
    
    // Note that getchar() will read the newline character as well, so you may need to consume it
    // using getchar() again if you want to read the next character
    // You can also use the fgets function to read a string from stdin
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Note that fgets will include the newline character in the string if it fits
    // You can remove the newline character if you want
    str[strcspn(str, "\n")] = '\0';  // Remove the newline character
    printf("You entered: %s\n", str);
    
    // You can also use the fscanf function to read formatted input from stdin
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening file");
        return;
    }

    int fileNumber;
    fscanf(inputFile, "%d", &fileNumber);
    printf("Number read from file: %d\n", fileNumber);
}