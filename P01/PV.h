// Define point structure, for the point that are part of the border
typedef struct{
  unsigned int x;
  unsigned int y;
}PIXEL;

// Define vector structure, for the array of points of the borders
typedef struct{
  PIXEL *data;
  unsigned int len;
}VECTOR;

// Define important functions for Vector structure
VECTOR * AllocVector(gcIMG *img);
void * InitVector(VECTOR *V, gcIMG *img);
void FreeVector(VECTOR * V);

// Initialization for Vector, counts how many pixels are black in the received image
void * InitVector(VECTOR *V, gcIMG *img) {
  unsigned short int i, j;
  unsigned int k = 0;

  for(i=0; i<img->ancho; i++)
    for(j=0; j<img->alto; j++)
      if(img->imx[i*img->alto + j] == 0) {
        V->data[k].x = i;
        V->data[k++].y = j;
      }
  if(k == V->len) printf("True\n");
}

// Allocate the space necessary for the Vector
VECTOR * AllocVector(gcIMG *img) {
  VECTOR * V;
  unsigned short int i, j;
  unsigned int len = 0;

  // Counts how many pixel are borders in the image
  V = (VECTOR*)malloc(sizeof(VECTOR));
  for(i=0; i<img->alto; i++)
    for(j=0; j<img->ancho; j++)
      if(img->imx[i*img->ancho + j] == 0) len++;
  V->len = len;

  // Allocated the space needed for the vector
  V->data = (PIXEL*)malloc(len*sizeof(PIXEL));
  return V;
}
