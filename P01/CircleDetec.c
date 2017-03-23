#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "DIP.h"
#include "PSO.h"

#define NUMBERofPARTICLES 20
#define NUMBERofPARAMS 2
#define NUMBERofITERATIONS 50
#define TOP_LIMIT 10.0
#define FLOOR_LIMIT 0.0

int main(int argc, char const *argv[]) {
  float i;
  unsigned int xc, yc, r, indswrm, x, y, j, k, It = 0;

  SWARM *swrm;
  gcIMG *img;

  // Open the image that is going to be used for the circle detection
  img = gcGetImgBmp("dos.bmp");

  // Sets the swarm ready to detection
  swrm = AllocSwarm(NUMBERofPARTICLES, NUMBERofPARAMS);

  // A partir de aquí hay que modificar la fórmula con la que se calcula el fitness
  InitSwarm(swrm, TOP_LIMIT, FLOOR_LIMIT, 2, 2, 1, -1);
  EvaluateSwarm(swrm);
  InitBests(swrm);
  // Show Swarm and best particle
  ShowSwarm(swrm);
  printf("\nBest = %u", swrm->idGBest );

  // Pero después se va a iterar igual que en el ejemplo, hasta encontrar los circulos
  while(It < NUMBERofITERATIONS && 50-swrm->Swrm[swrm->idGBest].PFit >0.1 ) {
    UpdateSpeed(swrm);
    UpdatePosition(swrm);
    EvaluateSwarm(swrm);
    UpdateBests(swrm);
    ShowSwarm(swrm);
    It++;
    printf("\nBest = %u", swrm->idGBest );
  }
  FreeSwarm(swrm);
  return 0;
}
