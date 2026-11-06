# Low-Level Programming & Computer Science Fundamentals 💻

Welcome to my repository for **Low-Level Programming and Systems Architecture** completed at **Holberton School**. This repository serves as a comprehensive collection of fundamental C programming concepts, memory management techniques, data structures, and debugging workflows.

---

## 📌 Topics Covered & Directory Structure

| Directory | Description | Core Concepts |
| :--- | :--- | :--- |
| `hello_world` | Introduction to C compilation pipeline | `gcc`, preprocessor, assembly, object code |
| `variables_if_else_while` | Control flow and loops | Conditionals, logical operators, ASCII |
| `functions_nested_loops` | Functional decomposition | Scope, stack frames, nested loops |
| `pointers_arrays_strings` | Pointers & Memory addressing | Pointer arithmetic, string manipulation |
| `malloc_free` | Dynamic memory allocation | `malloc`, `free`, heap management |
| `more_malloc_free` | Advanced dynamic allocation | `realloc`, `calloc`, memory leak prevention |
| `singly_linked_lists` | Linear data structures | Structs, dynamic node allocation |
| `doubly_linked_lists` | Bi-directional linked lists | Node traversal, pointer manipulation |
| `hash_tables` | Key-value data indexing | Hash functions, collision handling (chaining) |
| `file_io` | System calls & I/O operations | `open`, `read`, `write`, `close`, file descriptors |
| `ai_memory_visualizer_valgrind_tracer` | Memory Analysis & Leak Detection | Valgrind, heap profiling, crash analysis |
| `secure_data_handling` | Safe C practices | Buffer overflow prevention, robust failure handling |

---

## 🛠️ Environment & Tools

- **OS:** Ubuntu / Linux WSL2
- **Compiler:** `gcc` (Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`)
- **Code Style:** Betty Coding Standard (Linter)
- **Debugging & Analysis:** GDB, Valgrind

---

## 🚀 How to Compile & Run

To compile any project file using the standard flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 filename.c -o output_name
./output_name
