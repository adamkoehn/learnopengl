AM_CXXFLAGS = -Wall -pedantic

bin_PROGRAMS = tutorial

tutorial_SOURCES = main.cpp manager/Window.cpp
tutorial_CXXFLAGS = $(AM_CXXFLAGS) $(GLFW_CFLAGS) $(GLEW_CFLAGS)
tutorial_LDADD = $(GLFW_LIBS) $(GLEW_LIBS)
