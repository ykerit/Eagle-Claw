#pragma once

#include "common.h"

class VertexBuffer 
{
public:
	VertexBuffer(const void* data, const size_t size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
private:
	GLuint renderID_;
};