#include <string>
#include <iostream>

#include "CGL/viewer.h"
#include "CGL/renderer.h"
#include "CGL/vector3D.h"
#include "CGL/matrix3x3.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;
using namespace CGL;
unsigned int texture;

/**
 * Part 2:
 * Write your own matrix vector multiplication function. Do not use the built-in CGL function!
 */
Vector3D mult(Matrix3x3 mat, Vector3D input) {
  return input; /* TODO */
}

class QuadDrawer : public Renderer {
 public:

  QuadDrawer() : mat(0, 1, 0, -1, 0, 0, 0, 0, 1), a(-.75, .5, 0), b(-.75, -.5, 0.0), c(.75, -.5, 0.0), d(.75,0.5,0.0) { }

  ~QuadDrawer() { }

  string name() {
    return "Quad Drawing";
  }

  string info() {
    return "Quad Drawing";
  }

  void init() {
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    /*TODO: Change GL_NEAREST, and compare the effects of the following filters.
      The following are the following potential filter options:
      GL_LINEAR
      GL_NEAREST_MIPMAP_NEAREST
      GL_LINEAR_MIPMAP_NEAREST
      GL_NEAREST_MIPMAP_LINEAR
      GL_LINEAR_MIPMAP_LINEAR
     */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // load and generate the texture
    int width, height, nrChannels;
    //TODO: (optional) Change the picture here!
    unsigned char *data = stbi_load("../wall.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
    std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    return;
  }
  
  void render() {
    glBindTexture(GL_TEXTURE_2D, texture); // Comment this out to disable textures
    glBegin(GL_QUADS);

    glColor3f( 1.0, 1.0, 0.0); // Can play with RGB values here :)

    Vector3D a_trans = mult(mat, a);
    Vector3D b_trans = mult(mat, b);
    Vector3D c_trans = mult(mat, c);
    Vector3D d_trans = mult(mat, d);
      
    glTexCoord2f(0,0);
    glVertex3f(a_trans[0], a_trans[1], a_trans[2]);
    /* TODO: change the (0,1) below to (0,.1) to zoom into the texture to see changes. */
    glTexCoord2f(0,1);
    glVertex3f(b_trans[0], b_trans[1], b_trans[2]);
    /* TODO: change the (1,1) below to (.1,.1) to zoom into the texture to see changes. */
    glTexCoord2f(1,1);
    glVertex3f(c_trans[0], c_trans[1], c_trans[2]);
    /* TODO: change the (1,0) to (.1,0) to zoom into the texture to see changes. */
    glTexCoord2f(1,0);
    glVertex3f(d_trans[0], d_trans[1], d_trans[2]);
    glDeleteTextures(1, &texture);
    glDisable(GL_TEXTURE_2D);
    glEnd();
  }

  void resize(size_t w, size_t h) {
    
    this->w = w;
    this->h = h;

    return;
  }
  
 private:
  // frame buffer size
  size_t w, h; 
  Matrix3x3 mat;
  Vector3D a;
  Vector3D b;
  Vector3D c;
  Vector3D d;

};

int main( int argc, char** argv ) {

  // create viewer
  Viewer viewer = Viewer();

  // defined a user space renderer
  Renderer* renderer = new QuadDrawer();

  // set user space renderer
  viewer.set_renderer(renderer);

  // start the viewer
  viewer.init(600, 600);
  viewer.start();

  return 0;
}

