#include <stdio.h>
#include <math.h>
#define g 10
//global variables
//condições iniciais
float Vox;
float Voy;
float Xo = 0;
float Yo = 0;

void velocity_y(float time) {
  float v = Voy - (g*time);
  printf("Voy(%f) = %f", time, v);
}
void position_x(float time) {
  float x = Xo + Vox*time;
  printf("X(%f) = %f", time, x);
}
void position_y(float time) {
  float y = Yo + Voy*time -(g*pow(time, 2))/2;
  printf("Y(%f) = %f", time, y);
}

int main() {
  printf("Digite a velocidade no eixo y em m/s: ");
  scanf("\n%f", &Voy);
  fflush( stdout );
  printf("Digite a velocidade no eixo X em m/s: ");
  scanf("\n%f", &Vox);
  float Tmax = (2*Voy)/g;
  float delta_t = Tmax/100;
  float t;
  for (t = 0; t <= Tmax; ) {
    velocity_y(t);
    position_x(t);
    position_y(t);
    t = t + delta_t;
  }

  return 0;
}
