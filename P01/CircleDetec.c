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
  SWARM *swrm;

  gcIMG *img;
  float i;
	unsigned int xc, yc, r, index, x, y, j, k;

  //Abrir una imagen llamada Uno.bmp
  img = gcGetImgBmp("dos.bmp");

  swrm = AllocSwarm(NUMBERofPARTICLES, NUMBERofPARAMS);
  InitSwarm(swrm, TOP_LIMIT, FLOOR_LIMIT, 2, 2, 1, -1);
  EvaluateSwarm(swrm);
  InitBests(swrm);
  // Show Swarm and best particle
  ShowSwarm(swrm);
  printf("\nBest = %u", ex->idGBest );

  while(It < NUMBERofITERATIONS && 50-ex->Swrm[ex->idGBest].PFit >0.1 ) {
    UpdateSpeed(ex);
    UpdatePosition(ex);
    EvaluateSwarm(ex);
    UpdateBests(ex);
    ShowSwarm(ex);
    It++;
    printf("\nBest = %u", ex->idGBest );
  }
  FreeSwarm(ex);
  return 0;
}
