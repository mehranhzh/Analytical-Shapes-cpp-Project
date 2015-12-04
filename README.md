#Analytical Shapes
The current aim is to make every surface of a primitive triangulated. The vertices of these triangles will be stored into a vector called Points. The information a .stl file needs will calculated in the Triangle and 3D primitive class, such as normal vector of a triangle and the coordinates of its vertices. Then use the stlWriter to output the information of these vertices to get the STL files.

Our goal is to design a data structure to efficiently represent meshes of every primitives and the outcomes of the their transformation.
