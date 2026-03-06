# 🎮 CLI Game Store — DSA Assignment 2

This repo contains the source files of the DSA Assignment 2.

---

## 📁 Project Structure

```
DSA/
│
├── include/            # All header files (.h)
│   ├── common.h
│   ├── catalog.h
│   ├── cart.h
│   ├── download.h
│   ├── navigation.h
│   ├── library.h
│   ├── wishlist.h
│   └── support.h
│
├── src/                # All source files (.c)
│   ├── main.c
│   ├── catalog.c
│   ├── cart.c
│   ├── download.c
│   ├── navigation.c
│   ├── library.c
│   ├── wishlist.c
│   └── support.c
│
└── README.md
```

---

## ▶️ How to Run

```bash
gcc src/*.c -Iinclude -o gamestore
./gamestore
```

---

## 📐 Naming Conventions

To ensure compatibility of each module please follow these naming conventions:

**Structs & Typedef → PascalCase**
```c
typedef struct StudentRecord {
    // values
} StudentRecord;
```

**Functions → module_snake_case()**

Start every function with the module name.
```c
catalog_sort_games()
cart_add_item()
```

**Variables → camelCase**
```c
int gameCount;
float totalPrice;
```

**Constants → UPPER_SNAKE_CASE**
```c
#define MAX 100
```

---

## ⚠️ Rules

**!!ALWAYS free the memory after using `malloc` or `calloc`!!**

**!!ALWAYS write good comments!!**
