<h1 align="center">filler - A multiplayer game AI.</h1>
<p align="center">
    <img src="https://github.com/salahadawi/filler/blob/master/images/filler_demo.gif">
</p>

Filler is an algorithmic game which consists of filling a grid with randomly generated pieces, 
without the pieces being stacked more than one square above each other and without them exceeding the grid.

Each successfully placed piece yields a number of points. The goal of Filler is to place as many
pieces as possible while attempting to prevent your opponent from doing the same. At the
end of the game, the one with the most points wins the match.

<h2 align="center">How does it work?</h2>

<h2 align="center">Usage</h2>

1. Clone the repo:
```
git clone https://github.com/salahadawi/filler.git
```
2. Compile the project:
```
make
```

3. Run the AI against a simple practice AI:
```
./filler_vm -f maps/map00 -p1 ./sadawi.filler -p2 ./players/random.filler
```
The game will be output to the terminal.

<p align="center">
    <img src="https://github.com/salahadawi/ft_ls/blob/master/images/ft_ls-libft.gif">
</p>
