# Cache Management Policies in a Fixed-Size Cache

Implementation of cache replacement policies in C to analyze  and  behavior in a fixed-size cache environment. This project was developed for the CSE360 Computer Architecture course.

---

## 📌 Project Objective

The objective of this project is to simulate and compare different cache replacement policies in order to observe:

* Cache hits and misses
* Cache pollution
* Thrashing behavior
* Overall cache performance in a fixed-size cache system

---

## 🧠 Concepts Covered

* Cache Memory
* Cache Replacement Policies
* FIFO (First In First Out)
* LRU (Least Recently Used)
* Cache Pollution
* Thrashing
* Memory Access Simulation

---

## ⚙️ Features

* Fixed-size cache simulation
* FIFO cache replacement implementation
* LRU cache replacement implementation
* Cache hit/miss tracking
* Performance comparison between policies
* Analysis of cache pollution and thrashing effects

---

## 🛠 Technologies Used

* C Programming Language
* Standard C Libraries
* Console-based Simulation

---

## 📂 Project Structure

```text id="project-structure"
Cache-Management-Policies/
│
├── source-code/
├── reports/
├── output-screenshots/
├── README.md
└── LICENSE
```

---

## 🚀 How to Run

1. Clone the repository:

```bash id="clone-repo"
git clone <repository-link>
```

2. Navigate to the project directory:

```bash id="cd-project"
cd Cache-Management-Policies
```

3. Compile the program:

```bash id="compile"
gcc main.c -o cache
```

4. Run the executable:

```bash id="run"
./cache
```

---

## 📊 Project Analysis

This project demonstrates how inefficient cache management can lead to:

* Increased cache misses
* Reduced performance
* Cache pollution caused by unnecessary data retention
* Thrashing due to excessive replacement operations

The comparison between FIFO and LRU helps visualize how different replacement strategies affect cache efficiency.

---

## 🎯 Learning Outcomes

* Understanding cache memory architecture
* Implementing cache replacement algorithms
* Analyzing memory management behavior
* Studying performance optimization techniques in computer systems

---

## 👩‍💻 Authors

* Shairin Akter Hashi
* Zihad Khan

Department of Computer Science & Engineering
East West University

---

## 📘 Course Information

* Course: Computer Architecture
* Course Code: CSE360
* Semester: Spring 2026
