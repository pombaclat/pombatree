# Disk Analyzer

A C++ CLI tool to see what's taking up space on your disk.

## Versions

### V1 - Basic Scanner

* Scan a directory
* Calculate folder sizes
* Show biggest files
* Display file sizes in a readable format
* Skip directories without permission

### Instructions

##### Compile

```bash
c++ main.cpp -o pomtree
```

##### Usage

```bash
./pomtree size (path)
./pomtree biggest (path) (topnumber)
```

### Commands

#### `size`

Calculates the total size of all files inside a directory and its subdirectories.

```bash
./pomtree size /home/user
```

Example output:

```text
Total size: 12.45GB
```

#### `biggest`

Shows the biggest files inside a directory and its subdirectories.

The `topnumber` argument controls how many files are displayed.

For example, to show the **10 biggest files**:

```bash
./pomtree biggest /home/user 10
```

To show only the **biggest file**:

```bash
./pomtree biggest /home/user
```

Example output:

```text
1. 4.82GB - /home/user/Downloads/linux.iso
2. 3.21GB - /home/user/Videos/video.mkv
3. 2.87GB - /home/user/backup.zip
```

The scanner recursively searches through subdirectories and skips directories where permission is denied.
