# aed3-tp3

## Player

### Compilation

```
cd src
make
```

## Game

###  Installation

Program c_linea.py runs on Python 2

If you only have python 2 installed, run `sudo pip install pygame`

If you have python 3 alongside python 2, run `sudo python2 -m pip install pygame`

### Sample run

If you only have python 2 installed and want to compite two HUMAN PLAYERS, run `python c_linea.py --first azul --ui True --columns 7 --rows 6 --p 21 --c 4`

If you only have python 2 installed and want to compite you against CUSTOM PLAYER, run `python c_linea.py --blue_player ./your_player --first azul --ui True --columns 7 --rows 6 --p 21 --c 4`

If you have python 2 alongside python 2, run `python2 c_linea.py --blue_player ./random_player --first azul --ui True --columns 7 --rows 6 --p 21 --c 4`


## Run naive player

```
cd cmake-build-debug
cmake ..
make
python c_linea.py --blue_player ./jugador_greedy --first azul --ui True --columns 7 --rows 6 --p 21 --c 4
```

## Run player with genetic parameter (obtenidos por correr optimizaciones_jugador_greedy)

```
cd cmake-build-debug
cmake ..
make
python c_linea.py --blue_player ./genetic_parametriced_player --first azul --ui True --columns 7 --rows 6 --p 21 --c 4
```

## Correr experimento random contra jugador genético

```
cd cmake-build-debug
cmake ..
make
python c_linea.py --blue_player ./experimento-genetico-random --first azul --ui True --columns 7 --rows 6 --p 21 --c 4
```
