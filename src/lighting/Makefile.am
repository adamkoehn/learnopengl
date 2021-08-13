AM_CXXFLAGS = -Wall -pedantic

bin_PROGRAMS = lighting
lighting_SOURCES = main.cpp ../manager/Window.cpp ../scene/Lighting.cpp ../graphics/Shader.cpp ../graphics/TexturedCube.cpp ../graphics/Light.cpp ../manager/Camera.cpp ../manager/Input.cpp
lighting_CXXFLAGS = $(AM_CXXFLAGS) $(GLFW_CFLAGS) $(GLEW_CFLAGS) $(GLM_CFLAGS) $(STB_CFLAGS)
lighting_LDADD = $(GLFW_LIBS) $(GLEW_LIBS) $(GLM_LIBS) $(STB_LIBS)