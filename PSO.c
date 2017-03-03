#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBERofPARTICLES 5
#define NUMBERofPARAMS 2
#define NUMBERofITERATIONS 1
#define TOP_LIMIT 10.0
#define FLOOR_LIMIT 0.0

/* Example
  Obtain the maximum for the following equation:
  f(x,y) = 50 - (x-5)² - (y-5)²
*/

// Swarm structure definition
typedef struct {
  float * Xi; // Position
  float * Vi; // speed
  float * Pi; // best position
  float XFit; // Position Fitness
  float PFit; // Best Position Fitness
}PARTICLE;

typedef struct {
  unsigned int NParticles;  // number of particles
  unsigned int NParams;     // number of params
  unsigned int idGBest;     // index of the best particle
  float C1;
  float C2;
  PARTICLE * Swrm;
}SWARM;

SWARM *AllocSwarm(const unsigned int NParticles,const unsigned int NParam);
void InitSwarm(SWARM * pSwrm, const float TLimit, const float FLimit, const float C1, const float C2);
void ShowParticle(SWARM * pSwrm, const unsigned int i);
void ShowSwarm(SWARM * pSwrm);
void FreeSwarm(SWARM * pSwrm);
void EvaluateSwarm(SWARM * pSwrm);
void InitBests(SWARM *pSwrm);
void UpdateSpeed(SWARM * pSwrm);
void UpdatePosition(SWARM *pSwrm);
void UpdateBests(SWARM *pSwrm);

int main(int argc, char const *argv[]) {
  SWARM *ex;
  unsigned int It = 0;

  ex = AllocSwarm(NUMBERofPARTICLES, NUMBERofPARAMS);
  InitSwarm(ex, TOP_LIMIT, FLOOR_LIMIT, 2, 2);
  EvaluateSwarm(ex);
  InitBests(ex);
  // Show Swarm and best particle
  ShowSwarm(ex);
  printf("\nBest = %u", ex->idGBest );

  while(It < NUMBERofITERATIONS) {
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

void UpdateBests(SWARM *pSwrm) {
  unsigned int i,k;
  float Best;
  Best = pSwrm->Swrm[pSwrm->idGBest].PFit;
  // Test each particle
  for(i=0; i<pSwrm->NParticles; i++) {
    if(pSwrm->Swrm[i].XFit > pSwrm->Swrm[i].PFit) {
      for(k=0; k<pSwrm->NParams; k++)
        pSwrm->Swrm[i].Pi[k] = pSwrm->Swrm[i].Xi[k];
      pSwrm->Swrm[i].PFit = pSwrm->Swrm[i].XFit;
    }
    if(pSwrm->Swrm[i].PFit>Best) {
      pSwrm->idGBest=i;
      Best=pSwrm->Swrm[i].PFit;
    }
  }
}

void UpdatePosition(SWARM *pSwrm){
  unsigned int i, k;
  // For each particles
  for(i=0; i<pSwrm->NParticles; i++)
    for(k=0; k<pSwrm->NParams; k++)
      pSwrm->Swrm[i].Xi[k]  += pSwrm->Swrm[i].Vi[k];
}


void UpdateSpeed(SWARM * pSwrm) {
  unsigned int i,k;
  float Y1, Y2;
  // For each particle
  for(i=0; i<pSwrm->NParticles; i++)
    for(k=0; k<pSwrm->NParams; k++)
    { // For each param
      Y1 = ((double)rand()/RAND_MAX);
      Y2 = ((double)rand()/RAND_MAX);
      pSwrm->Swrm[i].Vi[k] += pSwrm->C1*Y1*(pSwrm->Swrm[i].Pi[k]-pSwrm->Swrm[i].Xi[k]) + pSwrm->C2*Y2*(pSwrm->Swrm[pSwrm->idGBest].Pi[k]-pSwrm->Swrm[i].Xi[k]);
    }
}

void InitBests(SWARM *pSwrm) {
  unsigned int k;
  float Best;
  Best = pSwrm->Swrm[0].XFit;
  // Test each particle
  for(k=0; k<pSwrm->NParticles; k++) {
    pSwrm->Swrm[k].PFit = pSwrm->Swrm[k].XFit;
    if(pSwrm->Swrm[k].PFit>Best) {
      pSwrm->idGBest=k;
      Best=pSwrm->Swrm[k].PFit;
    }
  }
}

void EvaluateSwarm(SWARM * pSwrm) {
  unsigned int k;
  // Test each particle
  for(k=0; k<pSwrm->NParticles; k++)
    pSwrm->Swrm[k].XFit = 50 - ( ( (pSwrm->Swrm[k].Xi[0]-5) ) * ( (pSwrm->Swrm[k].Xi[0]-5) ) + ((pSwrm->Swrm[k].Xi[1]-5) ) * ( (pSwrm->Swrm[k].Xi[1]-5) ));
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
  free(pSwrm);
  // free memory for swarm
}

void ShowSwarm(SWARM * pSwrm) {
  unsigned int i;

  // for each particle
  for(i=0; i<pSwrm->NParticles; i++)
    ShowParticle(pSwrm, i);
  printf("\n");

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

  printf("\n XFit%u : ", i);
  printf("%2.4f ", pSwrm->Swrm[i].XFit);

  printf("\n PFit%u : ", i);
  printf("%2.4f ", pSwrm->Swrm[i].PFit);
}

void InitSwarm(SWARM * pSwrm, const float TLimit, const float FLimit, const float C1, const float C2) {
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
  pSwrm->C1 = C1;
  pSwrm->C2 = C2;
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
