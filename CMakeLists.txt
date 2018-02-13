cmake_minimum_required(VERSION 3.8)
project(raytracer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    RT/Bmpfile.cpp
    RT/Bmpfile.h
    RT/Color.h
    RT/Common.h
    RT/Light.h
    RT/Object.h
    RT/Point3d.h
    RT/PointLight.h
    RT/Ray.h
    RT/Scene.cpp
    RT/Scene.h
    RT/Sphere.cpp
    RT/Sphere.h
    RT/Vector3d.h
    main.cpp)

add_executable(raytracer ${SOURCE_FILES})