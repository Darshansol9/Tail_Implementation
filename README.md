# Tail_Implementation

NYU Tandon Operating systems Course is acknowledged for this work.<br>

In this assignment, I implemented tail command that could run on xv6 system.
Use Cases Covered:<br>

If the file name is not given, read it from the stdin.<br>
If number of lines to be printed not provided, use by default as 10.<br>
If the number of lines in a file is less than user input, print all the lines without giving error.<br>
If the number of lines given by the user but no file name provided, take the input from the console and print the lines.<br>
It works of multi type commands such as grep, cat etc.<br>.


How to run on xv6.

Install the ova file on ubuntu for xv6.
Edit the MakeFile under the UPROGS, inser the file name in this case it is _tail\.
If you are working on custom based test file, you need to modify the MakeFile content.
You can read this link to understand more : https://stackoverflow.com/questions/47250441/add-a-generic-file-in-xv6-makefile<br>

Open the Terminal:
go inside the xv-6 directory, run the commands:
make clean
make 
make qemu
tail -10 README or tail -5 user input or grep the README | tail -2.
Try out more commands by yourself.

Happy Coding.
