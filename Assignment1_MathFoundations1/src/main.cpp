// Includes for the assignment
#include "Vector4f.h"
#include "Matrix4f.h"
#include <iostream>

// Tests for comparing our library
// You may compare your operations against the glm library
// which is a well tested library.
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Sample unit test comparing against GLM.
bool unitTest0(){
	glm::mat4 glmIdentityMatrix = glm::mat4(1.0f);
	Matrix4f myIdentity( 1.0f,0,0,0,
        			     0,1.0f,0,0,
		        	     0,0,1.0f,0,
			             0,0,0,1.0f);

    if(
        glmIdentityMatrix[0][0]==myIdentity[0][0] &&
        glmIdentityMatrix[0][1]==myIdentity[0][1] &&
        glmIdentityMatrix[0][2]==myIdentity[0][2] &&
        glmIdentityMatrix[0][3]==myIdentity[0][3] &&
        glmIdentityMatrix[1][0]==myIdentity[1][0] &&
        glmIdentityMatrix[1][1]==myIdentity[1][1] &&
        glmIdentityMatrix[1][2]==myIdentity[1][2] &&
        glmIdentityMatrix[1][3]==myIdentity[1][3] &&
        glmIdentityMatrix[2][0]==myIdentity[2][0] &&
        glmIdentityMatrix[2][1]==myIdentity[2][1] &&
        glmIdentityMatrix[2][2]==myIdentity[2][2] &&
        glmIdentityMatrix[2][3]==myIdentity[2][3] &&
        glmIdentityMatrix[3][0]==myIdentity[3][0] &&
        glmIdentityMatrix[3][1]==myIdentity[3][1] &&
        glmIdentityMatrix[3][2]==myIdentity[3][2] &&
        glmIdentityMatrix[3][3]==myIdentity[3][3]){
            return true;
    }
	
    return false;	
}

bool unitTest1(){
	glm::mat4 glmIdentityMatrix = glm::mat4(1.0f);
	Matrix4f myIdentity( 1.0f,0,0,0,
        			     0,1.0f,0,0,
		        	     0,0,1.0f,0,
			             0,0,0,1.0f);

    if(
        glmIdentityMatrix[0][0]==myIdentity(0,0) &&
        glmIdentityMatrix[0][1]==myIdentity(0,1) &&
        glmIdentityMatrix[0][2]==myIdentity(0,2) &&
        glmIdentityMatrix[0][3]==myIdentity(0,3) &&
        glmIdentityMatrix[1][0]==myIdentity(1,0) &&
        glmIdentityMatrix[1][1]==myIdentity(1,1) &&
        glmIdentityMatrix[1][2]==myIdentity(1,2) &&
        glmIdentityMatrix[1][3]==myIdentity(1,3) &&
        glmIdentityMatrix[2][0]==myIdentity(2,0) &&
        glmIdentityMatrix[2][1]==myIdentity(2,1) &&
        glmIdentityMatrix[2][2]==myIdentity(2,2) &&
        glmIdentityMatrix[2][3]==myIdentity(2,3) &&
        glmIdentityMatrix[3][0]==myIdentity(3,0) &&
        glmIdentityMatrix[3][1]==myIdentity(3,1) &&
        glmIdentityMatrix[3][2]==myIdentity(3,2) &&
        glmIdentityMatrix[3][3]==myIdentity(3,3)){
            return true;
    }
	
    return false;	
}

// Sample unit test comparing against GLM.
bool unitTest2(){
	glm::mat4 glmIdentityMatrix = glm::mat4(1.0f);
	Vector4f a(1.0f ,0.0f,  0.0f,   0.0f);
	Vector4f b(0.0f ,1.0f,  0.0f,   0.0f);
	Vector4f c(0.0f ,0.0f,  1.0f,   0.0f);
	Vector4f d(0.0f ,0.0f,  0.0f,   1.0f);
	Matrix4f myIdentity(a,b,c,d);

    if(
        glmIdentityMatrix[0][0]==myIdentity[0][0] &&
        glmIdentityMatrix[0][1]==myIdentity[0][1] &&
        glmIdentityMatrix[0][2]==myIdentity[0][2] &&
        glmIdentityMatrix[0][3]==myIdentity[0][3] &&
        glmIdentityMatrix[1][0]==myIdentity[1][0] &&
        glmIdentityMatrix[1][1]==myIdentity[1][1] &&
        glmIdentityMatrix[1][2]==myIdentity[1][2] &&
        glmIdentityMatrix[1][3]==myIdentity[1][3] &&
        glmIdentityMatrix[2][0]==myIdentity[2][0] &&
        glmIdentityMatrix[2][1]==myIdentity[2][1] &&
        glmIdentityMatrix[2][2]==myIdentity[2][2] &&
        glmIdentityMatrix[2][3]==myIdentity[2][3] &&
        glmIdentityMatrix[3][0]==myIdentity[3][0] &&
        glmIdentityMatrix[3][1]==myIdentity[3][1] &&
        glmIdentityMatrix[3][2]==myIdentity[3][2] &&
        glmIdentityMatrix[3][3]==myIdentity[3][3]){
            return true;
    }
	
    return false;	
}

// Sample unit test comparing against GLM.
// TODO: Test against glm::scale
bool unitTest3(){
	glm::mat4 glmScale = glm::scale(glm::mat4(1.0f), glm::vec3(2.0f));
	Vector4f a(1.0f,0,0,0);
	Vector4f b(0.0f,1.0f,0,0);
	Vector4f c(0,0,1.0f,0);
	Vector4f d(0,0,0,1.0f);
	Matrix4f scalar(a,b,c,d);
	Matrix4f myScaled;
    myScaled = scalar * scalar.MakeScale(2.0f,2.0f,2.0f);

    if(
        glmScale[0][0]==myScaled[0][0] &&
        glmScale[0][1]==myScaled[0][1] &&
        glmScale[0][2]==myScaled[0][2] &&
        glmScale[0][3]==myScaled[0][3] &&
        glmScale[1][0]==myScaled[1][0] &&
        glmScale[1][1]==myScaled[1][1] &&
        glmScale[1][2]==myScaled[1][2] &&
        glmScale[1][3]==myScaled[1][3] &&
        glmScale[2][0]==myScaled[2][0] &&
        glmScale[2][1]==myScaled[2][1] &&
        glmScale[2][2]==myScaled[2][2] &&
        glmScale[2][3]==myScaled[2][3] &&
        glmScale[3][0]==myScaled[3][0] &&
        glmScale[3][1]==myScaled[3][1] &&
        glmScale[3][2]==myScaled[3][2] &&
        glmScale[3][3]==myScaled[3][3]){
            return true;
    }
	
    return false;	
}

// Sample unit test comparing against GLM.
// Testing operator
bool unitTest4(){
	glm::mat4 glmTest = glm::mat4(1.0f);
    glmTest[1][3] = 72.0f;
    glmTest[2][3] = 2.1f;

	Matrix4f myMatrix(0,0,0,0,
                      0,0,0,0,
                      0,0,0,0,
                      0,0,0,0);

    myMatrix[1][3] = 72.0f;
    myMatrix[2][3] = 2.1f;

    if( glmTest[1][3]==myMatrix[1][3] &&
        glmTest[2][3]==myMatrix[2][3] ){
            return true;
    }
	
    return false;	
}

// Sample unit test testing your library
bool unitTest5(){
  Vector4f a(1,1,1,1);
  Vector4f b(0,0,0,0);
  Vector4f c = a + b;

  if(c.x == 1 && c.y == 1 && c.z ==1 && c.w==1){
    return true;
  }
    return false;
}

//Rotation X testing
bool unitTest6() {
	glm::mat4 glmRotationX = glm::rotate(glm::mat4(1.0f), 45.0f, glm::vec3(1.0f, 0.0f, 0.0f));

	Vector4f a(1.0f, 0.0f, 0.0f, 0.0f);
	Vector4f b(0.0f, 1.0f, 0.0f, 0.0f);
	Vector4f c(0.0f, 0.0f, 1.0f, 0.0f);
	Vector4f d(0.0f, 0.0f, 0.0f, 1.0f);
	Matrix4f rotation(a, b, c, d);
	Matrix4f myRotationX = rotation * rotation.MakeRotationX(45.0f);

	if (
		glmRotationX[0][0] == myRotationX[0][0] &&
		glmRotationX[0][1] == myRotationX[0][1] &&
		glmRotationX[0][2] == myRotationX[0][2] &&
		glmRotationX[0][3] == myRotationX[0][3] &&
		glmRotationX[1][0] == myRotationX[1][0] &&
		glmRotationX[1][1] == myRotationX[1][1] &&
		glmRotationX[1][2] == myRotationX[1][2] &&
		glmRotationX[1][3] == myRotationX[1][3] &&
		glmRotationX[2][0] == myRotationX[2][0] &&
		glmRotationX[2][1] == myRotationX[2][1] &&
		glmRotationX[2][2] == myRotationX[2][2] &&
		glmRotationX[2][3] == myRotationX[2][3] &&
		glmRotationX[3][0] == myRotationX[3][0] &&
		glmRotationX[3][1] == myRotationX[3][1] &&
		glmRotationX[3][2] == myRotationX[3][2] &&
		glmRotationX[3][3] == myRotationX[3][3]) {
		return true;
	}

	std::cout << std::endl;

	return false;
}

//Rotation Y testing
bool unitTest7() {
	glm::mat4 glmRotationY = glm::rotate(glm::mat4(1.0f), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	Vector4f a(1.0f, 0.0f, 0.0f, 0.0f);
	Vector4f b(0.0f, 1.0f, 0.0f, 0.0f);
	Vector4f c(0.0f, 0.0f, 1.0f, 0.0f);
	Vector4f d(0.0f, 0.0f, 0.0f, 1.0f);
	Matrix4f rotation(a, b, c, d);
	Matrix4f myRotationY = rotation * rotation.MakeRotationY(45.0f);

	if (
		glmRotationY[0][0] == myRotationY[0][0] &&
		glmRotationY[0][1] == myRotationY[0][1] &&
		glmRotationY[0][2] == myRotationY[0][2] &&
		glmRotationY[0][3] == myRotationY[0][3] &&
		glmRotationY[1][0] == myRotationY[1][0] &&
		glmRotationY[1][1] == myRotationY[1][1] &&
		glmRotationY[1][2] == myRotationY[1][2] &&
		glmRotationY[1][3] == myRotationY[1][3] &&
		glmRotationY[2][0] == myRotationY[2][0] &&
		glmRotationY[2][1] == myRotationY[2][1] &&
		glmRotationY[2][2] == myRotationY[2][2] &&
		glmRotationY[2][3] == myRotationY[2][3] &&
		glmRotationY[3][0] == myRotationY[3][0] &&
		glmRotationY[3][1] == myRotationY[3][1] &&
		glmRotationY[3][2] == myRotationY[3][2] &&
		glmRotationY[3][3] == myRotationY[3][3]) {
		return true;
	}

	std::cout << std::endl;

	return false;
}

//Rotation X testing
bool unitTest8() {
	glm::mat4 glmRotationZ = glm::rotate(glm::mat4(1.0f), 45.0f, glm::vec3(0.0f, 0.0f, 1.0f));

	Vector4f a(1.0f, 0.0f, 0.0f, 0.0f);
	Vector4f b(0.0f, 1.0f, 0.0f, 0.0f);
	Vector4f c(0.0f, 0.0f, 1.0f, 0.0f);
	Vector4f d(0.0f, 0.0f, 0.0f, 1.0f);
	Matrix4f rotation(a, b, c, d);
	Matrix4f myRotationZ = rotation * rotation.MakeRotationZ(45.0f);

	if (
		glmRotationZ[0][0] == myRotationZ[0][0] &&
		glmRotationZ[0][1] == myRotationZ[0][1] &&
		glmRotationZ[0][2] == myRotationZ[0][2] &&
		glmRotationZ[0][3] == myRotationZ[0][3] &&
		glmRotationZ[1][0] == myRotationZ[1][0] &&
		glmRotationZ[1][1] == myRotationZ[1][1] &&
		glmRotationZ[1][2] == myRotationZ[1][2] &&
		glmRotationZ[1][3] == myRotationZ[1][3] &&
		glmRotationZ[2][0] == myRotationZ[2][0] &&
		glmRotationZ[2][1] == myRotationZ[2][1] &&
		glmRotationZ[2][2] == myRotationZ[2][2] &&
		glmRotationZ[2][3] == myRotationZ[2][3] &&
		glmRotationZ[3][0] == myRotationZ[3][0] &&
		glmRotationZ[3][1] == myRotationZ[3][1] &&
		glmRotationZ[3][2] == myRotationZ[3][2] &&
		glmRotationZ[3][3] == myRotationZ[3][3]) {
		return true;
	}

	std::cout << std::endl;

	return false;
}

int main(){
    // Keep track of the tests passed
    unsigned int testsPassed = 0;

    // Run 'unit tests'
    std::cout << "Passed 0: " << unitTest0() << " \n";
    std::cout << "Passed 1: " << unitTest1() << " \n";
    std::cout << "Passed 2: " << unitTest2() << " \n";
    std::cout << "Passed 3: " << unitTest3() << " \n";
    std::cout << "Passed 4: " << unitTest4() << " \n";
    std::cout << "Passed 5: " << unitTest5() << " \n";
	std::cout << "Passed 6: " << unitTest6() << " \n";
	std::cout << "Passed 7: " << unitTest7() << " \n";
	std::cout << "Passed 8: " << unitTest7() << " \n";
    return 0;
}
