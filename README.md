# Spotify

### Name: Tim Marder
### BU Userid: B00789845

### Setting up the Makefile
Please take a look at the [makefile](./makefile) given to you and replace all the "replaceme" strings accordingly.

The makefile does not include target to separately compile, create .o files and then link them to create the CA3 executable. YOU WILL NEED TO DEFINE THESE TARGETS YOURSELF IN THE makefile.

### Run the program
To run your CA3 executable use the below command.
_Note: Replace the angular brackets and everything inside it._
```commandline
make run inputdir=<name of songs directory> workdir=<name of working/output directory>
```

### Memory Leak Check
To check for memory leaks using valgrind run the below command.
_Note: Replace the angular brackets and everything inside it._
```commandline
make memcheck inputdir=<name of songs directory> workdir=<name of working/output directory>
```

### Creating Submission tar.gz File
Once you are ready to submit CA3, please run the below command.
```commandline
make tar
```

This will create the tar.gz file in the parent directory.
