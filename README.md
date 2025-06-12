# 🔍 Reconix

**Reconix** is a minimal and efficient command-line tool written in C for performing initial reconnaissance on web domains.  
It automates multiple basic information gathering techniques, allowing security researchers and bug bounty hunters to quickly collect and save intel on target domains.

---

## 🚀 Features

- Performs WHOIS, NSLOOKUP, and PING tests from a single CLI interface
- Optional integration with Subfinder for subdomain enumeration
- Outputs are automatically saved in a clean `output/` directory
- Fast execution with minimal system resource usage
- Easily extendable for future recon modules

---

## 📥 Installation & Usage

### 📦 Prerequisites

Ensure the following tools are installed on your system:

- `whois`
- `nslookup` (from `dnsutils` on most Linux systems)
- `ping` (default on most OSes)
- `subfinder` *(optional but recommended)*

### 🔧 Clone and Build

```bash
git clone https://github.com/dipranjanda/Reconix.git
cd Reconix
make

