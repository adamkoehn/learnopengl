AM_CXXFLAGS = -Wall -pedantic

bin_PROGRAMS = cubes

cubes_SOURCES = main.cpp ../manager/Window.cpp ../manager/Camera.cpp ../manager/Input.cpp ../graphics/Shader.cpp ../graphics/TexturedCube.cpp ../scene/Cubes.cpp
cubes_CXXFLAGS = $(AM_CXXFLAGS) $(GLFW_CFLAGS) $(GLEW_CFLAGS) $(STB_CFLAGS) $(GLM_CFLAGS)
cubes_LDADD = $(GLFW_LIBS) $(GLEW_LIBS) $(STB_LIBS) $(GLM_LIBS)