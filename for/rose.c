//
// Created by hfwei on 2023/10/12.
//

#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");

  int x, y;
  double theta;
  int a = 10, b = 7; // Adjust these values for different shapes

  for (theta = 0; theta <= 2 * M_PI; theta += 0.001) {
    // Parametric equations for the rose pattern
    x = getmaxx() / 2 + (a - b) * cos(theta) * cos(theta) * cos(theta);
    y = getmaxy() / 2 - (a - b) * sin(theta) * sin(theta) * sin(theta);
    putpixel(x, y, RED);
  }

  delay(5000); // Display the pattern for 5 seconds

  closegraph();
  return 0;
}