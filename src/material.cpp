// material.cpp
#include "material.h"
#include "GLinclude.h"

void SetMaterial(MATERIAL materialType, float r, float g, float b){
    GLfloat mat_ambient[] = { r, g, b, 1.0 };
    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
    GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 0.0 };
    GLfloat mat_emission[] = { 0.0, 0.0, 0.0, 0.0 };

    switch(materialType){
        // plastic
        case M_OBJECT:
        mat_specular[0] = 1; mat_specular[1] = 1; mat_specular[2] = 1;
        mat_shininess[0] = 5;
        break;

        // earth
        case M_FLOOR: case M_WALL:
        mat_specular[0] =1; mat_specular[1] = 1; mat_specular[2] = 1;
        mat_shininess[0] = 3;
        break;


        default:
        break;
    }

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission);
}
