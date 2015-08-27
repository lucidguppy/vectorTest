cmake_minimum_required(VERSION 3.2)
project(vectorTest)

configure_file(process.py process.py COPYONLY)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2")

set(SOURCE_FILES main.cpp TimeToCopyVector.cpp TimeToCopyArray.cpp)
add_executable(vectorTest ${SOURCE_FILES})

function(generate_data buffer_size loops)
    set(output_data_file data${buffer_size}.csv)
    set(output_image_file data${buffer_size}.svg)

    add_custom_command(OUTPUT ${output_data_file}
        COMMAND vectorTest ${buffer_size} ${loops} > ${output_data_file}
        DEPENDS vectorTest)

    add_custom_command(OUTPUT ${output_image_file}
        COMMAND python ./process.py ${output_data_file} save ${output_image_file}
        DEPENDS ${output_data_file})
endfunction(generate_data)

generate_data(64 25000000)
generate_data(128 12500000)
generate_data(256  6250000)
generate_data(1024 3125000)
generate_data(2048 1500000)
generate_data(4096 750000)
generate_data(8192 300000)
generate_data(16384 150000)
generate_data(32768 75000)
generate_data(65535 37500)
generate_data(1048576 15000)

add_custom_target(data
    DEPENDS
        data64.csv
        data128.csv
        data256.csv
        data1024.csv
        data2048.csv
        data4096.csv
        data8192.csv
        data16384.csv
        data32768.csv
        data65535.csv
        data1048576.csv
)

add_custom_target(images
    DEPENDS
        data64.svg
        data128.svg
        data256.svg
        data1024.svg
        data2048.svg
        data4096.svg
        data8192.svg
        data16384.svg
        data32768.svg
        data65535.svg
        data1048576.svg
)