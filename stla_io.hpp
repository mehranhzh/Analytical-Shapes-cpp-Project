int stla_offset_get ( void );
void stla_offset_set ( int offset );
void stla_write ( string output_file_name, int node_num, int face_num, 
double node_xyz[], int face_node[], double face_normal[] );
string word_next_read ( string s, bool *done );

static int stla_offset_value = 0;







