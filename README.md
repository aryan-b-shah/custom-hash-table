# CustomHashMap

## 🧠 Team Alias: Team Vision

- **Member 1:** Aryan Bhavin Shah  
- **Member 2:** Tushar Sachan  

## 📄 Project Overview

This project implements a custom chaining-based hash map in Java. The core objective is to minimize deviation by uniformly distributing data across available slots in the hash table. The implementation leverages arbitrary constants and optimized switch-case logic to handle specific input scenarios effectively.

## 📂 How It Works

- The program reads key-value input data from a file.
- It applies a hash function tailored for uniform distribution using modulus and constants.
- Collisions are handled using **chaining**, where each bucket stores a linked list of entries.
- A switch-case strategy is employed for tuning constants dynamically based on the dataset.

## ⚙️ Features

- Custom hash function for uniform key distribution
- Collision resolution using chaining
- Adjustable hashing constants via switch-case logic
- Input parsing from external file
- Console output for internal structure and results

## 🛠️ How to Compile and Run

### Prerequisites
- A C++ compiler (e.g., `g++`)
- `make` installed (Linux/macOS/WSL)

### Steps
1. Navigate to the directory
2. Compile the project:
   ```bash
   make
3. Run the program with a sample input:
   ```bash
   ./encoder < inputs/sample_input.txt

## 📌 Future Improvements

- Dynamic resizing of the hash table

- Load factor threshold warnings

- GUI visualization of hash distribution
