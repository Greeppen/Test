#include "programm.h"

void print_env_1(void) {
    for (int i = 0; i < 10 && environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}

void print_env_2(void) {
    const char *variables[] = {
        "PATH", "HOME", "USER", "SHELL", "LANG", 
        "TERM", "PWD", "LOGNAME", "DISPLAY", "EDITOR"
    };
    
    for (int i = 0; i < 10; i++) {
        const char *value = getenv(variables[i]);
        printf("%s=%s\n", variables[i], value ? value : "not set");
    }
}

void print_file_content(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s': %s\n", filename, strerror(errno));
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading file '%s'\n", filename);
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing file '%s': %s\n", filename, strerror(errno));
    }
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s [-1 | -2] [-f file]\n", program_name);
}

int main(int argc, char *argv[]) {
    int show_env_method = 0;
    const char *filename = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-1") == 0) {
            show_env_method = 1;
        } else if (strcmp(argv[i], "-2") == 0) {
            show_env_method = 2;
        } else if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                filename = argv[++i];
            } else {
                fprintf(stderr, "Error: -f option requires a file name.\n");
                print_usage(argv[0]);
                return EXIT_FAILURE;
            }
        } else {
            fprintf(stderr, "Error: unknown option '%s'.\n", argv[i]);
            print_usage(argv[0]);
            return EXIT_FAILURE;
        }
    }

    if (show_env_method == 1) {
        printf("Displaying environment variables (method 1):\n");
        print_env_1();
    } else if (show_env_method == 2) {
        printf("Displaying environment variables (method 2):\n");
        print_env_2();
    }

    if (filename != NULL) {
        printf("\nContents of file '%s':\n", filename);
        print_file_content(filename);
    }

    printf("\nProgram author: Nikita Afanasev, id: 999777333\n");

    return EXIT_SUCCESS;
}

