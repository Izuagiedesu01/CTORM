# CTORM — C to Rust Migration 

> **SIWES Technical Project & Performance Benchmark**  
> Department of Software Engineering — Bowen University

`CTORM` is an engineering project focused on migrating legacy, memory-vulnerable C system components to safe, idiomatic Rust without performance degradation.

---

## 🛠️ Project Structure

* **`c_legacy/`**: Original C dynamic string buffer library (`sbuf`), featuring manual memory management via `malloc`, `realloc`, and `free`.
* **`rust_crate/`**: Migrated, memory-safe Rust library leveraging ownership, RAII, and the `Drop` trait.
* **`app/`**: Practical CLI Log Stream Aggregator application consuming `rust_crate`.
* **`docs/`**: SIWES documentation, logbook references, and 15-slide defense deck outline.

---

## 📊 Benchmark Summary (1,000,000 Appends)

| Metric | C Legacy (`c_legacy`) | Safe Rust (`rust_crate`) |
| :--- | :--- | :--- |
| **Execution Speed** | ~0.031s | ~0.029s |
| **Memory Allocation** | Manual (`malloc`/`realloc`) | Managed (`Vec<u8>`) |
| **Safety Guarantees** | Manual Discipline | Compile-Time (Borrow Checker) |
| **Leak Vulnerability** | Risk of Leaks / Double Free | 0% (Automatic `Drop` cleanup) |

---

## 🚀 How to Run

### Run C Legacy Tests & Benchmarks
```bash
cd c_legacy
make
./sbuf_test
gcc -O3 sbuf.c bench.c -o bench_c && ./bench_c
