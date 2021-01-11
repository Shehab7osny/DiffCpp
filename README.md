# DiffCpp
This package is used to compare two text files and show the difference

## Installation
Use the g++ compiler to compile the diff.cpp file
```
g++ diff.cpp -o DiffCpp
```

## Usage
```
DiffCpp File_1_Path File_2_Path [/N] [/A] [/W]
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

File 1 (recursion_Old.py)
```Python
def tri_recursion(k):
  if(k > 0):
    result = k + tri_recursion(k - 1)
  else:
    result = 1
  return result
```
File 2 (recursion_New.py)
```Python
def tri_recursion(k):
  if(k > 0):
    result = k + tri_recursion(k - 1)
    print(result)
  else:
    result = 0
  return result
```
