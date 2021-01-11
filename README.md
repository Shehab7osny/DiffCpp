# DiffCpp
![CI status](https://github.com/<Shehab7osny>/<diffCpp>/workflows/<Project%20Test%20Automation>/badge.svg)
This package is used to compare two text files and show the difference

## Installation
Use the g++ compiler to compile the diff.cpp file
```
g++ diff.cpp -o DiffCpp
```

## Usage
### Windows
```
DiffCpp File_1_Path File_2_Path [/N] [/A] [/W]
```
### Linux
```
./DiffCpp File_1_Path File_2_Path [/N] [/A] [/W]
```

Main Arguments

| Argument                | Description                                                   |
|-------------------------|---------------------------------------------------------------|
| File_1_Path	            |	This represents the old version of the file                   |
| File_2_Path			        | This represents the new version of the file                   |

Optional Arguments

| Argument                | Description                                                   |
|-------------------------|---------------------------------------------------------------|
| /N			                | Option to add line number to the displayed output             |
| /A		                  | Option to display the updates only and ignore common matches  |
| /W	                    | Option to ignore whitespaces difference while comparing files |

## Sample Use Case


### File 1 (recursion_Old.py)
```Python
def tri_recursion(k):
  if(k > 0):
    result = k + tri_recursion(k - 1)
  else:
    result = 1
  return result
```

### File 2 (recursion_New.py)
```Python
def tri_recursion(k):
  if(k > 0):
    result = k + tri_recursion(k - 1)
    print(result)
  else:
    result = 0
  return result
```
### Decide which options to use
* Since this is a code, the line number is vital. So we may need to include ```/N``` option.
* Since this is a python code, whitespaces are vital. So we must avoid using ```/W``` option.
* Since this is a small file, it is preferred to display the whole updated file. So we may avoid using ```/A``` option.

### File Paths
Assume that both files are in the same directory of the executable DiffCpp.
(The files can be placed in any other directory)

### With all this being said, the command line to get the job done will be as follows:
```
DiffCpp ./recursion_Old.py ./recursion_New.py /N
```

### Expected Output
```
+-------------------------------------------------+
|        ____  _  __  __  ____                    |
|       |  _ \(_)/ _|/ _|/ ___|_ __  _ __         |
|       | | | | | |_| |_| |   | '_ \| '_ \        |
|       | |_| | |  _|  _| |___| |_) | |_) |       |
|       |____/|_|_| |_|  \____| .__/| .__/        |
|                             |_|   |_|           |
|                                                 |
|       Version 1.0                               |
+-------------------------------------------------+
| DiffCpp  File1_Path  File2_Path  [/N] [/W] [/A] |
|                                                 |
| /N -> Display the line numbers                  |
| /W -> Ignore Whitespaces                        |
| /A -> Display the changes only                  |
+-------------------------------------------------+

File2 -> recursion_New.py
File1 -> recursion_Old.py

+-------+-------+---+----------------------------------------
| File2 | File1 |   | Updated File - recursion_New.py
+-------+-------+---+----------------------------------------
| 1     | 1     |   | def tri_recursion(k):
| 2     | 2     |   |   if(k > 0):
| 3     | 3     |   |     result = k + tri_recursion(k - 1)
| 4     |       | + |     print(result)
| 5     | 4     |   |   else:
|       | 5     | - |     result = 1
| 6     |       | + |     result = 0
| 7     | 6     |   |   return result
+-------+-------+---+----------------------------------------
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
