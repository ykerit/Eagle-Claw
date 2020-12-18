#pragma once

#include "common.h"

#include <vector>

struct VertexElement
{
	GLenum type;
	GLboolean normalized;
	size_t count;

	static const size_t getTypeSize(GLenum type) {
		switch (type)
		{
		case GL_FLOAT:
			return sizeof(GLfloat);
		case GL_UNSIGNED_INT:
			return sizeof(GLuint);
		case GL_UNSIGNED_BYTE:
			return sizeof(GLubyte);
		}
		ASSERT(false);
	}
};

class VertexBufferLayout
{
public:

	VertexBufferLayout() : stride_(0) {}

	template <typename T>
	void push(const size_t count) {
		static_assert(false);
	}

	template <>
	void push<GLfloat>(const size_t count) {
		elements_.push_back({GL_FLOAT, GL_FALSE, count });
		stride_ += count * sizeof(GLfloat);
	}

	template <>
	void push<GLuint>(const size_t count) {
		elements_.push_back({ GL_UNSIGNED_INT, GL_FALSE, count });
		stride_ += count * sizeof(GLuint);
	}

	template <>
	void push<GLubyte>(const size_t count) {
		elements_.push_back({ GL_UNSIGNED_BYTE, GL_TRUE, count });
		stride_ += count * sizeof(GLubyte);
	}

	const std::vector<VertexElement> getElements() const {
		return elements_;
	}

	const size_t getStride() const {
		return stride_;
	}

private:
	size_t stride_;
	std::vector<VertexElement> elements_;
};