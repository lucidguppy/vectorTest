./vectorTest 64 10000000 > data64.csv
./vectorTest 128 8000000 > data128.csv
./vectorTest 256 4000000 > data256.csv
./vectorTest 1024 2000000 > data1024.csv
./vectorTest 2048 1000000 > data2048.csv
./vectorTest 4096 700000 > data4096.csv
./vectorTest 8192 500000 > data8192.csv
./vectorTest 16384 300000 > data16384.csv
./vectorTest 32768 200000 > data32768.csv
./vectorTest 65535 100000 > data65535.csv
./vectorTest 1048576 70000 > data1048576.csv

python ./process.py data64.csv save
python ./process.py data128.csv save
python ./process.py data256.csv save
python ./process.py data1024.csv save
python ./process.py data2048.csv save
python ./process.py data4096.csv save
python ./process.py data8192.csv save
python ./process.py data16384.csv save
python ./process.py data65535.csv save
python ./process.py data1048576.csv save