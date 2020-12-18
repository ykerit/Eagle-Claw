#pragma once

#include "common.h"

class IndexBuffer 
{
public:
	IndexBuffer(const GLuint* data, const size_t count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
	const size_t getCount() const;
private:
	GLuint renderID_;
	size_t count_;
};