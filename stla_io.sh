
g++ -c stla_io.cpp
if [ $? -ne 0 ]; then
  echo "Errors compiling stla_io.cpp"
  exit
fi

echo "Library installed as stla_io.o"
