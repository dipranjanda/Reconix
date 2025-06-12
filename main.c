#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "modules.h"

void print_banner() {
    printf("=====================================\n");
    printf("         Reconix  Scanner        \n");
    printf("       Lightweight CLI Recon Tool    \n");
    printf("=====================================\n\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <target_domain>\n", argv[0]);
        return 1;
    }

    char *domain = argv[1];
    char choice_input[100];

    // Create output directory
    struct stat st = {0};
    if (stat("results", &st) == -1) {
        if (mkdir("results", 0700) == -1) {
            perror("Error creating results directory");
            return 1;
        }
    }

    print_banner();
    printf("Target: %s\n\n", domain);
    printf("Select recon modules to run:\n");
    printf("1 - WHOIS Lookup\n");
    printf("2 - DNS NSLOOKUP\n");
    printf("3 - Ping Check\n");
    printf("4 - Subdomain Finder\n");
    printf("Enter choices (comma-separated, e.g. 1,2,4): ");

    fgets(choice_input, sizeof(choice_input), stdin);
    choice_input[strcspn(choice_input, "\n")] = 0;

    char *token = strtok(choice_input, ",");
    while (token != NULL) {
        switch (atoi(token)) {
            case 1: module_whois(domain); break;
            case 2: module_nslookup(domain); break;
            case 3: module_ping(domain); break;
            case 4: module_subfinder(domain); break;
            default: printf("Invalid option: %s\n", token); break;
        }
        token = strtok(NULL, ",");
    }

    printf("\n[+] Recon complete. Results saved in 'results/' directory.\n");
    return 0;
}
