AM_CXXFLAGS = -Wall -pedantic

bin_PROGRAMS = tutorial

tutorial_SOURCES = main.cpp manager/Window.cpp graphics/Shader.cpp graphics/Rectangle.cpp
tutorial_CXXFLAGS = $(AM_CXXFLAGS) $(GLFW_CFLAGS) $(GLEW_CFLAGS) $(STB_CFLAGS)
tutorial_LDADD = $(GLFW_LIBS) $(GLEW_LIBS) $(STB_LIBS)
