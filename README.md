# Pombatree (File Size CLI)

A simple command-line tool written in C++ to analyze directory sizes and find the largest files.

## Features
- Calculate the total size of a directory recursively.
- Find the biggest files in a directory.
- Choose how many of the largest files to display.
- Automatically convert bytes into KB, MB and GB.
- Skip directories with permission restrictions.

## Usage

### Calculate directory size
```bash
./pombatree size /path/to/directory
```

### Find the biggest files
```bash
./pombatree biggest /path/to/directory
```

### Show the 5 biggest files
```bash
./pombatree biggest /path/to/directory 5
```

## Compilation

Requires a C++17-compatible compiler.

```bash
c++ main.cpp -o pombatree
```

## Technologies
- C++17
- Filesystem library
- STL (`vector`, `algorithm`, `sstream`)
