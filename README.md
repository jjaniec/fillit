# Fillit  [![Build Status](https://travis-ci.org/UgoNic/fillit.svg?branch=master)](https://travis-ci.org/UgoNic/fillit)

## What's fillit ?

see [subject.en.pdf](https://github.com/jjaniec/fillit/blob/master/fillit.en.pdf) or [subject.fr.pdf](https://github.com/jjaniec/fillit/blob/master/fillit.fr.pdf)

>Fillit is a project that let you discover and/or familiarize yourself with a recurring problematic in programming: searching the optimal solution among a huge set of possibilities, in a respectable timing. In this particular project, you will have to find a way to assemble a given Tetriminos set altogether in the smallest possible square.

## Usage

### Trying it with Docker

```bash
docker run -it jjaniec/fillit
```

### Manual Installation

You can try our project with the following commands:

First, clone the repository and it's dependencies to create the executable

```bash
git clone https://github.com/jjaniec/fillit
cd fillit
git clone https://github.com/jjaniec/libft
make
```

then, create a file containing tetriminos

```bash
make map T_COUNT=x
```

>with x, number of tetriminos to create in the file "map.fillit", 5 by default

finally, run fillit with your file

```bash
./fillit map.fillit
```

## Example


    user% make map
    ./map_generator 5

    user%cat -e map.fillit
    ....$
    ####$
    ....$
    ....$
    $
    .#..$
    .###$
    ....$
    ....$
    $
    .#..$
    .##.$
    .#..$
    ....$
    $
    ....$
    ....$
    ###.$
    .#..$
    $
    .#..$
    .##.$
    .#..$
    ....$

    user% ./fillit map.fillit
    AAAA.
    DDDC.
    ED.CC
    EEBC.
    E.BBB
