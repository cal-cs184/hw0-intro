# HW0 - Getting Started

## Part 1 - Setting up your machine and running the project

For instructions on how to setup your comupter and build CS184 projects, go to [the CS184 website > Resources > Building CS184 Assignments](https://cs184.eecs.berkeley.edu/sp21/docs/building-assignments) for a detailed guide.

If all goes well, you should see a window pop up with a rectangle with a brick texture.

### Common issue: I only see a yellow rectangle
If you only see a yellow rectangle, it means that the HW0 ran properly, but it couldn't find the `wall.jpg` texture. If you look inside the source code, you will find a line that says `stbi_load("../wall.jpg"`. This means that the binary is trying to look for the texture file in a parent directory. To solve this issue, run the executable with the working directory inside the build folder. Refer to the specific build section for instructions on how to use this.

## Part 2 - Basic C++/Linear Algebra Practice

Fill in the ```mult``` function at the top of ```quad_test.cpp``` by implementing a 3 dimensional matrix-vector multiplication. Do not use the built-in CGL multiplication function! Read the [CGL vectors documentations](https://cs184.eecs.berkeley.edu/sp21/docs/cgl-vector-docs) in order to get a better idea for how to use the two parameters. Once the function is properly implemented, you should see the brick rotated 90 degrees.

Try to achieve this __without__ manually writing out the equation for each __component__ of the vector. (Hint: a 3d matrix-vector multiplication is the sum of three scalar-vector multiplication, and you can access use columns of matrix as vectors)

Remember to run ```make``` to compile your edits.

If you are feeling ambitious, try instantiating the matrix to perform a scaling operation (possible) or shifting operation (not possible, why is that?). We'll learn more formally about these later on in the course.

## Part 3 - Types of Filters

There should be two sets of TODO comments in the code - one near a ```glTexParameteri``` function, and another near ```glTexCoord2f``` functions. These two are API calls to the ```OpenGL``` library, the first one setting extra options on texture processing, and another on texture coordinate binding. 

```OpenGL``` is totally optional now, and we don't need to go into the details (though it may be helpful knowledge, especially for the final project!) For now, simply use the two functions to explore the different filtering functions available in many standard libraries, and compare and contrast their effects. If it's hard to see, we can somewhat 'zoom in' by setting smaller values for the ```glTexCoord2f``` coordinates, essentially binding a smaller region of the texture to the entire rectangle.

How does `Linear` filtering compare to `Nearest`? How does adding `MipMap` options affect the outcome? How are they each implemented? (You will do this for the first assignment)

Optional: For further reading on filtering, specifically in `OpenGL`, as well as a great `OpenGL` beginner resource, [click here](https://learnopengl.com/Getting-started/Textures).

## Part 4 - Going Above and Beyond (Optional)

In computer graphics, almost everything is made out of triangles or quads. Shapes and objects are represented as [meshes composed of hundreds or even thousands of triangles](https://en.wikipedia.org/wiki/Triangle_mesh). Let's try and do something more interesting with our triangle.

Take a look at the ```render``` function in ```quad_test.cpp```. Notice the following commands:

* ```glColor3f(1.0, 1.0, 0.0)``` tells our computer to render the following shapes using the RGB value (1.0, 1.0, 0.0), or yellow.
* ```glBegin(GL_QUADS)``` tells our computer that we want to render quads with the following vertices we will specify.
* ```glVertex3f(x, y, z)``` tells our computer to draw a vertex at a particular location.

With the above setup, if we specify eight vertices, our computer will render one quad with the first four vertices, and another quad with the second four vertices (One can do the same for triangles with ```glBegin(GL_TRIANGLES)```, which uses three vertices per triangle). Try modifying the given render code to draw "something interesting". (Note: If you want to disable the textures, you'll need to comment out the line ```glBindTexture(GL_TEXTURE_2D, texture)``` in the beginning of the ```render``` function) It could be a cool picture, your name, an interesting pattern... Feel free to share your creative work on Piazza! There should be a thread where you can share your creation.

## Submission
There is no graded submission for this homework. However, to familiarize yourself with the process, you should try committing and tagging your code as specified in [part 1](https://cs184.eecs.berkeley.edu/sp21/docs/submitting-assignments). We highly recommend that you finish the homework, to prevent any issues when you start on the projects for this class.
