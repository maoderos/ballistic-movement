#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 10
//global variables
//condições iniciais
float Vox;
float Voy;
float Xo = 0;
float Yo = 0;

float velocity_y(float time) {
  float v = Voy - (g*time);
  printf("\nVoy(%f) = %f", time, v);
  return v;
}
float position_x(float time) {
  float x = Xo + Vox*time;
  printf("/X(%f) = %f", time, x);
  return x;
}
float position_y(float time) {
  float y = Yo + Voy*time - (g*pow(time, 2))/2;
  printf("/Y(%f) = %f", time, y);
  return y;
}
void w_plot_voy(float x, float y, FILE *p) {
  fprintf(p, "%f %f\n", x, y);
}
void w_plot_y(float x, float y, FILE *p) {
  fprintf(p, "%f %f\n", x, y);
}
void w_plot_x(float x, float y, FILE *p) {
  fprintf(p, "%f %f\n", x, y);
}
void plot() {
 system("gnuplot -p -e \"plot 'data_Vy.txt'\"");
 system("gnuplot -p -e \"plot 'data_x.txt'\"");
 system("gnuplot -p -e \"plot 'data_y.txt'\"");
}
void close_files(FILE *p1, FILE *p2, FILE *p3) {
  fclose(p1);
  fclose(p2);
  fclose(p3);
}
//char * commandsForGnuplot[] = {
  //"set xrange \"[-1:1]\""
//}
int main() {
  printf("Digite a velocidade no eixo y em m/s: ");
  scanf("\n%f", &Voy);
  printf("Digite a velocidade no eixo X em m/s: ");
  scanf("\n%f", &Vox);
  float Tmax = (2*Voy)/g;
  float delta_t = Tmax/100;
  float t, x, y, vy;
  FILE *p_vy = fopen("data_Vy.txt", "w");
  FILE *p_y = fopen("data_y.txt", "w");
  FILE *p_x = fopen("data_x.txt", "w");

  for (t = 0; t <= Tmax; ) {
    vy = velocity_y(t);
    x = position_x(t);
    y = position_y(t);
    w_plot_voy(t, vy, p_vy);
    w_plot_y(t, y, p_y);
    w_plot_x(t, x, p_x);
    t = t + delta_t;
  }
  close_files(p_vy, p_y, p_x);
  plot();
  return 0;
}
