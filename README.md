# makefile
Creating a makefile should be just as easy as compiling a project.<br>
That's what this program allow you to do. By the end of this 10 minutes you could create a makefile just by typing `makemake` and then an executable by typing `make`.


## Instructions
### Fast run
Open a terminal in the makefile project path, and run
```
$ sudo chmod +x createCmd
$ sudo createCmd
```
Congratulations! now you can create a makefile in any directory for any c++ project by typing `makemake` in a terminal located on the project path.

### Slow and safe
#### step 1
Clone this project, or download it.
#### step 2
Open a terminal in the makefile project path, and run
```
$ make
```
Now you will find in the directory an executable named `mkfile`, you can move it to any directory and run it to create a makefile for the current path; or you can run it with a path argument like so
```
$ ./mkfile path/to/cpp/project/
```
<br>
This is not a comfortable way to create a make a make file, so bare with me in the last few steps.
#### step 4
In the makefile project you can find three bash scripts:<br>
`createCmd` , `deleteCmd` and `makemake` .<br>
Those files contain only a few lines of code each so you can check their innocence out if you want before the next step.<br>
Open a terminal in the makefile project path, and run
```
$ sudo chmod +x createCmd
$ sudo createCmd
```
This will create a new command (`makemake`) that will allow you to create a makefile.

Now you can create a makefile in any directory for any c++ project by typing `makemake` in a terminal located on the project path.

## Uninstall
Open a terminal in the makefile project path, and run
```
$ sudo chmod +x deleteCmd
$ sudo deleteCmd
```
