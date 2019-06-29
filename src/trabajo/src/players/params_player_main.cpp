//
// Created by Christian nahuel Rivera on 15/6/19.
//

#include "../Game.h"
#include "../strategies/ParamsStrategy.h"
#include "../entities/Defines.h"


int main(){
  Game game = Game();

  // Estos parámetros hay que optimizar. Pueden tomar valores de 0 a 20 (el máximo lo acabo de definir,
  // podemos poner un máximo mayor).

  int paramCentralidad = 5;
  int paramLineaGanadora = 15;
  int paramRivalPuedeGanar = 20;
  int paramLongitudMaximaPropia = 10;
  int paramLongitudMaximaRival = 7;

  ParamsStrategy strategy(paramCentralidad, paramLineaGanadora, paramRivalPuedeGanar,
                          paramLongitudMaximaPropia, paramLongitudMaximaRival);
  
  game.runGame(&strategy);
  
  return 0;
}