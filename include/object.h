#ifndef OBJECT_H
#define OBJECT_H

#include "material.h"
#include <iostream>
#include <cmath>
#include <string>

#define ESP 1e-6

class object{
protected:
    glm::vec3 loc, v, a;
    std::string name;
    float m;
public:
    object(glm::vec3 loc, glm::vec3 v, glm::vec3 a, float m);
    object();
    object(glm::vec3 loc);
    void update(float);
    void setV(glm::vec3);
    void setA(glm::vec3);
    void setLoc(glm::vec3);
    void setM(float);
    void setName(std::string);
    glm::vec3 getV();
    glm::vec3 getA();
    glm::vec3 getLoc();
    float getM();
    std::string getName();
    virtual ~object();
    virtual void draw(MATERIAL, float, float, float);
    virtual bool isCollide(object &);
};

#endif