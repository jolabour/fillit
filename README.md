# fillit

Fillit is the first algo project of 42. 
the goal is to make the smallest possible square with a list of pieces of tetriminos written in a file.

## compile and run

run ```make && ./fillit [file with tetriminos]```

###### example of file
```
$> cat sample.fillit | cat -e
....$
##..$
.#..$
.#..$
$
....$
####$
....$
....$
$
#...$
###.$
....$
....$
$
....$
##..$
.##.$
....$
```

###### example of output
```
$> ./fillit sample.fillit | cat -e
DDAA$
CDDA$
CCCA$
BBBB$
$>
```
