#pragma once

#include <GL/glew.h>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>

/** TODO:
 * I should implement something to parse shader so that I can handle UBO, uniform, buffer, etc. more
 * easily.
 */

class Program
{
public:
	GLuint addr;
	std::map<std::string, GLint> uniforms_location;
	Program(GLuint p)
	{
		addr = p;
	};
	~Program()
	{
		glDeleteProgram(addr);
	};
};

class Shader
{
public:
	GLuint addr;
	std::vector<std::string> uniforms;
	Shader(GLuint s)
	{
		addr = s;
	};
	~Shader()
	{
		glDeleteShader(addr);
	};
};

class ShaderHandler
{
public:
	static ShaderHandler& instance()
	{
		static ShaderHandler instance;
		return instance;
	}

	std::shared_ptr<Shader> create_shader(GLenum type, const std::string& shader_src, const std::string& name);
	std::shared_ptr<Shader> create_shader(GLenum type, const std::string& filepath);
	std::shared_ptr<Program> create_program(std::vector<std::shared_ptr<Shader>>& shaders);

private:
	ShaderHandler() {};
	ShaderHandler(ShaderHandler const&);
	void operator=(ShaderHandler const&);
};
