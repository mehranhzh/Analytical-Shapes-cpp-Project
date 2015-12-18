# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

# include "stla_io.hpp"

int main ( );
void test04 ( string file_name );

int main ( )
{
  test04 ( "cube.stla" );
  return 0;
}

void test04 ( string output_file_name )
{
# define FACE_NUM 12
# define NODE_NUM 8

  int face_node[3*FACE_NUM] = {
    1, 3, 2, 
    2, 3, 4, 
    1, 6, 5,
    1, 2, 6, 
    3, 7, 4, 
    4, 7, 8, 
    5, 6, 8, 
    5, 8, 7, 
    1, 5, 7, 
    1, 7, 3, 
    2, 4, 6, 
    6, 4, 8 };
  double face_normal[3*FACE_NUM] = {
    0.0,  0.0, -1.0, 
    0.0,  0.0, -1.0, 
    0.0, -1.0,  0.0, 
    0.0, -1.0,  0.0, 
    0.0, +1.0,  0.0, 
    0.0, +1.0,  0.0, 
    0.0,  0.0, +1.0, 
    0.0,  0.0, +1.0, 
   -1.0,  0.0,  0.0, 
   -1.0,  0.0,  0.0, 
   +1.0,  0.0,  0.0, 
   +1.0,  0.0,  0.0 }; 
  double node_xyz[3*NODE_NUM] = {
    0.0, 0.0, 0.0, 
    1.0, 0.0, 0.0, 
    0.0, 1.0, 0.0, 
    1.0, 1.0, 0.0, 
    0.0, 0.0, 1.0, 
    1.0, 0.0, 1.0, 
    0.0, 1.0, 1.0, 
    1.0, 1.0, 1.0 };
  int offset;

  offset = 1;
  stla_offset_set ( offset );

  stla_write ( output_file_name, NODE_NUM, FACE_NUM, node_xyz, 
    face_node, face_normal );

  cout << "\n";
  cout << "  Graphics data was written to the STLA file \""
    << output_file_name << "\".\n";

  return;
# undef FACE_NUM
# undef NODE_NUM
}
