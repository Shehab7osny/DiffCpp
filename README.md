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
| Argument                | Description                                                   |
|-------------------------|---------------------------------------------------------------|
| File_1_Path	            |	This represents the old version of the file                   |
| File_2_Path			        | This represents the new version of the file                   |
| /N			                | Option to add lines number to the displayed output            |
| /A		                  | Option to display the updates only and ignore common matches  |
| /W	                    | Option to ignore whitespaces difference while comparing files |
