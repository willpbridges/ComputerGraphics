// High level design note
// Our matrix should match the behavior of the glm library.
#ifndef MATRIX4F_H
#define MATRIX4F_H

#include <cmath>

// We need to Vector4f header in order to multiply a matrix
// by a vector.
#include "Vector4f.h"

// Matrix 4f represents 4x4 matrices in Math
struct Matrix4f {
private:
	float n[4][4];  // Store each value of the matrix

public:
	Matrix4f() = default;

	// TODO: Row or column major order you decide!
	// Matrix constructor with 9 scalar values.
	Matrix4f(float n00, float n01, float n02, float n03,
		float n10, float n11, float n12, float n13,
		float n20, float n21, float n22, float n23,
		float n30, float n31, float n32, float n33) {

		n[0][0] = n00; n[0][1] = n01; n[0][2] = n02; n[0][3] = n03;
		n[1][0] = n10; n[1][1] = n11; n[1][2] = n12; n[1][3] = n13;
		n[2][0] = n20; n[2][1] = n21; n[2][2] = n22; n[2][3] = n23;
		n[3][0] = n30; n[3][1] = n31; n[3][2] = n32; n[3][3] = n33;
	}

	// Matrix constructor from four vectors.
	// Note: 'd' will almost always be 0,0,0,1
	Matrix4f(const Vector4f& a, const Vector4f& b, const Vector4f& c, const Vector4f& d) {
		n[0][0] = a.x; n[0][1] = b.x; n[0][2] = c.x; n[0][3] = d.x;
		n[1][0] = a.y; n[1][1] = b.y; n[1][2] = c.y; n[1][3] = d.y;
		n[2][0] = a.z; n[2][1] = b.z; n[2][2] = c.z; n[2][3] = d.z;
		n[3][0] = a.w; n[3][1] = b.w; n[3][2] = c.w; n[3][3] = d.w;
	}

	// Makes the matrix an identity matrix
	void identity() {
		n[0][0] = 1; n[0][1] = 0; n[0][2] = 0; n[0][3] = 0;
		n[1][0] = 0; n[1][1] = 1; n[1][2] = 0; n[1][3] = 0;
		n[2][0] = 0; n[2][1] = 0; n[2][2] = 1; n[2][3] = 0;
		n[3][0] = 0; n[3][1] = 0; n[3][2] = 0; n[3][3] = 1;
	}

	// Index operator with two dimensions
	// Example: M(1,1) returns row 1 and column 1 of matrix M.
	float& operator ()(int i, int j) {
		return (n[i][j]);
	}

	// Index operator with two dimensions
	// Example: M(1,1) returns row 1 and column 1 of matrix M.
	const float& operator ()(int i, int j) const {
		return (n[i][j]);
	}

	// Return a single  vector from the matrix (row or columnn major? hmm).
	Vector4f& operator [](int j) {
		return (*reinterpret_cast<Vector4f *>(n[j]));
	}

	// Return a single  vector from the matrix (row or columnn major? hmm).
	const Vector4f& operator [](int j) const {
		return (*reinterpret_cast<const Vector4f *>(n[j]));
	}

	// Make a matrix rotate about various axis
	Matrix4f MakeRotationX(float t) {
		
		Matrix4f rotationX;
		
		rotationX[0][0] = 1;	rotationX[0][1] = 0;				rotationX[0][2] = 0;			rotationX[0][3] = 0;
		rotationX[1][0] = 0;	rotationX[1][1] = std::cos(t);		rotationX[1][2] = std::sin(t);	rotationX[1][3] = 0;
		rotationX[2][0] = 0;	rotationX[2][1] = -std::sin(t);		rotationX[2][2] = std::cos(t);	rotationX[2][3] = 0;
		rotationX[3][0] = 0;	rotationX[3][1] = 0;				rotationX[3][2] = 0;			rotationX[3][3] = 1;

		return(rotationX); // You will need to modify this.
							// When you test, test against glm_gtx_transform
	}
	Matrix4f MakeRotationY(float t) {
		// TODO:
		Matrix4f rotationY;
	
		rotationY[0][0] = std::cos(t);	rotationY[0][1] = 0;		rotationY[0][2] = -std::sin(t);		rotationY[0][3] = 0;
		rotationY[1][0] = 0;			rotationY[1][1] = 1;		rotationY[1][2] = 0;				rotationY[1][3] = 0;
		rotationY[2][0] = std::sin(t);	rotationY[2][1] = 0;		rotationY[2][2] = std::cos(t);		rotationY[2][3] = 0;
		rotationY[3][0] = 0;			rotationY[3][1] = 0;		rotationY[3][2] = 0;				rotationY[3][3] = 1;

		return(rotationY); // You will need to modify this.
							// When you test, test against glm_gtx_transform
	}
	Matrix4f MakeRotationZ(float t) {
		// TODO:
		Matrix4f rotationZ;
		
		rotationZ[0][0] = std::cos(t);		rotationZ[0][1] = std::sin(t);		rotationZ[0][2] = 0;		rotationZ[0][3] = 0;
		rotationZ[1][0] = -std::sin(t);		rotationZ[1][1] = std::cos(t);		rotationZ[1][2] = 0;		rotationZ[1][3] = 0;
		rotationZ[2][0] = 0;				rotationZ[2][1] = 0;				rotationZ[2][2] = 1;		rotationZ[2][3] = 0;
		rotationZ[3][0] = 0;				rotationZ[3][1] = 0;				rotationZ[3][2] = 0;		rotationZ[3][3] = 1;

		return(rotationZ); // You will need to modify this.
							// When you test, test against glm_gtx_transform
	}
	Matrix4f MakeScale(float sx, float sy, float sz) {
		// TODO:
		Matrix4f scale;

		scale[0][0] = sx;	scale[0][1] = 0; scale[0][2] = 0; scale[0][3] = 0;
		scale[1][0] = 0;	scale[1][1] = sy; scale[1][2] = 0; scale[1][3] = 0;
		scale[2][0] = 0;	scale[2][1] = 0; scale[2][2] = sz; scale[2][3] = 0;
		scale[3][0] = 0;	scale[3][1] = 0; scale[3][2] = 0; scale[3][3] = 1;

		return(scale); // You will need to modify this.
							// When you test, test against glm_gtx_transform
	}


};

// Matrix Multiplication
Matrix4f operator *(const Matrix4f& A, const Matrix4f& B) {
	// TODO:
	Matrix4f mat4;

	Vector4f bCol0 = Vector4f(B[0][0], B[1][0], B[2][0], B[3][0]);
	Vector4f bCol1 = Vector4f(B[0][1], B[1][1], B[2][1], B[3][1]);
	Vector4f bCol2 = Vector4f(B[0][2], B[1][2], B[2][2], B[3][2]);
	Vector4f bCol3 = Vector4f(B[0][3], B[1][3], B[2][3], B[3][3]);
	
	mat4[0][0] = Dot(A[0], bCol0);
	mat4[0][1] = Dot(A[0], bCol1);
	mat4[0][2] = Dot(A[0], bCol2);
	mat4[0][3] = Dot(A[0], bCol3);

	mat4[1][0] = Dot(A[1], bCol0);
	mat4[1][1] = Dot(A[1], bCol1);
	mat4[1][2] = Dot(A[1], bCol2);
	mat4[1][3] = Dot(A[1], bCol3);

	mat4[2][0] = Dot(A[2], bCol0);
	mat4[2][1] = Dot(A[2], bCol1);
	mat4[2][2] = Dot(A[2], bCol2);
	mat4[2][3] = Dot(A[2], bCol3);

	mat4[3][0] = Dot(A[3], bCol0);
	mat4[3][1] = Dot(A[3], bCol1);
	mat4[3][2] = Dot(A[3], bCol2);
	mat4[3][3] = Dot(A[3], bCol3);

	return mat4;
}

// Matrix multiply by a vector

Vector4f operator *(const Matrix4f& M, const Vector4f& v) {
	// TODO:
	Vector4f vec;
	
	vec.x = Dot(M[0], v);
	vec.y = Dot(M[1], v);
	vec.z = Dot(M[2], v);
	vec.w = Dot(M[3], v);

	return vec;
}


#endif
