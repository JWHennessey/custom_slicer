#include "circle_slice.h"

CircleSlice::CircleSlice(
    Printhead* ph,
    //std::vector<std::string>* cmds,
    float x_c, 
    float y_c, 
    float r, 
    float t_int)
{
  //std::cout << "Slice radius " << radius << "\n";
  _ph = ph;
  //commands = cmds;
  x_center = x_c;
  y_center = y_c;
  radius = r;
  t_interval = t_int;
  CIRCLE_POINTS = 100;
  LINE_WIDTH = 0.3f;
  LAYER_HEIGHT = 0.1f;
}

void CircleSlice::generateOuterWall(int width)
{
  //std::cout << "Generate OuterWall \n";
  //_ph->extrudeXYAxisTo(x_center, y_center);
  //

  radius -= LINE_WIDTH * width;

  for(int i = 0; i < width; i++){
    double t = 0.0;
    double x = x_center + radius * cos(6.2832);
    double y = y_center + radius * sin(6.2832);
    _ph->extrudeXYAxisTo(x, y);
    for(int j=0; j<=CIRCLE_POINTS; j++)
    {
      //std::cout << radius << "\n";
      x = x_center + radius * cos(t);
      y = y_center + radius * sin(t);
      t += t_interval;
      _ph->extrudeXYAxisTo(x, y);
    }
    //TODO FIX THIS HACK how much should it decrease by
    radius += LINE_WIDTH;
    x += LINE_WIDTH;
   //_ph->extrudeXYAxisTo(x, y);
  }
  _ph->moveZAxis();
}

//void CircleSlice::addCommand(float x, float y, float e = 0.0, float z = 0.0)
//{

  ////x_coord += x;
  ////y_coord += y;
  ////z_coord += z;
  ////e_val   += e;

  ////std::stringstream ss;

  ////if(z == 0.0 && e == 0.0)
    ////ss << "G1 F1200 X" << x_coord << " Y" << y_coord << "\n";
  ////else if (z != 0.0)
    ////ss << "G1 F9000 X" << x_coord << " Y" << y_coord << " Z" << z_coord  << "\n";
  ////else if (e != 0.0)
    ////ss << "G1 F1200 X" << x_coord << " Y" << y_coord << " E" << e_val << "\n";

  ////std::string s = ss.str();
  ////gcode->push_back(s);
//}
