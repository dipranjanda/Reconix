#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules.h"

void module_whois(const char *domain) {
    printf("[*] Running WHOIS...\n");
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "whois %s > results/%s_whois.txt", domain, domain);
    system(cmd);
}

void module_nslookup(const char *domain) {
    printf("[*] Running NSLOOKUP...\n");
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "nslookup %s > results/%s_dns.txt", domain, domain);
    system(cmd);
}

void module_ping(const char *domain) {
    printf("[*] Running PING...\n");
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "ping -c 4 %s > results/%s_ping.txt", domain, domain);
    system(cmd);
}

void module_subfinder(const char *domain) {
    printf("[*] Running Subfinder...\n");
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "subfinder -d %s -o results/%s_subs.txt", domain, domain);
    system(cmd);
}
