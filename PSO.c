#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMBERofPARTICLES 5
#define NUMBERofPARAMS 2
#define TOP_LIMIT 10.0
#define FLOOR_LIMIT 0.0

/* Example
  Obtain the maximum for the following equation:
  f(x,y) = 50 - (x-5)² - (y-5)²
*/

// Swarm structure definition
typedef struct {
  float * Xi; // Position
  float * Vi; // velocity
  float * Pi; // best position
}PARTICLE;

typedef struct {
  unsigned int NParticles;  // number of particles
  unsigned int NParams;     // number of params
  PARTICLE * Swrm;
}SWARM;

SWARM *AllocSwarm(const unsigned int NParticles,const unsigned int NParam);
void InitSwarm(SWARM * pSwrm, const float TLimit, const float FLimit);
void ShowParticle(SWARM * pSwrm, const unsigned int i);
void ShowSwarm(SWARM * pSwrm);
void FreeSwarm(SWARM * pSwrm);

int main(int argc, char const *argv[]) {
  SWARM *ex;

  ex = AllocSwarm(NUMBERofPARTICLES, NUMBERofPARAMS);

  InitSwarm(ex, TOP_LIMIT, FLOOR_LIMIT);

  ShowSwarm(ex);

  FreeSwarm(ex);

  return 0;
}

SWARM *AllocSwarm(const unsigned int NParticles, const unsigned int NParam) {
  SWARM *ptr;
  unsigned int k;

  // Memory allocation for Swarm structure
  ptr = malloc(sizeof(SWARM));
  if(ptr == NULL) {
    printf("Error allocating memory for Swarm strucuture\n");
    exit(-1);
  }

  // Structure initialization
  ptr->NParticles = NParticles;
  ptr->NParams = NParam;

  // Memory allocation for the particles
  ptr->Swrm = (PARTICLE *)malloc(sizeof(PARTICLE)*NParticles);
  if(ptr->Swrm == NULL) {
    printf("Error allocating memory for particles\n");
    exit(-1);
  }
  // Allocate memory for each particle
  for(k=0; k<NParticles; k++) {
    ptr->Swrm[k].Xi = (float *)malloc(sizeof(float)*NParam);
    ptr->Swrm[k].Vi = (float *)malloc(sizeof(float)*NParam);
    ptr->Swrm[k].Pi = (float *)malloc(sizeof(float)*NParam);
  }

  return ptr;
}

void InitSwarm(SWARM * pSwrm, const float TLimit, const float FLimit) {
  unsigned int i, k;
  float r;

  // For all particles
  for(i=0; i<pSwrm->NParticles; i++) {
    // for all params
    for(k=0; k<pSwrm->NParams; k++ ) {
      r = (TLimit-FLimit)*((double)rand()/RAND_MAX)+FLimit;
      pSwrm->Swrm[i].Xi[k] = r;
      pSwrm->Swrm[i].Vi[k] = 0;
      pSwrm->Swrm[i].Pi[k] = r;
    }
  }
}

void ShowParticle(SWARM * pSwrm, const unsigned int i) {
  unsigned int k;

  printf("\n X%u : ", i);
  for(k=0; k<pSwrm->NParams; k++)
    printf("%2.4f ", pSwrm->Swrm[i].Xi[k]);

  printf("\n V%u : ", i);
  for(k=0; k<pSwrm->NParams; k++)
    printf("%2.4f ", pSwrm->Swrm[i].Vi[k]);

  printf("\n P%u : ", i);
  for(k=0; k<pSwrm->NParams; k++)
    printf("%2.4f ", pSwrm->Swrm[i].Pi[k]);
}

void ShowSwarm(SWARM * pSwrm) {
  unsigned int i;

  // Para todas las particulas
  for(i=0; i<pSwrm->NParticles; i++)
    ShowParticle(pSwrm, i);
  printf("\n");
}

void FreeSwarm(SWARM * pSwrm) {
  unsigned int k;
  // free memory for all params of each Particle
  for(k=0; k<pSwrm->NParticles; k++) {
    free(pSwrm->Swrm[k].Xi);
    free(pSwrm->Swrm[k].Vi);
    free(pSwrm->Swrm[k].Pi);
  }

  // free memory for all particles
  free(pSwrm->Swrm);

  // free memory for swarm
  free(pSwrm);
}
