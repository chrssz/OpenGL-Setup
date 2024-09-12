#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H
#include<glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include <stdexcept>
#include<iostream>
#include<cerrno>
class Shader
{
    public:
        GLuint ID;
        Shader();
        void Activate();
        void Delete();
};
#endif