# HW0 - Getting Started

## Part 1 - Setting up your machine

If you face any issues with setup, please don't hesitate to talk to a TA! We will do our best to help get your machine up and running.

### A. Install C++

In CS 184, all of your projects will be done in C++. If you are new to the language, please read a handy [primer we wrote](https://cs184.eecs.berkeley.edu/sp19/article/11/c-basics) that gives a quick overview of important C++ specific concepts. 

First, make sure to install the appropriate version of C++ on your machine. 

On Mac, first go install XCode through the Mac App Store. Once you've done that, open up your terminal and run ```xcode-select --install```. You should now be able to run ```g++ --version``` without any errors. On Windows, install Visual Studio.

Aside from C++, we highly recommend that you use an real IDE, not Sublime Text or Visual Studio Code, in order to work on your projects in this class. Many of the projects require serious debugging, made exponentially easier through the use of an IDE. We highly recommend [CLion](https://www.jetbrains.com/clion/), Xcode for Mac users, or Visual Studio for Windows users.

### B. Install CMake

We will be using [CMake](http://www.cmake.org/) to build the assignments. If you don't have CMake (version >= 2.8) on your personal computer, you can install it using apt-get on Linux or Macports/Homebrew on OS X. Alternatively, you can [download](https://cmake.org/download/) it directly from the CMake website.

If you are using an IDE, you can use CMake to generate project files. CLion should be able to directly open CMake projects. If you are using Xcode or Visual Studio, you can use a [CMake Generator](https://cmake.org/cmake/help/v3.0/manual/cmake-generators.7.html).

### C. Building the Test Code

If you are on Windows, you probably want to follow [these instructions](https://cs184.eecs.berkeley.edu/sp19/article/10/cmake-gui-windows-tutorial).

If you are using Xcode, here is a [helpful video tutorial](https://www.youtube.com/watch?v=9EADCyN_Fek) made by our very own Prof. Ren Ng last spring.

First, clone the ```hw0``` repo from Github. Change directory into the folder, and run 

    mkdir build; cd build

to create a build directory and enter it. If you'd like to use an IDE, i.e. Xcode, run

    cmake -G Xcode ..

and CMake should generate the appropriate IDE project files. Open the new project with your chosen IDE. Once you hit run, you should see a window pop up with a yellow triangle.

Instead, if you'd rather use the command line, run

    cmake ..

to have CMake generate the appropriate Makefiles for your system, and then run

    make 

to actually compile your files. If both of these commands ran without any errors, you should see a ```triangle_test``` executable file under the ```build``` directory. Run this file by typing

    ./triangle_test

If all goes well, you should see a window pop up with a yellow triangle.


## Part 2 - Basic C++/Linear Algebra Practice

Fill in the ```mult``` function at the top of ```triangle_test.cpp``` by implementing a 3 dimensional matrix-vector multiplication. Do not use the built-in CGL multiplication function! Read the CGL source files for ```matrix3x3.cpp``` and ```vector3D.cpp``` in order to get a better idea for how to use the two parameters. Once the function is properly implemented, you should see the yellow triangle rotated 90 degrees.

Remember to run ```make``` to compile your edits.

If you are feeling ambitious, try instantiating the matrix to perform a scaling operation (possible) or shifting operation (not possible, why is that?). We'll learn more formally about these later on in the course.

## Part 3 - Going Above and Beyond (Optional)

In computer graphics, almost everything is made out of triangles. Shapes and objects are represented as [meshes composed of hundreds or even thousands of triangles](https://en.wikipedia.org/wiki/Triangle_mesh). Let's try and do something more interesting with our triangle.

Take a look at the ```render``` function in ```triangle_test.cpp```. Notice the following commands:

* ```glColor3f(1.0, 1.0, 0.0)``` tells our computer to render the following shapes using the RGB value (1.0, 1.0, 0.0), or yellow.
* ```glBegin(GL_TRIANGLES)``` tells our computer that we want to render triangles with the following vertices we will specify.
* ```glVertex3f(x, y, z)``` tells our computer to draw a vertex at a particular location.

With the above setup, if we specify six vertices, our computer will render one triangle with the first three vertices, and another triangle with the second three vertices. Try modifying the given render code to draw "something interesting". It could be a cool picture, your name, an interesting pattern... Feel free to share your creative work on Piazza! There should be a thread where you can share your creation.

## Submission
There is no submission for this homework. However, we highly recommend that you finish the homework, to prevent any issues when you start on the projects for this class.