AM_CXXFLAGS = -Wall -pedantic

bin_PROGRAMS = lighting
lighting_SOURCES = main.cpp
lighting_CXXFLAGS = $(AM_CXXFLAGS) $(GLFW_CFLAGS) $(GLEW_CFLAGS) $(GLM_CFLAGS)
lighting_LDADD = $(GLFW_LIBS) $(GLEW_LIBS) $(GLM_LIBS)