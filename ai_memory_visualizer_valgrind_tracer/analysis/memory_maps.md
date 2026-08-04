# Memory Maps Analysis: Stack vs Heap & Lifetimes

## 1. Introduction
This document provides a memory analysis of the C programs in the `programs/` directory, mapping out stack frame behaviors, variable lifetimes, and pointer states.

---

## 2. Analysis of `stack_example.c`

### Execution Flow & Stack Frames
- **`main` Stack Frame:** Allocates local variables whose lifetime ends when `main` returns.
- **Function Stack Frames:** Pushed on top during calls. Local variables inside them are destroyed immediately upon function return. Returning pointers to these local variables causes dangling pointers and undefined behavior.

---

## 3. Critical Review of AI-Assisted Memory Visualization
- **AI Initial Assumption:** Local variables persist briefly after a function returns, making stack pointer returns temporarily acceptable.
- **Manual Correction:** Incorrect and hazardous. Stack memory is immediately reclaimed. Pointers to stack variables must never escape their scope; persistent data requires Heap allocation via `malloc`.